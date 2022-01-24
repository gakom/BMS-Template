#ifndef _BMS_GLOBALVARIABLE_H_
#define _BMS_GLOBALVARIABLE_H_


#include "includes.h"




#define BMS_Cell_Numer 20
#define BMS_Temp_Numer 5






//保护板实时信息
typedef struct
{
	int16_t  Current;					//总电流 单位:0.01A(充电为正、放电为负)

	uint8_t MaxCellVolNum;				//最大单体电压编号
	uint8_t MinCellVolNum;				//最小单体电压编号

	uint16_t TotalVol;					//总电压 单位:0.01V
	uint16_t AverageVol;				//平均电压 单位:0.001V
	uint16_t CellVol[BMS_Cell_Numer];	//单体电压 单位:0.001V
	uint16_t MaxSingleVol;				//最大单体电压 单位:0.001V
	uint16_t MinSingleVol;				//最小单体电压 单位:0.001V

	uint8_t CellTempNum;				//电池温度数量

	uint8_t MaxCellTempNum;				//最大电池温度编号
	uint8_t MinCellTempNum;				//最小电池温度编号

	int16_t MaxCellTemp;				//最大电池温度 单位:0.1摄氏度
	int16_t MinCellTemp;				//最小电池温度 单位:0.1摄氏度
	int16_t CellTemp[BMS_Temp_Numer];	//电池温度 单位:0.1摄氏度

	int16_t EnvirTmep;					//环境温度 单位:0.1摄氏度
	int16_t MOSTmep;  					//MOS温度 单位:0.1摄氏度

	uint8_t SOC;						//荷电荷状态 单位:1% 范围:0%~100%
	uint8_t SOH;						//电池健康状态 单位:1% 范围:0%~100%



}tBMSInfo;



//故障保护标记
typedef struct
{
	uint8_t TotalVol_Over:1;		//总压过压
	uint8_t TotalVol_Under:1;		//总压欠压

	uint8_t CellVol_Over:1;			//单体过压
	uint8_t CellVol_Under:1;		//单体欠压

	uint8_t ChgTemp_Over:1;			//充电过温
	uint8_t ChgTemp_Under:1;		//充电欠温

	uint8_t DchgTemp_Over:1;		//放电过温
	uint8_t DchgTemp_Under:1;		//放电欠温

	uint8_t EnvirTemp_Over:1;		//环境过温
	uint8_t EnvirTemp_Under:1;		//环境欠温

	uint8_t MOSTemp_Over:1;			//功率(MOS)过温

	uint8_t ChgCur_Over:1;			//充电过流

	uint8_t DchgCur_L1_Over:1;		//放电过流一级

	uint8_t DchgCur_L2_Over:1;		//放电过流二级

	uint8_t DiffVol_Over:1;			//压差过大
}tProtectFlag;

//故障告警标记
typedef struct
{
	uint8_t TotalVol_Over:1;		//总压过压
	uint8_t TotalVol_Under:1;		//总压欠压

	uint8_t CellVol_Over:1;			//单体过压
	uint8_t CellVol_Under:1;		//单体欠压

	uint8_t ChgTemp_Over:1;			//充电过温
	uint8_t ChgTemp_Under:1;		//充电欠温

	uint8_t DchgTemp_Over:1;		//放电过温
	uint8_t DchgTemp_Under:1;		//放电欠温

	uint8_t EnvirTemp_Over:1;		//环境过温
	uint8_t EnvirTemp_Under:1;		//环境欠温

	uint8_t MOSTempOver:1;			//功率(MOS)过温

	uint8_t ChgCurOver:1;			//充电过流

	uint8_t DchgCur_Over:1;			//放电过流

	uint8_t DiffVol_Over:1;			//压差过大
}tAlarmFlag;








#endif

