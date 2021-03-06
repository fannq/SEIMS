//! Class for the Precipitation Interception module
#include "clsPI_MSM.h"
#include "MetadataInfo.h"
#include "ModelException.h"
#include "api.h"
#include "ClimateParams.h"
#include "util.h"
#define _USE_MATH_DEFINES
#include <sstream>
#include <fstream>
#include <math.h>
#include <cmath>
#include <time.h>
#include <omp.h>

clsPI_MSM::clsPI_MSM(void):m_st(NULL)
{
	m_nCells = -1;
	this->m_Pi_b = -1.0f;
	this->m_dateLastTimeStep = -1;
	this->m_Init_IS = 0.0f;
}

clsPI_MSM::~clsPI_MSM(void)
{
	if(this->m_interceptionLoss != NULL) delete [] this->m_interceptionLoss;
	if(this->m_st != NULL) delete [] this->m_st;
	if(this->m_netPrecipitation != NULL) delete [] this->m_netPrecipitation;
	if(this->m_evaporation != NULL) delete [] this->m_evaporation;
}

void clsPI_MSM::Set1DData(const char* key, int nRows, float* data)
{
	this->CheckInputSize(key,nRows);

	string s(key);
	if(StringMatch(s, VAR_PRECI))				
		m_P = data;
	else if(StringMatch(s,VAR_PET))			
		m_PET = data;
	else if(StringMatch(s, VAR_INTERC_MAX))	
		m_maxSt = data;
	else if(StringMatch(s,VAR_INTERC_MIN))	
		m_minSt = data;	
	else									
		throw ModelException(MID_PI_MSM,"Set1DData", "Parameter " + s + " does not exist in current module. Please contact the module developer.");
}

void clsPI_MSM::SetValue(const char* key, float data)
{
	string s(key);
	if(StringMatch(s,VAR_PI_B))				this->m_Pi_b = data;
	else if(StringMatch(s, VAR_INIT_IS))		this->m_Init_IS = data;
	else if (StringMatch(s, VAR_OMP_THREADNUM)) omp_set_num_threads((int)data);
	else									
		throw ModelException(MID_PI_MSM,"SetValue","Parameter " + s + " does not exist in current module. Please contact the module developer.");
}

void clsPI_MSM::Get1DData(const char* key, int* nRows, float** data)
{
	string s(key);
	if(StringMatch(s, VAR_INLO))				
		*data = m_interceptionLoss;
	else if(StringMatch(s, VAR_INET))			
		*data = m_evaporation;
	else if(StringMatch(s, VAR_NEPR))			
		*data = m_netPrecipitation;
	else									
		throw ModelException(MID_PI_MSM,"Get1DData","Result " + s + " does not exist in current module. Please contact the module developer.");
	*nRows = this->m_nCells;
}

//! 
int clsPI_MSM::Execute()
{
	//check input data
	this->CheckInputData();

	//initial the state variable
	if(this->m_st == NULL)
	{
		m_st = new float[this->m_nCells];
		this->m_evaporation = new float[this->m_nCells];
		this->m_interceptionLoss = new float[this->m_nCells];
		this->m_netPrecipitation = new float[this->m_nCells];
		
		#pragma omp parallel for
		for(int i = 0 ;i<this->m_nCells;i++) 
		{
			m_st[i] = this->m_Init_IS;
			m_evaporation[i] = 0.f;
			m_interceptionLoss[i] = 0.f;
			m_netPrecipitation[i] = 0.f;
		}
	}

	int julian = JulianDay(m_date);
	#pragma omp parallel for
	for(int i = 0 ; i < this->m_nCells; i ++)
	{
		if (m_P[i] > 0)
		{
			//interception storage capacity
			float degree = 2 * PI * (julian - 87)/365.f;
			float min = m_minSt[i];
			float max = m_maxSt[i];
			float capacity = min + (max - min)*pow(0.5 + 0.5*sin(degree),double(m_Pi_b));

			//interception
			float availableSpace = capacity - m_st[i];
			if (availableSpace < 0)
				availableSpace = 0.f;

			if(availableSpace < m_P[i]) 
				m_interceptionLoss[i] = availableSpace;
			else
				m_interceptionLoss[i] = m_P[i];

			//net precipitation
			m_netPrecipitation[i] = m_P[i] - m_interceptionLoss[i];
			m_st[i] += m_interceptionLoss[i];
		}
		else
		{
			m_interceptionLoss[i] = 0.f;
			m_netPrecipitation[i] = 0.f;
		}

		//evaporation
		if(m_st[i] > m_PET[i])	
			m_evaporation[i] = m_PET[i];
		else														
			m_evaporation[i] = m_st[i];
		m_st[i] -= m_evaporation[i];
	}
	return 0;
}

bool clsPI_MSM::CheckInputData()
{
	if(this->m_date == -1)
	{
		throw ModelException(MID_PI_MSM,"CheckInputData","You have not set the time.");
		return false;
	}

	if(m_nCells <= 0)
	{
		throw ModelException(MID_PI_MSM,"CheckInputData","The dimension of the input data can not be less than zero.");
		return false;
	}

	if(this->m_P == NULL)
	{
		throw ModelException(MID_PI_MSM,"CheckInputData","The precipitation data can not be NULL.");
		return false;
	}

	if(this->m_PET == NULL)
	{
		throw ModelException(MID_PI_MSM,"CheckInputData","The PET data can not be NULL.");
		return false;
	}

	if(this->m_maxSt == NULL)
	{
		throw ModelException(MID_PI_MSM,"CheckInputData","The maximum interception storage capacity can not be NULL.");
		return false;
	}

	if(this->m_minSt == NULL)
	{
		throw ModelException(MID_PI_MSM,"CheckInputData","The minimum interception storage capacity can not be NULL.");
		return false;
	}

	if(this->m_Pi_b > 1.5 || this->m_Pi_b < 0.5)
	{
		throw ModelException(MID_PI_MSM,"CheckInputData","The interception storage capacity exponent can not be " + ValueToString(this->m_Pi_b)  + ". It should between 0.5 and 1.5.");
		return false;
	}

	if(this->m_Init_IS > 1 || this->m_Init_IS < 0)
	{
		throw ModelException(MID_PI_MSM,"CheckInputData","The Initial interception storage can not be " + ValueToString(this->m_Init_IS) + ". It should between 0 and 1.");
		return false;
	}

	return true;
}

bool clsPI_MSM::CheckInputSize(const char* key, int n)
{
	if(n<=0)
	{
		throw ModelException(MID_PI_MSM,"CheckInputSize","Input data for "+string(key) +" is invalid. The size could not be less than zero.");
		return false;
	}
	if(this->m_nCells != n)
	{
		if(this->m_nCells <=0) this->m_nCells = n;
		else
		{
			throw ModelException(MID_PI_MSM,"CheckInputSize","Input data for "+string(key) +" is invalid. All the input data should have same size.");
			return false;
		}
	}
	return true;
}



