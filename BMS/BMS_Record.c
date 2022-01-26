#include "BMS_Record.h"


tRecordInfo AlarmRecordInfo;
tRecordInfo RunRecordInfo;


//0:Alarm  1:Run
void WriteOneRecord(enumRecordType type,uint8_t recordtype)
{

	tRecordInfo *RecordInfo;

	RecordInfo = recordtype == 0 ? &AlarmRecordInfo : &RunRecordInfo;

	if(RecordInfo->TotalRecordNum < MaxRecordNumber)//还没有存满，第一条地址都在1，最后一条地址+1
	{
		RecordInfo->TotalRecordNum++;
		RecordInfo->FristRecordAddr = 1;
		RecordInfo->LastRecordAddr = RecordInfo->TotalRecordNum;
	}
	else//存满了之后，每次存储第一条和最后一条地址都+1
	{
		if(++RecordInfo->FristRecordAddr > MaxRecordNumber)
			RecordInfo->FristRecordAddr = 1;

		if(++RecordInfo->LastRecordAddr > MaxRecordNumber)
			RecordInfo->LastRecordAddr = 1;
	}

	//add to epprom  不同类型的记录，存储的地址不一样





}


void WriteOneRecordForAlarm(enumRecordType type)
{
	// if(AlarmRecordInfo.TotalRecordNum < MaxRecordNumber)//还没有存满，第一条地址都在1，最后一条地址+1
	// {
	// 	AlarmRecordInfo.TotalRecordNum++;
	// 	AlarmRecordInfo.FristRecordAddr = 1;
	// 	AlarmRecordInfo.LastRecordAddr = AlarmRecordInfo.TotalRecordNum;
	// }
	// else//存满了之后，每次存储第一条和最后一条地址都+1
	// {
	// 	if(++AlarmRecordInfo.FristRecordAddr > MaxRecordNumber)
	// 		AlarmRecordInfo.FristRecordAddr = 1;

	// 	if(++AlarmRecordInfo.LastRecordAddr > MaxRecordNumber)
	// 		AlarmRecordInfo.LastRecordAddr = 1;
	// }



	WriteOneRecord(type,0);
}


void WriteOneRecordForRun(enumRecordType type)
{
	// if(RunRecordInfo.TotalRecordNum < MaxRecordNumber)//还没有存满，第一条地址都在1，最后一条地址+1
	// {
	// 	RunRecordInfo.TotalRecordNum++;
	// 	RunRecordInfo.FristRecordAddr = 1;
	// 	RunRecordInfo.LastRecordAddr = RunRecordInfo.TotalRecordNum;
	// }
	// else//存满了之后，每次存储第一条和最后一条地址都+1
	// {
	// 	if(++RunRecordInfo.FristRecordAddr > MaxRecordNumber)
	// 		RunRecordInfo.FristRecordAddr = 1;

	// 	if(++RunRecordInfo.LastRecordAddr > MaxRecordNumber)
	// 		RunRecordInfo.LastRecordAddr = 1;
	// }

	WriteOneRecord(type,1);
}

void IsRecord_AlarmTotalVol_Over(void)
{
	static uint8_t falg = 0;

	if(AlarmTotalVol_Over.Flag != falg)
	{
		falg = AlarmTotalVol_Over.Flag;
		AlarmTotalVol_Over.Flag == 1 ? WriteOneRecordForAlarm(RecordType_AlarmTotalVol_Over) : WriteOneRecordForAlarm(RecordType_AlarmTotalVol_OverFree);
	}
}

void IsRecord_ProtectTotalVol_Over(void)
{
	static uint8_t falg = 0;

	if(ProtectTotalVol_Over.Flag != falg)
	{
		falg = ProtectTotalVol_Over.Flag;
		ProtectTotalVol_Over.Flag == 1 ? WriteOneRecordForAlarm(RecordType_ProtectTotalVol_Over) : WriteOneRecordForAlarm(RecordType_ProtectTotalVol_OverFree);
	}
}

