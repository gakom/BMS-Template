//#include "led.h"
#include "delay.h"
#include "sys.h"
//#include "usart.h"
#include "includes.h"
#include "SEGGER_RTT.h"


//#define SEGGER_RTT_printf(BufferIndex,sFormat, ...)

/*
****************************************************************************************

	��ʼ����

****************************************************************************************
*/

//�������ȼ�
#define START_TASK_PRIO		3
//�����ջ��С	
#define START_STK_SIZE 		512
//������ƿ�
OS_TCB StartTaskTCB;
//�����ջ	
CPU_STK START_TASK_STK[START_STK_SIZE];
//������
void start_task(void *p_arg);


/*
****************************************************************************************

	�������1

****************************************************************************************
*/

//�������ȼ�
#define Task_Test_1_task_PRIO		6
//�����ջ��С
#define Task_Test_1_task_SIZE		128
//������ƿ�
OS_TCB	Task_Test_1_task_TCB;
//�����ջ
CPU_STK	Task_Test_1_task_STK[Task_Test_1_task_SIZE];
//������
void Task_Test_1_task(void *p_arg);



/*
****************************************************************************************

	�������2

****************************************************************************************
*/

//�������ȼ�
#define Task_Test_2_task_PRIO		7
//�����ջ��С
#define Task_Test_2_task_SIZE		128
//������ƿ�
OS_TCB	Task_Test_2_task_TCB;
//�����ջ
CPU_STK	Task_Test_2_task_STK[Task_Test_2_task_SIZE];
//������
void Task_Test_2_task(void *p_arg);



/*
****************************************************************************************

	�������3

****************************************************************************************
*/

//�������ȼ�
#define Task_Test_3_task_PRIO		8
//�����ջ��С
#define Task_Test_3_task_SIZE		128
//������ƿ�
OS_TCB	Task_Test_3_task_TCB;
//�����ջ
CPU_STK	Task_Test_3_task_STK[Task_Test_3_task_SIZE];
//������
void Task_Test_3_task(void *p_arg);




/*
****************************************************************************************

	���task�Ķ�ջ��CPUʹ�����

****************************************************************************************
*/

//�������ȼ�
#define Check_Stack_Cup_task_PRIO		20
//�����ջ��С
#define Check_Stack_Cup_task_SIZE		128
//������ƿ�
OS_TCB	Check_Stack_Cup_task_TCB;
//�����ջ
CPU_STK	Check_Stack_Cup_task_STK[Check_Stack_Cup_task_SIZE];
//������
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

		SEGGER_RTT_printf(0, "\n");

		SEGGER_RTT_printf(0, "Task_Test_1_task --- StkUsed: %d  StkFree: %d  CPUUsage: %d  CPUUsageMax: %d\n" ,
			Task_Test_1_task_TCB.StkUsed,
			Task_Test_1_task_TCB.StkFree,
			Task_Test_1_task_TCB.CPUUsage,
			Task_Test_1_task_TCB.CPUUsageMax
			);

		SEGGER_RTT_printf(0, "Task_Test_2_task --- StkUsed: %d  StkFree: %d  CPUUsage: %d  CPUUsageMax: %d\n" ,
			Task_Test_2_task_TCB.StkUsed,
			Task_Test_2_task_TCB.StkFree,
			Task_Test_2_task_TCB.CPUUsage,
			Task_Test_2_task_TCB.CPUUsageMax
			);

		SEGGER_RTT_printf(0, "Task_Test_3_task --- StkUsed: %d  StkFree: %d  CPUUsage: %d  CPUUsageMax: %d\n" ,
			Task_Test_3_task_TCB.StkUsed,
			Task_Test_3_task_TCB.StkFree,
			Task_Test_3_task_TCB.CPUUsage,
			Task_Test_3_task_TCB.CPUUsageMax
			);

		SEGGER_RTT_printf(0, "\n");
	}
}


/*
****************************************************************************************

	start_task

****************************************************************************************
*/
//��ʼ������
void start_task(void *p_arg)
{
	OS_ERR err;
	CPU_SR_ALLOC();
	p_arg = p_arg;

	CPU_Init();
#if OS_CFG_STAT_TASK_EN > 0u
   OSStatTaskCPUUsageInit(&err);  	//ͳ������                
#endif
	
#ifdef CPU_CFG_INT_DIS_MEAS_EN		//���ʹ���˲����жϹر�ʱ��
    CPU_IntDisMeasMaxCurReset();	
#endif
	
#if	OS_CFG_SCHED_ROUND_ROBIN_EN  //��ʹ��ʱ��Ƭ��ת��ʱ��
	 //ʹ��ʱ��Ƭ��ת���ȹ���,ʱ��Ƭ����Ϊ1��ϵͳʱ�ӽ��ģ���1*5=5ms
	OSSchedRoundRobinCfg(DEF_ENABLED,1,&err);  
#endif		
	
	OS_CRITICAL_ENTER();	//�����ٽ���

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

	OS_TaskSuspend((OS_TCB*)&StartTaskTCB,&err);		//����ʼ����			 
	OS_CRITICAL_EXIT();	//�����ٽ���
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
	
	delay_init();       //��ʱ��ʼ��
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2); //�жϷ�������

	//SEGGER_RTT_Init();

	OSInit(&err);		//��ʼ��UCOSIII
	OS_CRITICAL_ENTER();//�����ٽ���
	//������ʼ����
	OSTaskCreate((OS_TCB 	* )&StartTaskTCB,		//������ƿ�
				 (CPU_CHAR	* )"start task", 		//��������
                 (OS_TASK_PTR )start_task, 			//������
                 (void		* )0,					//���ݸ��������Ĳ���
                 (OS_PRIO	  )START_TASK_PRIO,     //�������ȼ�
                 (CPU_STK   * )&START_TASK_STK[0],	//�����ջ����ַ
                 (CPU_STK_SIZE)START_STK_SIZE/10,	//�����ջ�����λ
                 (CPU_STK_SIZE)START_STK_SIZE,		//�����ջ��С
                 (OS_MSG_QTY  )0,					//�����ڲ���Ϣ�����ܹ����յ������Ϣ��Ŀ,Ϊ0ʱ��ֹ������Ϣ
                 (OS_TICK	  )0,					//��ʹ��ʱ��Ƭ��תʱ��ʱ��Ƭ���ȣ�Ϊ0ʱΪĬ�ϳ��ȣ�
                 (void   	* )0,					//�û�����Ĵ洢��
                 (OS_OPT      )OS_OPT_TASK_STK_CHK|OS_OPT_TASK_STK_CLR, //����ѡ��
                 (OS_ERR 	* )&err);				//��Ÿú�������ʱ�ķ���ֵ
	OS_CRITICAL_EXIT();	//�˳��ٽ���	 
	OSStart(&err);  //����UCOSIII
	while(1);
}




