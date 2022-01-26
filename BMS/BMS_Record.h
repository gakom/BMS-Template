#ifndef _BMS_RECORD_H_
#define _BMS_RECORD_H_


#include "includes.h"

#include "BMS_FaultDiagnose.h"
#include "BMS_GlobalVariable.h"



#define MaxRecordNumber (1000)





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
	uint64_t Timestamp;					//时间戳
	uint16_t TotalVol;					//总电压 单位:0.01V
	int16_t  Current;					//总电流 单位:0.01A(充电为正、放电为负)

	uint16_t LeftCap;					//剩余容量 单位:0.01AH
	uint16_t RatedCap;					//额定容量 单位:0.01AH
	uint16_t FullCap;					//最大可用容量-单次欠压到过压充满的容量 单位:0.01AH

	uint8_t SOC;						//荷电荷状态 单位:1% 范围:0%~100%
	uint8_t SOH;						//电池健康状态 单位:1% 范围:0%~100%
	uint8_t ChgDepth;					//充电深度
	uint8_t DchgDepth;					//放电深度
	uint16_t ChgCount;					//充电次数
	uint16_t DchgCount;					//放电次数

	uint16_t MaxCellVol;				//最大单体电压 单位:0.001V
	uint16_t MinCellVol;				//最小单体电压 单位:0.001V
	uint16_t CellVol[BMS_Cell_Numer];	//单体电压 单位:0.001V
	uint16_t DiffVol;					//压差 单位:0.001V


	uint32_t RunDistance;				//行驶里程 单位:1km

	int16_t EnvirTmep;					//环境温度 单位:0.1摄氏度
	int16_t MOSTmep;  					//MOS温度 单位:0.1摄氏度
	int16_t MaxCellTemp;				//最大电池温度 单位:0.1摄氏度
	int16_t MinCellTemp;				//最小电池温度 单位:0.1摄氏度
	int16_t CellTemp[BMS_Temp_Numer];	//电池温度 单位:0.1摄氏度


	enumRecordType Type;				//记录类型

}tRecord;



typedef struct
{
	uint16_t TotalRecordNum;	//已存储了多少条记录
	uint16_t FristRecordAddr;	//第一条记录的位置
	uint16_t LastRecordAddr;	//最后一条记录的位置
	uint16_t Index;				//当前索引
}tRecordInfo;

extern tRecordInfo AlarmRecordInfo;
extern tRecordInfo RunRecordInfo;



extern void WriteRecordForRun(void);


#endif