void IsRecord_AlarmTotalVol_Under(void)
{
	static uint8_t falg = 0;

	if(AlarmTotalVol_Under.Flag != falg)
	{
		falg = AlarmTotalVol_Under.Flag;
		AlarmTotalVol_Under.Flag == 1 ? WriteOneRecordForAlarm(RecordType_AlarmTotalVol_Under) : WriteOneRecordForAlarm(RecordType_AlarmTotalVol_UnderFree);
	}
}

void IsRecord_ProtectTotalVol_Under(void)
{
	static uint8_t falg = 0;

	if(ProtectTotalVol_Under.Flag != falg)
	{
		falg = ProtectTotalVol_Under.Flag;
		ProtectTotalVol_Under.Flag == 1 ? WriteOneRecordForAlarm(RecordType_ProtectTotalVol_Under) : WriteOneRecordForAlarm(RecordType_ProtectTotalVol_UnderFree);
	}
}

void IsRecord_AlarmCellVol_Over(void)
{
	static uint8_t falg = 0;

	if(AlarmCellVol_Over.Flag != falg)
	{
		falg = AlarmCellVol_Over.Flag;
		AlarmCellVol_Over.Flag == 1 ? WriteOneRecordForAlarm(RecordType_AlarmCellVol_Over) : WriteOneRecordForAlarm(RecordType_AlarmCellVol_Over);
	}
}

void IsRecord_ProtectCellVol_Over(void)
{
	static uint8_t falg = 0;

	if(ProtectCellVol_Over.Flag != falg)
	{
		falg = ProtectCellVol_Over.Flag;
		ProtectCellVol_Over.Flag == 1 ? WriteOneRecordForAlarm(RecordType_ProtectCellVol_Over) : WriteOneRecordForAlarm(RecordType_ProtectCellVol_Over);
	}
}

void IsRecord_AlarmCellVol_Under(void)
{
	static uint8_t falg = 0;

	if(AlarmCellVol_Under.Flag != falg)
	{
		falg = AlarmCellVol_Under.Flag;
		AlarmCellVol_Under.Flag == 1 ? WriteOneRecordForAlarm(RecordType_AlarmCellVol_Under) : WriteOneRecordForAlarm(RecordType_AlarmCellVol_Under);
	}
}

void IsRecord_ProtectCellVol_Under(void)
{
	static uint8_t falg = 0;

	if(ProtectCellVol_Under.Flag != falg)
	{
		falg = ProtectCellVol_Under.Flag;
		ProtectCellVol_Under.Flag == 1 ? WriteOneRecordForAlarm(RecordType_ProtectCellVol_Under) : WriteOneRecordForAlarm(RecordType_ProtectCellVol_Under);
	}
}

void IsRecord_AlarmChgTemp_Over(void)
{
	static uint8_t falg = 0;

	if(AlarmChgTemp_Over.Flag != falg)
	{
		falg = AlarmChgTemp_Over.Flag;
		AlarmChgTemp_Over.Flag == 1 ? WriteOneRecordForAlarm(RecordType_AlarmChgTemp_Over) : WriteOneRecordForAlarm(RecordType_AlarmChgTemp_Over);
	}
}

void IsRecord_ProtectChgTemp_Over(void)
{
	static uint8_t falg = 0;

	if(ProtectChgTemp_Over.Flag != falg)
	{
		falg = ProtectChgTemp_Over.Flag;
		ProtectChgTemp_Over.Flag == 1 ? WriteOneRecordForAlarm(RecordType_ProtectChgTemp_Over) : WriteOneRecordForAlarm(RecordType_ProtectChgTemp_Over);
	}
}

void IsRecord_AlarmChgTemp_Under(void)
{
	static uint8_t falg = 0;

	if(AlarmChgTemp_Under.Flag != falg)
	{
		falg = AlarmChgTemp_Under.Flag;
		AlarmChgTemp_Under.Flag == 1 ? WriteOneRecordForAlarm(RecordType_AlarmChgTemp_Under) : WriteOneRecordForAlarm(RecordType_AlarmChgTemp_Under);
	}
}

