#include "BMS_Balance.h"


tBalance Balance;


void BalancePro(void)
{
	uint8_t i;
	uint32_t status = 0;

	if(
		(BMSInfo.FuncSwitch.Balance == 1) &&
		(BMSInfo.SystemState == SystemState_Chging) &&
		(Balance.Status == 0 && BMSInfo.DiffVol > Balance.StartDiffVol) &&
		(Balance.Status != 0 && BMSInfo.DiffVol > Balance.StopDiffVol)
	 )
	{
		for(i = 0;i < BMSInfo.BMS_Cell_Numer;i++)
		{
			if(BMSInfo.CellVol[i] > Balance.StartVol && BMSInfo.CellVol[i] > BMSInfo.AverageVol)
			{
				status |= 1 << i;
			}
		}

		Balance.Status = status;
	}
	else
	{
		Balance.Status = 0;
	}
}


void ResetBalancePara(void)
{
	Balance.StartVol 			= Default_Para_BalStartVol;
	Balance.StopVol	 			= Default_Para_BalStopVol;
	Balance.StartDiffVol	 	= Default_Para_BalStartDiffVol;
	Balance.StopDiffVol	 		= Default_Para_BalStopDiffVol;
	Balance.Status 				= 0;
	BMSInfo.FuncSwitch.Balance 	= Default_Fun_Balance;
}



