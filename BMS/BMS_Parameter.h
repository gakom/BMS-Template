#ifndef _BMS_PARAMETER_H_
#define _BMS_PARAMETER_H_


#include "includes.h"


//总压过压告警
#define ParaAlarm_TotalVolOver				(830)	//单位:0.1V
#define ParaAlarm_TotalVolOverFree			(820)	//单位:0.1V
#define ParaAlarm_TotalVolDelay				(10)	//单位:0.1S


//总压过压保护
#define ParaProtect_TotalVolOver			(840)	//单位:0.1V
#define ParaProtect_TotalVolOverFree		(820)	//单位:0.1V
#define ParaProtect_TotalVolOverDelay		(10)	//单位:0.1S

//总压欠压告警
#define ParaAlarm_TotalVolUnder				(600)	//单位:0.1V
#define ParaAlarm_TotalVolUnderFree			(630)	//单位:0.1V
#define ParaAlarm_TotalVolUnderDelay		(10)	//单位:0.1S

//总压欠压保护
#define ParaProtect_TotalVolUnder			(560)	//单位:0.1V
#define ParaProtect_TotalVolUnderFree		(630)	//单位:0.1V
#define ParaProtect_TotalVolUnderDelay		(10)	//单位:0.1S

//单体过压告警
#define ParaAlarm_CellVolOver				(4150)	//单位:1mv
#define ParaAlarm_CellVolOverFree			(4100)	//单位:1mv
#define ParaAlarm_CellVolOverDelay			(10)	//单位:0.1S

//单体过压保护
#define ParaProtect_CellVolOver				(4200)	//单位:1mv
#define ParaProtect_CellVolOverFree			(4100)	//单位:1mv
#define ParaProtect_CellVolOverDelay		(10)	//单位:0.1S

//单体欠压告警
#define ParaAlarm_CellVolUnder				(3000)	//单位:1mv
#define ParaAlarm_CellVolUnderFree			(3150)	//单位:1mv
#define ParaAlarm_CellVolUnderDelay			(10)	//单位:0.1S

//单体欠压保护
#define ParaProtect_CellVolUnder			(2800)	//单位:1mv
#define ParaProtect_CellVolUnderFree		(3000)	//单位:1mv
#define ParaProtect_CellVolUnderDelay		(10)	//单位:0.1S

//充电过温告警
#define ParaAlarm_ChgTempOver				(55*10)	//单位:0.1摄氏度
#define ParaAlarm_ChgTempOverFree			(50*10)	//单位:0.1摄氏度
#define ParaAlarm_ChgTempOverDelay			(10)	//单位:0.1S

//充电过温保护
#define ParaProtect_ChgTempOver				(60*10)	//单位:0.1摄氏度
#define ParaProtect_ChgTempOverFree			(55*10)	//单位:0.1摄氏度
#define ParaProtect_ChgTempOverDelay		(10)	//单位:0.1S

//充电欠温告警
#define ParaAlarm_ChgTempUnder				(0*10)	//单位:0.1摄氏度
#define ParaAlarm_ChgTempUnderFree			(5*10)	//单位:0.1摄氏度
#define ParaAlarm_ChgTempUnderDelay			(10)	//单位:0.1S

//充电欠温保护
#define ParaProtect_ChgTempUnder			(0*10)	//单位:0.1摄氏度
#define ParaProtect_ChgTempUnderFree		(5*10)	//单位:0.1摄氏度
#define ParaProtect_ChgTempUnderDelay		(10)	//单位:0.1S

//放电过温告警
#define ParaAlarm_DchgTempOver				(55*10)	//单位:0.1摄氏度
#define ParaAlarm_DchgTempOverFree			(50*10)	//单位:0.1摄氏度
#define ParaAlarm_DchgTempOverDelay			(10)	//单位:0.1S

//放电过温保护
#define ParaProtect_DchgTempOver			(60*10)	//单位:0.1摄氏度
#define ParaProtect_DchgTempOverFree		(55*10)	//单位:0.1摄氏度
#define ParaProtect_DchgTempOverDelay		(10)	//单位:0.1S

//放电欠温告警
#define ParaAlarm_DchgTempUnder				(-15*10)//单位:0.1摄氏度
#define ParaAlarm_DchgTempUnderFree			(-10*10)//单位:0.1摄氏度
#define ParaAlarm_DchgTempUnderDelay		(10)	//单位:0.1S