void IsRecord_ProtectChgTemp_Under(void)
{
	static uint8_t falg = 0;

	if(ProtectChgTemp_Under.Flag != falg)
	{
		falg = ProtectChgTemp_Under.Flag;
		ProtectChgTemp_Under.Flag == 1 ? WriteOneRecordForAlarm(RecordType_ProtectChgTemp_Under) : WriteOneRecordForAlarm(RecordType_ProtectChgTemp_Under);
	}
}

void IsRecord_AlarmDchgTemp_Over(void)
{
	static uint8_t falg = 0;

	if(AlarmDchgTemp_Over.Flag != falg)
	{
		falg = AlarmDchgTemp_Over.Flag;
		AlarmDchgTemp_Over.Flag == 1 ? WriteOneRecordForAlarm(RecordType_AlarmDchgTemp_Over) : WriteOneRecordForAlarm(RecordType_AlarmDchgTemp_Over);
	}
}

void IsRecord_ProtectDchgTemp_Over(void)
{
	static uint8_t falg = 0;

	if(ProtectDchgTemp_Over.Flag != falg)
	{
		falg = ProtectDchgTemp_Over.Flag;
		ProtectDchgTemp_Over.Flag == 1 ? WriteOneRecordForAlarm(RecordType_ProtectDchgTemp_Over) : WriteOneRecordForAlarm(RecordType_ProtectDchgTemp_Over);
	}
}

void IsRecord_AlarmDchgTemp_Under(void)
{
	static uint8_t falg = 0;

	if(AlarmDchgTemp_Under.Flag != falg)
	{
		falg = AlarmDchgTemp_Under.Flag;
		AlarmDchgTemp_Under.Flag == 1 ? WriteOneRecordForAlarm(RecordType_AlarmDchgTemp_Under) : WriteOneRecordForAlarm(RecordType_AlarmDchgTemp_Under);
	}
}

void IsRecord_ProtectDchgTemp_Under(void)
{
	static uint8_t falg = 0;

	if(ProtectDchgTemp_Under.Flag != falg)
	{
		falg = ProtectDchgTemp_Under.Flag;
		ProtectDchgTemp_Under.Flag == 1 ? WriteOneRecordForAlarm(RecordType_ProtectDchgTemp_Under) : WriteOneRecordForAlarm(RecordType_ProtectDchgTemp_Under);
	}
}

void IsRecord_AlarmEnvirTemp_Over(void)
{
	static uint8_t falg = 0;

	if(AlarmEnvirTemp_Over.Flag != falg)
	{
		falg = AlarmEnvirTemp_Over.Flag;
		AlarmEnvirTemp_Over.Flag == 1 ? WriteOneRecordForAlarm(RecordType_AlarmEnvirTemp_Over) : WriteOneRecordForAlarm(RecordType_AlarmEnvirTemp_Over);
	}
}

void IsRecord_ProtectEnvirTemp_Over(void)
{
	static uint8_t falg = 0;

	if(ProtectEnvirTemp_Over.Flag != falg)
	{
		falg = ProtectEnvirTemp_Over.Flag;
		ProtectEnvirTemp_Over.Flag == 1 ? WriteOneRecordForAlarm(RecordType_ProtectEnvirTemp_Over) : WriteOneRecordForAlarm(RecordType_ProtectEnvirTemp_Over);
	}
}

void IsRecord_AlarmEnvirTemp_Under(void)
{
	static uint8_t falg = 0;

	if(AlarmEnvirTemp_Under.Flag != falg)
	{
		falg = AlarmEnvirTemp_Under.Flag;
		AlarmEnvirTemp_Under.Flag == 1 ? WriteOneRecordForAlarm(RecordType_AlarmEnvirTemp_Under) : WriteOneRecordForAlarm(RecordType_AlarmEnvirTemp_Under);
	}
}

