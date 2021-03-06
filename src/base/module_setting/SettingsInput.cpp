/*!
 * \file SettingsInput.cpp
 * \brief Setting Inputs for SEIMS
 *
 * \author Junzhi Liu, LiangJun Zhu
 * \version 1.1
 * \date June 2010
 */
#include "SettingsInput.h"
#include "util.h"
#include "utils.h"
//#include "DBManager.h"
#include "ModelException.h"
#include "MongoUtil.h"
#include <cstdlib>
using namespace std;

SettingsInput::SettingsInput(string fileName, mongoc_client_t* conn, string dbName, int nSubbasin, int scenarioID):m_subbasinID(nSubbasin)
{
	size_t index = fileName.find_last_of(SEP);
	string projectPath = fileName.substr(0,index+1);

	m_conn = conn;
	m_scenario = NULL;
	//if(scenarioID != -1) m_scenario = new Scenario(projectPath,scenarioID); //-1 means this model doesn't need scenario information
	LoadSettingsFromFile(fileName,dbName);
}
//! Destructor 
SettingsInput::~SettingsInput(void)
{
	//StatusMessage("Start to release SettingsInput ...");
	if(m_scenario != NULL) delete m_scenario;
	if(m_inputStation!=NULL) delete m_inputStation;
	//StatusMessage("End to release SettingsInput ...");
}

bool SettingsInput::readDate()
{
	//read start and end time
	utils utl;
	m_startDate = utl.ConvertToTime2(Value(Tag_StartTime), "%d-%d-%d %d:%d:%d", true);
	m_endDate = utl.ConvertToTime2(Value(Tag_EndTime), "%d-%d-%d %d:%d:%d", true);

	if (m_startDate == -1 || m_endDate == -1) return false;
	
	// make sure the start and end times are in the proper order
	if (m_endDate < m_startDate)
	{
		time_t tmp = m_startDate;
		m_startDate = m_endDate;
		m_endDate = tmp;
	}

	m_mode = GetUpper(Value(Tag_Mode));

	//read interval
	vector<string> dtList = utl.SplitString(Value(Tag_Interval), ',');
	m_dtHs = atoi(dtList[0].c_str());
	m_dtCh = m_dtHs;
	if (dtList.size() > 1)
		m_dtCh = atoi(dtList[1].c_str());
	// convert the time interval to seconds to conform to time_t struct
	if (StringMatch(m_mode, Tag_Mode_Daily))
	{
		m_dtHs = 86400; // 86400 secs is 1 day
		m_dtCh = 86400;
	}
	return true;
}

//bool SettingsInput::readTimeSeriesData()
//{
//	for (size_t i=0; i<m_Settings.size(); i++)
//	{		
//		//if (StringMatch(m_Settings[i][0], Tag_SiteName) && m_Settings[i].size() == 3 )
//		//{
//		//	m_inputStation->readOneStationData(atoi(m_Settings[i][1].c_str()), trim(m_Settings[i][2]));
//		//} 
//		//if (StringMatch(m_Settings[i][0], Tag_ReachName) && m_Settings[i].size() == 4)
//		//{	
//		//	m_inputReach->readOneReachData(m_Settings[i][1],m_Settings[i][2],m_Settings[i][3]);
//		//} 
//	}
//	
//	return true;
//}

//void SettingsInput::buildTimeQuery(time_t startTime, time_t endTime, bson* query)
//{
//	//bson_append_start_object(query, "MEASURE_TIME");
//	//bson_append_date(query, "$gte", startTime*1000);
//	//bson_append_date(query, "$lte", endTime*1000);
//	//bson_append_finish_object(query);
//	
//}
//! build query for mongodb
//void SettingsInput::buildQuery(const set<int>& idSet, const string& type, bson* query)
//{
//	set<int>::iterator it;
//
//	// id
//	if (!idSet.empty())
//	{
//		bson con_id[1];
//		bson_init(con_id);
//		bson_append_start_array(con_id, "$in");
//		int i = 0;
//		ostringstream oss;
//		for (it = idSet.begin(); it != idSet.end(); ++it)
//		{
//			oss.str("");
//			oss << i;
//			bson_append_int(con_id, oss.str().c_str(), *it);
//			i++;
//		}
//		bson_append_finish_array(con_id);
//		bson_finish(con_id);
//		bson_append_bson(query, "ID", con_id);
//	}
//
//	// type
//	bson_append_string(query, "TYPE", type.c_str());
//
//}


