/*!
 * \file text.h
 * \brief Predefined string constants used in the code
 
 * \author Junzhi Liu, LiangJun Zhu, Huiran Gao
 * \version 1.1
 * \date Jun. 2010, Apr.2016
 *
 * 
 */
#ifndef SEIMS_TEXT_H
#define SEIMS_TEXT_H

// 
// TODO - you may consider moving these to an external resource file 
//        to make it easier to change them later 

#define SEIMS_EMAIL "SEIMS2015@163.com"
#define SEIMS_SITE "http://seims.github.io/SEIMS"

//! Constant input variables
#define CONS_IN_ELEV							"Elevation"
#define CONS_IN_LAT						    "Latitude"
#define CONS_IN_XPR							"xpr"
#define CONS_IN_YPR							"ypr"

//! Climate data type, used in SEIMS_ModuleSetting class, ITP, etc. // LJ, Apr.,2016
#define DataType_Precipitation "P"					//1, Suffix of precipitation data
#define DataType_MeanTemperature "TMEAN"      	    //2
#define DataType_MinimumTemperature "TMIN"			//3
#define DataType_MaximumTemperature "TMAX"			//4
#define DataType_PotentialEvapotranspiration "PET"	//5
#define DataType_SolarRadiation "SR"				//6
#define DataType_WindSpeed "WS"						//7
#define DataType_RelativeAirMoisture "RM"			//8
#define DataType_Meteorology "M"                    // Suffix of meteorology data
#define DataType_Prefix_TS "T"                      // Prefix of time series data
#define DataType_Prefix_DIS "D"                     // Prefix of distributed data

//! Tags
#define Tag_Configuration "Configuration"
#define Tag_DEM "DEM"
#define Tag_Elevation_Meteorology "StationElevation_M"
#define Tag_Elevation_PET "StationElevation_PET"
#define Tag_Elevation_Precipitation "StationElevation_P"
#define Tag_Elevation_Temperature "StationElevation_T"
#define Tag_LapseRate "LapseRate"
#define Tag_Latitude_Meteorology "Latitude_M"
#define Tag_ProjectsPath "ProjectsPath"
#define Tag_StationElevation "StationElevation"
#define Tag_VerticalInterpolation "VERTICALINTERPOLATION"
#define Tag_Weight "WEIGHT"

///////  define parameter-related string constants used in the SEIMS ///////
#define PARAM_USE_Y			"Y"
#define PARAM_USE_N			"N"
#define PARAM_CHANGE_RC		"RC"
#define PARAM_CHANGE_AC		"AC"
#define PARAM_CHANGE_NC		"NC"
#define PARAM_FLD_NAME		"NAME"
#define PARAM_FLD_DESC		"DESCRIPTION"
#define PARAM_FLD_UNIT		"UNIT"
#define PARAM_FLD_MIDS		"MODULE"
#define PARAM_FLD_VALUE		"VALUE"
#define PARAM_FLD_IMPACT	"IMPACT"
#define PARAM_FLD_CHANGE	"CHANGE"
#define PARAM_FLD_MAX		"MAX"
#define PARAM_FLD_MIN		"MIN"
#define PARAM_FLD_USE		"USE"


#ifndef linux
    #define Tag_ModuleDirectoryName "\\"
	#define SEP "\\"
    #define Tag_ModuleExt ".dll"
#else
    #define Tag_ModuleDirectoryName "/"
	#define SEP "/"
    #define Tag_ModuleExt ".so"
#endif

#define Tag_OutputID "OUTPUTID"
#define Tag_Interval "INTERVAL"
#define Tag_SiteCount "SITECOUNT"
#define Tag_SiteName "SITENAME"
#define Tag_SiteID "SITEID"
#define Tag_ReachName "REACHNAME"
#define Tag_StartTime "STARTTIME"
#define Tag_EndTime "ENDTIME"
#define Tag_FileName "FILENAME"
#define Tag_Type "TYPE"
#define Tag_Count "COUNT"
#define Tag_DataType "DATA_TYPE"


#define Tag_SubbasinCount "SUBBASINCOUNT"
#define Tag_SubbasinId "SubbasinID"
#define Tag_ReservoirCount "RESERVOIRCOUNT"
#define Tag_ReservoirId "RESERVOIRID"
#define Tag_SubbasinSelected "subbasinSelected"
#define Tag_CellSize "CELLSIZE"
#define Tag_Mask "MASK"
#define Tag_TimeStep "TimeStep"
#define Tag_HillSlopeTimeStep "DT_HS"
#define Tag_ChannelTimeStep "DT_CH"
#define Tag_CellWidth "CELLWIDTH" // this is the size of a single CELL
#define Tag_PStat "P_STAT"


// D8 Flow model
#define Tag_FLOWIN_INDEX_D8 "FLOWIN_INDEX_D8"
#define Tag_FLOWOUT_INDEX_D8 "FLOWOUT_INDEX_D8"
#define Tag_ROUTING_LAYERS "ROUTING_LAYERS"

// TODO: Dinf, MFD, MFD-md integrated into SEIMS.
//! D-infinity Flow model after Tarboton et al.(1991)
#define Tag_FLOWIN_INDEX_DINF "FLOWIN_INDEX_DINF"
#define Tag_FLOWIN_PERCENTAGE_DINF "FLOWIN_PERCENTAGE_DINF"
#define Tag_FLOWOUT_INDEX_DINF "FLOWOUT_INDEX_DINF"
#define Tag_FLOWOUT_PERCENTAGE_DINF "FLOWOUT_PERCENTAGE_DINF"
#define Tag_ROUTING_LAYERS_DINF "ROUTING_LAYERS_DINF"
//! Multi-Flow model after Quinn et al.(1991)
#define Tag_FLOWIN_INDEX_MFD "FLOWIN_INDEX_MFD"
#define Tag_FLOWIN_PERCENTAGE_MFD "FLOWIN_PERCENTAGE_MFD"
#define Tag_FLOWIN_PERCENTAGE_D8 "FLOWIN_PERCENTAGE_D8"
#define Tag_FLOWOUT_INDEX_MFD "FLOWOUT_INDEX_MFD"
#define Tag_FLOWOUT_PERCENTAGE_MFD "FLOWOUT_PERCENTAGE_MFD"
#define Tag_ROUTING_LAYERS_MFD "ROUTING_LAYERS_MFD"
//! MFD-md flow model after Qin et al.(2007) (md means maximum downslope)
#define Tag_FLOWIN_INDEX_MFD_MD "FLOWIN_INDEX_MFD_MD"
#define Tag_FLOWIN_PERCENTAGE_MFD_MD "FLOWIN_PERCENTAGE_MFD_MD"
#define Tag_FLOWOUT_INDEX_MFD_MD "FLOWOUT_INDEX_MFD_MD"
#define Tag_FLOWOUT_PERCENTAGE_MFD_MD "FLOWOUT_PERCENTAGE_MFD_MD"
#define Tag_ROUTING_LAYERS_MFD_MD "ROUTING_LAYERS_MFD_MD"
/// Replaced by VAR_RCHPARAM
#define Tag_ReachParameter	"ReachParameter"
#define DESC_REACH_PARAMETER "Reach parameters such as stream order, manning's n and downstream subbasin id (Array2D)"
#define Tag_RchParam		"RchParam"
#define VAR_RCHPARAM	"ReachParameters"

////////////  Output Tags   ///////////////
//// Output aggregation type //////
#define Tag_Unknown			"UNKNOWN" 
#define Tag_Sum				"SUM"
#define Tag_Average			"AVERAGE"
#define Tag_Average2		"AVE"
#define Tag_Average3		"MEAN"
#define Tag_Minimum			"MIN"
#define Tag_Maximum			"MAX"
#define Tag_SpecificCells	"SPECIFIC"

#define TAG_OUT_QOUTLET "QOUTLET"
#define TAG_OUT_QTOTAL "QTotal"
#define TAG_OUT_SEDOUTLET "SEDOUTLET"
#define TAG_OUT_OL_IUH "OL_IUH"
#define Tag_DisPOutlet "DissovePOutlet"
#define Tag_AmmoOutlet "AmmoniumOutlet"
#define Tag_NitrOutlet "NitrateOutlet"
#define TAG_OUT_QSUBBASIN "QSUBBASIN"



//!for reach hydro climate data
#define DIVERSION	"flowdiversion"
#define POINTSOURCE "pointsource"
#define RESERVOIR	"reservoir"
#define FLOW		"flow"
#define SDEIDMENT	"sediment"
#define ORGANICN	"organicN"
#define ORGANICP	"organicP"
#define NO3			"NO3"
#define NH3			"NH3"
#define NO2			"NO2"
#define MINERALP	"mineralP"