void IsRecord_ProtectEnvirTemp_Under(void)
{
	static uint8_t falg = 0;

	if(ProtectEnvirTemp_Under.Flag != falg)
	{
		falg = ProtectEnvirTemp_Under.Flag;
		ProtectEnvirTemp_Under.Flag == 1 ? WriteOneRecordForAlarm(RecordType_ProtectEnvirTemp_Under) : WriteOneRecordForAlarm(RecordType_ProtectEnvirTemp_Under);
	}
}

void IsRecord_AlarmMOSTempOver(void)
{
	static uint8_t falg = 0;

	if(AlarmMOSTempOver.Flag != falg)
	{
		falg = AlarmMOSTempOver.Flag;
		AlarmMOSTempOver.Flag == 1 ? WriteOneRecordForAlarm(RecordType_AlarmMOSTempOver) : WriteOneRecordForAlarm(RecordType_AlarmMOSTempOver);
	}
}

void IsRecord_ProtectMOSTemp_Over(void)
{
	static uint8_t falg = 0;

	if(ProtectMOSTemp_Over.Flag != falg)
	{
		falg = ProtectMOSTemp_Over.Flag;
		ProtectMOSTemp_Over.Flag == 1 ? WriteOneRecordForAlarm(RecordType_ProtectMOSTemp_Over) : WriteOneRecordForAlarm(RecordType_ProtectMOSTemp_Over);
	}
}

void IsRecord_AlarmChgCurOver(void)
{
	static uint8_t falg = 0;

	if(AlarmChgCurOver.Flag != falg)
	{
		falg = AlarmChgCurOver.Flag;
		AlarmChgCurOver.Flag == 1 ? WriteOneRecordForAlarm(RecordType_AlarmChgCurOver) : WriteOneRecordForAlarm(RecordType_AlarmChgCurOver);
	}
}

void IsRecord_ProtectChgCur_Over(void)
{
	static uint8_t falg = 0;

	if(ProtectChgCur_Over.Flag != falg)
	{
		falg = ProtectChgCur_Over.Flag;
		ProtectChgCur_Over.Flag == 1 ? WriteOneRecordForAlarm(RecordType_ProtectChgCur_Over) : WriteOneRecordForAlarm(RecordType_ProtectChgCur_Over);
	}
}

void IsRecord_AlarmDchgCur_Over(void)
{
	static uint8_t falg = 0;

	if(AlarmDchgCur_Over.Flag != falg)
	{
		falg = AlarmDchgCur_Over.Flag;
		AlarmDchgCur_Over.Flag == 1 ? WriteOneRecordForAlarm(RecordType_AlarmDchgCur_Over) : WriteOneRecordForAlarm(RecordType_AlarmDchgCur_Over);
	}
}

void IsRecord_ProtectDchgCur_L1_Over(void)
{
	static uint8_t falg = 0;

	if(ProtectDchgCur_L1_Over.Flag != falg)
	{
		falg = ProtectDchgCur_L1_Over.Flag;
		ProtectDchgCur_L1_Over.Flag == 1 ? WriteOneRecordForAlarm(RecordType_ProtectDchgCur_L1_Over) : WriteOneRecordForAlarm(RecordType_ProtectDchgCur_L1_Over);
	}
}

void IsRecord_ProtectDchgCur_L2_Over(void)
{
	static uint8_t falg = 0;

	if(ProtectDchgCur_L2_Over.Flag != falg)
	{
		falg = ProtectDchgCur_L2_Over.Flag;
		ProtectDchgCur_L2_Over.Flag == 1 ? WriteOneRecordForAlarm(RecordType_ProtectDchgCur_L2_Over) : WriteOneRecordForAlarm(RecordType_ProtectDchgCur_L2_Over);
	}
}

