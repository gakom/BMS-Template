#include "BMS_Temperature.h"





void UpdateTemperaturePro(void)
{
	uint8_t index = 0;
	uint8_t minnum = 0;
	uint8_t maxnum = 0;
	uint8_t i;

	int16_t mincelltemp;
	int16_t maxcelltemp;

	int16_t bmscelltemp[PCB_Temp_Numer];

	//get cell temperature

	//get mos temperature

	//get envir temperature

	for(i = 0; i < PCB_Temp_Numer ; i++)					//判断每一路PCB上的温感
	{
		if(BMSInfo.FuncSwitch.Temperature & 1 << i)			//如果PCB上当前编号的温感被使能
		{
			if(index < BMS_Temp_Numer)						//如果小于最大温感数量
				BMSInfo.CellTemp[index++] = bmscelltemp[i];
		}
	}

	mincelltemp = 121;
	maxcelltemp = -41;


	for(i = 0; i < BMS_Temp_Numer ; i++)					//判断每一路温度
	{
		if(BMSInfo.CellTemp[i] < mincelltemp)				//如果更小
		{
			mincelltemp = BMSInfo.CellTemp[i];
			minnum		= i;
		}

		if(BMSInfo.CellTemp[i] > maxcelltemp)				//如果更大
		{
			maxcelltemp = BMSInfo.CellTemp[i];
			maxnum		= i;
		}
	}

	BMSInfo.MinCellTemp 	= mincelltemp;
	BMSInfo.MinCellTempNum 	= minnum;
	BMSInfo.MaxCellTemp 	= maxcelltemp;
	BMSInfo.MaxCellTempNum 	= maxnum;
}