/// Files or database constant strings
#define ASCIIExtension ".asc"
#define GTiffExtension ".tif"
#define TextExtension ".txt"
#define File_HydroClimateDB "HydroClimate.db3"
#define File_ParameterDB "Parameter.db3"
#define File_BMPDB "BMP.db3"
#define Table_LapseRate "lapse_rate"
#define NAME_MASK "MASK"

#define File_Config				"config.fig"
#define File_Input				"file.in"
#define File_Output				"file.out"
#define Source_HydroClimateDB	"HydroClimateDB"
#define Source_ParameterDB		"ParameterDB"
#define Source_Module			"Module"

///////// Table Names required in MongoDB /////////
#define DB_TAB_PARAMETERS		"parameters"
#define DB_TAB_LOOKUP_LANDUSE	"LanduseLookup"
#define DB_TAB_LOOKUP_SOIL		"SoilLookup"
#define DB_TAB_SITELIST			"SiteList"
#define DB_TAB_REACH			"reaches"
#define DB_TAB_SPATIAL			"spatial"  /// spatial.files
#define DB_TAB_SITES			"Sites"
#define DB_TAB_DATAVALUES		"DataValues" // hydroClimate data values
#define DB_TAB_MEASUREMENT		"measurement" // TODO: discharge, nutrient etc. should be stored in this collection

#define DB_TAB_OUT_SPATIAL		"output"

/// Fields in DB_TAB_REACH ///
#define REACH_SUBBASIN			"SUBBASIN"
#define REACH_NUMCELLS			"NUM_CELLS"
#define REACH_GROUP						"GROUP"
#define REACH_GROUPDIVIDED		"GROUP_DIVIDE"
#define REACH_KMETIS						"GROUP_KMETIS"
#define REACH_PMETIS						"GROUP_PMETIS"
#define REACH_DOWNSTREAM		"DOWNSTREAM"
#define REACH_UPDOWN_ORDER		"UP_DOWN_ORDER"
#define REACH_DOWNUP_ORDER		"DOWN_UP_ORDER"
#define REACH_WIDTH				"WIDTH"
#define REACH_LENGTH			"LENGTH"
#define REACH_DEPTH				"DEPTH"
#define REACH_V0				"V0"
#define REACH_AREA				"AREA"
#define REACH_MANNING			"MANNING"
#define REACH_SLOPE				"SLOPE" 


/// these four are defined in DB_TAB_SITELIST in Source_ParameterDB
#define SITELIST_TABLE_M		"SiteListM"
#define SITELIST_TABLE_P		"SiteListP"
#define SITELIST_TABLE_PET		"SiteListPET"
#define SITELIST_TABLE_STORM	"StormSiteList"

//! define string constants used in the code, also used in the mongoDB.SiteList table's header
#define Tag_NoDataValue			"NoDataValue"
#define Tag_SubbasinSelected	"subbasinSelected"
#define Tag_Mode				"Mode"
#define Tag_Mode_Storm			"STORM"
#define Tag_Mode_Daily			"DAILY"

#define Type_Scenario			"SCENARIO"
#define Type_LapseRateArray		"LAPSERATEARRAY"
#define Type_SiteInformation	"SITEINFORMATION"
#define Type_Raster1D		"RASTER1D"
#define Type_Raster2D		"RASTER2D"
#define Type_Array1DDateValue	"ARRAY1DDATEVALUE"
#define Type_Array3D			"ARRAY3D"
#define Type_Array2D			"ARRAY2D"
#define Type_Array1D			"ARRAY1D"
#define Type_Single				"SINGLE"

//// These maybe USELESS, right? by LJ
////// Optional Output Data ////  
//#define Print_D_PREC "D_PREC"
//#define Print_D_POET "D_POET"
//#define Print_D_TEMP "D_TEMP"
//#define Print_D_INLO "D_INLO"
//#define Print_D_INET "D_INET"
//#define Print_D_NEPR "D_NEPR"

///// 2D Soil Attribute Data ///
//#define Print_2D_CONDUCTIVITY	"Conductivity_2D"
//#define Print_2D_POROSITY		"Porosity_2D"
//#define Print_2D_POREINDEX		"Poreindex_2D"
//#define Print_2D_FIELDCAP		"FieldCap_2D"
//#define Print_2D_WILTINGPOINT	"WiltingPoint_2D"
//#define Print_2D_DENSITY		"Density_2D"

//////////////////////////////////////////////////////////////////////////
/// Define models' ID and description in SEIMS  //////////////////////////
/// By LiangJun Zhu, Apr. 26, 2016  //////////////////////////////////////
//////////////////////////////////////////////////////////////////////////

/// Hydro-Meteorological data
#define MCLS_CLIMATE								"HydroClimate"
#define MCLSDESC_CLIMATE					"HydroClimate data modules"
#define MID_TSD_RD									"TSD_RD"
#define MDESC_TSD_RD							"Read time series data from HydroClimate database."
#define MID_ITP											"ITP"
#define MDESC_ITP									"Interpolation of P, T, etc."

/// Soil temperature
#define MCLS_SOLT									"Soil Temperature"
#define MCLSDESC_SOLT							"Calculate the soil temperature."
#define MID_STP_FP									"STP_FP"
#define MDESC_STP_FP							"Finn Plauborg Method to compute soil temperature."
/// Interception
#define MCLS_INTERC								"Interception"
#define MCLSDESC_INTERC						"Precipation interception module"
#define MID_PI_STORM								"PI_STORM"
#define MDESC_PI_STORM						"Calculate precipitation interception for STORM model."
#define MID_PI_MSM									"PI_MSM"
#define MDESC_PI_MSM							"Calculate precipitation interception using the maximum storage method."
/// Snow redistribution
#define MCLS_SNO_RD								"Snow redistribution"
#define MCLSDESC_SNO_RD					"Snow redistribution calculation"
#define MID_SRD_MB									"SRD_MB"
#define MDESC_SRD_MB							"the algorithm used in the original WetSpa."
/// Snow sublimation
#define MCLS_SNO_SB								"Snow sublimation"
#define MCLSDESC_SNO_SB					"Calculate the amount of snow sublimation ."
#define MID_SSM_PE									"SSM_PE"
#define MDESC_SSM_PE							"A simple method that used in the old WetSpa to calculate snow sublimation."
/// Snow melt
#define MCLS_SNOW									"Snow accumulation and melt"
#define MCLSDESC_SNOW						"Calculate the amount of snow  accumulation andmelt."
#define MID_SNO_WB									"SNO_WB"
#define MDESC_SNO_WB							"Calculate snow water balance"
#define MID_SNO_DD									"SNO_DD"
#define MDESC_SNO_DD							"Degree-Day method (Martinec et al., 1983) for snow melt modeling"
#define MID_SNO_SP									"SNO_SP"
#define MDESC_SNO_SP							"Snowpack Daily method from SWAT"

