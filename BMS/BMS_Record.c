#include "BMS_Record.h"











void WriteOneRecord(enumRecordType type)
{

}




void IsRecord_AlarmTotalVol_Over(void)
{
	static uint8_t falg = 0;

	if(AlarmTotalVol_Over.Flag != falg)
	{
		falg = AlarmTotalVol_Over.Flag;
		AlarmTotalVol_Over.Flag == 1 ? WriteOneRecord(RecordType_AlarmTotalVol_Over) : WriteOneRecord(RecordType_AlarmTotalVol_OverFree);
	}
}

void IsRecord_ProtectTotalVol_Over(void)
{
	static uint8_t falg = 0;

	if(ProtectTotalVol_Over.Flag != falg)
	{
		falg = ProtectTotalVol_Over.Flag;
		ProtectTotalVol_Over.Flag == 1 ? WriteOneRecord(RecordType_ProtectTotalVol_Over) : WriteOneRecord(RecordType_ProtectTotalVol_OverFree);
	}
}

void IsRecord_AlarmTotalVol_Under(void)
{
	static uint8_t falg = 0;

	if(AlarmTotalVol_Under.Flag != falg)
	{
		falg = AlarmTotalVol_Under.Flag;
		AlarmTotalVol_Under.Flag == 1 ? WriteOneRecord(RecordType_AlarmTotalVol_Under) : WriteOneRecord(RecordType_AlarmTotalVol_UnderFree);
	}
}

void IsRecord_ProtectTotalVol_Under(void)
{
	static uint8_t falg = 0;

	if(ProtectTotalVol_Under.Flag != falg)
	{
		falg = ProtectTotalVol_Under.Flag;
		ProtectTotalVol_Under.Flag == 1 ? WriteOneRecord(RecordType_ProtectTotalVol_Under) : WriteOneRecord(RecordType_ProtectTotalVol_UnderFree);
	}
}

void IsRecord_AlarmCellVol_Over(void)
{
	static uint8_t falg = 0;

	if(AlarmCellVol_Over.Flag != falg)
	{
		falg = AlarmCellVol_Over.Flag;
		AlarmCellVol_Over.Flag == 1 ? WriteOneRecord(RecordType_AlarmCellVol_Over) : WriteOneRecord(RecordType_AlarmCellVol_Over);
	}
}

void IsRecord_ProtectCellVol_Over(void)
{
	static uint8_t falg = 0;

	if(ProtectCellVol_Over.Flag != falg)
	{
		falg = ProtectCellVol_Over.Flag;
		ProtectCellVol_Over.Flag == 1 ? WriteOneRecord(RecordType_ProtectCellVol_Over) : WriteOneRecord(RecordType_ProtectCellVol_Over);
	}
}

void IsRecord_AlarmCellVol_Under(void)
{
	static uint8_t falg = 0;

	if(AlarmCellVol_Under.Flag != falg)
	{
		falg = AlarmCellVol_Under.Flag;
		AlarmCellVol_Under.Flag == 1 ? WriteOneRecord(RecordType_AlarmCellVol_Under) : WriteOneRecord(RecordType_AlarmCellVol_Under);
	}
}

void IsRecord_ProtectCellVol_Under(void)
{
	static uint8_t falg = 0;

	if(ProtectCellVol_Under.Flag != falg)
	{
		falg = ProtectCellVol_Under.Flag;
		ProtectCellVol_Under.Flag == 1 ? WriteOneRecord(RecordType_ProtectCellVol_Under) : WriteOneRecord(RecordType_ProtectCellVol_Under);
	}
}

void IsRecord_AlarmChgTemp_Over(void)
{
	static uint8_t falg = 0;

	if(AlarmChgTemp_Over.Flag != falg)
	{
		falg = AlarmChgTemp_Over.Flag;
		AlarmChgTemp_Over.Flag == 1 ? WriteOneRecord(RecordType_AlarmChgTemp_Over) : WriteOneRecord(RecordType_AlarmChgTemp_Over);
	}
}

void IsRecord_ProtectChgTemp_Over(void)
{
	static uint8_t falg = 0;

	if(ProtectChgTemp_Over.Flag != falg)
	{
		falg = ProtectChgTemp_Over.Flag;
		ProtectChgTemp_Over.Flag == 1 ? WriteOneRecord(RecordType_ProtectChgTemp_Over) : WriteOneRecord(RecordType_ProtectChgTemp_Over);
	}
}

