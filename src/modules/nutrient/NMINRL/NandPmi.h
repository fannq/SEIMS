/** \defgroup NMINRL
 * \ingroup Nutrient
 * \brief Daily nitrogen and phosphorus mineralization and immobilization.
 */
/*!
 * \file NandPmi.h
 * \ingroup NMINRL
 * \author Huiran Gao
 * \date April 2016
 */

#pragma once
#ifndef SEIMS_NMINRL_PARAMS_INCLUDE
#define SEIMS_NMINRL_PARAMS_INCLUDE
#include <string>
#include "api.h"
#include "SimulationModule.h"
using namespace std;

/*!
 * \class NandPmi
 * \ingroup NMINRL
 *
 * \brief Daily nitrogen and phosphorus mineralization and immobilization.
 *  Considering fresh organic material (plant residue) and active and stable humus material.
 *
 */

class NandPim : public SimulationModule {
	public:
	NandPim(void);
	~NandPim(void);

	virtual void Set1DData(const char* key, int n, float *data);
	virtual void Set2DData(const char* key, int nRows, int nCols, float** data);
	virtual void SetValue(const char* key, float value);
	virtual int Execute();
	virtual void GetValue(const char* key, float* value);
	//virtual void Get1DData(const char* key, int* n, float** data);
	virtual void Get2DData(const char* key, int* nRows, int* nCols, float*** data);
private:
	/// cell width of grid map (m)
	float m_cellWidth;
	/// number of cells
	int m_nCells;

	int m_nSolLyrs;

	///input data
	///rate factor for humus mineralization on active organic N
	float m_cmn;
	///nitrogen active pool fraction. The fraction of organic nitrogen in the active pool.
	float m_nactfr;
	///Phosphorus availability index. The fraction of fertilizer P remaining in labile pool after initial rapid phase of P sorption
	float* m_psp;
	//rate coefficient for denitrification
	float* m_cdn;
	///land cover code from crop.dat
	float* m_idplt;
	///plant residue decomposition coefficient.
	///The fraction of residue which will decompose in a day assuming optimal moisture, temperature, C:N ratio, and C:P ratio
	float* m_rsdco_pl;
	///percent organic carbon in soil layer(%)
	float** m_sol_cbn;
	///amount of water stored in the soil layer on current day(mm H2O)
	float** m_sol_st;
	///Water content of soil profile at field capacity(mm H2O)
	float** m_sol_fc;
	///daily average temperature of soil layer(deg C)
	float** m_sol_tmp;
	///amount of water held in the soil layer at saturation(mm H2O)
	float** m_sol_ul;
	///depth to bottom of soil layer
	float** m_sol_z;
	///amount of phosphorus stored in the active mineral phosphorus pool
	float** m_sol_actp;
	///amount of phosphorus in the soil layer stored in the stable mineral phosphorus pool
	float** m_sol_stap;

	///output data
	///amount of nitrogen moving from active organic to nitrate pool in soil profile on current day in cell(kg N/km2)
	float m_hmntl;
	///amount of phosphorus moving from the organic to labile pool in soil profile on current day in cell(kg P/km2)
	float m_hmptl;
	///amount of nitrogen moving from the fresh organic (residue) to the nitrate(80%) and active organic(20%) pools in soil profile on current day in cell(kg N/km2)
	float m_rmn2tl;
	///amount of phosphorus moving from the fresh organic (residue) to the labile(80%) and organic(20%) pools in soil profile on current day in cell(kg P/km2)
	float m_rmptl;
	///amount of nitrogen moving from active organic to stable organic pool in soil profile on current day in cell(kg N/km2)
	float m_rwntl;
	///amount of nitrogen lost from nitrate pool by denitrification in soil profile on current day in cell(kg N/km2)
	float m_wdntl;
	///amount of phosphorus moving from the labile mineral pool to the active mineral pool in the soil profile on the current day in cell(kg P/km2)
	float m_rmp1tl;
	///amount of phosphorus moving from the active mineral pool to the stable mineral pool in the soil profile on the current day in cell(kg P/km2)
	float m_roctl;

	///input & output data
	///amount of nitrogen stored in the active organic (humic) nitrogen pool(kg N/km2)
	float** m_sol_aorgn;
	///amount of nitrogen stored in the fresh organic (residue) pool(kg N/km2)
	float** m_sol_fon;
	///amount of phosphorus stored in the fresh organic (residue) pool(kg P/km2)
	float** m_sol_fop;
	///amount of nitrogen stored in the nitrate pool in soil layer(kg N/km2)
	float** m_sol_no3;
	///amount of nitrogen stored in the stable organic N pool(kg N/km2)
	float**  m_sol_orgn;
	///amount of phosphorus stored in the organic P pool in soil layer(kg P/km2)
	float** m_sol_orgp;
	///amount of organic matter in the soil classified as residue(kg/km2)
	float** m_sol_rsd;
	///amount of phosohorus stored in solution(kg P/km2)
	float** m_sol_solp;
	///amount of nitrogen stored in the ammonium pool in soil layer(kg/km2)
	float** m_sol_nh3;
	///water content of soil at -1.5 MPa (wilting point)
	float** m_sol_wpmm;
	///average annual amount of nitrogen lost from nitrate pool due to denitrification in watershed(kg N/km2)
	float m_wshd_dnit;
	///average annual amount of nitrogen moving from active organic to nitrate pool in watershed(kg N/km2)
	float m_wshd_hmn;
	///average annual amount of phosphorus moving from organic to labile pool in watershed(kg P/km2)
	float m_wshd_hmp;
	///average annual amount of nitrogen moving from fresh organic (residue) to nitrate and active organic pools in watershed(kg N/km2)
	float m_wshd_rmn;
	///average annual amount of phosphorus moving from fresh organic (residue) to labile and organic pools in watershed(kg P/km2)
	float m_wshd_rmp;
	///average annual amount of nitrogen moving from active organic to stable organic pool in watershed(kg N/km2)
	float m_wshd_rwn;
	///average annual amount of nitrogen moving from active organic to stable organic pool in watershed(kg N/km2)
	float m_wshd_nitn;
	///average annual amount of nitrogen moving from active organic to stable organic pool in watershed(kg N/km2)
	float m_wshd_voln;
	///average annual amount of phosphorus moving from labile mineral to active mineral pool in watershed
	float m_wshd_pal;
	///average annual amount of phosphorus moving from active mineral to stable mineral pool in watershed
	float m_wshd_pas;

private:

	/*!
	 * \brief check the input data. Make sure all the input data is available.
	 * \return bool The validity of the input data.
	 */
	bool CheckInputData(void);

	/*!
	 * \brief check the input size. Make sure all the input data have same dimension.
	 *
	 * \param[in] key The key of the input data
	 * \param[in] n The input data dimension
	 * \return bool The validity of the dimension
	 */
	bool CheckInputSize(const char*,int);

	/*!
	* \brief estimates daily nitrogen and phosphorus mineralization and immobilization.
	 *
	 * \return void
	 */
	void CalculateMinerandImmobi();

	/*!
	* \brief estimates daily mineralization (NH3 to NO3) and volatilization of NH3.
	 *
	 * \return void
	 */
	void CalculateMinerandVolati();
	
	/*!
	* \brief Calculate P flux between the labile, active mineral and stable mineral p pools.
	 *
	 * \return void
	 */
	void CalculatePflux();

	
};

#endif