/// Potential Evapotranspiration Modules
#define MCLS_PET										"Potential Evapotranspiration"
#define MCLSDESC_PET							"Calculate the potential evapotranspiration"
#define MID_PET_H										"PET_H"
#define MDESC_PET_H								"Hargreaves method for calculating the potential evapotranspiration."
#define MID_PET_PT									"PET_PT"
#define MDESC_PET_PT							"PriestleyTaylor method for calculating the potential evapotranspiration."
#define MID_PET_PM									"PET_PM"
#define MDESC_PET_PM							"Penman Monteith method for calculating the potential evapotranspiration."
/// Actual Evapotranspiration
#define MCLS_AET										"Actual Evapotranspiration"
#define MCLSDESC_AET							"Calculates potential plant transpiration and potential and actual soil evaporation. "
#define MID_AET_PTH								"AET_PTH"
#define MDESC_AET_PTH							"Potential plant transpiration for Priestley-Taylor and Hargreaves ET methods "
/// Depression
#define MCLS_DEP										"Depression"
#define MCLSDESC_DEP							"Calculate depression storage."
#define MID_DEP_FS									"DEP_FS"
#define MDESC_DEP_FS							"A simple fill and spill method method to calculate depression storage."
#define MID_DEP_LINSLEY						"DEP_LINSLEY"
#define MDESC_DEP_LINSLEY					"Linsley method to calculate depression storage"
/// Surface runoff
#define MCLS_SUR_RUNOFF					"Surface runoff"
#define MCLSDESC_SUR_RUNOFF			"Calculate infiltration and excess precipitation."
#define MID_SUR_MR									"SUR_MR"
#define MDESC_SUR_MR							"Modified rational method to calculate infiltration and excess precipitation."
#define MID_SUR_CN									"SUR_CN"
#define MDESC_SUR_CN							"SCS curve number method to calculate infiltration and excess precipitation."
#define MID_SUR_SGA								"SUR_SGA"
#define MDESC_SUR_SGA						"Modified rational method to calculate infiltration and excess precipitation."
/// Interflow
#define MCLS_INTERFLOW						"Interflow routing"
#define MCLSDESC_INTERFLOW			"Interflow routing."
#define MID_IKW_IF									"IKW_IF"
#define MDESC_IKW_IF								"interflow routing using the method of WetSpa model."
#define MID_IUH_IF										"IUH_IF"
#define MDESC_IUH_IF								"IUH overland method to calculate interflow routing."
/// Percolation
#define MCLS_PERCO								"Percolation"
#define MCLSDESC_PERCO						"Calculate the amount of water percolated out of the root zone within the time step."
#define MID_PER_PI									"PER_PI"
#define MDESC_PER_PI								"Percolation calculated by Darcy's law and Brooks-Corey equation"
#define MID_PER_STR								"PET_STR"
#define MDESC_PER_STR							"Percolation calculated by storage routing method"
#define MID_PERCO_DARCY					"PERCO_DARCY"
#define MDESC_PERCO_DARCY				"The method relating percolation with soil moisture and pore size distribution index used in the original WetSpa will be the default method to estimate percolation out of the root zone."

/// Hillslope hydrology
#define MCLS_HS_HYDRO							"Hillslope water balance"
#define MCLSDESC_HS_HYDRO				"Water balance calculation in hillslope."
#define MID_HS_WB									"HS_WB"
#define MDESC_HS_WB								"Hillsloope water balance."
/// Groundwater
#define MCLS_GW										"Groundwater"
#define MCLSDESC_GW							"Calculate groundwater balance and baseflow."
#define MID_GW_RSVR								"GW_RSVR"
#define MDESC_GW_RSVR						"Calculate groundwater using reservoir method"			
/// Erosion related modules
#define MCLS_OL_EROSION						"Overland erosion"
#define MCLS_CH_EROSION					"Channel erosion"
#define MCLSDESC_OL_EROSION			"Calculate the amount sediment yield of overland erosion."
#define MCLSDESC_CH_EROSION			"Calculate the amount channel erosion."
#define MID_SplashEro_Park						"SplashEro_Park"
#define MDESC_SplashEro_Park				"use Park equation to calculate sediment yield of each cell"
#define MID_KINWAVSED_OL					"KinWavSed_OL"
#define MID_KINWAVSED_CH					"KinWavSed_CH"
#define MDESC_KINWAVSED_OL			"Use energy function(Govers) method to calculate sediment yield routing of each hillslope cell"	
#define MDESC_KINWAVSED_CH			"Srinivasan & Galvao function to calculate sediment yield routing of each channel cell"
#define MID_MUSLE_AS								"MUSLE_AS"
#define MDESC_MUSLE_AS						"use MUSLE method to calculate sediment yield of each cell"
/// Plant growth
#define MCLS_POT_BIOM							"Potential Biomass"
#define MCLSDESC_POT_BIOM				"Calculate the amount of PotentialBiomass."
#define MID_PBIO_EPIC								"PBIO_EPIC"
#define MDESC_PBIO_EPIC						"Calculate potential biomass using a simplified version of the EPIC plant growth model as in SWAT"
/// Overland routing related modules
#define MCLS_OL_ROUTING						"Overland routing"
#define MCLSDESC_OL_ROUTING			"Overland routing module"
#define MID_IKW_OL									"IKW_OL"
#define MDESC_IKW_OL							"Overland routing using 4-point implicit finite difference method."
/// Channel routing related modules
#define MCLS_CH_ROUTING						"Channel routing"
#define MCLSDESC_CH_ROUTING			"Channel routing modules"
#define MID_CH_DW									"CH_DW"
#define MDESC_CH_DW							"Channel routing using diffusive wave equation."
#define MID_CH_MSK									"CH_MSK"
#define MDESC_CH_MSK							"Channel routing using Muskingum-Cunge method."
#define MID_IKW_CH									"IKW_CH"
#define MDESC_IKW_CH							"Channel routing using 4-point implicit finite difference method for kinematic wave."
/// Sediment routing related modules
#define MCLS_SED_ROUTING					"Sediment routing"
#define MCLSDESC_SED_ROUTING		"Sediment channel routing modules."
#define MID_SEDR_VCD							"SEDR_VCD"
#define MDESC_SEDR_VCD						"Sediment channel routing using variable channel dimension method as used in SWAT."

