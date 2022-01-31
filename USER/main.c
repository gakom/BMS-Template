#include "delay.h"
#include "sys.h"
#include "includes.h"
#include "SEGGER_RTT.h"


#include "BMS_FaultDiagnose.h"
#include "BMS_SystemStateSwitching.h"
#include "BMS_Record.h"
#include "BMS_Temperature.h"
#include "BMS_Voltage.h"
#include "BMS_Balance.h"

//#define Degub_Printf(BufferIndex,sFormat, ...)  SEGGER_RTT_printf(BufferIndex,sFormat, ...)

/*
****************************************************************************************

	开始任务

****************************************************************************************
*/

//任务优先级
#define START_TASK_PRIO		3
//任务堆栈大小	
#define START_STK_SIZE 		512
//任务控制块
OS_TCB StartTaskTCB;
//任务堆栈	
CPU_STK START_TASK_STK[START_STK_SIZE];
//任务函数
void start_task(void *p_arg);


/*
****************************************************************************************

	任务测试1

****************************************************************************************
*/

//任务优先级
#define Task_Test_1_task_PRIO		6
//任务堆栈大小
#define Task_Test_1_task_SIZE		128
//任务控制块
OS_TCB	Task_Test_1_task_TCB;
//任务堆栈
CPU_STK	Task_Test_1_task_STK[Task_Test_1_task_SIZE];
//任务函数
void Task_Test_1_task(void *p_arg);



/*
****************************************************************************************

	任务测试2

****************************************************************************************
*/

//任务优先级
#define Task_Test_2_task_PRIO		7
//任务堆栈大小
#define Task_Test_2_task_SIZE		128
//任务控制块
OS_TCB	Task_Test_2_task_TCB;
//任务堆栈
CPU_STK	Task_Test_2_task_STK[Task_Test_2_task_SIZE];
//任务函数
void Task_Test_2_task(void *p_arg);



/*
****************************************************************************************

	任务测试3

****************************************************************************************
*/

//任务优先级
#define Task_Test_3_task_PRIO		8
//任务堆栈大小
#define Task_Test_3_task_SIZE		128
//任务控制块
OS_TCB	Task_Test_3_task_TCB;
//任务堆栈
CPU_STK	Task_Test_3_task_STK[Task_Test_3_task_SIZE];
//任务函数
void Task_Test_3_task(void *p_arg);




/*
****************************************************************************************

	检测task的堆栈、CPU使用情况

****************************************************************************************
*/

//任务优先级
#define Check_Stack_Cup_task_PRIO		20
//任务堆栈大小
#define Check_Stack_Cup_task_SIZE		128
//任务控制块
OS_TCB	Check_Stack_Cup_task_TCB;
//任务堆栈
CPU_STK	Check_Stack_Cup_task_STK[Check_Stack_Cup_task_SIZE];
//任务函数
void Check_Stack_Cup_task(void *p_arg);





/*
****************************************************************************************

	Task_Test_1_task

****************************************************************************************
*/
void Task_Test_1_task(void *p_arg)
{
	OS_ERR err;

	while(1)
	{

		FaultDiagnosePro();
		SystemStateSwitchingPro();
		WriteRecordForRun();
		UpdateTemperaturePro();
		UpdateVoltagePro();
		BalancePro();
		
		//SEGGER_RTT_printf(0, "Task_Test_1_task\n");
		OSTimeDlyHMSM(0,0,0,5,OS_OPT_TIME_HMSM_STRICT,&err);
	}
}

/*
****************************************************************************************

	Task_Test_2_task

****************************************************************************************
*/
void Task_Test_2_task(void *p_arg)
{
	OS_ERR err;

	while(1)
	{
		//SEGGER_RTT_printf(0, "Task_Test_2_task\n");
		OSTimeDlyHMSM(0,0,2,0,OS_OPT_TIME_HMSM_STRICT,&err);
	}
}

/*
****************************************************************************************

	Task_Test_3_task

****************************************************************************************
*/
void Task_Test_3_task(void *p_arg)
{
	OS_ERR err;

	while(1)
	{
		//SEGGER_RTT_printf(0, "Task_Test_3_task\n");
		OSTimeDlyHMSM(0,0,3,0,OS_OPT_TIME_HMSM_STRICT,&err);
	}
}