//放电欠温保护
#define ParaProtect_DchgTempUnder			(-20*10)//单位:0.1摄氏度
#define ParaProtect_DchgTempUnderFree		(-10*10)//单位:0.1摄氏度
#define ParaProtect_DchgTempUnderDelay		(10)	//单位:0.1S

//环境过温告警
#define ParaAlarm_EnvirTempOver				(55*10)	//单位:0.1摄氏度
#define ParaAlarm_EnvirTempOverFree			(50*10)	//单位:0.1摄氏度
#define ParaAlarm_EnvirTempOverDelay		(10)	//单位:0.1S

//环境过温保护
#define ParaProtect_EnvirTempOver			(60*10)	//单位:0.1摄氏度
#define ParaProtect_EnvirTempOverFree		(55*10)	//单位:0.1摄氏度
#define ParaProtect_EnvirTempOverDelay		(10)	//单位:0.1S

//环境欠温告警
#define ParaAlarm_EnvirTempUnder			(-5*10)	//单位:0.1摄氏度
#define ParaAlarm_EnvirTempUnderFree		(0*10)	//单位:0.1摄氏度
#define ParaAlarm_EnvirTempUnderDelay		(10)	//单位:0.1S

//环境欠温保护
#define ParaProtect_EnvirTempUnder			(-20*10)//单位:0.1摄氏度
#define ParaProtect_EnvirTempUnderFree		(-15*10)//单位:0.1摄氏度
#define ParaProtect_EnvirTempUnderDelay		(10)	//单位:0.1S

//功率(MOS)过温告警
#define ParaAlarm_MOSTempOver				(85*10)	//单位:0.1摄氏度
#define ParaAlarm_MOSTempOverFree			(80*10)	//单位:0.1摄氏度
#define ParaAlarm_MOSTempOverDelay			(10)	//单位:0.1S

//功率(MOS)过温保护
#define ParaProtect_MOSTempOver				(90*10)	//单位:0.1摄氏度
#define ParaProtect_MOSTempOverFree			(85*10)	//单位:0.1摄氏度
#define ParaProtect_MOSTempOverDelay		(10)	//单位:0.1S

//充电过流告警
#define ParaAlarm_ChgCurOver				(270)	//单位:0.1A
#define ParaAlarm_ChgCurOverFree			(260)	//单位:0.1A
#define ParaAlarm_ChgCurOverDelay			(10)	//单位:0.1S

//充电过流保护
#define ParaProtect_ChgCurOver				(280)	//单位:0.1A
#define ParaProtect_ChgCurOverDelay			(20)	//单位:0.1S
#define ParaProtect_ChgCurOverDelayFree		(50)	//单位:0.1S

//放电过流告警
#define ParaAlarm_DchgCurL1Over				(520)	//单位:0.1A
#define ParaAlarm_DchgCurL1OverFree			(510)	//单位:0.1A
#define ParaAlarm_DchgCurL1OverDelay		(10)	//单位:0.1S

//放电过流一级保护
#define ParaProtect_DchgCurL1Over			(530)	//单位:0.1A
#define ParaProtect_DchgCurL1OverDelay		(20)	//单位:0.1S
#define ParaProtect_DchgCurL1OverDelayFree	(50)	//单位:0.1S

//放电过流二级保护
#define ParaProtect_DchgCurL2Over			(750)	//单位:0.1A
#define ParaProtect_DchgCurL2OverDelay		(10)	//单位:0.1S
#define ParaProtect_DchgCurL2OverDelayFree	(120)	//单位:1S

//短路保护
#define ParaProtect_ShortCircuit			(400)	//单位:1A
#define ParaProtect_ShortCircuitDelay		(250)	//单位:1uS
#define ParaProtect_ShortCircuitDelayFree	(120)	//单位:1S

//压差过大告警
#define ParaAlarm_DiffVolOver				(800)	//单位:1mv
#define ParaAlarm_DiffVolOverFree			(400)	//单位:1mv
#define ParaAlarm_DiffVolOverDelay			(10)	//单位:0.1S

//压差过大保护
#define ParaProtect_DiffVolOver				(1000)	//单位:1mv
#define ParaProtect_DiffVolOverFree			(500)	//单位:1mv
#define ParaProtect_DiffVolOverDelay		(10)	//单位:0.1S



#endif