/// Nutrient
#define MCLS_NMINRL "Daily nitrogen and phosphorus mineralization and immobilization"
#define MCLSDESC_NMINRL "Daily nitrogen and phosphorus mineralization and immobilization considering fresh organic material (plant residue) and active and stable humus material."
#define MID_NMINRL "NMINRL"
#define MDESC_NMINRL "Daily nitrogen and phosphorus mineralization and immobilization considering fresh organic material (plant residue) and active and stable humus material."
#define MCLS_SurTra "Nutrient removed and loss in surface runoff, lateral flow, tile flow, and percolation out of the profile."
#define MCLSDESC_SurTra "Nutrient removed and loss in surface runoff, lateral flow, tile flow, and percolation out of the profile."
#define MID_SurTra "SurTra"
#define MDESC_SurTra "Nutrient removed and loss in surface runoff, lateral flow, tile flow, and percolation out of the profile."
#define MCLS_ATMDEP "AtmosphericDeposition"
#define MCLSDESC_ATMDEP "AtmosphericDeposition"
#define MID_ATMDEP "ATMDEP"
#define MDESC_ATMDEP "AtmosphericDeposition"
#define MCLS_NutRemv "Nutrient remove"
#define MCLSDESC_NutRemv "Simulates the loss of nitrate and phosphorus via surface runoff"
#define MID_NutRemv "NutRemv"
#define MDESC_NutRemv "Simulates the loss of nitrate and phosphorus via surface runoff"
//////////////////////////////////////////////////////////////////////////
/// Define unit names common used in SEIMS, in case of inconsistency /////
/// By LiangJun Zhu, HuiRan Gao ///
///Apr. , 2016  //////////////////////////////////////
//////////////////////////////////////////////////////////////////////////
#define VAR_A_BNK "a_bnk"                           /// bank flow recession constant
#define VAR_ALBDAY "ALBDAY"
#define VAR_ACC "acc"
#define VAR_ACC_INFIL "AccumuInfil"
#define VAR_ADDRNH3 "addrnh3"                       /// ammonium added by rainfall (kg/km2)
#define VAR_ADDRNO3 "addrno3"                       /// nitrate added by rainfall (kg/km2)
#define VAR_B_BNK "b_bnk"                           /// bank storage loss coefficient
#define VAR_Base_ex "Base_ex"                       /// baseflow recession exponent
#define VAR_BKST "BKST"                             /// bank storage
#define VAR_BNK0 "Bnk0"                             /// initial bank storage per meter of reach length
#define VAR_CELL_LAT "celllat"            /// latitude of each valid cells
#define VAR_C_RAIN "c_rain"
#define VAR_C_SNOW "c_snow"
#define VAR_C_SNOW12 "c_snow12"
#define VAR_C_SNOW6 "c_snow6"
#define VAR_C_WABA "C_WABA"                         /// Channel water balance in a text format for each reach and at each time step
#define VAR_CDN "cdn"                               /// rate coefficient for denitrification
#define VAR_CDN "cdn"                               /// rate coefficient for denitrification
#define VAR_CH_DEP "DEP"
#define VAR_CH_DET "DET"
#define VAR_CH_DETCO "ChDetCo"
#define VAR_CH_FLOWCAP "CAP"
#define VAR_CH_MANNING_F "CH_ManningFactor"
#define VAR_CH_SEDRATE "QSN"
#define VAR_CH_TCCO "ChTcCo"
#define VAR_CH_V "CHANV"
#define VAR_CH_VOL "CHANVOL"
#define VAR_CHS0 "Chs0"                               /// initial channel storage per meter of reach length
#define VAR_CHSB "CHSB"
#define VAR_CHST "CHST"                               /// channel storage
#define VAR_CHT "CHT" /// canopy height for the day(m)
#define VAR_CHWIDTH "CHWIDTH"
#define VAR_CHWTDEPTH "CHWTDEPTH"                     /// channel water depth
#define VAR_CLAY "CLAY"
#define VAR_CMN "cmn"                                 /// Rate coefficient for mineralization of the humus active organic nutrients
#define VAR_CN2 "CN2"
#define VAR_CO2 "Co2"                                 /// CO2 Concentration
#define VAR_COND_MAX "Cond_max"                       /// "Maximum automata's conductance"
#define VAR_COND_RATE "Cond_rate"                     /// Rate of decline in automata's conductance per unit increase in vapor pressure deficit
#define VAR_CONDUCT "Conductivity"
#define VAR_D_P "D_P" /// Distrubution of precipitation
#define VAR_DEET "DEET"                               /// Distribution of evaporation from depression storage
#define VAR_DEET "DEET"                               /// evaporation from the depression storage
#define VAR_DEM "DEM"                                 /// Digital Elevation Model
#define VAR_DEPREIN "Depre_in"                        /// initial depression storage coefficient
#define VAR_DEPRESSION "Depression"                   /// Depression storage capacity
#define VAR_DETSPLASH "DETSplash"
#define VAR_DF_COEF "df_coef"                         /// Deep percolation coefficient
#define VAR_DPST "DPST"                               /// Distribution of depression storage
#define VAR_DRYDEP_NH4 "drydep_nh4"                 /// atmospheric dry deposition of ammonia (kg/km2)
#define VAR_DRYDEP_NO3 "drydep_no3"                 /// atmospheric dry deposition of nitrates (kg/km2)
#define VAR_EP_CH "Ep_ch"                           /// reach evaporation adjustment factor
#define VAR_ESCO "esco"
#define VAR_EXCP "EXCP"                             /// excess precipitation
#define VAR_FIELDCAP "FieldCap"                     /// Soil field capacity" 
#define VAR_FLOWDIR "FLOW_DIR"
#define VAR_FLOWWIDTH "FlowWidth"
#define VAR_GRRE "GRRE"
#define VAR_GW0 "GW0"                               /// initial ground water storage
#define VAR_GW_KG "kg"
#define VAR_GWMAX "GWMAX"                           /// maximum ground water storage
#define VAR_GWNEW "GWNEW"                           /// The volume of water from the bank storage to the adjacent unsaturated zone and groundwater storage
#define VAR_GWWB "GWWB"
#define VAR_HCH "HCH"
#define VAR_HMNTL "hmntl"                           /// amount of nitrogen moving from active organic to nitrate pool in soil profile on current day in cell(kg N/km2)
#define VAR_HMPTL "hmptl"                           /// amount of phosphorus moving from the organic to labile pool in soil profile on current day in cell(kg P/km2)
#define VAR_ID_OUTLET "ID_OUTLET"
#define VAR_IGRO "IGRO"
#define VAR_INET "INET"                             /// evaporation from the interception storage
#define VAR_INFIL "INFIL"                           /// Infiltration
#define VAR_INFILCAPSURPLUS "INFILCAPSURPLUS" 
#define VAR_INIT_IS "Init_IS"
#define VAR_INLO "INLO"
#define VAR_INTERC_MAX "Interc_max"                 /// Maximum Interception Storage Capacity
#define VAR_INTERC_MIN "Interc_min"                 /// Minimum Interception Storage Capacity
#define VAR_JULIAN_DAY "JDay"                       /// Julian day (int)
#define VAR_K_BANK "K_bank"                         /// hydraulic conductivity of the channel bank
#define VAR_K_BLOW "K_blow"
#define VAR_K_CHB "K_chb"                           /// hydraulic conductivity of the channel bed
#define VAR_K_RUN "K_run"
#define VAR_K_SOIL10 "k_soil10"
#define VAR_K_SUBLI "K_subli"
#define VAR_KG "Kg"                                 /// Baseflow recession coefficient
#define VAR_KI "Ki"
#define VAR_LAG_SNOW "lag_snow"
#define VAR_LAIDAY "LAIDAY"
#define VAR_LAP_RATE "LapseRate"                    /// Lapse rate
#define VAR_LCC "idplt"                             /// land cover code
#define VAR_MANNING "Manning"
#define VAR_MOIST_IN "Moist_in"
#define VAR_MSF "ManningScaleFactor"                /// flow velocity scaling factor for calibration
#define VAR_MSK_CO1 "MSK_co1"                       /// Weighting factor of bankful flow
#define VAR_MSK_X "MSK_X"                           /// muskingum weighing factor
#define VAR_NACTFR "nactfr"                         /// nitrogen active pool fraction. The fraction of organic nitrogen in the active pool.
#define VAR_NEPR "NEPR"
#define VAR_NEPR "NEPR"
#define VAR_OL_DET "DETOverland"
#define VAR_OL_IUH "Ol_iuh"                         /// IUH of each grid cell
#define VAR_OL_SED_CCOE "ccoe"
#define VAR_OL_SED_ECO1 "eco1"
#define VAR_OL_SED_ECO2 "eco2"
#define VAR_OMEGA "Omega"
#define VAR_OMP_THREADNUM "ThreadNum"               /// Thread numbers for OMP
#define VAR_P_MAX "P_max"
#define VAR_P_RF "p_rf"
#define VAR_PERCO "Percolation"                     /// the amount of water percolated from the soil water reservoir
#define VAR_PET "PET"                               /// PET 
#define VAR_PET_HCOEF "HCoef_pet"                   /// Coefficient related to radiation used in Hargreaves method
#define VAR_K_PET "K_pet"                           /// Correction factor for PET
#define VAR_PET "PET"                           /// Potential Evapotranspiration of day
#define VAR_PI_B "Pi_b"
#define VAR_PL_RSDCO "rsdco_pl"                     /// Plant residue decomposition coefficient
#define VAR_POREID "Poreindex"                      /// pore size distribution index
#define VAR_POROST "Porosity"                       /// soil porosity
#define VAR_PPT "PPT"
#define VAR_PRECI "D_P"                             /// precipitation for the day (mm)
#define VAR_PSP "psp"                               /// Phosphorus availability index
#define VAR_QCH "QCH"
#define VAR_QG "QG"                                 /// Groundwater discharge at each reach outlet and at each time step
#define VAR_QI "QI"                                 /// Interflow at each reach outlet and at each time step
#define VAR_QOUTLET "QOUTLET"                       /// discharge at the watershed outlet
#define VAR_QOVERLAND "QOverland"
#define VAR_QRECH "QRECH"                           /// Discharge in a text format at each reach outlet and at each time step
#define VAR_QS "QS"                                 /// Overland discharge at each reach outlet and at each time step
#define VAR_QSOIL "QSoil"
#define VAR_QSOUTLET "QSOUTLET"                     /// discharge at the watershed outlet
#define VAR_QSUBBASIN "QSUBBASIN"
#define VAR_QTOTAL "QTotal"
#define VAR_QUPREACH "QUPREACH"                     /// upreach
#define VAR_RadianSlope "RadianSlope"
#define VAR_RCA "rca"                               /// concentration of ammonia in the rain (mg N/m3)  L -> 0.001 * m3
#define VAR_RCN "rcn"                               /// concentration of nitrate in the rain (mg N/m3)  L -> 0.001 * m3
#define VAR_Reinfiltration "Reinfiltration"
#define VAR_RETURNFLOW "ReturnFlow"
#define VAR_REVAP "Revap"
#define VAR_RG "RG"
#define VAR_RMN2TL "rmn2tl"                         /// amount of nitrogen moving from the fresh organic (residue) to the nitrate(80%) and active organic(20%) pools in soil profile on current day in cell(kg N/km2)
#define VAR_RMP1TL "rmp1tl"                         /// amount of phosphorus moving from the labile mineral pool to the active mineral pool in the soil profile on the current day in cell
#define VAR_RMPTL "rmptl"                           /// amount of phosphorus moving from the fresh organic (residue) to the labile(80%) and organic(20%) pools in soil profile on current day in cell(kg P/km2)
#define VAR_ROCTL "roctl"                           /// amount of phosphorus moving from the active mineral pool to the stable mineral pool in the soil profile on the current day in cell
#define VAR_ROOTDEPTH "rootdepth"
#define VAR_SOILDEPTH "soilDepth"                       /// depth to bottom of soil layer
#define VAR_RUNOFF_CO "Runoff_co"
#define VAR_RWNTL "rwntl"                           /// amount of nitrogen moving from active organic to stable organic pool in soil profile on current day in cell(kg N/km2)
#define VAR_SAND "sand"
#define VAR_S_FROZEN "s_frozen"
#define VAR_SBGS "SBGS"
#define VAR_SBGS "SBGS"                             /// Groundwater storage of the subbasin
#define VAR_SBIF "SBIF"                             /// interflow to streams from each subbasin
#define VAR_SBOF "SBOF"                             /// overland flow to streams from each subbasin
#define VAR_SBPET "SBPET"
#define VAR_SBPET "SBPET"                           /// the potential evapotranspiration rate of the subbasin
#define VAR_SBQG "SBQG"
#define VAR_SBQG "SBQG"                             /// groundwater flow out of the subbasin
#define VAR_SED_DEP "SEDDEP"
#define VAR_SED_OUTLET "SEDOUTLET"
#define VAR_SED_RECH "SEDRECH"
#define VAR_SED_TO_CH "SEDTOCH"
#define VAR_SED_TO_CH_T "SEDTOCH_T"
#define VAR_SEDMINPA "sedminpa"                     /// amount of active mineral phosphorus adsorbed to sediment in surface runoff
#define VAR_SEDMINPS "sedminps"                     /// amount of stable mineral phosphorus adsorbed to sediment in surface runoff
#define VAR_SEDORGN "sedorgn"
#define VAR_SEDORGP "sedorgp"                       /// amount of organic phosphorus in surface runoff
#define VAR_SEEPAGE "SEEPAGE"                               /// seepage
#define VAR_SLOPE "slope"
#define VAR_SNAC "SNAC"
#define VAR_SNME "SNME"
#define VAR_SNO3UP "sno3up"
#define VAR_SNRD "SNRD"
#define VAR_SNSB "SNSB"
#define VAR_SNRD "SNRD"
#define VAR_SNWB "SNWB"
#define VAR_SOER "SOER"                             /// soil loss caused by water erosion (t)
#define VAR_SOET "SOET"                             /// evaporation from the soil water storage
#define VAR_SOIL_T10 "soil_t10"
#define VAR_SOL_ACTP "sol_actp"                     /// amount of phosphorus stored in the active mineral phosphorus pool(kg P/ha)
#define VAR_SOL_AORGN "sol_aorgn"                   /// amount of nitrogen stored in the active organic (humic) nitrogen pool(kg N/ha)
#define VAR_SOL_AWC "sol_awc"            /// amount of water available to plants in soil layer at field capacity (FC-WP)
#define VAR_SOL_BD "density"                         /// bulk density of the soil (mg/m3)
#define VAR_SOL_CBN "sol_cbn"                       /// percent organic carbon in soil layer(%)
#define VAR_SOL_COV "sol_cov"                    /// amount of residue on soil surface (kg/ha)
#define VAR_SOL_FON "sol_fon"                       /// amount of nitrogen stored in the fresh organic (residue) pool(kg N/ha)
#define VAR_SOL_FOP "sol_fop"                       /// amount of phosphorus stored in the fresh organic (residue) pool(kg P/ha)
#define VAR_SOL_MP "sol_mp" 
#define VAR_SOL_NH3 "sol_nh3"                       /// amount of nitrogen stored in the ammonium pool in soil layer
#define VAR_SOL_NO3 "sol_no3"                       /// amount of nitrogen stored in the nitrate pool in soil layer(kg N/ha)
#define VAR_SOL_ORGN "sol_orgn"                     /// amount of nitrogen stored in the stable organic N pool(kg N/ha)
#define VAR_SOL_ORGP "sol_orgp"                     /// amount of phosphorus stored in the organic P pool in soil layer(kg P/ha)
#define VAR_SOL_RSD "sol_rsd"                       /// amount of organic matter in the soil classified as residue(kg/ha)
#define VAR_SOL_SOLP "sol_solp"                     /// amount of phosphorus stored in solution(kg P/ha)
#define VAR_SOL_STAP "sol_stap"                     /// amount of phosphorus in the soil layer stored in the stable mineral phosphorus pool(kg P/ha)
#define VAR_SOL_TA0 "soil_ta0"
#define VAR_SOL_TA1 "soil_ta1"
#define VAR_SOL_TA2 "soil_ta2"
#define VAR_SOL_TA3 "soil_ta3"
#define VAR_SOL_TB1 "soil_tb1"
#define VAR_SOL_TB2 "soil_tb2"
#define VAR_SOL_TD1 "soil_td1"
#define VAR_SOL_TD2 "soil_td2"
#define VAR_SOL_TMP "sol_tmp"                       /// daily average temperature of soil layer(deg C)
#define VAR_SOL_WFC "sol_fc"                        /// Water content of soil profile at field capacity(mm H2O)
#define VAR_SOL_WH "sol_ul"                         /// amount of water held in the soil layer at saturation(mm H2O)
#define VAR_SOL_WPMM "sol_wpmm"                     /// water content of soil at -1.5 MPa (wilting point)
#define VAR_SOL_WST "sol_st"                        /// amount of water stored in the soil layer on current day(mm H2O)
#define VAR_SOILLAYERS "soillayers"
#define VAR_SOMO "SOMO"                             /// Distribution of soil moisture
#define VAR_SOMO_TOT  "somo_total"          /// Total soil water content in soil profile
#define VAR_SOTE "SOTE"                             /// Soil Temperature
#define VAR_SOWB "SOWB"
#define VAR_SPCON "spcon"
#define VAR_SPEXP "spexp"
#define VAR_SR_MAX "srMax"                          /// Max solar radiation
#define VAR_SSRU "SSRU"                             /// The subsurface runoff
#define VAR_SSRUVOL "SSRUVOL"
#define VAR_STCAPSURPLUS "STCAPSURPLUS"
#define VAR_STREAM_LINK "STREAM_LINK"
#define VAR_SUBBSN "subbasin"                       /// The subbasin grid
#define VAR_SUB_SEDTOCH	"SubSEDTOCH"
#define VAR_SURU "SURU"                             /// surface runoff generated
#define VAR_SWE "SWE"
#define VAR_SWE0 "swe0"
#define VAR_T_RG "T_RG"   /// groundwater runoff
#define VAR_T_SOIL "t_soil"                         /// threshold soil freezing temperature
#define VAR_T_SNOW "T_snow"                /// Snowfall temperature
#define VAR_WS "WS"
#define VAR_T0 "T0"
#define VAR_TMAX "TMAX"
#define VAR_TMEAN "TMEAN"
#define VAR_TMIN "TMIN"
#define VAR_TMEAN1 "TMEAN1"
#define VAR_TMEAN2 "TMEAN2"
#define VAR_TSD_DT "data_type"                      /// Time series data type
#define VAR_UPSOLDEP "UpperSoilDepth"               /// depth of the upper soil layer
#define VAR_USLE_C "USLE_C"
#define VAR_USLE_K "USLE_K"
#define VAR_USLE_LS "USLE_LS"
#define VAR_USLE_P "USLE_P"
#define VAR_VCRIT "vcrit"
#define VAR_VDIV "Vdiv"                             /// diversion loss of the river reach
#define VAR_VP_ACT "avp"                            /// actual vapor pressure
#define VAR_VP_SAT "svp"                            /// Saturated vapor pressure
#define VAR_VPOINT "Vpoint"                         /// point source discharge
#define VAR_VSEEP0 "Vseep0"                         ///  the initial volume of transmission loss to the deep aquifer over the time interval
#define VAR_VSF "VelScaleFactor"                    /// flow velocity scaling factor for calibration
#define VAR_WDNTL "wdntl"                           /// amount of nitrogen lost from nitrate pool by denitrification in soil profile on current day in cell(kg N/ha)
#define VAR_WILTPOINT "WiltingPoint"
#define VAR_WSHD_DNIT "wshd_dnit"                   /// average annual amount of nitrogen lost from nitrate pool due to denitrification in watershed(kg N/ha)
#define VAR_WSHD_HMN "wshd_hmn"                     /// average annual amount of nitrogen moving from active organic to nitrate pool in watershed(kg N/ha)
#define VAR_WSHD_HMP "wshd_hmp"                     /// average annual amount of phosphorus moving from organic to labile pool in watershed(kg P/ha)
#define VAR_WSHD_NITN "wshd_nitn"                   /// average annual amount of nitrogen moving from the NH3 to the NO3 pool by nitrification in the watershed
#define VAR_WSHD_PAL "wshd_pal"                     /// average annual amount of phosphorus moving from labile mineral to active mineral pool in watershed
#define VAR_WSHD_PAS "wshd_pas"                     /// average annual amount of phosphorus moving from active mineral to stable mineral pool in watershed
#define VAR_WSHD_RMN "wshd_rmn"                     /// average annual amount of nitrogen moving from fresh organic (residue) to nitrate and active organic pools in watershed(kg N/ha)
#define VAR_WSHD_RMP "wshd_rmp"                     /// average annual amount of phosphorus moving from fresh organic (residue) to labile and organic pools in watershed(kg P/ha)
#define VAR_WSHD_RNO3 "wshd_rno3"                   /// average annual amount of NO3 added to soil by rainfall in watershed (kg/ha)
#define VAR_WSHD_RWN "wshd_rwn"                     /// average annual amount of nitrogen moving from active organic to stable organic pool in watershed(kg N/ha)
#define VAR_WSHD_VOLN "wshd_voln"                   /// average annual amount if nitrogen lost by ammonia volatilization in watershed


