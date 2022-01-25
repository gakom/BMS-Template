#include "BMS_SystemStateSwitching.h"




void IsCheckToNormal(void)
{

}

void IsNormalToDeepSleep(void)
{
	if(!BMSInfo.FuncSwitch.DeepSleep)
		return;
}

void IsNormalToLightSleep(void)
{
	if(!BMSInfo.FuncSwitch.LightSleep)
		return;
}

void IsNormalToLock(void)
{
	if(FaultCellInvalid_Out.Flag == 1)
	{
		BMSInfo.SystemState = SystemState_Lock;
	}
}


#define ChgingCurThreshold			(50)	//单位:0.01A
#define DchgingCurThreshold			(-50)	//单位:0.01A

#define NormalToChgCurThresholdDelay	(50)	//单位:0.1S
#define NormalToDchgCurThresholdDelay	(50)	//单位:0.1S
#define ChgToNormalCurThresholdDelay		(50)	//单位:0.1S
#define DchgToNormalCurThresholdDelay		(50)	//单位:0.1S


void IsNormalToChging(void)
{
	static uint16_t count = 0;

	if(BMSInfo.SwitchState.ChgMos && BMSInfo.Current > ChgingCurThreshold)
	{
		if(++count >= NormalToChgCurThresholdDelay)
		{
			count = 0;
			BMSInfo.SystemState = SystemState_Chging;
		}
	}
	else
	{
		count = 0;
	}
}

void IsNormalToDchging(void)
{
	static uint16_t count = 0;

	if(BMSInfo.SwitchState.DchgMos && BMSInfo.Current < DchgingCurThreshold)
	{
		if(++count >= NormalToDchgCurThresholdDelay)
		{
			count = 0;
			BMSInfo.SystemState = SystemState_Dchging;
		}
	}
	else
	{
		count = 0;
	}
}

void IsChgingToNormal(void)
{
	static uint16_t count = 0;

	if(BMSInfo.SwitchState.DchgMos && BMSInfo.Current < ChgingCurThreshold)
	{
		if(++count >= ChgToNormalCurThresholdDelay)
		{
			count = 0;
			BMSInfo.SystemState = SystemState_Normal;
		}
	}
	else
	{
		count = 0;
	}
}

void IsDchgingToNormal(void)
{
	static uint16_t count = 0;

	if(BMSInfo.SwitchState.DchgMos && BMSInfo.Current < DchgingCurThreshold)
	{
		if(++count >= DchgToNormalCurThresholdDelay)
		{
			count = 0;
			BMSInfo.SystemState = SystemState_Normal;
		}
	}
	else
	{
		count = 0;
	}
}


void SystemStateSwitchingPro(void)
{
	switch(BMSInfo.SystemState)
	{
		case SystemState_Check:
			IsCheckToNormal();
			break;
		case SystemState_Normal:
			IsNormalToChging();
			IsNormalToDchging();
			IsNormalToLightSleep();
			IsNormalToDeepSleep();
			IsNormalToLock();
			break;
		case SystemState_Chging:
			IsChgingToNormal();
			break;
		case SystemState_Dchging:
			IsDchgingToNormal();
			break;
		case SystemState_LightSleep:
			break;
		case SystemState_DeepSleep:
			break;
		case SystemState_Lock:
			break;
		default:
			break;
	}
}
















