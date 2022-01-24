#include "BMS_FaultDiagnose.h"




typedef struct 
{
	uint8_t	 flag;			//故障标记
	int16_t  value;			//当前信号量
	int16_t  trigger;		//触发阈值
	int16_t  recovery;		//恢复阈值
	uint16_t cnt;			//持续时间
	uint16_t triggertime;	//触发延时时间
	uint16_t recoverytime;	//恢复延时时间
}tDiagnoseData;


//保护
tDiagnoseData ProtectTotalVol_Over;		//总压过压
tDiagnoseData ProtectTotalVol_Under;	//总压欠压

tDiagnoseData ProtectCellVol_Over;		//单体过压
tDiagnoseData ProtectCellVol_Under;		//单体欠压

tDiagnoseData ProtectChgTemp_Over;		//充电过温
tDiagnoseData ProtectChgTemp_Under;		//充电欠温

tDiagnoseData ProtectDchgTemp_Over;		//放电过温
tDiagnoseData ProtectDchgTemp_Under;	//放电欠温

tDiagnoseData ProtectEnvirTemp_Over;	//环境过温
tDiagnoseData ProtectEnvirTemp_Under;	//环境欠温

tDiagnoseData ProtectMOSTemp_Over;		//功率(MOS)过温
tDiagnoseData ProtectChgCur_Over;		//充电过流

tDiagnoseData ProtectDchgCur_L1_Over;	//放电过流一级
tDiagnoseData ProtectDchgCur_L2_Over;	//放电过流二级

tDiagnoseData ProtectDiffVol_Over;		//压差过大

//告警
tDiagnoseData AlarmTotalVol_Over;		//总压过压
tDiagnoseData AlarmTotalVol_Under;		//总压欠压

tDiagnoseData AlarmCellVol_Over;		//单体过压
tDiagnoseData AlarmCellVol_Under;		//单体欠压

tDiagnoseData AlarmChgTemp_Over;		//充电过温
tDiagnoseData AlarmChgTemp_Under;		//充电欠温

tDiagnoseData AlarmDchgTemp_Over;		//放电过温
tDiagnoseData AlarmDchgTemp_Under;		//放电欠温

tDiagnoseData AlarmEnvirTemp_Over;		//环境过温
tDiagnoseData AlarmEnvirTemp_Under;		//环境欠温

tDiagnoseData AlarmMOSTempOver;			//功率(MOS)过温

tDiagnoseData AlarmChgCurOver;			//充电过流

tDiagnoseData AlarmDchgCur_Over;		//放电过流

tDiagnoseData AlarmDiffVol_Over;		//压差过大




/////////////////////////////////////////////////////////////////////////////////////////////
//Function:判断是否大于阈值
//
/////////////////////////////////////////////////////////////////////////////////////////////
void IsOverFaultDiagnosePro(tDiagnoseData *DiagData)
{
	if(DiagData->flag == 0)//如果没有故障
	{
		if(DiagData->value >= DiagData->trigger)//如果大于或等于阈值
		{
			DiagData->cnt += 1;//时间累加
			if(DiagData->cnt > DiagData->triggertime)//如果时间大于触发延时
			{
				DiagData->flag  = 1;//置故障标记
				DiagData->cnt = 0;//时间清0
			}
		}
		else
		{
			DiagData->cnt = 0;//时间清0
		}
	}
	else
	{
		if(DiagData->value < DiagData->recovery)//如果小于恢复阈值
		{
			DiagData->cnt += 1;//时间累加
			if(DiagData->cnt > DiagData->recoverytime)//如果时间大于恢复延时
			{
				DiagData->flag  = 0;//清故障标记
				DiagData->cnt = 0;//时间清0
			}
		}
		else
		{
			DiagData->cnt = 0;//时间清0
		}
	}
}


/////////////////////////////////////////////////////////////////////////////////////////////
//Function:判断是否小于阈值
//
/////////////////////////////////////////////////////////////////////////////////////////////
void IsUnderFaultDiagnosePro(tDiagnoseData *DiagData)
{
	if(DiagData->flag == 0)//如果没有故障
	{
		if(DiagData->value <= DiagData->trigger)//如果小于或等于阈值
		{
			DiagData->cnt += 1;
			if(DiagData->cnt > DiagData->triggertime)//如果时间大于触发延时
			{
				DiagData->flag  = 1;//置故障标记
				DiagData->cnt = 0;//时间清0
			}
		}
		else
		{
			DiagData->cnt = 0;//时间清0
		}
	}
	else
	{
		if(DiagData->value > DiagData->recovery)//如果大于阈值
		{
			DiagData->cnt += 1;
			if(DiagData->cnt > DiagData->recoverytime)//如果时间大于恢复延时
			{
				DiagData->flag  = 0;//清故障标记
				DiagData->cnt = 0;//时间清0
			}
		}
		else
		{
			DiagData->cnt = 0;//时间清0
		}
	}
}




void FaultDiagnosePro(void)
{

	IsOverFaultDiagnosePro(&ProtectTotalVol_Over);
	IsUnderFaultDiagnosePro(&ProtectTotalVol_Under);

	IsOverFaultDiagnosePro(&ProtectCellVol_Over);
	IsUnderFaultDiagnosePro(&ProtectCellVol_Under);

	IsOverFaultDiagnosePro(&ProtectChgTemp_Over);
	IsUnderFaultDiagnosePro(&ProtectChgTemp_Under);

	IsOverFaultDiagnosePro(&ProtectDchgTemp_Over);
	IsUnderFaultDiagnosePro(&ProtectDchgTemp_Under);

	IsOverFaultDiagnosePro(&ProtectEnvirTemp_Over);
	IsUnderFaultDiagnosePro(&ProtectEnvirTemp_Under);

	IsOverFaultDiagnosePro(&ProtectMOSTemp_Over);
	IsOverFaultDiagnosePro(&ProtectChgCur_Over);
	IsOverFaultDiagnosePro(&ProtectDchgCur_L1_Over);
	IsOverFaultDiagnosePro(&ProtectDchgCur_L2_Over);
	IsOverFaultDiagnosePro(&ProtectDiffVol_Over);


	IsOverFaultDiagnosePro(AlarmTotalVol_Over);
	IsUnderFaultDiagnosePro(AlarmTotalVol_Under);

	IsOverFaultDiagnosePro(AlarmCellVol_Over);
	IsUnderFaultDiagnosePro(AlarmCellVol_Under);

	IsOverFaultDiagnosePro(AlarmChgTemp_Over);
	IsUnderFaultDiagnosePro(AlarmChgTemp_Under);

	IsOverFaultDiagnosePro(AlarmDchgTemp_Over);
	IsUnderFaultDiagnosePro(AlarmDchgTemp_Under);

	IsOverFaultDiagnosePro(AlarmEnvirTemp_Over);
	IsUnderFaultDiagnosePro(AlarmEnvirTemp_Under);

	IsOverFaultDiagnosePro(AlarmMOSTempOver);
	IsOverFaultDiagnosePro(AlarmChgCurOver);
	IsOverFaultDiagnosePro(AlarmDchgCur_Over);
	IsOverFaultDiagnosePro(AlarmDiffVol_Over);
}













