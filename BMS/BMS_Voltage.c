#include "BMS_Voltage.h"




void UpdateVoltagePro(void)
{
	uint8_t minnum = 0;
	uint8_t maxnum = 0;
	uint8_t i;

	uint16_t mincellvol;
	uint16_t maxcellvol;

	//get vlotage



	mincellvol = 0xffff;
	maxcellvol = 0;

	for(i = 0; i < BMS_Cell_Numer ; i++)				//判断每一路温度
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

	BMSInfo.MinCellVol 		= mincellvol;
	BMSInfo.MinCellVolNum 	= minnum;
	BMSInfo.MaxCellVol		= maxcellvol;
	BMSInfo.MaxCellVolNum 	= maxnum;

}







