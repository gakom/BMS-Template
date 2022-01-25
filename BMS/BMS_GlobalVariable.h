#ifndef _BMS_GLOBALVARIABLE_H_
#define _BMS_GLOBALVARIABLE_H_


#include "includes.h"

#include "BMS_Parameter.h"




typedef enum
{
	SystemState_Check,			//自检
	SystemState_Normal,			//待机
	SystemState_Chging,			//充电
	SystemState_Dchging,		//放电
	SystemState_LightSleep,		//浅休眠
	SystemState_DeepSleep,		//深度休眠
	SystemState_Lock,			//闭锁，不可恢复，需要重新上电才能恢复
}enumSystemState;


//功能开关
typedef struct
{
	uint8_t DeepSleep:1;
	uint8_t LightSleep:1;
	uint8_t Fire:1;
	uint8_t Heat:1;
	uint8_t BlueTooth:1;
	uint8_t _4G:1;
	uint8_t Balance:1;
}tFunSwitch;


//开关量状态
typedef struct
{
	uint8_t PreChg:1;
	uint8_t ChgMos:1;
	uint8_t	DchgMos:1;
	uint8_t Heat:1;
}tSwitchState;


//保护板实时信息
typedef struct
{
	int16_t  Current;					//总电流 单位:0.01A(充电为正、放电为负)

	uint8_t MaxCellVolNum;				//最大单体电压编号
	uint8_t MinCellVolNum;				//最小单体电压编号

	uint16_t TotalVol;					//总电压 单位:0.01V
	uint16_t AverageVol;				//平均电压 单位:0.001V
	uint16_t CellVol[BMS_Cell_Numer];	//单体电压 单位:0.001V
	uint16_t MaxCellVol;				//最大单体电压 单位:0.001V
	uint16_t MinCellVol;				//最小单体电压 单位:0.001V
	uint16_t DiffVol;					//压差 单位:0.001V

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

	uint64_t LeftCap;					//剩余容量 单位:1mAs  1Ah = 1000 * 3600 mAs
	uint64_t RatedCap;					//额定容量 单位:1mAs
	uint64_t FullCap;					//最大可用容量-单次欠压到过压充满的容量 单位:1mAs


	enumSystemState SystemState;		//系统状态
	tFunSwitch		FuncSwitch;			//功能开关位
	tSwitchState	SwitchState;		//

}tBMSInfo;
extern tBMSInfo BMSInfo;







#endif