//////////////////////////////////////////////////////////////////////////
/// Define units common used in SEIMS, in case of inconsistency //////////
/// By LiangJun Zhu, HuiRan Gao ///
/// Apr. , 2016  //////////////////////////////////////
//////////////////////////////////////////////////////////////////////////

#define UNIT_AREA_KM2 "km2"                         /// Square kilometer of area
#define UNIT_AREA_RATIO "m2/m2"
#define UNIT_CONDRATE_MSPA "m/s/kPa"                /// Rate of decline in stomatal conductance per unit increase in vapor pressure deficit
#define UNIT_CONT_KGKM2 "kg/km2"                    /// Kilograms per Square kilometers of nutrient content
#define UNIT_CONT_KGHA "ka/ha"                      /// For  convenient, keep consistent with SWAT, need Conversion later.
#define UNIT_DENSITY "mg/m3"                        /// density
#define UNIT_DEPTH_MM "mm"                          /// Depth related unit, mm
#define UNIT_FLOW_CMS "m3/s"                        /// Cubic meters per second of flow discharge
#define UNIT_GAS_PPMV "ppmv"                        /// Concentration of gas, e.g., CO2
#define UNIT_KG "kg"                                /// mass Kg
#define UNIT_KG_S "kg/s"
#define UNIT_KGM3 "kg/m3"
#define UNIT_LAP_RATE "/100m"                       /// Lapse rate
#define UNIT_LEN_M "m"                              /// Meter of length
#define UNIT_LONLAT_DEG "degree"                    /// Degree of longitude and latitude
#define UNIT_NON_DIM ""                             /// Non dimension  
#define UNIT_PERCENT "%"                            /// Percent
#define UNIT_PRESSURE "kPa"                         /// Vapor pressure
#define UNIT_SECOND "sec"
#define UNIT_VOL_FRA_M3M3 "m3/m3" 
#define UNIT_SPEED_MS "m/s"                         /// Speed related
#define UNIT_SR "MJ/m2/d"                           /// Solar Radiation
#define UNIT_STRG_M3M "m3/m"                       /// storage per meter of reach length
#define UNIT_TEMP_FACTOR "mm/deg C"                 /// temperature factor
#define UNIT_TEMP_DEG "deg C"                       /// Celsius degree of air temperature 
#define UNIT_TIMESTEP_HOUR "hr"                     /// Time step (h)
#define UNIT_TIMESTEP_SEC "s"                      /// Time step (s)
#define UNIT_TONS "t"                               /// metric tons
#define UNIT_VOL_M3 "m3"                           /// volume
#define UNIT_WTRDLT_MMD "mm/d"                      /// Millimeter per day of water changes
#define UNIT_WTRDLT_MMH "mm/h"                      /// Millimeter per hour of water changes
#define UNIT_MELT_FACTOR "mm/deg C/day"                 /// Melt factor