void IsRecord_AlarmDiffVol_Over(void)
{
	static uint8_t falg = 0;

	if(AlarmDiffVol_Over.Flag != falg)
	{
		falg = AlarmDiffVol_Over.Flag;
		AlarmDiffVol_Over.Flag == 1 ? WriteOneRecordForAlarm(RecordType_AlarmDiffVol_Over) : WriteOneRecordForAlarm(RecordType_AlarmDiffVol_Over);
	}
}

void IsRecord_ProtectDiffVol_Over(void)
{
	static uint8_t falg = 0;

	if(ProtectDiffVol_Over.Flag != falg)
	{
		falg = ProtectDiffVol_Over.Flag;
		ProtectDiffVol_Over.Flag == 1 ? WriteOneRecordForAlarm(RecordType_ProtectDiffVol_Over) : WriteOneRecordForAlarm(RecordType_ProtectDiffVol_Over);
	}
}


void IsRecord_SystemStateChange(void)
{
	static enumSystemState LastState = SystemState_Null;

	if(BMSInfo.SystemState != LastState)
	{

		if(BMSInfo.SystemState == SystemState_Chging && LastState != SystemState_Chging)
			WriteOneRecordForRun(RecordType_StartChg);

		if(BMSInfo.SystemState != SystemState_Chging && LastState == SystemState_Chging)
			WriteOneRecordForRun(RecordType_FinshChg);


		if(BMSInfo.SystemState == SystemState_Dchging && LastState != SystemState_Dchging)
			WriteOneRecordForRun(RecordType_StartDchg);

		if(BMSInfo.SystemState != SystemState_Dchging && LastState == SystemState_Dchging)
			WriteOneRecordForRun(RecordType_FinshDchg);


		LastState = BMSInfo.SystemState;
	}
}


void IsRecord_Timing(void)
{


}


void WriteRecordForAlarm(void)
{
	IsRecord_AlarmTotalVol_Over();
	IsRecord_ProtectTotalVol_Over();
	IsRecord_AlarmTotalVol_Under();
	IsRecord_ProtectTotalVol_Under();
	IsRecord_AlarmCellVol_Over();
	IsRecord_ProtectCellVol_Over();
	IsRecord_AlarmCellVol_Under();
	IsRecord_ProtectCellVol_Under();
	IsRecord_AlarmChgTemp_Over();
	IsRecord_ProtectChgTemp_Over();
	IsRecord_AlarmChgTemp_Under();
	IsRecord_ProtectChgTemp_Under();
	IsRecord_AlarmDchgTemp_Over();
	IsRecord_ProtectDchgTemp_Over();
	IsRecord_AlarmDchgTemp_Under();
	IsRecord_ProtectDchgTemp_Under();
	IsRecord_AlarmEnvirTemp_Over();
	IsRecord_ProtectEnvirTemp_Over();
	IsRecord_AlarmEnvirTemp_Under();
	IsRecord_ProtectEnvirTemp_Under();
	IsRecord_AlarmMOSTempOver();
	IsRecord_ProtectMOSTemp_Over();
	IsRecord_AlarmChgCurOver();
	IsRecord_ProtectChgCur_Over();
	IsRecord_AlarmDchgCur_Over();
	IsRecord_ProtectDchgCur_L1_Over();
	IsRecord_ProtectDchgCur_L2_Over();
	IsRecord_AlarmDiffVol_Over();
	IsRecord_ProtectDiffVol_Over();
}



void WriteRecordForRun(void)
{
	IsRecord_SystemStateChange();
	IsRecord_Timing();
}






void ResetRecord(void)
{
	AlarmRecordInfo.TotalRecordNum 	= 0;
	AlarmRecordInfo.FristRecordAddr = 0;
	AlarmRecordInfo.LastRecordAddr 	= 0;

	RunRecordInfo.TotalRecordNum 	= 0;
	RunRecordInfo.FristRecordAddr 	= 0;
	RunRecordInfo.LastRecordAddr 	= 0;
}






