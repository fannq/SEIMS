#include <stdio.h>
#include <string>
#include "api.h"
#include "util.h"
#include "AtmosphericDeposition.h"
#include <iostream>
#include "SimulationModule.h"
#include "MetadataInfo.h"
#include "MetadataInfoConst.h"

extern "C" SEIMS_MODULE_API SimulationModule* GetInstance()
{
	return new AtmosphericDeposition();
}

// function to return the XML Metadata document string
extern "C" SEIMS_MODULE_API const char* MetadataInformation()
{
	string res = "";
	MetadataInfo mdi;

	// set the information properties
	mdi.SetAuthor("Huiran Gao");
	mdi.SetClass(MCLS_ATMDEP, MCLSDESC_ATMDEP);
	mdi.SetDescription(MDESC_ATMDEP);
	mdi.SetEmail(SEIMS_EMAIL);
	mdi.SetID((MDESC_ATMDEP);
	mdi.SetName((MDESC_ATMDEP);
	mdi.SetVersion("0.1");
	mdi.SetWebsite(SEIMS_SITE);

	mdi.AddParameter(Tag_CellSize, UNIT_NON_DIM, DESC_CellSize, Source_ParameterDB, DT_Single);
	mdi.AddParameter(Tag_CellWidth, UNIT_LEN_M, DESC_CellWidth, Source_ParameterDB, DT_Single);
	mdi.AddParameter(VAR_RCN, UNIT_DENSITY, DESC_RCN, Source_ParameterDB, DT_Single); 
	mdi.AddParameter(VAR_RCA, UNIT_DENSITY, DESC_RCA, Source_ParameterDB, DT_Single);
	mdi.AddParameter(VAR_DRYDEP_NO3, UNIT_CONT_KGKM2, DESC_DRYDEP_NO3, Source_ParameterDB, DT_Single);
	mdi.AddParameter(VAR_DRYDEP_NH4, UNIT_CONT_KGKM2, DESC_DRYDEP_NH4, Source_ParameterDB, DT_Single);

	mdi.AddParameter(VAR_SOL_AORGN, UNIT_CONT_KGKM2, DESC_SOL_AORGN, Source_ParameterDB, DT_Array2D);
	mdi.AddParameter(VAR_SOL_FON, UNIT_CONT_KGKM2, DESC_SOL_FON, Source_ParameterDB, DT_Array2D);
	mdi.AddParameter(VAR_ROOTDEPTH, UNIT_DEPTH_MM, DESC_ROOTDEPTH, Source_ParameterDB, DT_Array2D); 

	mdi.AddInput(VAR_PRECI, UNIT_DEPTH_MM, DESC_PRECI, Source_Module, DT_Array1D);

	mdi.AddOutput(VAR_ADDRNO3, UNIT_CONT_KGKM2, DESC_ADDRNO3, DT_Single);
	mdi.AddOutput(VAR_WSHD_RNO3, UNIT_CONT_KGKM2, DESC_WSHD_RNO3, DT_Single);

	mdi.AddOutput(VAR_SOL_NO3, UNIT_CONT_KGKM2, DESC_SOL_NO3, DT_Array2D);

	res = mdi.GetXMLDocument();

	char* tmp = new char[res.size()+1];
	strprintf(tmp, res.size()+1, "%s", res.c_str());
	return tmp;
}