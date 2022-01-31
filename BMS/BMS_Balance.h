#ifndef _BMS_BALANCE_H_
#define _BMS_BALANCE_H_

#include "includes.h"
#include "BMS_Parameter.h"
#include "BMS_GlobalVariable.h"






typedef struct
{
	uint16_t StartVol;				//均衡开启电压 单位:0.001V
	uint16_t StopVol;				//均衡关闭电压 单位:0.001V
	uint16_t StartDiffVol;			//均衡开启压差 单位:0.001V
	uint16_t StopDiffVol;			//均衡关闭压差 单位:0.001V
	uint32_t Status;				//均衡状态
}tBalance;


extern tBalance Balance;




extern void BalancePro(void);


#endif