/*
****************************************************************************************

	Check_Stack_Cup_task

****************************************************************************************
*/

void Check_Stack_Cup_task(void *p_arg)
{
	OS_ERR err;

	while(1)
	{
		OSTimeDlyHMSM(0,0,5,0,OS_OPT_TIME_HMSM_STRICT,&err);

		// SEGGER_RTT_printf(0, "\n");

		// SEGGER_RTT_printf(0, "Task_Test_1_task --- StkUsed: %d  StkFree: %d  CPUUsage: %d  CPUUsageMax: %d\n" ,
		// 	Task_Test_1_task_TCB.StkUsed,
		// 	Task_Test_1_task_TCB.StkFree,
		// 	Task_Test_1_task_TCB.CPUUsage,
		// 	Task_Test_1_task_TCB.CPUUsageMax
		// 	);

		// SEGGER_RTT_printf(0, "Task_Test_2_task --- StkUsed: %d  StkFree: %d  CPUUsage: %d  CPUUsageMax: %d\n" ,
		// 	Task_Test_2_task_TCB.StkUsed,
		// 	Task_Test_2_task_TCB.StkFree,
		// 	Task_Test_2_task_TCB.CPUUsage,
		// 	Task_Test_2_task_TCB.CPUUsageMax
		// 	);

		// SEGGER_RTT_printf(0, "Task_Test_3_task --- StkUsed: %d  StkFree: %d  CPUUsage: %d  CPUUsageMax: %d\n" ,
		// 	Task_Test_3_task_TCB.StkUsed,
		// 	Task_Test_3_task_TCB.StkFree,
		// 	Task_Test_3_task_TCB.CPUUsage,
		// 	Task_Test_3_task_TCB.CPUUsageMax
		// 	);

		// SEGGER_RTT_printf(0, "\n");
	}
}