void SettingsInput::ReadSiteList()
{
	bson_t *query;
	query = bson_new();

	// subbasin id
	BSON_APPEND_INT32(query, Tag_SubbasinId, m_subbasinID);
	// mode
	BSON_APPEND_UTF8(query, Tag_Mode, m_mode.c_str());

	//string siteListTable = DB_TAB_SITELIST;
	bool stormMode = false;
	if (StringMatch(m_mode, Tag_Mode_Storm))
		stormMode = true;
	mongoc_cursor_t *cursor;
	mongoc_collection_t	*collection;
	const bson_t *doc;
	collection = mongoc_client_get_collection(m_conn,m_dbName.c_str(),DB_TAB_SITELIST);
	cursor = mongoc_collection_find(collection,MONGOC_QUERY_NONE,0,0,0,query,NULL,NULL);
	while(mongoc_cursor_next(cursor,&doc)){
		bson_iter_t iter;
		if (bson_iter_init (&iter, doc) && bson_iter_find (&iter,MONG_SITELIST_DB)){
			m_dbHydro = GetStringFromBSONITER(&iter);
		}
		else
			throw ModelException("SettingsInput", "ReadSiteList", "The DB field does not exist in SiteList table.");
		string siteList = "";
		if (bson_iter_init (&iter, doc) && bson_iter_find (&iter,SITELIST_TABLE_M)) 
		{
			siteList = GetStringFromBSONITER(&iter);
			m_inputStation->ReadSitesData(m_dbHydro, siteList, DataType_MeanTemperature, m_startDate, m_endDate);
			m_inputStation->ReadSitesData(m_dbHydro, siteList, DataType_MaximumTemperature, m_startDate, m_endDate);
			m_inputStation->ReadSitesData(m_dbHydro, siteList, DataType_MinimumTemperature, m_startDate, m_endDate);
			m_inputStation->ReadSitesData(m_dbHydro, siteList, DataType_WindSpeed, m_startDate, m_endDate);
			m_inputStation->ReadSitesData(m_dbHydro, siteList, DataType_SolarRadiation, m_startDate, m_endDate);
			m_inputStation->ReadSitesData(m_dbHydro, siteList, DataType_RelativeAirMoisture, m_startDate, m_endDate);
		}
		
		if (bson_iter_init (&iter, doc) && bson_iter_find (&iter,SITELIST_TABLE_P)) {
			siteList = GetStringFromBSONITER(&iter);
			m_inputStation->ReadSitesData(m_dbHydro, siteList, DataType_Precipitation, m_startDate, m_endDate, stormMode);
		}

		if (bson_iter_init (&iter, doc) && bson_iter_find (&iter,SITELIST_TABLE_PET)) {
			siteList = GetStringFromBSONITER(&iter);
			m_inputStation->ReadSitesData(m_dbHydro, siteList, DataType_PotentialEvapotranspiration, m_startDate, m_endDate, stormMode);
		}
	}

	bson_destroy(query);
	mongoc_cursor_destroy(cursor);
	mongoc_collection_destroy(collection);
}

bool SettingsInput::LoadSettingsFromFile(string filename,string dbName)
{
	m_dbName = dbName;

	//first get the SettingStrings from base class LoadSettingsFromFile function
	if(!Settings::LoadSettingsFromFile(filename)) 
		throw ModelException("SettingsInput","LoadSettingsFromFile","The file.in is invalid. Please check it.");
	if(!readDate()) 
		throw ModelException("SettingsInput","LoadSettingsFromFile",
		"The start time and end time in file.in is invalid. The format would be YYYY/MM/DD/HH. Please check it.");
	m_inputStation = new InputStation(m_conn, m_dtHs, m_dtCh);
	ReadSiteList();
	return true;
}

void SettingsInput::Dump(string fileName)
{
	ofstream fs;
	utils util;
	fs.open(fileName.c_str(), ios::out);
	if (fs.is_open())
	{
		fs << "Start Date :" << util.ConvertToString2(&m_startDate) <<  endl;
		fs << "End Date :" << util.ConvertToString2(&m_endDate) <<  endl;
		fs << "Interval :" << m_dtHs << "\t" << m_dtCh <<  endl;
		if(m_scenario!=NULL) m_scenario->Dump(&fs);
		fs.close();
	}
}

Scenario* SettingsInput::BMPScenario()
{
	return m_scenario;
}

InputStation* SettingsInput::StationData()
{
	return m_inputStation;
}

time_t SettingsInput::getStartTime() const
{
	return m_startDate;
}

time_t SettingsInput::getEndTime() const
{
	return m_endDate;
}

time_t SettingsInput::getDtHillslope() const
{
	return m_dtHs;
}

time_t SettingsInput::getDtChannel() const
{
	return m_dtCh;
}

time_t SettingsInput::getDtDaily() const
{
	return 86400;
}