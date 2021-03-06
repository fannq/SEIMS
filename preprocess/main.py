#! /usr/bin/env python
#coding=utf-8
## @Main function entrance for preprocessing
#

from text import *
from txt2db3 import reConstructSQLiteDB
## Climate modules
from hydroclimate_sites import ImportHydroClimateSitesInfo
from PrecipitationDaily import ImportDailyPrecData
from MeteorologicalDaily import ImportDailyMeteoData
from DischargeDaily import ImportDailyDischargeData
## Spatial modules
from subbasin_delineation import SubbasinDelineation
from gen_subbasins import GenerateSubbasins
from parameters_extraction import ExtractParameters

## Import to MongoDB
from build_db import BuildMongoDB
if __name__ == "__main__":
    ## Update SQLite Parameters.db3 database
    reConstructSQLiteDB()
    ## Climate Data
    SitesMList, SitesPList = ImportHydroClimateSitesInfo(HOSTNAME,PORT,ClimateDBName,HydroClimateVarFile, MetroSiteFile, PrecSiteFile)
    ImportDailyMeteoData(HOSTNAME, PORT, ClimateDBName, MeteoDailyFile, SitesMList)
    ImportDailyPrecData(HOSTNAME,PORT,ClimateDBName,PrecExcelPrefix,PrecDataYear, SitesPList)
    ## TODO: Measurements Data, i.e., DB_TAB_MEASUREMENT, field design refers to DB_TAB_DATAVALUES
    ImportDailyDischargeData(HOSTNAME,PORT,ClimateDBName,DischargeExcelPrefix,DischargeYear)
    ## Spatial Data derived from DEM
    SubbasinDelineation(np, WORKING_DIR, dem, outlet_file, threshold, mpiexeDir=MPIEXEC_DIR,exeDir=CPP_PROGRAM_DIR)
    GenerateSubbasins(WORKING_DIR, exeDir=CPP_PROGRAM_DIR)
    ## Extract parameters from landuse, soil properties etc.
    ExtractParameters(landuseFile, WORKING_DIR, True, True, True, True)
    ## Import to MongoDB database
    BuildMongoDB(WORKING_DIR, SpatialDBName, stormMode, forCluster, ClimateDBName, PrecSitesThiessen, MeteorSitesThiessen)