//////////////////////////////////////////////////////////////////////////
/// Define description of units common used in SEIMS            //////////
/// By LiangJun Zhu, HuiRan Gao //////////////////////////
///               Apr. 25, 2016  //////////////////////////////////////
//////////////////////////////////////////////////////////////////////////
#define DESC_A_BNK "bank flow recession constant"
#define DESC_ALBDAY "Albedo of the current day"
#define DESC_ACC "the number of flow accumulation cells of each cell"
#define DESC_ACC_INFIL "accumulative infiltration"
#define DESC_ADDRNH3 "ammonium added by rainfall"
#define DESC_ADDRNO3 "nitrate added by rainfall"
#define DESC_B_BNK "bank storage loss coefficient"
#define DESC_BASE_EX "baseflow recession exponent"
#define DESC_BKST "bank storage"
#define DESC_BNK0 "initial bank storage per meter of reach length"
#define DESC_C_RAIN "Rainfall impact factor"
#define DESC_C_SNOW "temperature impact factor"
#define DESC_C_SNOW12 "Melt factor on Decemeber 21"
#define DESC_C_SNOW6 "Melt factor on June 21"
#define DESC_C_WABA "Channel water balance in a text format for each reach and at each time step"
#define DESC_CDN "rate coefficient for denitrification"
#define DESC_CELL_LAT "latitude of each valid cells"
#define DESC_CellSize "numble of valid cells, i.e., excluding NODATA"
#define DESC_CellWidth "width of the cell"
#define DESC_CH_DEP "distribution of channel sediment deposition"
#define DESC_CH_DET "distribution of channel flow detachment"
#define DESC_CH_DETCO "Calibration coefficient of channel flow detachment"
#define DESC_CH_FLOWCAP "distribution of channel flow capacity"
#define DESC_CH_MANNING_F "Manning scaling factor for channel routing"
#define DESC_CH_SEDRATE "distribution of channel sediment rate"
#define DESC_CH_TCCO "Calibration coefficient of transport capacity calculation"
#define DESC_CH_V "flow velocity"
#define DESC_CH_VOL "water volume"
#define DESC_CHS0 "initial channel storage per meter of reach length"
#define DESC_CHSB "Channel sediment balance in a text format for each reach and at each time step (unit?)"
#define DESC_CHST "channel storage"
#define DESC_CHT "canopy height for the day(m)"
#define DESC_CHWIDTH "Channel width"
#define DESC_CHWTDEPTH "channel water depth"
#define DESC_CLAY "Percent of clay content"
#define DESC_CMN "Rate coefficient for mineralization of the humus active organic nutrients"
#define DESC_CN2 "CN under moisture condition II"
#define DESC_CO2 "CO2 Concentration"
#define DESC_CONDRATE "Rate of decline in stomatal conductance per unit increase in vapor pressure deficit"
#define DESC_CONDUCT "saturation hydraulic conductivity"
#define DESC_D_P "Precipitation distrubution raster"
#define DESC_DEET "Distribution of evaporation from depression storage"
#define DESC_DEM "Digital Elevation Model"
#define DESC_DEPREIN "initial depression storage coefficient"
#define DESC_DEPRESSION "Depression storage capacity"
#define DESC_DETSPLASH "distribution of splash detachment"
#define DESC_DF_COEF "Deep percolation coefficient"
#define DESC_DPST "Distribution of depression storage"
#define DESC_DRYDEP_NH4 "atmospheric dry deposition of ammonia"
#define DESC_DRYDEP_NO3 "atmospheric dry deposition of nitrates"
#define DESC_DT_HS "Time step of the simulation"
#define DESC_EP_CH "reach evaporation adjustment factor"
#define DESC_ESCO "soil evaporation compensation factor"
#define DESC_EXCP "excess precipitation"
#define DESC_FIELDCAP "Soil field capacity"
#define DESC_FLOWDIR "Flow direction by the rule of ArcGIS"
#define DESC_FLOWIN_INDEX_D8 "The index of flow in (D8) cell in the compressed array, and the first element in each sub-array is the number of flow in cells in this sub-array"
#define DESC_FLOWIN_PERCENTAGE_D8 "percentage of flow out to current cell from each upstream cells"
#define DESC_FLOWOUT_INDEX_D8 "The index of flow out (D8) cell of each cells in the compressed array"
#define DESC_FLOWOUT_INDEX_DINF "The index of flow in cell in the compressed array"
#define DESC_FLOWWIDTH "Flow width of overland plane"
#define DESC_GRRE ""
#define DESC_GW0 "initial ground water storage"
#define DESC_GW_KG "baseflow recession coefficient"
#define DESC_GWMAX "maximum ground water storage"
#define DESC_GWNEW "The volume of water from the bank storage to the adjacent unsaturated zone and groundwater storage"
#define DESC_HCH "Water depth in the downslope boundary of cells"
#define DESC_HMNTL "amount of nitrogen moving from active organic to nitrate pool in soil profile on current day in cell"
#define DESC_HMPTL "amount of phosphorus moving from the organic to labile pool in soil profile on current day in cell"
#define DESC_ID_OUTLET  "index of outlet in the compressed array"
#define DESC_IGRO "Land cover status code"
#define DESC_INET "evaporation from the interception storage"
#define DESC_INFIL "Infiltration calculated in the infiltration module"
#define DESC_INFILCAPSURPLUS "surplus of infiltration capacity"
#define DESC_INIT_IS "Initial interception storage"
#define DESC_INLO "Interception Loss Distribution"
#define DESC_INTERC_MAX "Maximum Interception Storage Capacity"
#define DESC_INTERC_MIN "Minimum Interception Storage Capacity"
#define DESC_JULIAN_DAY "Julian day (int)"
#define DESC_K_BANK "hydraulic conductivity of the channel bank"
#define DESC_K_BLOW "a fraction coefficient of snow blowing into or out of the watershed"
#define DESC_K_CHB "hydraulic conductivity of the channel bed"
#define DESC_K_RUN "Runoff exponent"
#define DESC_K_SOIL10 "Ratio between soil temperature at 10 cm and the mean"
#define DESC_K_SUBLI "Praction of PET for sublimation"
#define DESC_KG "Baseflow recession coefficient"
#define DESC_KI "Interflow scale factor"
#define DESC_LAG_SNOW "Snow temperature lag factor"
#define DESC_LAIDAY "Leaf area index of current day"
#define DESC_LAP_RATE "Lapse Rate"
#define DESC_LCC "land cover code"
#define DESC_MANNING "Manning's roughness"
#define DESC_MASK "Array containing the row and column numbers for valid cells"
#define DESC_MAXCOND "Maximum stomatal conductance"
#define DESC_MAXTEMP "Maximum Celsius degree of air temperature"
#define DESC_MEANTEMP "Mean Celsius degree of air temperature"
#define DESC_METEOLAT "Latitude of MeteoClimate station"
#define DESC_MINTEMP "Minimum Celsius degree of air temperature"
#define DESC_MOIST_IN "Initial soil moisture"
#define DESC_MSF "flow velocity scaling factor for calibration"
#define DESC_MSK_CO1 "Weighting factor of bankful flow"
#define DESC_MSK_X "muskingum weighing factor"
#define DESC_NACTFR "nitrogen active pool fraction. The fraction of organic nitrogen in the active pool."
#define DESC_NEPR "Net Precipitation Distribution"
#define DESC_NONE ""
#define DESC_OL_DET "distribution of overland flow detachment"
#define DESC_OL_IUH "IUH of each grid cell"
#define DESC_OL_SED_CCOE "calibration coefficient of overland flow detachment erosion"
#define DESC_OL_SED_ECO1 "calibration coefficient of transport capacity calculation"
#define DESC_OL_SED_ECO2 "calibration coefficient of transport capacity calculation"
#define DESC_OMEGA "calibration coefficient of splash erosion"
#define DESC_P_MAX "Maximum P corresponding to runoffCo"
#define DESC_P_RF "Peak rate adjustment factor"
#define DESC_PERCO "the amount of water percolated from the soil water reservoir, i.e., groundwater recharge"
#define DESC_PET_HCOEF "Coefficient related to radiation used in Hargreaves method"
#define DESC_PET_K "Correction factor for PET"
#define DESC_PET "Potential Evapotranspiration of day"
#define DESC_PI_B "Interception Storage Capacity Exponent"
#define DESC_PL_RSDCO "Plant residue decomposition coefficient"
#define DESC_POREID "pore size distribution index"
#define DESC_POROST "soil porosity"
#define DESC_PPT "potential plant transpiration"
#define DESC_PRECI "precipitation for the day"
#define DESC_PSP "Phosphorus availability index"
#define DESC_QCH "Flux in the downslope boundary of cells"
#define DESC_QG "Groundwater discharge at each reach outlet and at each time step"
#define DESC_QI "Interflow at each reach outlet and at each time step"
#define DESC_QOUTLET "discharge at the watershed outlet"
#define DESC_QOVERLAND "Water discharge in the downslope boundary of cells"
#define DESC_QRECH "Discharge in a text format at each reach outlet and at each time step"
#define DESC_QS "Overland discharge at each reach outlet and at each time step"
#define DESC_QSOIL "discharge added to channel flow from interflow"
#define DESC_QSOUTLET "sediment at the watershed outlet"
#define DESC_QSUBBASIN "discharge at each subbasin outlet"
#define DESC_QTOTAL "discharge at the watershed outlet"
#define DESC_QUPREACH "Upreach"
#define DESC_RadianSlope  "radian slope"
#define DESC_RCA "concentration of ammonia in the rain"
#define DESC_RCN "concentration of nitrate in the rain"
#define DESC_Reinfiltration "TODO: meaning?"
#define DESC_RETURNFLOW "water depth of return flow"
#define DESC_REVAP "Revap"
#define DESC_RM "Relative humidity"
#define DESC_RMN2TL "amount of nitrogen moving from the fresh organic (residue) to the nitrate(80%) and active organic(20%) pools in soil profile on current day in cell"
#define DESC_RMP1TL "amount of phosphorus moving from the labile mineral pool to the active mineral pool in the soil profile on the current day in cell"
#define DESC_RMPTL "amount of phosphorus moving from the fresh organic (residue) to the labile(80%) and organic(20%) pools in soil profile on current day in cell"
#define DESC_ROCTL "amount of phosphorus moving from the active mineral pool to the stable mineral pool in the soil profile on the current day in cell"
#define DESC_SOILDEPTH "depth to bottom of soil layer"
#define DESC_ROOTDEPTH "root depth of plants (mm)"
#define DESC_ROUTING_LAYERS "Routing layers according to the flow direction, there are no flow relationships within each layer, and the first element in each layer is the number of cells in the layer"
#define DESC_RUNOFF_CO "Potential runoff coefficient"
#define DESC_RWNTL "amount of nitrogen moving from active organic to stable organic pool in soil profile on current day in cell"
#define DESC_SAND "Percent of sand content"
#define DESC_S_FROZEN "Frozen moisture relative to porosity with no infiltration"
#define DESC_SBGS "Groundwater storage of the subbasin"
#define DESC_SBIF "interflow to streams from each subbasin"
#define DESC_SBOF "overland flow to streams from each subbasin"
#define DESC_SBPET "the potential evapotranspiration rate of the subbasin"
#define DESC_SBQG "groundwater flow out of the subbasin"
#define DESC_SED_DEP "distribution of sediment deposition"
#define DESC_SED_OUTLET "Sediment concentration at the watershed outlet"
#define DESC_SED_RECH "Sediment in a text format at each reach outlet and at each time step"
#define DESC_SED_TO_CH "Distribution of sediment flowing to channel"
#define DESC_SED_TO_CH_T  "Total sediment flowing to channel"
#define DESC_SEDMINPA " amount of active mineral phosphorus sorbed to sediment in surface runoff"
#define DESC_SEDMINPS "amount of stable mineral phosphorus sorbed to sediment in surface runoff"
#define DESC_SEDORGN "amount of organic nitrogen in surface runoff"
#define DESC_SEDORGP "amount of organic phosphorus in surface runoff"
#define DESC_SEEPAGE "seepage"
#define DESC_SLOPE "Slope gradient (percentage)"
#define DESC_SNAC "snow accumulation"
#define DESC_SNME "distribution of snowmelt"
#define DESC_T_SNOW "Snowfall temperature"
#define DESC_SNO3UP "amount of nitrate moving upward in the soil profile in watershed"
#define DESC_SNRD "distribution of snow blowing in or out the cell"
#define DESC_SNSB "Distribution of snow sublimation (water equivalent) for a user defined period"
#define DESC_SNRD "distribution of snow blowing in or out the cell"
#define DESC_SNWB "snow water balance for selected subbasins"
#define DESC_SOER "soil loss caused by water erosion"
#define DESC_SOET "evaporation from the soil water storage"
#define DESC_SOIL_T10 "Factor of soil temperature relative to short grass (degree)"
#define DESC_SOL_ACTP "amount of phosphorus stored in the active mineral phosphorus pool"
#define DESC_SOL_AORGN "amount of nitrogen stored in the active organic (humic) nitrogen pool"
#define DESC_SOL_AWC "amount of water available to plants in soil layer at field capacity (AWC=FC-WP)"
#define DESC_SOL_BD "bulk density of the soil"
#define DESC_SOL_CBN "percent organic carbon in soil layer"
#define DESC_SOL_COV "amount of residue on soil surface"
#define DESC_SOL_FON "amount of nitrogen stored in the fresh organic (residue) pool"
#define DESC_SOL_FOP "amount of phosphorus stored in the fresh organic (residue) pool"
#define DESC_SOL_MP "??"
#define DESC_SOL_NH3 "amount of nitrogen stored in the ammonium pool in soil layer"
#define DESC_SOL_NO3 "amount of nitrogen stored in the nitrate pool in soil layer"
#define DESC_SOL_ORGN "amount of nitrogen stored in the stable organic N pool"
#define DESC_SOL_ORGP "amount of phosphorus stored in the organic P pool in soil layer"
#define DESC_SOL_RSD "amount of organic matter in the soil classified as residue"
#define DESC_SOL_SOLP "amount of phosohorus stored in solution"
#define DESC_SOL_STAP "amount of phosphorus in the soil layer stored in the stable mineral phosphorus pool"
#define DESC_SOL_TA0 "Coefficient a0 for Finn Plauborg Method"
#define DESC_SOL_TA1 "Coefficient a1 for Finn Plauborg Method"
#define DESC_SOL_TA2 "Coefficient a2 for Finn Plauborg Method"
#define DESC_SOL_TA3 "Coefficient a3 for Finn Plauborg Method"
#define DESC_SOL_TB1 "Coefficient b1 for Finn Plauborg Method"
#define DESC_SOL_TB2 "Coefficient b2 for Finn Plauborg Method"
#define DESC_SOL_TD1 "Coefficient d1 for Finn Plauborg Method"
#define DESC_SOL_TD2 "Coefficient d2 for Finn Plauborg Method"
#define DESC_SOL_TMP "daily average temperature of soil layer"
#define DESC_SOL_WFC "Water content of soil profile at field capacity"
#define DESC_SOL_WH "amount of water held in the soil layer at saturation"
#define DESC_SOL_WPMM " water content of soil at -1.5 MPa (wilting point)"
#define DESC_SOL_WST "amount of water stored in the soil layer on current day"
#define DESC_SOILLAYERS "Soil layers number"
#define DESC_SOMO "Distribution of soil moisture"
#define DESC_SOMO_TOT "amount of water stored in the soil profile"
#define DESC_SOTE "Soil Temperature"
#define DESC_SOWB "soil water balance"
#define DESC_SPCON "Coefficient in sediment transport equation"
#define DESC_SPEXP "Exponent in sediment transport equation"
#define DESC_SR "Solar radiation"
#define DESC_SR_MAX "Max solar radiation"
#define DESC_SSRU "The subsurface runoff"
#define DESC_SSRUVOL "Distribution of subsurface runoff (m3)."
#define DESC_STCAPSURPLUS "surplus of storage capacity"
#define DESC_STREAM_LINK "Stream link (id of reaches)"
#define DESC_SubbasinSelected "The subbasion ids listed in file.out"
#define DESC_SUBBSN "The subbasion grid"
#define DESC_SUB_SEDTOCH "sediment to streams from each subbasin"
#define DESC_SURU "surface runoff generated"
#define DESC_SWE "average SA of the watershed"
#define DESC_SWE0 "Initial snow water equivalent"
#define DESC_T_RG "groundwater runoff"
#define DESC_T_SOIL "threshold soil freezing temperature"
#define DESC_T0 "the snowmelt threshold temperature"
#define DESC_Tag_FLOWIN_PERCENTAGE_DINF "Percentage of flow in"
#define DESC_TIMESTEP "time step"
#define DESC_TMAX "max temperature"
#define DESC_TMEAN "mean temperature"
#define DESC_TMIN "min temperature"
#define DESC_TMEAN1 "Mean air temperature of the (d-1)th day"
#define DESC_TMEAN2 "Mean air temperature of the (d-2)th day"
#define DESC_TSD_CLIMATE "Climate data of all the stations"
#define DESC_TSD_DT "Time series data type, e.g., climate data"
#define DESC_UPSOLDEP "depth of the upper soil layer"
#define DESC_USLE_C "the cover management factor"
#define DESC_USLE_K "The soil erodibility factor used in USLE"
#define DESC_USLE_LS "USLE LS factor"
#define DESC_USLE_P "the erosion control practice factor "
#define DESC_VCRIT "critical velocity for sediment deposition"
#define DESC_VDIV "diversion loss of the river reach"
#define DESC_VER_ITP "Execute vertical interpolation (1) or not (0), defined in config.fig"
#define DESC_VP_ACT "actual vapor pressure"
#define DESC_VP_SAT "Saturated vapor pressure"
#define DESC_VPOINT "point source discharge"
#define DESC_VSEEP0  "the initial volume of transmission loss to the deep aquifer over the time interval"
#define DESC_VSF "flow velocity scaling factor for calibration"
#define DESC_WDNTL "amount of nitrogen lost from nitrate pool by denitrification in soil profile on current day in cell"
#define DESC_WEIGHT_ITP "Weight used for interpolation"
#define DESC_WILTPOINT "Plant wilting point moisture"
#define DESC_WS "Wind speed (measured at 10 meters above surface)"
#define DESC_WSHD_DNIT "average annual amount of nitrogen lost from nitrate pool due to denitrification in watershed"
#define DESC_WSHD_HMN "average annual amount of nitrogen moving from active organic to nitrate pool in watershed"
#define DESC_WSHD_HMP "average annual amount of phosphorus moving from organic to labile pool in watershed"
#define DESC_WSHD_NITN "average annual amount of nitrogen moving from the NH3 to the NO3 pool by nitrification in the watershed"
#define DESC_WSHD_PAL "average annual amount of phosphorus moving from labile mineral to active mineral pool in watershed"
#define DESC_WSHD_PAS "average annual amount of phosphorus moving from active mineral to stable mineral pool in watershed"
#define DESC_WSHD_RMN "average annual amount of nitrogen moving from fresh organic (residue) to nitrate and active organic pools in watershed"
#define DESC_WSHD_RMP "average annual amount of phosphorus moving from fresh organic (residue) to labile and organic pools in watershed"
#define DESC_WSHD_RNO3 "average annual amount of NO3 added to soil by rainfall in watershed"
#define DESC_WSHD_RWN "average annual amount of nitrogen moving from active organic to stable organic pool in watershed" 
#define DESC_WSHD_VOLN "average annual amount if nitrogen lost by ammonia volatilization in watershed" 


