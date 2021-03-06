#! /usr/bin/env python
#coding=utf-8
## @ Constant strings used in SEIMS, means both in
##   data preprocessing and SEIMS modules
#
from config import *

## Simulation Model related tages
Tag_Model = "model"
Tag_Cluster = "cluster"
Tag_Mode = "MODE"
Tag_Mode_Storm = "STORM"
Tag_Mode_Daily = "DAILY"
## Database related tages
Tag_CLIM_STORM_Suf = "storm_cmorph"

## Regenerated SQLite database of Parameters for SEIMS
Tag_Params = "param"
Tag_Lookup = "lookup"
init_params = 'model_param_ini'
lookup_tabs = ['SoilLookup','LanduseLookup','TillageLookup',\
               'UrbanLookup','CropLookup','FertilizerLookup',\
               'ManagementTypeLookup','MgtOpSchedulesLookup']
CROP_FILE = TXT_DB_DIR + os.sep + 'crop.txt'
sqliteFile = TXT_DB_DIR + os.sep + "Parameter.db3"

## SOIL PARAMETERS NAMES, which will be appeared in MongoDB
SOL_SEQN    = "SEQN"
SOL_NAME    = "SNAM"
## required inputs
SOL_NLYRS = "SoilLAYERS"
SOL_Z       = "SoilDepth"
SOL_OM      = "OM"
SOL_CLAY    = "Clay"
SOL_SILT    = "Silt"
SOL_SAND    = "Sand"
SOL_ROCK    = "Rock"
## optional inputs, which can be auto-calculated
SOL_ZMX     = "Sol_ZMX"
SOL_ANIONEXCL = "ANION_EXCL"
SOL_CRK     = "Sol_CRK"
SOL_BD      = "Density"
SOL_K       = "Conductivity"
SOL_WP      = "WiltingPoint"
SOL_FC      = "FieldCap"
SOL_AWC     = "Sol_AWC"
SOL_POROSITY= "Porosity"
SOL_P_INDEX = "Poreindex"
SOL_USLE_K  = "USLE_K"
SOL_ALB     = "Sol_ALB"
#SOL_RM      = "Residual"
SOL_TEXTURE = "soil_Texture"
## soil chemical properties

## Climate datatype tags, MUST BE coincident with text.h in SEIMS
## /src/base/util/text.h
## BE AWARE: TMIN, TMAX, WS, Residual is required, and TMEAN, PET, SR is optional
##           WHEN SR is not provided, the SSD MUST be there!

Tag_ClimateDB_Data = "DataValues"
DataType_Precipitation = "P"					#1, Suffix of precipitation data
DataType_MeanTemperature = "TMEAN"      	    #2
DataType_MinimumTemperature = "TMIN"			#3
DataType_MaximumTemperature = "TMAX"			#4
DataType_PotentialEvapotranspiration = "PET"	#5
DataType_SolarRadiation = "SR"			    	#6
DataType_WindSpeed = "WS"						#7
DataType_RelativeAirMoisture = "RM"			    #8
DataType_SunDurationHour = "SSD"			    #9

DataType_Meteorology = "M"                      # Suffix of meteorology data
DataType_Prefix_TS = "T"                        # Prefix of time series data
DataType_Prefix_DIS = "D"                       # Prefix of distributed data
Tag_DT_StationID = 'StationID'
Tag_DT_Year = 'Y'
Tag_DT_Month = 'M'
Tag_DT_Day = 'D'
Tag_DT_Type = 'Type'
Tag_DT_LocalT = 'LocalDateTime'
Tag_DT_Zone = 'UTCOffset'
Tag_DT_UTC = 'UTCDateTime'
Tag_DT_Value = 'Value'

Tag_ClimateDB_VARs = 'Variables'
Tag_VAR_ID = 'ID'
Tag_VAR_Type = 'Type'
Tag_VAR_UNIT = 'Unit'
Tag_VAR_IsReg = 'IsRegular'
Tag_VAR_Time = 'TimeSupport'

Tag_ClimateDB_Sites = "Sites"
Tag_ST_StationID = 'StationID'
Tag_ST_StationName = 'Name'
Tag_ST_LocalX = 'LocalX'
Tag_ST_LocalY = 'LocalY'
Tag_ST_LocalPrjID = 'LocalPrjID'
Tag_ST_Longitude = 'Lon'
Tag_ST_Latitude = 'Lat'
Tag_ST_DatumID = 'DatumID'
Tag_ST_Elevation = 'Elevation'
Tag_ST_Type = 'Type'


## Table Names required in MongoDB
DB_TAB_PARAMETERS =	"parameters"
DB_TAB_LOOKUP_LANDUSE = "LanduseLookup"
DB_TAB_LOOKUP_SOIL = "SoilLookup"
DB_TAB_SPATIAL = "spatial"
DB_TAB_SITES = "Sites"
DB_TAB_DATAVALUES = "DataValues"
DB_TAB_MEASUREMENT = "Measurements"
DB_TAB_SITELIST = "SiteList"
DB_TAB_REACH = "reaches"

