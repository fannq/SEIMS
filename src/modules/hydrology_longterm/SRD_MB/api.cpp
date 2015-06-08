#include <stdio.h>
#include <string>
#include "api.h"
#include "util.h"
#include "SRD_MB.h"
#include <iostream>
#include "SimulationModule.h"
#include "MetadataInfo.h"
#include "MetadataInfoConst.h"

extern "C" WETSPA_MODULE_API SimulationModule* GetInstance()
{
	return new SRD_MB();
}

// function to return the XML Metadata document string
extern "C" WETSPA_MODULE_API const char* MetadataInformation()
{
	MetadataInfo mdi;

	// set the information properties
	mdi.SetAuthor("Chunping Ou");
	mdi.SetClass("Snow redistribution", "Snow redistribution");
	mdi.SetDescription("For simplicity purpose for the time being, the algorithm used in the original WetSpa is incorporated in the New WetSpa.");
	mdi.SetEmail("");
	mdi.SetID("SRD_MB");
	mdi.SetName("SRD_MB");
	mdi.SetVersion("0.5");
	mdi.SetWebsite("");
	mdi.SetHelpfile("SRD_MB.chm");

	//3 grid parameter
	mdi.AddParameter("slope_wind","%","Slope along wind direction","ParameterDB_Snow",DT_Raster);
	mdi.AddParameter("curva_wind","%","curvature along wind direction","ParameterDB_Snow",DT_Raster);
	mdi.AddParameter("shc","m","snow holding capacity","ParameterDB_Snow",DT_Raster);
	mdi.AddParameter("T_snow","oC","snowfall temperature","ParameterDB_Snow",DT_Single);
	mdi.AddParameter("swe0","mm","Initial snow water equivalent","ParameterDB_Snow",DT_Single);

	//8 single parameter
	mdi.AddParameter("shc_crop ","m","snow holding capacity of cropland with conventional tillage used to calculate land cover weighting factor","ParameterDB_Snow",DT_Single);
	mdi.AddParameter("k_slope","-","Slope coefficient in wind direction","ParameterDB_Snow",DT_Single);
	mdi.AddParameter("k_curvature","-","Curvature coefficient in wind direction","ParameterDB_Snow",DT_Single);
	mdi.AddParameter("ut0","m/s","Threshold wind speed at -27 degree for starting the redistribution of sno","ParameterDB_Snow",DT_Single);
	mdi.AddParameter("u0","m/s","a wind speed over threshold at which the decay coefficient is one","ParameterDB_Snow",DT_Single);
	//mdi.AddParameter("t_snow","oC","snowfall temperature","ParameterDB_Snow",DT_Single);
	mdi.AddParameter("t_wind","oC","temperature at which wind transport of snow is most favorable","ParameterDB_Snow",DT_Single);
	mdi.AddParameter("K_blow","-"," a fraction coefficient of snow blowing into or out of the watershed","ParameterDB_Snow",DT_Single);
	mdi.AddParameter("T0","oC","the snowmelt threshold temperature ","ParameterDB_Snow",DT_Single);	

	//input from other module	
	mdi.AddInput("T_WS","m/s","wind speed measured at 10 m height","Module",DT_Array1D);			// from time series data module
	mdi.AddInput("D_NEPR","mm","net precipitation","Module",DT_Raster);					// from interception module
	mdi.AddInput("D_SNAC","mm", "distribution of snow accumulation", "Module",DT_Raster);	// from snow water balance module
	mdi.AddInput("SWE","mm","average SA of the watershed","Module",DT_Single);						// from snow water balance module
	mdi.AddInput("D_TMIN","oC","min temperature","Module",DT_Raster);
	mdi.AddInput("D_TMAX","oC","max temperature","Module",DT_Raster);

	// set the output variables
	mdi.AddOutput("SNRD","mm", "distribution of snow blowing in or out the cell", DT_Raster);

	// write out the XML file.

	string res = mdi.GetXMLDocument();

	char* tmp = new char[res.size()+1];
	strprintf(tmp, res.size()+1, "%s", res.c_str());
	return tmp;
}