/*
****************************************************************************************

	start_task

****************************************************************************************
*/
//开始任务函数
void start_task(void *p_arg)
{
	OS_ERR err;
	CPU_SR_ALLOC();
	p_arg = p_arg;

	CPU_Init();
#if OS_CFG_STAT_TASK_EN > 0u
   OSStatTaskCPUUsageInit(&err);  	//统计任务                
#endif
	
#ifdef CPU_CFG_INT_DIS_MEAS_EN		//如果使能了测量中断关闭时间
    CPU_IntDisMeasMaxCurReset();	
#endif
	
#if	OS_CFG_SCHED_ROUND_ROBIN_EN  //当使用时间片轮转的时候
	 //使能时间片轮转调度功能,时间片长度为1个系统时钟节拍，既1*5=5ms
	OSSchedRoundRobinCfg(DEF_ENABLED,1,&err);  
#endif		
	
	OS_CRITICAL_ENTER();	//进入临界区

	OSTaskCreate((OS_TCB 	* )&Task_Test_1_task_TCB,		
				 (CPU_CHAR	* )"Task_Test_1_task", 		
                 (OS_TASK_PTR )Task_Test_1_task, 			
                 (void		* )0,					
                 (OS_PRIO	  )Task_Test_1_task_PRIO,     
                 (CPU_STK   * )&Task_Test_1_task_STK[0],	
                 (CPU_STK_SIZE)Task_Test_1_task_SIZE/10,	
                 (CPU_STK_SIZE)Task_Test_1_task_SIZE,		
                 (OS_MSG_QTY  )0,					
                 (OS_TICK	  )0,					
                 (void   	* )0,					
                 (OS_OPT      )OS_OPT_TASK_STK_CHK|OS_OPT_TASK_STK_CLR,
                 (OS_ERR 	* )&err);

	OSTaskCreate((OS_TCB 	* )&Task_Test_2_task_TCB,		
				 (CPU_CHAR	* )"Task_Test_2_task", 		
                 (OS_TASK_PTR )Task_Test_2_task, 			
                 (void		* )0,					
                 (OS_PRIO	  )Task_Test_2_task_PRIO,     
                 (CPU_STK   * )&Task_Test_2_task_STK[0],	
                 (CPU_STK_SIZE)Task_Test_2_task_SIZE/10,	
                 (CPU_STK_SIZE)Task_Test_2_task_SIZE,		
                 (OS_MSG_QTY  )0,					
                 (OS_TICK	  )0,					
                 (void   	* )0,					
                 (OS_OPT      )OS_OPT_TASK_STK_CHK|OS_OPT_TASK_STK_CLR,
                 (OS_ERR 	* )&err);

	OSTaskCreate((OS_TCB 	* )&Task_Test_3_task_TCB,		
				 (CPU_CHAR	* )"Task_Test_3_task", 		
                 (OS_TASK_PTR )Task_Test_3_task, 			
                 (void		* )0,					
                 (OS_PRIO	  )Task_Test_3_task_PRIO,     
                 (CPU_STK   * )&Task_Test_3_task_STK[0],	
                 (CPU_STK_SIZE)Task_Test_3_task_SIZE/10,	
                 (CPU_STK_SIZE)Task_Test_3_task_SIZE,		
                 (OS_MSG_QTY  )0,					
                 (OS_TICK	  )0,					
                 (void   	* )0,					
                 (OS_OPT      )OS_OPT_TASK_STK_CHK|OS_OPT_TASK_STK_CLR,
                 (OS_ERR 	* )&err);

	OSTaskCreate((OS_TCB 	* )&Check_Stack_Cup_task_TCB,		
				 (CPU_CHAR	* )"Check_Stack_Cup_task", 		
                 (OS_TASK_PTR )Check_Stack_Cup_task, 			
                 (void		* )0,					
                 (OS_PRIO	  )Check_Stack_Cup_task_PRIO,     	
                 (CPU_STK   * )&Check_Stack_Cup_task_STK[0],	
                 (CPU_STK_SIZE)Check_Stack_Cup_task_SIZE/10,	
                 (CPU_STK_SIZE)Check_Stack_Cup_task_SIZE,		
                 (OS_MSG_QTY  )0,					
                 (OS_TICK	  )0,					
                 (void   	* )0,				
                 (OS_OPT      )OS_OPT_TASK_STK_CHK|OS_OPT_TASK_STK_CLR, 
                 (OS_ERR 	* )&err);	

	OS_TaskSuspend((OS_TCB*)&StartTaskTCB,&err);		//挂起开始任务			 
	OS_CRITICAL_EXIT();	//进入临界区
}




/*
****************************************************************************************

	main

****************************************************************************************
*/

int main(void)
{
	OS_ERR err;
	CPU_SR_ALLOC();
	
	//delay_init();       //延时初始化
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2); //中断分组配置

	//SEGGER_RTT_Init();

	OSInit(&err);		//初始化UCOSIII
	OS_CRITICAL_ENTER();//进入临界区
	//创建开始任务
	OSTaskCreate((OS_TCB 	* )&StartTaskTCB,		//任务控制块
				 (CPU_CHAR	* )"start task", 		//任务名字
                 (OS_TASK_PTR )start_task, 			//任务函数
                 (void		* )0,					//传递给任务函数的参数
                 (OS_PRIO	  )START_TASK_PRIO,     //任务优先级
                 (CPU_STK   * )&START_TASK_STK[0],	//任务堆栈基地址
                 (CPU_STK_SIZE)START_STK_SIZE/10,	//任务堆栈深度限位
                 (CPU_STK_SIZE)START_STK_SIZE,		//任务堆栈大小
                 (OS_MSG_QTY  )0,					//任务内部消息队列能够接收的最大消息数目,为0时禁止接收消息
                 (OS_TICK	  )0,					//当使能时间片轮转时的时间片长度，为0时为默认长度，
                 (void   	* )0,					//用户补充的存储区
                 (OS_OPT      )OS_OPT_TASK_STK_CHK|OS_OPT_TASK_STK_CLR, //任务选项
                 (OS_ERR 	* )&err);				//存放该函数错误时的返回值
	OS_CRITICAL_EXIT();	//退出临界区	 
	OSStart(&err);  //开启UCOSIII
	while(1);
}