void IsRecord_AlarmChgTemp_Under(void)
{
	static uint8_t falg = 0;

	if(AlarmChgTemp_Under.Flag != falg)
	{
		falg = AlarmChgTemp_Under.Flag;
		AlarmChgTemp_Under.Flag == 1 ? WriteOneRecord(RecordType_AlarmChgTemp_Under) : WriteOneRecord(RecordType_AlarmChgTemp_Under);
	}
}

void IsRecord_ProtectChgTemp_Under(void)
{
	static uint8_t falg = 0;

	if(ProtectChgTemp_Under.Flag != falg)
	{
		falg = ProtectChgTemp_Under.Flag;
		ProtectChgTemp_Under.Flag == 1 ? WriteOneRecord(RecordType_ProtectChgTemp_Under) : WriteOneRecord(RecordType_ProtectChgTemp_Under);
	}
}

void IsRecord_AlarmDchgTemp_Over(void)
{
	static uint8_t falg = 0;

	if(AlarmDchgTemp_Over.Flag != falg)
	{
		falg = AlarmDchgTemp_Over.Flag;
		AlarmDchgTemp_Over.Flag == 1 ? WriteOneRecord(RecordType_AlarmDchgTemp_Over) : WriteOneRecord(RecordType_AlarmDchgTemp_Over);
	}
}

void IsRecord_ProtectDchgTemp_Over(void)
{
	static uint8_t falg = 0;

	if(ProtectDchgTemp_Over.Flag != falg)
	{
		falg = ProtectDchgTemp_Over.Flag;
		ProtectDchgTemp_Over.Flag == 1 ? WriteOneRecord(RecordType_ProtectDchgTemp_Over) : WriteOneRecord(RecordType_ProtectDchgTemp_Over);
	}
}

void IsRecord_AlarmDchgTemp_Under(void)
{
	static uint8_t falg = 0;

	if(AlarmDchgTemp_Under.Flag != falg)
	{
		falg = AlarmDchgTemp_Under.Flag;
		AlarmDchgTemp_Under.Flag == 1 ? WriteOneRecord(RecordType_AlarmDchgTemp_Under) : WriteOneRecord(RecordType_AlarmDchgTemp_Under);
	}
}

void IsRecord_ProtectDchgTemp_Under(void)
{
	static uint8_t falg = 0;

	if(ProtectDchgTemp_Under.Flag != falg)
	{
		falg = ProtectDchgTemp_Under.Flag;
		ProtectDchgTemp_Under.Flag == 1 ? WriteOneRecord(RecordType_ProtectDchgTemp_Under) : WriteOneRecord(RecordType_ProtectDchgTemp_Under);
	}
}

void IsRecord_AlarmEnvirTemp_Over(void)
{
	static uint8_t falg = 0;

	if(AlarmEnvirTemp_Over.Flag != falg)
	{
		falg = AlarmEnvirTemp_Over.Flag;
		AlarmEnvirTemp_Over.Flag == 1 ? WriteOneRecord(RecordType_AlarmEnvirTemp_Over) : WriteOneRecord(RecordType_AlarmEnvirTemp_Over);
	}
}

void IsRecord_ProtectEnvirTemp_Over(void)
{
	static uint8_t falg = 0;

	if(ProtectEnvirTemp_Over.Flag != falg)
	{
		falg = ProtectEnvirTemp_Over.Flag;
		ProtectEnvirTemp_Over.Flag == 1 ? WriteOneRecord(RecordType_ProtectEnvirTemp_Over) : WriteOneRecord(RecordType_ProtectEnvirTemp_Over);
	}
}

void IsRecord_AlarmEnvirTemp_Under(void)
{
	static uint8_t falg = 0;

	if(AlarmEnvirTemp_Under.Flag != falg)
	{
		falg = AlarmEnvirTemp_Under.Flag;
		AlarmEnvirTemp_Under.Flag == 1 ? WriteOneRecord(RecordType_AlarmEnvirTemp_Under) : WriteOneRecord(RecordType_AlarmEnvirTemp_Under);
	}
}

