#include "SoilTemperatureFINPL.h"
#include "MetadataInfo.h"
#include "util.h"
#include "ClimateParams.h"
#include "ModelException.h"
#include <cmath>

#include <omp.h>

using namespace std;

SoilTemperatureFINPL::SoilTemperatureFINPL(void):m_a0(NODATA),m_a1(NODATA), m_a2(NODATA), m_a3(NODATA),
	m_b1(NODATA), m_b2(NODATA), m_d1(NODATA), m_d2(NODATA), m_kSoil10(NODATA), m_julianDay(-1), m_nCells(-1),
	m_relativeFactor(NULL), m_soilTemp(NULL),  m_tMean(NULL), m_t1(NULL),m_t2(NULL)
{
	w = PI * 2.f / 365.f;
}

SoilTemperatureFINPL::~SoilTemperatureFINPL(void)
{
	if (m_soilTemp != NULL) delete []m_soilTemp;
	if (m_t1 != NULL) delete []m_t1;
	if (m_t2 != NULL) delete []m_t2;
}

int SoilTemperatureFINPL::Execute()
{
	/// check the data
	CheckInputData();	
	/// initial output of m_t1 and m_t2 for the first run
	initalOutputs();
	m_julianDay = JulianDay(m_date);
	if(this->m_soilTemp == NULL)
	{
		this->m_soilTemp = new float[this->m_nCells];
		//this->m_t1 = new float[this->m_nCells];
		//this->m_t2 = new float[this->m_nCells];

/*		#pragma omp parallel for
		for (int i=0; i<m_nCells; ++i)
		{
			m_t1[i] = m_tMean[i];
			m_t2[i] = m_t1[i];
		}	*/	
	}

	#pragma omp parallel for
	for (int i=0; i<m_nCells; ++i)
	{
		float t = m_tMean[i];
		float t1 = m_t1[i];
		float t2 = m_t2[i];
		float t10 = m_a0 + m_a1*t2 + m_a2*t1 + m_a3*t 
			+ m_b1*sin(w*m_julianDay) + m_d1*cos(w*m_julianDay) 
			+ m_b2*sin(2*w*m_julianDay) + m_d2*cos(2*w*m_julianDay);
		m_soilTemp[i] = t10*m_kSoil10 + m_relativeFactor[i];
		if (m_soilTemp[i] > 60.0f || m_soilTemp[i] < -90.0f)
		{
			ostringstream oss;
			oss << "The calculated soil temperature at cell (" << i
			<< ") is out of reasonable range, whose value is " << m_soilTemp[i] << ".\nJulianDay: " 
			<< m_julianDay << endl;
			throw ModelException(MID_STP_FP,"Execute", oss.str());
		}
		//save the temperature
		m_t2[i] = m_t1[i];
		m_t1[i] = t;
	}
	return 0;
}

bool SoilTemperatureFINPL::CheckInputData(void)
{
	if(FloatEqual(m_a0, NODATA))
		throw ModelException(MID_STP_FP,"CheckInputData","The parameter: SoilTa0 has not been set.");
	if(FloatEqual(m_a1, NODATA))
		throw ModelException(MID_STP_FP,"CheckInputData","The parameter: SoilTa1 has not been set.");
	if(FloatEqual(m_a2, NODATA))
		throw ModelException(MID_STP_FP,"CheckInputData","The parameter: SoilTa2 has not been set.");
	if(FloatEqual(m_a3, NODATA))
		throw ModelException(MID_STP_FP,"CheckInputData","The parameter: SoilTa3 has not been set.");
	if(FloatEqual(m_b1, NODATA))
		throw ModelException(MID_STP_FP,"CheckInputData","The parameter: SoilTb1 has not been set.");
	if(FloatEqual(m_b2, NODATA))
		throw ModelException(MID_STP_FP,"CheckInputData","The parameter: SoilTb2 has not been set.");
	if(FloatEqual(m_d1, NODATA))
		throw ModelException(MID_STP_FP,"CheckInputData","The parameter: SoilTd1 has not been set.");
	if(FloatEqual(m_d2, NODATA))
		throw ModelException(MID_STP_FP,"CheckInputData","The parameter: SoilTd2 has not been set.");
	if(FloatEqual(m_kSoil10, NODATA))
		throw ModelException(MID_STP_FP,"CheckInputData","The parameter: KSoil10 has not been set.");
	if(m_date < 0)
		throw ModelException(MID_STP_FP,"CheckInputData","The date has not been set.");
	if(m_relativeFactor == NULL)
		throw ModelException(MID_STP_FP,"CheckInputData","The parameter: LandcoverFactor has not been set.");
	if(m_tMean == NULL)
		throw ModelException(MID_STP_FP,"CheckInputData","The parameter: mean air temperature has not been set.");
	if(m_t1 == NULL)
		throw ModelException(MID_STP_FP,"CheckInputData","The parameter: mean air temperature of (d-1) day has not been set.");
	if(m_t2 == NULL)
		throw ModelException(MID_STP_FP,"CheckInputData","The parameter: mean air temperature of (d-2) day has not been set.");
	return true;
}

