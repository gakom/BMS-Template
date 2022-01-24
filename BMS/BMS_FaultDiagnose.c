#include "BMS_FaultDiagnose.h"



tDiagnoseData AlarmTotalVol_Over;		//总压过压告警
tDiagnoseData ProtectTotalVol_Over;		//总压过压保护

tDiagnoseData AlarmTotalVol_Under;		//总压欠压告警
tDiagnoseData ProtectTotalVol_Under;	//总压欠压保护

tDiagnoseData AlarmCellVol_Over;		//单体过压告警
tDiagnoseData ProtectCellVol_Over;		//单体过压保护

tDiagnoseData AlarmCellVol_Under;		//单体欠压告警
tDiagnoseData ProtectCellVol_Under;		//单体欠压保护

tDiagnoseData AlarmChgTemp_Over;		//充电过温告警
tDiagnoseData ProtectChgTemp_Over;		//充电过温保护

tDiagnoseData AlarmChgTemp_Under;		//充电欠温告警
tDiagnoseData ProtectChgTemp_Under;		//充电欠温保护

tDiagnoseData AlarmDchgTemp_Over;		//放电过温告警
tDiagnoseData ProtectDchgTemp_Over;		//放电过温保护

tDiagnoseData AlarmDchgTemp_Under;		//放电欠温告警
tDiagnoseData ProtectDchgTemp_Under;	//放电欠温保护

tDiagnoseData AlarmEnvirTemp_Over;		//环境过温告警
tDiagnoseData ProtectEnvirTemp_Over;	//环境过温保护

tDiagnoseData AlarmEnvirTemp_Under;		//环境欠温告警
tDiagnoseData ProtectEnvirTemp_Under;	//环境欠温保护

tDiagnoseData AlarmMOSTempOver;			//功率(MOS)过温告警
tDiagnoseData ProtectMOSTemp_Over;		//功率(MOS)过温保护

tDiagnoseData AlarmChgCurOver;			//充电过流告警
tDiagnoseData ProtectChgCur_Over;		//充电过流保护

tDiagnoseData AlarmDchgCur_Over;		//放电过流告警
tDiagnoseData ProtectDchgCur_L1_Over;	//放电过流一级保护
tDiagnoseData ProtectDchgCur_L2_Over;	//放电过流二级保护

tDiagnoseData AlarmDiffVol_Over;		//压差过大告警
tDiagnoseData ProtectDiffVol_Over;		//压差过大保护




/////////////////////////////////////////////////////////////////////////////////////////////
//Function:判断是否大于阈值
//
/////////////////////////////////////////////////////////////////////////////////////////////
void IsOverFaultDiagnosePro(tDiagnoseData *DiagData,int16_t Value)
{
	if(DiagData->Flag == 0)//如果没有故障
	{
		if(Value >= DiagData->Trigger)//如果大于或等于阈值
		{
			DiagData->Cnt += 1;//时间累加
			if(DiagData->Cnt > DiagData->Triggertime)//如果时间大于触发延时
			{
				DiagData->Flag  = 1;//置故障标记
				DiagData->Cnt = 0;//时间清0
			}
		}
		else
		{
			DiagData->Cnt = 0;//时间清0
		}
	}
	else
	{
		if(Value < DiagData->Recovery)//如果小于恢复阈值
		{
			DiagData->Cnt += 1;//时间累加
			if(DiagData->Cnt > DiagData->Recoverytime)//如果时间大于恢复延时
			{
				DiagData->Flag  = 0;//清故障标记
				DiagData->Cnt = 0;//时间清0
			}
		}
		else
		{
			DiagData->Cnt = 0;//时间清0
		}
	}
}

/////////////////////////////////////////////////////////////////////////////////////////////
//Function:判断是否小于阈值
//
/////////////////////////////////////////////////////////////////////////////////////////////
void IsUnderFaultDiagnosePro(tDiagnoseData *DiagData,int16_t Value)
{
	if(DiagData->Flag == 0)//如果没有故障
	{
		if(Value <= DiagData->Trigger)//如果小于或等于阈值
		{
			DiagData->Cnt += 1;
			if(DiagData->Cnt > DiagData->Triggertime)//如果时间大于触发延时
			{
				DiagData->Flag  = 1;//置故障标记
				DiagData->Cnt = 0;//时间清0
			}
		}
		else
		{
			DiagData->Cnt = 0;//时间清0
		}
	}
	else
	{
		if(Value > DiagData->Recovery)//如果大于阈值
		{
			DiagData->Cnt += 1;
			if(DiagData->Cnt > DiagData->Recoverytime)//如果时间大于恢复延时
			{
				DiagData->Flag  = 0;//清故障标记
				DiagData->Cnt = 0;//时间清0
			}
		}
		else
		{
			DiagData->Cnt = 0;//时间清0
		}
	}
}



