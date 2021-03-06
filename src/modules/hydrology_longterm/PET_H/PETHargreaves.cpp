/*!
 * \file PETHargreaves.cpp
 *
 * \author Junzhi Liu
 * \date Nov. 2010
 * \revised LiangJun Zhu
 *
 */
#include "PETHargreaves.h"
#include "MetadataInfo.h"
#include <vector>
#include <cmath>
#include <string>
#include <iostream>
#include <fstream>
#include "util.h"
#include "ClimateParams.h"
#include "ModelException.h"
#include <omp.h>

using namespace std;

PETHargreaves::PETHargreaves(void):m_nCells(-1), m_petFactor(1.f),m_HCoef_pet(0.0023f), 
	m_tMean(NULL), m_tMin(NULL), m_tMax(NULL), m_pet(NULL)
{
}

PETHargreaves::~PETHargreaves(void)
{
	if(this->m_pet != NULL) delete [] this->m_pet;
}

void PETHargreaves::SetValue(const char* key, float value)
{
	string sk(key);
	if (StringMatch(sk,VAR_K_PET)) m_petFactor  = value;
	else if (StringMatch(sk, VAR_PET_HCOEF)) m_HCoef_pet = value;
	else if (StringMatch(sk, VAR_OMP_THREADNUM)) omp_set_num_threads((int)value);
	else
		throw ModelException(MID_PET_H,"SetValue","Parameter " + sk + " does not exist in current module. Please contact the module developer.");
}

void PETHargreaves::Set1DData(const char* key,int n, float *value)
{
	if(!this->CheckInputSize(key,n)) return;
	string sk(key);
	if (StringMatch( sk,DataType_MeanTemperature))
		this->m_tMean = value;
	else if (StringMatch( sk,DataType_MaximumTemperature))
		this->m_tMax = value;
	else if (StringMatch( sk, DataType_MinimumTemperature))
		this->m_tMin = value;
	else if (StringMatch( sk, VAR_CELL_LAT))
		this->m_cellLat = value;
	else
		throw ModelException(MID_PET_H,"Set1DValue","Parameter " + sk + " does not exist in current module. Please contact the module developer.");
}

int PETHargreaves::Execute()
{
	if(!this->CheckInputData()) return false;
	if(NULL == m_pet)
		this->m_pet = new float[m_nCells];
	m_jday = JulianDay(this->m_date);
	//cout<<m_tMean[0]<<","<<m_tMax[0]<<","<<m_tMin[0]<<endl;
#pragma omp parallel for
	for (int i = 0; i < m_nCells; ++i)
	{	
		m_srMax = MaxSolarRadiation(m_jday, m_cellLat[i]);
		///calculate latent heat of vaporization(from swat)
		float latentHeat = 2.501f - 0.002361f * m_tMean[i];
		/// extraterrestrial radiation
		/// equation 1:1.1.6 in SWAT Theory 2009, p33
		float h0 = m_srMax * 37.59f / 30.0f;
		/// calculate potential evapotranspiration, equation 2:2.2.24 in SWAT Theory 2009, p133
		/// Hargreaves et al., 1985. In SWAT Code, 0.0023 is replaced by harg_petco, which range from 0.0019 to 0.0032. by LJ
		float petValue = m_HCoef_pet * h0 * pow(abs(m_tMax[i]-m_tMin[i]), 0.5f)
			* (m_tMean[i] + 17.8f) / latentHeat;
		m_pet[i] = m_petFactor * max(0.0f, petValue);
	}
	return 0;
}


void PETHargreaves::Get1DData(const char* key, int* n, float **data)
{
	string sk(key);
	if(this->m_pet == NULL) 
		throw ModelException(MID_PET_H,"Get1DData","The result is NULL. Please first execute the module.");
	if (StringMatch(sk, VAR_PET))
	{
		*data = this->m_pet;
		*n = this->m_nCells;
	}
	else
		throw ModelException(MID_PET_H, "Get1DData","Parameter " + sk + " does not exist. Please contact the module developer.");
}

bool PETHargreaves::CheckInputSize(const char* key, int n)
{
	if(n<=0)
		throw ModelException(MID_PET_H,"CheckInputSize","Input data for "+string(key) +" is invalid. The size could not be less than zero.");
	if(this->m_nCells != n)
	{
		if(this->m_nCells <=0) this->m_nCells = n;
		else
			throw ModelException(MID_PET_H,"CheckInputSize","Input data for "+string(key) +" is invalid. All the input data should have same size.");
	}
	return true;
}

bool PETHargreaves::CheckInputData()
{
	if(this->m_date == -1)
	{
		throw ModelException(MID_PET_H,"CheckInputData","You have not set the time.");
		return false;
	}
	if(m_nCells <= 0)
		throw ModelException(MID_PET_H,"CheckInputData","The dimension of the input data can not be less than zero.");
	if(this->m_tMax == NULL)
		throw ModelException(MID_PET_H,"CheckInputData","The maximum temperature can not be NULL.");
	if(this->m_tMin == NULL)
		throw ModelException(MID_PET_H,"CheckInputData","The minimum temperature can not be NULL.");
	if(this->m_tMean == NULL)
		throw ModelException(MID_PET_H,"CheckInputData","The mean temperature can not be NULL.");
	return true;
}