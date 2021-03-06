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
	uint64_t Timestamp;					//?????????
	uint16_t TotalVol;					//????????? ??????:0.01V
	int16_t  Current;					//????????? ??????:0.01A(???????????????????????????)

	uint16_t LeftCap;					//???????????? ??????:0.01AH
	uint16_t RatedCap;					//???????????? ??????:0.01AH
	uint16_t FullCap;					//??????????????????-???????????????????????????????????? ??????:0.01AH

	uint8_t SOC;						//??????????????? ??????:1% ??????:0%~100%
	uint8_t SOH;						//?????????????????? ??????:1% ??????:0%~100%
	uint8_t ChgDepth;					//????????????
	uint8_t DchgDepth;					//????????????
	uint16_t ChgCount;					//????????????
	uint16_t DchgCount;					//????????????

	uint16_t MaxCellVol;				//?????????????????? ??????:0.001V
	uint16_t MinCellVol;				//?????????????????? ??????:0.001V
	uint16_t CellVol[PCB_Cell_Numer];	//???????????? ??????:0.001V
	uint16_t DiffVol;					//?????? ??????:0.001V


	uint32_t RunDistance;				//???????????? ??????:1km

	int16_t EnvirTmep;					//???????????? ??????:0.1?????????
	int16_t MOSTmep;  					//MOS?????? ??????:0.1?????????
	int16_t MaxCellTemp;				//?????????????????? ??????:0.1?????????
	int16_t MinCellTemp;				//?????????????????? ??????:0.1?????????
	int16_t CellTemp[PCB_Temp_Numer];	//???????????? ??????:0.1?????????


	enumRecordType Type;				//????????????

}tRecord;



typedef struct
{
	uint16_t TotalRecordNum;	//???????????????????????????
	uint16_t FristRecordAddr;	//????????????????????????
	uint16_t LastRecordAddr;	//???????????????????????????
	uint16_t Index;				//????????????
}tRecordInfo;

extern tRecordInfo AlarmRecordInfo;
extern tRecordInfo RunRecordInfo;



extern void WriteRecordForRun(void);


#endif