bool SoilTemperatureFINPL::CheckInputSize(const char* key, int n)
{
	if(n <= 0)
	{
		return false;
	}
	if(this->m_nCells != n)
	{
		if(this->m_nCells <=0) this->m_nCells = n;
		else
		{
			return false;
		}
	}
	return true;
}

void SoilTemperatureFINPL::SetValue(const char* key, float value)
{
	string sk(key);
	if (StringMatch(sk, VAR_OMP_THREADNUM))
	{
		omp_set_num_threads((int)value);
	}
	else if (StringMatch(sk, VAR_SOL_TA0))
		m_a0 = value;
	else if (StringMatch(sk,VAR_SOL_TA1))
		m_a1 = value;
	else if (StringMatch(sk, VAR_SOL_TA2))
		m_a2 = value;
	else if (StringMatch(sk, VAR_SOL_TA3))
		m_a3 = value;
	else if (StringMatch(sk, VAR_SOL_TB1))
		m_b1 = value;
	else if (StringMatch(sk, VAR_SOL_TB2))
		m_b2 = value;
	else if (StringMatch(sk, VAR_SOL_TD1))
		m_d1 = value;
	else if (StringMatch(sk, VAR_SOL_TD2))
		m_d2 = value;
	else if (StringMatch(sk, VAR_K_SOIL10))
		m_kSoil10 = value;
}

void SoilTemperatureFINPL::Set1DData(const char* key, int n, float* data)
{
	//check the input data
	CheckInputSize(key,n);
	string sk(key);
	if (StringMatch(sk, VAR_SOIL_T10))
		this->m_relativeFactor = data;
	else if(StringMatch(sk, DataType_MeanTemperature))
		this->m_tMean = data;
	else if (StringMatch(sk, VAR_TMEAN1))
		this->m_t1 = data;
	else if(StringMatch(sk, VAR_TMEAN2))
		this->m_t2 = data;
	else
		throw ModelException(MID_STP_FP, "Set1DData", "Parameter " + sk 
		+ " does not exist in current module. Please contact the module developer.");
}

void SoilTemperatureFINPL::Get1DData(const char* key, int* n, float** data)
{
	initalOutputs();
	string sk(key);
	*n = m_nCells;
	if (StringMatch(sk, VAR_SOTE))*data = m_soilTemp;
	else if (StringMatch(sk, VAR_TMEAN1))*data = m_t1;
	else if(StringMatch(sk, VAR_TMEAN2))*data = m_t2;
	else
		throw ModelException(MID_STP_FP, "Get1DData", "Parameter " + sk 
		+ " does not exist in current module. Please contact the module developer.");
}


void SoilTemperatureFINPL::initalOutputs()
{
	if(this->m_nCells <= 0) throw ModelException(MID_STP_FP,"initalOutputs","The cell number of the input can not be less than zero.");

	if(m_t1 == NULL && m_tMean != NULL)
	{
		m_t1 = new float[m_nCells];
#pragma omp parallel for
		for (int i = 0; i < m_nCells; ++i)
			m_t1[i] = m_tMean[i];	
	}
	if(m_t2 == NULL && m_tMean != NULL)
	{
		m_t2 = new float[m_nCells];
#pragma omp parallel for
		for (int i = 0; i < m_nCells; ++i)
			m_t2[i] = m_tMean[i];	
	}
}