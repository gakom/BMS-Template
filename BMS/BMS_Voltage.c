#include "BMS_Voltage.h"




void UpdateVoltagePro(void)
{
	uint8_t minnum = 0;
	uint8_t maxnum = 0;
	uint8_t i;

	
	uint16_t mincellvol = 0xffff;
	uint16_t maxcellvol = 0;
	uint32_t totalvol = 0;

	//get vlotage

	for(i = 0; i < BMSInfo.BMS_Cell_Numer ; i++)			//判断每一路电池
	{
		if(BMSInfo.CellVol[i] < mincellvol)				//如果更小
		{
			mincellvol 	= BMSInfo.CellVol[i];
			minnum		= i;
		}

		if(BMSInfo.CellVol[i] > maxcellvol)				//如果更大
		{
			maxcellvol 	= BMSInfo.CellVol[i];
			maxnum		= i;
		}
	}

	for(i = 0; i < BMSInfo.BMS_Cell_Numer ; i++)
	{
		totalvol += BMSInfo.CellVol[i];
	}

	BMSInfo.MinCellVol 		= mincellvol;
	BMSInfo.MinCellVolNum 	= minnum;
	BMSInfo.MaxCellVol		= maxcellvol;
	BMSInfo.MaxCellVolNum 	= maxnum;
	BMSInfo.TotalVol 		= totalvol / 10;
	BMSInfo.AverageVol 		= totalvol / BMSInfo.BMS_Cell_Numer;

}




void ResetVoltagePara(void)
{
	BMSInfo.BMS_Cell_Numer = Default_BMS_Cell_Numer;
}