void IsRecord_ProtectEnvirTemp_Under(void)
{
	static uint8_t falg = 0;

	if(ProtectEnvirTemp_Under.Flag != falg)
	{
		falg = ProtectEnvirTemp_Under.Flag;
		ProtectEnvirTemp_Under.Flag == 1 ? WriteOneRecord(RecordType_ProtectEnvirTemp_Under) : WriteOneRecord(RecordType_ProtectEnvirTemp_Under);
	}
}

void IsRecord_AlarmMOSTempOver(void)
{
	static uint8_t falg = 0;

	if(AlarmMOSTempOver.Flag != falg)
	{
		falg = AlarmMOSTempOver.Flag;
		AlarmMOSTempOver.Flag == 1 ? WriteOneRecord(RecordType_AlarmMOSTempOver) : WriteOneRecord(RecordType_AlarmMOSTempOver);
	}
}

void IsRecord_ProtectMOSTemp_Over(void)
{
	static uint8_t falg = 0;

	if(ProtectMOSTemp_Over.Flag != falg)
	{
		falg = ProtectMOSTemp_Over.Flag;
		ProtectMOSTemp_Over.Flag == 1 ? WriteOneRecord(RecordType_ProtectMOSTemp_Over) : WriteOneRecord(RecordType_ProtectMOSTemp_Over);
	}
}

void IsRecord_AlarmChgCurOver(void)
{
	static uint8_t falg = 0;

	if(AlarmChgCurOver.Flag != falg)
	{
		falg = AlarmChgCurOver.Flag;
		AlarmChgCurOver.Flag == 1 ? WriteOneRecord(RecordType_AlarmChgCurOver) : WriteOneRecord(RecordType_AlarmChgCurOver);
	}
}

void IsRecord_ProtectChgCur_Over(void)
{
	static uint8_t falg = 0;

	if(ProtectChgCur_Over.Flag != falg)
	{
		falg = ProtectChgCur_Over.Flag;
		ProtectChgCur_Over.Flag == 1 ? WriteOneRecord(RecordType_ProtectChgCur_Over) : WriteOneRecord(RecordType_ProtectChgCur_Over);
	}
}

void IsRecord_AlarmDchgCur_Over(void)
{
	static uint8_t falg = 0;

	if(AlarmDchgCur_Over.Flag != falg)
	{
		falg = AlarmDchgCur_Over.Flag;
		AlarmDchgCur_Over.Flag == 1 ? WriteOneRecord(RecordType_AlarmDchgCur_Over) : WriteOneRecord(RecordType_AlarmDchgCur_Over);
	}
}

void IsRecord_ProtectDchgCur_L1_Over(void)
{
	static uint8_t falg = 0;

	if(ProtectDchgCur_L1_Over.Flag != falg)
	{
		falg = ProtectDchgCur_L1_Over.Flag;
		ProtectDchgCur_L1_Over.Flag == 1 ? WriteOneRecord(RecordType_ProtectDchgCur_L1_Over) : WriteOneRecord(RecordType_ProtectDchgCur_L1_Over);
	}
}

void IsRecord_ProtectDchgCur_L2_Over(void)
{
	static uint8_t falg = 0;

	if(ProtectDchgCur_L2_Over.Flag != falg)
	{
		falg = ProtectDchgCur_L2_Over.Flag;
		ProtectDchgCur_L2_Over.Flag == 1 ? WriteOneRecord(RecordType_ProtectDchgCur_L2_Over) : WriteOneRecord(RecordType_ProtectDchgCur_L2_Over);
	}
}

void IsRecord_AlarmDiffVol_Over(void)
{
	static uint8_t falg = 0;

	if(AlarmDiffVol_Over.Flag != falg)
	{
		falg = AlarmDiffVol_Over.Flag;
		AlarmDiffVol_Over.Flag == 1 ? WriteOneRecord(RecordType_AlarmDiffVol_Over) : WriteOneRecord(RecordType_AlarmDiffVol_Over);
	}
}

void IsRecord_ProtectDiffVol_Over(void)
{
	static uint8_t falg = 0;

	if(ProtectDiffVol_Over.Flag != falg)
	{
		falg = ProtectDiffVol_Over.Flag;
		ProtectDiffVol_Over.Flag == 1 ? WriteOneRecord(RecordType_ProtectDiffVol_Over) : WriteOneRecord(RecordType_ProtectDiffVol_Over);
	}
}


void WriteRecordForAlarm(void)
{

}



void WriteRecordForRun(void)
{
	//判断是否需要存记录



	//存记录


}