/////////////////////////////////////////////////////////////////////////////////////////////
//Function:故障诊断
//
/////////////////////////////////////////////////////////////////////////////////////////////
void FaultDiagnosePro(void)
{
	//总压过压告警
	IsOverFaultDiagnosePro(&AlarmTotalVol_Over,BMSInfo.TotalVol);

	//总压过压保护
	IsOverFaultDiagnosePro(&ProtectTotalVol_Over,BMSInfo.TotalVol);

	//总压欠压告警
	IsUnderFaultDiagnosePro(&AlarmTotalVol_Under,BMSInfo.TotalVol);

	//总压欠压保护
	IsUnderFaultDiagnosePro(&ProtectTotalVol_Under,BMSInfo.TotalVol);

	//单体过压告警
	IsOverFaultDiagnosePro(&AlarmCellVol_Over,BMSInfo.MaxCellVol);

	//单体过压保护
	IsOverFaultDiagnosePro(&ProtectCellVol_Over,BMSInfo.MaxCellVol);

	//单体欠压告警
	IsUnderFaultDiagnosePro(&AlarmCellVol_Under,BMSInfo.MinCellVol);

	//单体欠压保护
	IsUnderFaultDiagnosePro(&ProtectCellVol_Under,BMSInfo.MinCellVol);

	//环境过温告警
	IsOverFaultDiagnosePro(&AlarmEnvirTemp_Over,BMSInfo.EnvirTmep);

	//环境过温保护
	IsOverFaultDiagnosePro(&ProtectEnvirTemp_Over,BMSInfo.EnvirTmep);

	//环境欠温告警
	IsUnderFaultDiagnosePro(&AlarmEnvirTemp_Under,BMSInfo.EnvirTmep);

	//环境欠温保护
	IsUnderFaultDiagnosePro(&ProtectEnvirTemp_Under,BMSInfo.EnvirTmep);

	//功率(MOS)过温告警
	IsOverFaultDiagnosePro(&AlarmMOSTempOver,BMSInfo.MOSTmep);

	//功率(MOS)过温保护
	IsOverFaultDiagnosePro(&ProtectMOSTemp_Over,BMSInfo.MOSTmep);

	//压差过大告警
	IsOverFaultDiagnosePro(&AlarmDiffVol_Over,BMSInfo.DiffVol);

	//压差过大保护
	IsOverFaultDiagnosePro(&ProtectDiffVol_Over,BMSInfo.DiffVol);


	
	if(BMSInfo.SystemState == SystemState_Chging)
	{
		//充电过温告警
		IsOverFaultDiagnosePro(&AlarmChgTemp_Over,BMSInfo.MaxCellTempNum);

		//充电过温保护
		IsOverFaultDiagnosePro(&ProtectChgTemp_Over,BMSInfo.MaxCellTempNum);

		//充电欠温告警
		IsUnderFaultDiagnosePro(&AlarmChgTemp_Under,BMSInfo.MinCellTempNum);

		//充电欠温保护
		IsUnderFaultDiagnosePro(&ProtectChgTemp_Under,BMSInfo.MinCellTempNum);

		//充电过流告警
		IsOverFaultDiagnosePro(&AlarmChgCurOver,BMSInfo.Current);

		//充电过流保护
		IsOverFaultDiagnosePro(&ProtectChgCur_Over,BMSInfo.Current);
	}
	else
	{
		AlarmChgTemp_Over.Flag = 0;
		ProtectChgTemp_Over.Flag = 0;
		AlarmChgTemp_Under.Flag = 0;
		ProtectChgTemp_Under.Flag = 0;
		AlarmChgCurOver.Flag = 0;
		ProtectChgCur_Over.Flag = 0;
	}

	
	if(BMSInfo.SystemState == SystemState_Dchging)
	{
		//放电过温告警
		IsOverFaultDiagnosePro(&AlarmDchgTemp_Over,BMSInfo.MaxCellTempNum);

		//放电过温保护
		IsOverFaultDiagnosePro(&ProtectDchgTemp_Over,BMSInfo.MaxCellTempNum);

		//放电欠温告警
		IsUnderFaultDiagnosePro(&AlarmDchgTemp_Under,BMSInfo.MinCellTempNum);

		//放电欠温保护
		IsUnderFaultDiagnosePro(&ProtectDchgTemp_Under,BMSInfo.MinCellTempNum);

		//放电过流告警
		IsOverFaultDiagnosePro(&AlarmDchgCur_Over,BMSInfo.Current);

		//放电过流一级保护
		IsOverFaultDiagnosePro(&ProtectDchgCur_L1_Over,BMSInfo.Current);

		//放电过流二级保护
		IsOverFaultDiagnosePro(&ProtectDchgCur_L2_Over,BMSInfo.Current);
	}
	else
	{
		AlarmDchgTemp_Over.Flag = 0;
		ProtectDchgTemp_Over.Flag = 0;
		AlarmDchgTemp_Under.Flag = 0;
		ProtectDchgTemp_Under.Flag = 0;
		AlarmDchgCur_Over.Flag = 0;
		ProtectDchgCur_L1_Over.Flag = 0;
		ProtectDchgCur_L2_Over.Flag = 0;
	}
}



