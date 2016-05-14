#pragma once

#include <string>
#include <vector>
#include "api.h"
#include "SimulationModule.h"

using namespace std;

typedef vector<vector<float> > double2DArray;

class clsPI_MSM : public SimulationModule
{
private:
	//---------------------
	//five parameters
	float m_Pi_b;
	float m_dt;
	//float m_K_pet;
	float m_Init_IS;	
	float* m_maxInterception;
	float* m_minInterception;

	//two input variables
	float* m_P;
	//float* m_PET;

	//state variable, the initial value equal to 0
	float* m_interceptionLast;	

	//three results
	float* m_interceptionLoss;
	//float* m_evaporation;
	float* m_netPrecipitation;

	// number of valid cells 
	int m_size;

	// slope
	float *m_s0;
	//previous date
	time_t m_dateLastTimeStep;
	//---------------------
public:
	clsPI_MSM(void);
	virtual ~clsPI_MSM(void);

	virtual int Execute(void);
	virtual void Set1DData(const char* key, int n, float* data);
	virtual void SetValue(const char* key, float data);
	virtual void Get1DData(const char* key, int* n, float** data);
	virtual void SetDate(time_t date);
private:
	int DayOfYear(time_t);

	/**
	*	@brief check the input data. Make sure all the input data is available.
	*
	*	@return bool The validity of the input data.
	*/
	bool CheckInputData(void);

	/**
	*	@brief checke the input size. Make sure all the input data have same dimension.
	*	
	*	@param key The key of the input data
	*	@param n The input data dimension
	*	@return bool The validity of the dimension
	*/
	bool CheckInputSize(const char*,int);
	
	static string toString(float value);
};

