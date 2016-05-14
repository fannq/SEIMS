/*!
 * \file api.cpp
 *
 * \author JunZhi Liu, LiangJun Zhu
 * \date April 2016
 *
 * 
 */
#include <stdio.h>
#include <string>
#include "api.h"
#include "util.h"
#include "PETHargreaves.h"
#include <iostream>
#include "SimulationModule.h"
#include "MetadataInfo.h"
#include "MetadataInfoConst.h"
/** \defgroup PET_H
 * \ingroup Hydrology_longterm
 * \brief Calculate potential evapotranspiration using Hargreaves method
 *
 *
 *
 */
//! Get instance of SimulationModule class
extern "C" SEIMS_MODULE_API SimulationModule* GetInstance()
{
	return new PETHargreaves();
}
/*!
 * \ingroup PET_H
 * \brief function to return the XML Metadata document string
 */
extern "C" SEIMS_MODULE_API const char* MetadataInformation()
{
	MetadataInfo mdi;

	// set the information properties
	mdi.SetAuthor("Junzhi Liu");
	mdi.SetClass(MCLS_PET, MCLSDESC_PET);
	mdi.SetDescription(MDESC_PET_H);
	mdi.SetEmail(SEIMS_EMAIL);
	mdi.SetID(MID_PET_H);
	mdi.SetName(MID_PET_H);
	mdi.SetVersion("1.0");
	mdi.SetWebsite(SEIMS_SITE);
	mdi.SetHelpfile("PET_H.html");

	// set the parameters (non-time series)
	//mdi.AddInput("T_MEAN","degree","Mean Air Temperature","interpolation module", Array1D);
	mdi.AddParameter(VAR_PET_K, UNIT_NON_DIM, DESC_PET_K, Source_ParameterDB, DT_Single);
	mdi.AddParameter(VAR_PET_HCOEF, UNIT_NON_DIM, DESC_PET_HCOEF, Source_ParameterDB, DT_Single);
	mdi.AddParameter(Tag_Latitude_Meteorology,UNIT_LONLAT_DEG,DESC_METEOLAT,Source_HydroClimateDB, DT_Array1D);

	mdi.AddInput(VAR_JULIAN_DAY,UNIT_NON_DIM,DESC_JULIAN_DAY,Source_Module,DT_Single); /// ICLIM
	mdi.AddInput(VAR_SR_MAX,UNIT_SR,DESC_SR_MAX,Source_Module,DT_Array1D);/// ICLIM
	mdi.AddInput(DataType_MeanTemperature,UNIT_TEMP_DEG,DESC_MAXTEMP,Source_Module, DT_Array1D);
	mdi.AddInput(DataType_MaximumTemperature,UNIT_TEMP_DEG,DESC_MAXTEMP,Source_Module, DT_Array1D);
	mdi.AddInput(DataType_MinimumTemperature,UNIT_TEMP_DEG,DESC_MINTEMP,Source_Module, DT_Array1D);
	
	// set the output variables
	mdi.AddOutput(VAR_PET_T,UNIT_WTRDLT_MMD, DESC_PET_T, DT_Array1D);

	// set the dependencies, does this necessary? LJ
	mdi.AddDependency(MID_ICLIM, MDESC_ICLIM);

	string res = mdi.GetXMLDocument();

	char* tmp = new char[res.size()+1];
	strprintf(tmp, res.size()+1, "%s", res.c_str());
	return tmp;
}