/////////////////////////////////////////////////////////////////////////////////////////////
//Function:恢复故障参数为默认值
//
/////////////////////////////////////////////////////////////////////////////////////////////
void ResetFaultDiagDefaultPara(void)
{
	//总压过压告警
	AlarmTotalVol_Over.Flag 			= 0;
	AlarmTotalVol_Over.Trigger 			= ParaAlarm_TotalVolOver;
	AlarmTotalVol_Over.Recovery 		= ParaAlarm_TotalVolOverFree;
	AlarmTotalVol_Over.Cnt 				= 0;
	AlarmTotalVol_Over.Triggertime 		= ParaAlarm_TotalVolFreeDelay;
	AlarmTotalVol_Over.Recoverytime 	= ParaAlarm_TotalVolFreeDelay;

	//总压过压保护
	ProtectTotalVol_Over.Flag 			= 0;
	ProtectTotalVol_Over.Trigger 		= ParaProtect_TotalVolOver;
	ProtectTotalVol_Over.Recovery 		= ParaProtect_TotalVolOverFree;
	ProtectTotalVol_Over.Cnt 			= 0;
	ProtectTotalVol_Over.Triggertime 	= ParaProtect_TotalVolOverDelay;
	ProtectTotalVol_Over.Recoverytime 	= ParaProtect_TotalVolOverDelay;

	//总压欠压告警
	AlarmTotalVol_Under.Flag 			= 0;
	AlarmTotalVol_Under.Trigger 		= ParaAlarm_TotalVolUnder;
	AlarmTotalVol_Under.Recovery 		= ParaAlarm_TotalVolUnderFree;
	AlarmTotalVol_Under.Cnt 			= 0;
	AlarmTotalVol_Under.Triggertime 	= ParaAlarm_TotalVolUnderDelay;
	AlarmTotalVol_Under.Recoverytime 	= ParaAlarm_TotalVolUnderDelay;

	//总压欠压告警
	ProtectTotalVol_Under.Flag 			= 0;
	ProtectTotalVol_Under.Trigger 		= ParaProtect_TotalVolUnder;
	ProtectTotalVol_Under.Recovery 		= ParaProtect_TotalVolUnderFree;
	ProtectTotalVol_Under.Cnt 			= 0;
	ProtectTotalVol_Under.Triggertime 	= ParaProtect_TotalVolUnderDelay;
	ProtectTotalVol_Under.Recoverytime 	= ParaProtect_TotalVolUnderDelay;

	//单体过压告警
	AlarmCellVol_Over.Flag 				= 0;
	AlarmCellVol_Over.Trigger 			= ParaAlarm_CellVolOver;
	AlarmCellVol_Over.Recovery 			= ParaAlarm_CellVolOverFree;
	AlarmCellVol_Over.Cnt 				= 0;
	AlarmCellVol_Over.Triggertime 		= ParaAlarm_CellVolOverDelay;
	AlarmCellVol_Over.Recoverytime 		= ParaAlarm_CellVolOverDelay;

	//单体过压保护
	ProtectCellVol_Over.Flag 			= 0;
	ProtectCellVol_Over.Trigger 		= ParaProtect_CellVolOver;
	ProtectCellVol_Over.Recovery 		= ParaProtect_CellVolOverFree;
	ProtectCellVol_Over.Cnt 			= 0;
	ProtectCellVol_Over.Triggertime 	= ParaProtect_CellVolOverDelay;
	ProtectCellVol_Over.Recoverytime 	= ParaProtect_CellVolOverDelay;

	//单体欠压告警
	AlarmCellVol_Under.Flag 			= 0;
	AlarmCellVol_Under.Trigger 			= ParaAlarm_CellVolUnder;
	AlarmCellVol_Under.Recovery 		= ParaAlarm_CellVolUnderFree;
	AlarmCellVol_Under.Cnt 				= 0;
	AlarmCellVol_Under.Triggertime 		= ParaAlarm_CellVolUnderDelay;
	AlarmCellVol_Under.Recoverytime 	= ParaAlarm_CellVolUnderDelay;

	//单体欠压保护
	ProtectCellVol_Under.Flag 			= 0;
	ProtectCellVol_Under.Trigger 		= ParaProtect_CellVolUnder;
	ProtectCellVol_Under.Recovery 		= ParaProtect_CellVolUnderFree;
	ProtectCellVol_Under.Cnt 			= 0;
	ProtectCellVol_Under.Triggertime 	= ParaProtect_CellVolUnderDelay;
	ProtectCellVol_Under.Recoverytime 	= ParaProtect_CellVolUnderDelay;

	//充电过温告警
	AlarmChgTemp_Over.Flag 				= 0;
	AlarmChgTemp_Over.Trigger 			= ParaAlarm_ChgTempOver;
	AlarmChgTemp_Over.Recovery 			= ParaAlarm_ChgTempOverFree;
	AlarmChgTemp_Over.Cnt 				= 0;
	AlarmChgTemp_Over.Triggertime 		= ParaAlarm_ChgTempOverDelay;
	AlarmChgTemp_Over.Recoverytime 		= ParaAlarm_ChgTempOverDelay;

	//充电过温保护
	ProtectChgTemp_Over.Flag 			= 0;
	ProtectChgTemp_Over.Trigger 		= ParaProtect_ChgTempOver;
	ProtectChgTemp_Over.Recovery 		= ParaProtect_ChgTempOverFree;
	ProtectChgTemp_Over.Cnt 			= 0;
	ProtectChgTemp_Over.Triggertime 	= ParaProtect_ChgTempOverDelay;
	ProtectChgTemp_Over.Recoverytime 	= ParaProtect_ChgTempOverDelay;

	//充电欠温告警
	AlarmChgTemp_Under.Flag 			= 0;
	AlarmChgTemp_Under.Trigger 			= ParaAlarm_ChgTempUnder;
	AlarmChgTemp_Under.Recovery 		= ParaAlarm_ChgTempUnderFree;
	AlarmChgTemp_Under.Cnt 				= 0;
	AlarmChgTemp_Under.Triggertime 		= ParaAlarm_ChgTempUnderDelay;
	AlarmChgTemp_Under.Recoverytime 	= ParaAlarm_ChgTempUnderDelay;

	//充电欠温保护
	ProtectChgTemp_Under.Flag 			= 0;
	ProtectChgTemp_Under.Trigger 		= ParaProtect_ChgTempUnder;
	ProtectChgTemp_Under.Recovery 		= ParaProtect_ChgTempUnderFree;
	ProtectChgTemp_Under.Cnt 			= 0;
	ProtectChgTemp_Under.Triggertime 	= ParaProtect_ChgTempUnderDelay;
	ProtectChgTemp_Under.Recoverytime 	= ParaProtect_ChgTempUnderDelay;

	//放电过温告警
	AlarmDchgTemp_Over.Flag 			= 0;
	AlarmDchgTemp_Over.Trigger 			= ParaAlarm_DchgTempOver;
	AlarmDchgTemp_Over.Recovery 		= ParaAlarm_DchgTempOverFree;
	AlarmDchgTemp_Over.Cnt 				= 0;
	AlarmDchgTemp_Over.Triggertime 		= ParaAlarm_DchgTempOverDelay;
	AlarmDchgTemp_Over.Recoverytime 	= ParaAlarm_DchgTempOverDelay;

	//放电过温保护
	ProtectDchgTemp_Over.Flag 			= 0;
	ProtectDchgTemp_Over.Trigger 		= ParaProtect_DchgTempOver;
	ProtectDchgTemp_Over.Recovery 		= ParaProtect_DchgTempOverFree;
	ProtectDchgTemp_Over.Cnt 			= 0;
	ProtectDchgTemp_Over.Triggertime 	= ParaProtect_DchgTempOverDelay;
	ProtectDchgTemp_Over.Recoverytime 	= ParaProtect_DchgTempOverDelay;

	//放电欠温告警
	AlarmDchgTemp_Under.Flag 			= 0;
	AlarmDchgTemp_Under.Trigger 		= ParaAlarm_DchgTempUnder;
	AlarmDchgTemp_Under.Recovery 		= ParaAlarm_DchgTempUnderFree;
	AlarmDchgTemp_Under.Cnt 			= 0;
	AlarmDchgTemp_Under.Triggertime 	= ParaAlarm_DchgTempUnderDelay;
	AlarmDchgTemp_Under.Recoverytime 	= ParaAlarm_DchgTempUnderDelay;

	//放电欠温保护
	ProtectDchgTemp_Under.Flag 			= 0;
	ProtectDchgTemp_Under.Trigger 		= ParaProtect_DchgTempUnder;
	ProtectDchgTemp_Under.Recovery 		= ParaProtect_DchgTempUnderFree;
	ProtectDchgTemp_Under.Cnt 			= 0;
	ProtectDchgTemp_Under.Triggertime 	= ParaProtect_DchgTempUnderDelay;
	ProtectDchgTemp_Under.Recoverytime 	= ParaProtect_DchgTempUnderDelay;

	//环境过温告警
	AlarmEnvirTemp_Over.Flag 			= 0;
	AlarmEnvirTemp_Over.Trigger 		= ParaAlarm_EnvirTempOver;
	AlarmEnvirTemp_Over.Recovery 		= ParaAlarm_EnvirTempOverFree;
	AlarmEnvirTemp_Over.Cnt 			= 0;
	AlarmEnvirTemp_Over.Triggertime 	= ParaAlarm_EnvirTempOverDelay;
	AlarmEnvirTemp_Over.Recoverytime 	= ParaAlarm_EnvirTempOverDelay;

	//环境过温保护
	ProtectEnvirTemp_Over.Flag 			= 0;
	ProtectEnvirTemp_Over.Trigger 		= ParaProtect_EnvirTempOver;
	ProtectEnvirTemp_Over.Recovery 		= ParaProtect_EnvirTempOverFree;
	ProtectEnvirTemp_Over.Cnt 			= 0;
	ProtectEnvirTemp_Over.Triggertime 	= ParaProtect_EnvirTempOverDelay;
	ProtectEnvirTemp_Over.Recoverytime 	= ParaProtect_EnvirTempOverDelay;

	//环境欠温告警
	AlarmEnvirTemp_Under.Flag 			= 0;
	AlarmEnvirTemp_Under.Trigger 		= ParaAlarm_EnvirTempUnder;
	AlarmEnvirTemp_Under.Recovery 		= ParaAlarm_EnvirTempUnderFree;
	AlarmEnvirTemp_Under.Cnt 			= 0;
	AlarmEnvirTemp_Under.Triggertime 	= ParaAlarm_EnvirTempUnderDelay;
	AlarmEnvirTemp_Under.Recoverytime 	= ParaAlarm_EnvirTempUnderDelay;

	//环境欠温保护
	ProtectEnvirTemp_Under.Flag 		= 0;
	ProtectEnvirTemp_Under.Trigger 		= ParaProtect_EnvirTempUnder;
	ProtectEnvirTemp_Under.Recovery 	= ParaProtect_EnvirTempUnderFree;
	ProtectEnvirTemp_Under.Cnt 			= 0;
	ProtectEnvirTemp_Under.Triggertime 	= ParaProtect_EnvirTempUnderDelay;
	ProtectEnvirTemp_Under.Recoverytime = ParaProtect_EnvirTempUnderDelay;

	//功率(MOS)过温告警
	AlarmMOSTempOver.Flag 				= 0;
	AlarmMOSTempOver.Trigger 			= ParaAlarm_MOSTempOver;
	AlarmMOSTempOver.Recovery 			= ParaAlarm_MOSTempOverFree;
	AlarmMOSTempOver.Cnt 				= 0;
	AlarmMOSTempOver.Triggertime 		= ParaAlarm_MOSTempOverDelay;
	AlarmMOSTempOver.Recoverytime 		= ParaAlarm_MOSTempOverDelay;

	//功率(MOS)过温保护
	ProtectMOSTemp_Over.Flag 			= 0;
	ProtectMOSTemp_Over.Trigger 		= ParaProtect_MOSTempOver;
	ProtectMOSTemp_Over.Recovery 		= ParaProtect_MOSTempOverFree;
	ProtectMOSTemp_Over.Cnt 			= 0;
	ProtectMOSTemp_Over.Triggertime 	= ParaProtect_MOSTempOverDelay;
	ProtectMOSTemp_Over.Recoverytime 	= ParaProtect_MOSTempOverDelay;

	//充电过流告警
	AlarmChgCurOver.Flag 				= 0;
	AlarmChgCurOver.Trigger 			= ParaAlarm_ChgCurOver;
	AlarmChgCurOver.Recovery 			= ParaAlarm_ChgCurOverFree;
	AlarmChgCurOver.Cnt 				= 0;
	AlarmChgCurOver.Triggertime 		= ParaAlarm_ChgCurOverDelay;
	AlarmChgCurOver.Recoverytime 		= ParaAlarm_ChgCurOverDelay;

	//充电过流保护
	ProtectChgCur_Over.Flag 			= 0;
	ProtectChgCur_Over.Trigger 			= ParaProtect_ChgCurOver;
	ProtectChgCur_Over.Recovery 		= ParaProtect_ChgCurOver;
	ProtectChgCur_Over.Cnt 				= 0;
	ProtectChgCur_Over.Triggertime 		= ParaProtect_ChgCurOverDelay;
	ProtectChgCur_Over.Recoverytime 	= ParaProtect_ChgCurOverDelayFree;

	//放电过流告警
	AlarmDchgCur_Over.Flag 				= 0;
	AlarmDchgCur_Over.Trigger 			= ParaAlarm_DchgCurL1Over;
	AlarmDchgCur_Over.Recovery 			= ParaAlarm_DchgCurL1OverFree;
	AlarmDchgCur_Over.Cnt 				= 0;
	AlarmDchgCur_Over.Triggertime 		= ParaAlarm_DchgCurL1OverDelay;
	AlarmDchgCur_Over.Recoverytime 		= ParaAlarm_DchgCurL1OverDelay;

	//放电过流一级保护
	ProtectDchgCur_L1_Over.Flag 		= 0;
	ProtectDchgCur_L1_Over.Trigger 		= ParaProtect_DchgCurL1Over;
	ProtectDchgCur_L1_Over.Recovery 	= ParaProtect_DchgCurL1Over;
	ProtectDchgCur_L1_Over.Cnt 			= 0;
	ProtectDchgCur_L1_Over.Triggertime 	= ParaProtect_DchgCurL1OverDelay;
	ProtectDchgCur_L1_Over.Recoverytime = ParaProtect_DchgCurL1OverDelayFree;

	//放电过流二级保护
	ProtectDchgCur_L2_Over.Flag 		= 0;
	ProtectDchgCur_L2_Over.Trigger 		= ParaProtect_DchgCurL2Over;
	ProtectDchgCur_L2_Over.Recovery 	= ParaProtect_DchgCurL2Over;
	ProtectDchgCur_L2_Over.Cnt 			= 0;
	ProtectDchgCur_L2_Over.Triggertime 	= ParaProtect_DchgCurL2OverDelay;
	ProtectDchgCur_L2_Over.Recoverytime = ParaProtect_DchgCurL2OverDelayFree;

	//压差过大告警
	AlarmDiffVol_Over.Flag 				= 0;
	AlarmDiffVol_Over.Trigger 			= ParaAlarm_DiffVolOver;
	AlarmDiffVol_Over.Recovery 			= ParaAlarm_DiffVolOverFree;
	AlarmDiffVol_Over.Cnt 				= 0;
	AlarmDiffVol_Over.Triggertime 		= ParaAlarm_DiffVolOverDelay;
	AlarmDiffVol_Over.Recoverytime 		= ParaAlarm_DiffVolOverDelay;

	//压差过大保护
	ProtectDiffVol_Over.Flag 			= 0;
	ProtectDiffVol_Over.Trigger 		= ParaProtect_DiffVolOver;
	ProtectDiffVol_Over.Recovery 		= ParaProtect_DiffVolOverFree;
	ProtectDiffVol_Over.Cnt 			= 0;
	ProtectDiffVol_Over.Triggertime 	= ParaProtect_DiffVolOverDelay;
	ProtectDiffVol_Over.Recoverytime 	= ParaProtect_DiffVolOverDelay;

}