//////////////////////////////////////////////////////////////////////////
/// Define MongoDB related constant strings used in SEIMS and preprocess//
/// By LiangJun Zhu, May. 4, 2016  ///////////////////////////////////////
//////////////////////////////////////////////////////////////////////////
#define MONG_GRIDFS_FN				"filename"
#define MONG_GRIDFS_WEIGHT_CELLS	"NUM_CELLS"
#define MONG_GRIDFS_WEIGHT_SITES	"NUM_SITES"
#define MONG_GRIDFS_ID				"ID"
#define MONG_GRIDFS_SUBBSN			"SUBBASIN"
#define MONG_HYDRO_SITE_TYPE		"Type"
#define MONG_HYDRO_SITE_LAT			"Lat"
#define MONG_HYDRO_SITE_ELEV		"Elevation"
#define MONG_HYDRO_DATA				"DataValues"
#define MONG_HYDRO_DATA_SITEID		"StationID"
#define MONG_HYDRO_DATA_UTC			"UTCDateTime"
#define MONG_HYDRO_DATA_LOCALT		"LocalDateTime"
#define MONG_HYDRO_DATA_VALUE		"Value"
#define MONG_SITELIST_SUBBSN		"SubbasinID"
#define MONG_SITELIST_DB			"DB"


//////////////////////////////////////////////////////////////////////////
/// Define Raster/ related constant strings used in SEIMS and preprocess//
/// By LiangJun Zhu, May. 5, 2016  ///////////////////////////////////////
//////////////////////////////////////////////////////////////////////////
#define HEADER_RS_TAB	    "Header"
#define HEADER_RS_NODATA	"NODATA_VALUE"
#define HEADER_RS_XLL		"XLLCENTER"
#define HEADER_RS_YLL		"YLLCENTER"
#define HEADER_RS_NROWS		"NROWS"
#define HEADER_RS_NCOLS		"NCOLS"
#define HEADER_RS_CELLSIZE	"CELLSIZE"
#define HEADER_RS_LAYERS		"LAYERS"
#define HEADER_RS_SRS				"SRS"
#endif