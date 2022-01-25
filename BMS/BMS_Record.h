#ifndef _BMS_RECORD_H_
#define _BMS_RECORD_H_


#include "includes.h"

#include "BMS_FaultDiagnose.h"



#define MaxRecordNumber




/*
历史记录存储的数据


时间戳			uint64_t
总电压			uint16_t		0.01V
总电流			int16_t			0.01A
剩余容量			uint32_t		0.01Ah
额定容量			uint32_t		0.01Ah
最大可用容量		uint32_t		0.01Ah
SOC				uint8_t
SOH				uint8_t
最高电压			uint16_t		0.001V
最低电压			uint16_t		0.001V
压差				uint16_t		0.001V
充电次数			uint16_t
放电次数			uint16_t
充电深度			uint8_t
放电深度			uint8_t
运行里程			uint32_t		1km
电池温度 1~5		int16_t*5		1'C
环境温度			int16_t			1'C
MOS温度			int16_t			1'C
电池电压 1~20	uint16_t*20		0.001V




*/


typedef enum
{
	RecordType_Timing,

	RecordType_StartChg,
	RecordType_FinshChg,

	RecordType_StartDchg,
	RecordType_FinshDchg,

	RecordType_AlarmTotalVol_Over,
	RecordType_AlarmTotalVol_OverFree,

	RecordType_ProtectTotalVol_Over,
	RecordType_ProtectTotalVol_OverFree,

	RecordType_AlarmTotalVol_Under,
	RecordType_AlarmTotalVol_UnderFree,

	RecordType_ProtectTotalVol_Under,
	RecordType_ProtectTotalVol_UnderFree,

	RecordType_AlarmCellVol_Over,
	RecordType_AlarmCellVol_OverFree,

	RecordType_ProtectCellVol_Over,
	RecordType_ProtectCellVol_OverFree,

	RecordType_AlarmCellVol_Under,
	RecordType_AlarmCellVol_UnderFree,

	RecordType_ProtectCellVol_Under,
	RecordType_ProtectCellVol_UnderFree,

	RecordType_AlarmChgTemp_Over,
	RecordType_AlarmChgTemp_OverFree,

	RecordType_ProtectChgTemp_Over,
	RecordType_ProtectChgTemp_OverFree,

	RecordType_AlarmChgTemp_Under,
	RecordType_AlarmChgTemp_UnderFree,

	RecordType_ProtectChgTemp_Under,
	RecordType_ProtectChgTemp_UnderFree,

	RecordType_AlarmDchgTemp_Over,
	RecordType_AlarmDchgTemp_OverFree,

	RecordType_ProtectDchgTemp_Over,
	RecordType_ProtectDchgTemp_OverFree,

	RecordType_AlarmDchgTemp_Under,
	RecordType_AlarmDchgTemp_UnderFree,

	RecordType_ProtectDchgTemp_Under,
	RecordType_ProtectDchgTemp_UnderFree,

	RecordType_AlarmEnvirTemp_Over,
	RecordType_AlarmEnvirTemp_OverFree,

	RecordType_ProtectEnvirTemp_Over,
	RecordType_ProtectEnvirTemp_OverFree,

	RecordType_AlarmEnvirTemp_Under,
	RecordType_AlarmEnvirTemp_UnderFree,

	RecordType_ProtectEnvirTemp_Under,
	RecordType_ProtectEnvirTemp_UnderFree,

	RecordType_AlarmMOSTempOver,
	RecordType_AlarmMOSTempOverFree,

	RecordType_ProtectMOSTemp_Over,
	RecordType_ProtectMOSTemp_OverFree,

	RecordType_AlarmChgCurOver,
	RecordType_AlarmChgCurOverFree,

	RecordType_ProtectChgCur_Over,

	RecordType_ProtectChgCur_OverFree,
	RecordType_AlarmDchgCur_Over,
	RecordType_AlarmDchgCur_OverFree,

	RecordType_ProtectDchgCur_L1_Over,
	RecordType_ProtectDchgCur_L1_OverFree,

	RecordType_ProtectDchgCur_L2_Over,
	RecordType_ProtectDchgCur_L2_OverFree,

	RecordType_AlarmDiffVol_Over,
	RecordType_AlarmDiffVol_OverFree,

	RecordType_ProtectDiffVol_Over,
	RecordType_ProtectDiffVol_OverFree,


}enumRecordType;









typedef struct
{
	uint64_t Timestamp;			//时间戳
	uint16_t TotalVol;			//总电压 单位:0.01V
	int16_t  Current;			//总电流 单位:0.01A(充电为正、放电为负)

	//add record


	enumRecordType Type;		//记录类型

}tRecord;



typedef struct
{
	uint16_t TotalRecordNum;	//已存储了多少条记录
	uint16_t Index;				//当前索引


}tRecordInfo;






#endif