### Fields in DB_TAB_REACH
REACH_SUBBASIN = "SUBBASIN"
REACH_NUMCELLS = "NUM_CELLS"
REACH_GROUP = "GROUP"
REACH_GROUPDIVIDED = "GROUP_DIVIDE"
REACH_DOWNSTREAM = "DOWNSTREAM"
REACH_UPDOWN_ORDER = "UP_DOWN_ORDER"
REACH_DOWNUP_ORDER = "DOWN_UP_ORDER"
REACH_WIDTH	 = "WIDTH"
REACH_LENGTH = "LENGTH"
REACH_DEPTH	 = "DEPTH"
REACH_V0	 = "V0"
REACH_AREA	 = "AREA"
REACH_MANNING = "MANNING"
REACH_SLOPE	 = "SLOPE"
REACH_KMETIS = 'GROUP_KMETIS'
REACH_PMETIS = 'GROUP_PMETIS'
## Hydrological data related tags
DataType_Discharge = "Discharge"
Tag_Dischage = 'q'
## Spatial Data related string or values
DEFAULT_NODATA = -9999
## Spatial data preprocessing
DIR_REACHES = "reaches"
DIR_SUBBASIN = "subbasins"
DIR_TIFF = "tif_files"
DIR_LAYERING = "layering_info"
DIR_METIS = "metis_output"
DIR_LOOKUP = "lookup"
## intermediate data files' names
filledDem = "demFilledTau.tif"
flowDir = "flowDirTauD8.tif"
slope = "slopeTau.tif"
acc = "accTauD8.tif"
streamRaster = "streamRasterTau.tif"

flowDirDinf = "flowDirDinfTau.tif"
dirCodeDinf = "dirCodeDinfTau.tif"
slopeDinf = "slopeDinfTau.tif"
weightDinf = "weightDinfTau.tif"
cellLat = "cellLatOrg.tif"

modifiedOutlet = "outletM.shp"
streamSkeleton = "streamSkeleton.tif"
streamOrder = "streamOrderTau.tif"
chNetwork = "chNetwork.txt"
chCoord = "chCoord.txt"
streamNet = "streamNet.shp"
subbasin = "subbasinTau.tif"
mask_to_ext = "mask.tif"
## masked file names
subbasinM = "subbasinTauM.tif"
flowDirM = "flowDirTauM.tif"
streamRasterM = "streamRasterTauM.tif"
## output to mongoDB file names
reachesOut = "reach.shp"
subbasinOut = "subbasin.tif"
flowDirOut = "flow_dir.tif"
streamLinkOut = "stream_link.tif"
## masked and output to mongoDB file names
slopeM = "slope.tif"
filldemM = "dem.tif"
accM = "acc.tif"
streamOrderM = "stream_order.tif"
flowDirDinfM = "flow_dir_angle_dinf.tif"
dirCodeDinfM = "flow_dir_dinf.tif"
slopeDinfM = "slope_dinf.tif"
weightDinfM = "weight_dinf.tif"
cellLatM = "celllat.tif"

subbasinVec = "subbasin.shp"
basinVec = "basin.shp"
chwidthName = "chwidth.tif"

landuseMFile = "landuse.tif"
soiltypeMFile = "soiltype.tif"

soilTexture = "soil_texture.tif"
hydroGroup = "hydro_group.tif"
usleK = "usle_k.tif"

initSoilMoist = "moist_in.tif"
depressionFile = "depression.tif"

CN2File = "CN2.tif"
radiusFile = "radius.tif"
ManningFile = "Manning.tif"
velocityFile = "velocity.tif"
## flow time to the main river from each grid cell
t0_sFile = "t0_s.tif"
## standard deviation of t0_s
delta_sFile = "delta_s.tif"
## potential runoff coefficient
runoff_coefFile = "runoff_co.tif"

## Other filenames used in preprocessing
FN_STATUS_MONGO = "status_BuildMongoDB.txt"

## Header information of raster data (Derived from Mask.tif)
HEADER_RS_TAB =     "Header"
HEADER_RS_NODATA =	"NODATA_VALUE"
HEADER_RS_XLL =		"XLLCENTER"
HEADER_RS_YLL =		"YLLCENTER"
HEADER_RS_NROWS =	"NROWS"
HEADER_RS_NCOLS =	"NCOLS"
HEADER_RS_CELLSIZE ="CELLSIZE"

## Fields in parameter table of MongoDB
PARAM_FLD_NAME =    "NAME"
PARAM_FLD_DESC =    "DESCRIPTION"
PARAM_FLD_UNIT =    "UNIT"
PARAM_FLD_MODS =    "MODULE"
PARAM_FLD_VALUE =   "VALUE"
PARAM_FLD_IMPACT =  "IMPACT"
PARAM_FLD_CHANGE =  "CHANGE"
PARAM_FLD_MAX =     "MAX"
PARAM_FLD_MIN =     "MIN"
PARAM_FLD_USE =     "USE"
PARAM_CHANGE_RC =	"RC"
PARAM_CHANGE_AC =	"AC"
PARAM_CHANGE_NC	=	"NC"
PARAM_USE_Y =       "Y"
PARAM_USE_N =       "N"