#ifndef _BMS_FAULTDIAGNOSE_H_
#define _BMS_FAULTDIAGNOSE_H_

#include "includes.h"

#include "BMS_GlobalVariable.h"




typedef struct 
{
	uint8_t	 Flag;			//故障标记	1:有故障		0:没有故障
	int16_t  Trigger;		//触发阈值
	int16_t  Recovery;		//恢复阈值
	uint16_t Cnt;			//持续时间
	uint16_t Triggertime;	//触发延时时间
	uint16_t Recoverytime;	//恢复延时时间
}tDiagnoseData;



extern tDiagnoseData AlarmTotalVol_Over;		//总压过压告警
extern tDiagnoseData ProtectTotalVol_Over;		//总压过压保护

extern tDiagnoseData AlarmTotalVol_Under;		//总压欠压告警
extern tDiagnoseData ProtectTotalVol_Under;		//总压欠压保护

extern tDiagnoseData AlarmCellVol_Over;			//单体过压告警
extern tDiagnoseData ProtectCellVol_Over;		//单体过压保护

extern tDiagnoseData AlarmCellVol_Under;		//单体欠压告警
extern tDiagnoseData ProtectCellVol_Under;		//单体欠压保护

extern tDiagnoseData AlarmChgTemp_Over;			//充电过温告警
extern tDiagnoseData ProtectChgTemp_Over;		//充电过温保护

extern tDiagnoseData AlarmChgTemp_Under;		//充电欠温告警
extern tDiagnoseData ProtectChgTemp_Under;		//充电欠温保护

extern tDiagnoseData AlarmDchgTemp_Over;		//放电过温告警
extern tDiagnoseData ProtectDchgTemp_Over;		//放电过温保护

extern tDiagnoseData AlarmDchgTemp_Under;		//放电欠温告警
extern tDiagnoseData ProtectDchgTemp_Under;		//放电欠温保护

extern tDiagnoseData AlarmEnvirTemp_Over;		//环境过温告警
extern tDiagnoseData ProtectEnvirTemp_Over;		//环境过温保护

extern tDiagnoseData AlarmEnvirTemp_Under;		//环境欠温告警
extern tDiagnoseData ProtectEnvirTemp_Under;	//环境欠温保护

extern tDiagnoseData AlarmMOSTempOver;			//功率(MOS)过温告警
extern tDiagnoseData ProtectMOSTemp_Over;		//功率(MOS)过温保护

extern tDiagnoseData AlarmChgCurOver;			//充电过流告警
extern tDiagnoseData ProtectChgCur_Over;		//充电过流保护

extern tDiagnoseData AlarmDchgCur_Over;			//放电过流告警
extern tDiagnoseData ProtectDchgCur_L1_Over;	//放电过流一级保护
extern tDiagnoseData ProtectDchgCur_L2_Over;	//放电过流二级保护

extern tDiagnoseData AlarmDiffVol_Over;			//压差过大告警
extern tDiagnoseData ProtectDiffVol_Over;		//压差过大保护






extern void FaultDiagnosePro(void);




#endif
