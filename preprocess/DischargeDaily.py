#! /usr/bin/env python
#coding=utf-8
## @Discharge daily data import
#
#
from text import *
from pymongo import MongoClient
from pymongo.errors import ConnectionFailure
import xlrd
from util import *

def ImportOneYear(year, db, siteFile):
    bk = xlrd.open_workbook(siteFile)
    cList = db.collection_names()
    ##if not DataType_Discharge in cList:  changed by LJ
    if not StringInList(DataType_Discharge, cList):
        db.create_collection(DataType_Discharge)
    
    for sh in bk.sheets():
        #print sh.name
        # the sum result is stored in row of index 32
        for j in range(1, 13):
            for i in range(1, 1+GetDayNumber(year, j)):
                s = str(sh.cell_value(i, j))
                if(len(s) > 0):
                    value = float(s.split('*')[0])
                else:
                    value = 0
                
                t = datetime.datetime(year, j, i, 0, 0, 0)
                sec = time.mktime(t.timetuple())
                utcTime = time.gmtime(sec)  
                if value != 0:
                    dic = {}
                    dic[Tag_ST_StationName] = sh.name
                    dic['UTCOffset'] = 8    
                    dic['LocalDateTime'] = t
                    dic['UTCDateTime'] = datetime.datetime(utcTime[0], utcTime[1], utcTime[2], utcTime[3], utcTime[4])
                    dic[Tag_Dischage] = value
                    db.Discharge.insert(dic)
    
def ImportDailyDischargeData(hostname,port,dbName,DischargeExcelPrefix,DischargeYear):
    try:
        connMongo = MongoClient(hostname, port)
        print "Connected successfully"
    except ConnectionFailure, e:
        sys.stderr.write("Could not connect to MongoDB: %s" % e)
        sys.exit(1)
   
    db = connMongo[dbName]        
    for year in DischargeYear:
        siteFile = r'%s%d.xls' % (DischargeExcelPrefix, year)
        print siteFile
        ImportOneYear(year, db, siteFile)

def ImportMeasurementData():
    '''
    This function mainly to import measurement data to mongoDB
    data type may include Q (discharge, m3/s), totalN, totalP, etc.
    TODO: LJ
    '''
    print "TODO"
