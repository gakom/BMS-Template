#include "BMS_UpperComputerProtocol.h"
#include <stdbool.h>

static uint16_t UpperComputerProcotolCRC16(uint8_t *buf,uint8_t Length)
{
	uint16_t i,k,c = 0xFFFF;

	for(k = 0;k < Length;k++)
	{
		uint16_t b = buf[k];
		for(i = 0;i < 8;i++)
		{
			c = ((b^c)&1) ? ((c>>1)^0xA001) : (c>>1);
			b >>= 1;
		}
	}

	return c;
}


bool IsUpperComputerProtocol(uint8_t* rx,uint16_t rxlen)
{
	uint16_t crc1,crc2;

	if (rxlen < 6 || rxlen > 255 || rx == NULL)
		return false;

	if (rx[0] != PROCOTOL_SOI)
		return false;
	
	if (rx[1] != PROCOTOL_DID_BMS && rx[1] != PROCOTOL_DID_RADIO)
		return false;

	crc1 = rx[rxlen-1] | rx[rxlen-2];
	crc2 = UpperComputerProcotolCRC16(&rx[1],rxlen-3);

	if (crc1 != crc2)
		return false;
	
	return true;
}


// static uint16_t ProcotolRespone(uint8_t DID,uint8_t CID,uint8_t err,uint8_t *pCmdOut,uint16_t CmdOutMaxLen)
// {
// 	uint16_t rtnLen = 0;
// 	uint16_t CRC16;

// 	pCmdOut[rtnLen++] = PROCOTOL_SOI;
// 	pCmdOut[rtnLen++] = DID;
// 	pCmdOut[rtnLen++] = CID;
// 	pCmdOut[rtnLen++] = 7;
// 	pCmdOut[rtnLen++] = err;
// 	CRC16 = UpperComputerProcotolCRC16(&pCmdOut[1],4);


// 	LITTLE_BUFFER16(pCmdOut,rtnLen,CRC16);
	
// 	return rtnLen;
// }





static uint8_t ProcotolReadParam(uint16_t addr,uint8_t *buff,uint8_t leftlen)
{
	uint8_t len = 0,i;

	switch(addr)
	{
		case 0:
			if(leftlen >= 1)
			{
				buff[len++] = BMSInfo.SystemState;
			}
			break;
		case 1:
			if(leftlen >= 2)
			{
				buff[len++] = BMSInfo.TotalVol & 0xff;
				buff[len++] = BMSInfo.TotalVol >> 8 & 0xff;
			}
			break;
		case 2:
			if(leftlen >= 2)
			{
				buff[len++] = (BMSInfo.Current + 30000) & 0xff;
				buff[len++] = (BMSInfo.Current + 30000) >> 8 & 0xff;
			}
		case 3:
			if(leftlen >= 1)
			{
				buff[len++] = BMSInfo.SOC;
			}
			break;
		case 4:
			if(leftlen >= 1)
			{
				buff[len++] = BMSInfo.SOH;
			}
			break;
		case 5:
			if(leftlen >= 1)
			{
				buff[len++] = BMSInfo.BMS_Cell_Numer;
			}
			break;
		case 6:
			if(leftlen >= 2 * BMSInfo.BMS_Cell_Numer)
			{
				for(i = 0;i < BMSInfo.BMS_Cell_Numer;i++)
				{
					buff[len++] = BMSInfo.CellVol[i] & 0xff;
					buff[len++] = BMSInfo.CellVol[i] >> 8 & 0xff;
				}	
			}
			break;
		case 7:
			if(leftlen >= 2)
			{
				buff[len++] = BMSInfo.MaxCellVol & 0xff;
				buff[len++] = BMSInfo.MaxCellVol >> 8 & 0xff;
			}
			break;
		case 8:
			if(leftlen >= 2)
			{
				buff[len++] = BMSInfo.MinCellVol & 0xff;
				buff[len++] = BMSInfo.MinCellVol >> 8 & 0xff;
			}
			break;
		case 9:
			if(leftlen >= 1)
			{
				buff[len++] = BMSInfo.MaxCellVolNum;
			}
			break;
		case 10:
			if(leftlen >= 1)
			{
				buff[len++] = BMSInfo.MinCellVolNum;
			}
			break;
		case 11:
			if(leftlen >= 1)
			{
				buff[len++] = BMSInfo.BMS_Temp_Numer;
			}
			break;
		case 12:
			if(leftlen >= BMSInfo.BMS_Temp_Numer)
			{
				for(i = 0;i < BMSInfo.BMS_Temp_Numer;i++)
				{
					buff[len++] = BMSInfo.CellTemp[i] / 10 + 40;
				}	
			}
			break;
		case 13:
			if(leftlen >= 1)
			{
				buff[len++] = BMSInfo.MaxCellTemp / 10 + 40;
			}
			break;
		case 14:
			if(leftlen >= 1)
			{
				buff[len++] = BMSInfo.MinCellTemp / 10 + 40;
			}
			break;
		case 15:
			if(leftlen >= 1)
			{
				buff[len++] = BMSInfo.MaxCellTempNum;
			}
			break;
		case 16:
			if(leftlen >= 1)
			{
				buff[len++] = BMSInfo.MinCellTempNum;
			}
			break;
		case 17:
			if(leftlen >= 1)
			{
				buff[len++] = BMSInfo.EnvirTmep / 10 + 40;
			}
			break;
		case 18:
			if(leftlen >= 1)
			{
				buff[len++] = BMSInfo.MOSTmep / 10 + 40;
			}
			break;
		case 19:
			break;
		case 20:
			break;
		case 21:
			if(leftlen >= 2)
			{
				buff[len++] = BMSInfo.CycleCount & 0xff;
				buff[len++] = BMSInfo.CycleCount >> 8 & 0xff;
			}
			break;


		case 1000:
			if(leftlen >= 2)
			{
				buff[len++] = BMS_HardwareVer & 0xff;
				buff[len++] = BMS_HardwareVer >> 8 & 0xff;
			}
			break;
		case 1001:
			if(leftlen >= 2)
			{
				buff[len++] = BMS_SoftwareVer & 0xff;
				buff[len++] = BMS_SoftwareVer >> 8 & 0xff;
			}
			break;
		case 1002:
			break;
		case 1003:
			if(leftlen >= 4)
			{
				buff[len++] = BMSInfo.CurKCoef & 0xff;
				buff[len++] = BMSInfo.CurKCoef >> 8 & 0xff;
				buff[len++] = BMSInfo.CurKCoef >> 16 & 0xff;
				buff[len++] = BMSInfo.CurKCoef >> 24 & 0xff;
			}
			break;
		case 1004:
			if(leftlen >= 4)
			{
				buff[len++] = BMSInfo.CurBCoef & 0xff;
				buff[len++] = BMSInfo.CurBCoef >> 8 & 0xff;
				buff[len++] = BMSInfo.CurBCoef >> 16 & 0xff;
				buff[len++] = BMSInfo.CurBCoef >> 24 & 0xff;
			}
			break;
		case 1005:
			break;
		case 1006:
			if(leftlen >= 2)
			{
				buff[len++] = UpperComputerProcotolVer & 0xff;
				buff[len++] = UpperComputerProcotolVer >> 8 & 0xff;
			}
			break;
		case 1007:
			break;
		case 1008:
			break;
		case 1100:
			if(leftlen >= 32)
			{
				memcpy(buff,BMSInfo.BatteryID,32);
				leftlen += 32;
			}
			break;
		case 1101:
			break;
		case 1102:
			if(leftlen >= 1)
			{
				buff[len++] = BMSInfo.BMS_Cell_Numer;
			}
			break;
		case 1103:
			if(leftlen >= 1)
			{
				buff[len++] = BMSInfo.BMS_Temp_Numer;
			}
			break;
		case 1104:
			break;
		case 1105:
			break;
		case 1106:
			if(leftlen >= 1)
			{
				buff[len++] = BMSInfo.FuncSwitch.Heat;
			}
			break;
		case 1107:
			break;
		case 1108:
			break;
		case 1109:
			if(leftlen >= 1)
			{
				buff[len++] = BMSInfo.FuncSwitch.Balance;
			}
			break;
		case 1110:
			if(leftlen >= 2)
			{
				buff[len++] = Balance.StartVol & 0xff;
				buff[len++] = Balance.StartVol >> 8 & 0xff;
			}
			break;
		case 1111:
			if(leftlen >= 2)
			{
				buff[len++] = Balance.StopVol & 0xff;
				buff[len++] = Balance.StopVol >> 8 & 0xff;
			}
			break;
		case 1112:
			if(leftlen >= 2)
			{
				buff[len++] = Balance.StartDiffVol & 0xff;
				buff[len++] = Balance.StartDiffVol >> 8 & 0xff;
			}
			break;
		case 1113:
			break;
		case 1114:
			if(leftlen >= 2)
			{
				buff[len++] = FaultCellInvalid_Out.TriggerL & 0xff;
				buff[len++] = FaultCellInvalid_Out.TriggerL >> 8 & 0xff;
			}
			break;
		case 1115:
			if(leftlen >= 2)
			{
				buff[len++] = FaultCellInvalid_Out.TriggerH & 0xff;
				buff[len++] = FaultCellInvalid_Out.TriggerH >> 8 & 0xff;
			}
			break;
		case 1120:
			if(leftlen >= 64)
			{
				memcpy(buff,BMSInfo.ServerIPAddr,64);
				leftlen += 64;
			}
			break;
		case 1121:
			if(leftlen >= 2)
			{
				buff[len++] = BMSInfo.ServerPort & 0xff;
				buff[len++] = BMSInfo.ServerPort >> 8 & 0xff;
			}
			break;


		case 2000:
			if(leftlen >= 2)
			{
				buff[len++] = AlarmTotalVol_Over.Trigger & 0xff;
				buff[len++] = AlarmTotalVol_Over.Trigger >> 8 & 0xff;
			}
			break;
		case 2001:
			if(leftlen >= 2)
			{
				buff[len++] = AlarmTotalVol_Over.Recovery & 0xff;
				buff[len++] = AlarmTotalVol_Over.Recovery >> 8 & 0xff;
			}
			break;

		case 2002:
			if(leftlen >= 2)
			{
				buff[len++] = ProtectTotalVol_Over.Trigger & 0xff;
				buff[len++] = ProtectTotalVol_Over.Trigger >> 8 & 0xff;
			}
			break;
		case 2003:
			if(leftlen >= 2)
			{
				buff[len++] = ProtectTotalVol_Over.Recovery & 0xff;
				buff[len++] = ProtectTotalVol_Over.Recovery >> 8 & 0xff;
			}
			break;

		case 2004:
			if(leftlen >= 2)
			{
				buff[len++] = AlarmTotalVol_Under.Trigger & 0xff;
				buff[len++] = AlarmTotalVol_Under.Trigger >> 8 & 0xff;
			}
			break;
		case 2005:
			if(leftlen >= 2)
			{
				buff[len++] = AlarmTotalVol_Under.Recovery & 0xff;
				buff[len++] = AlarmTotalVol_Under.Recovery >> 8 & 0xff;
			}
			break;

		case 2006:
			if(leftlen >= 2)
			{
				buff[len++] = ProtectTotalVol_Under.Trigger & 0xff;
				buff[len++] = ProtectTotalVol_Under.Trigger >> 8 & 0xff;
			}
			break;
		case 2007:
			if(leftlen >= 2)
			{
				buff[len++] = ProtectTotalVol_Under.Recovery & 0xff;
				buff[len++] = ProtectTotalVol_Under.Recovery >> 8 & 0xff;
			}
			break;

		case 2008:
			if(leftlen >= 2)
			{
				buff[len++] = AlarmCellVol_Over.Trigger & 0xff;
				buff[len++] = AlarmCellVol_Over.Trigger >> 8 & 0xff;
			}
			break;
		case 2009:
			if(leftlen >= 2)
			{
				buff[len++] = AlarmCellVol_Over.Recovery & 0xff;
				buff[len++] = AlarmCellVol_Over.Recovery >> 8 & 0xff;
			}
			break;

		case 2010:
			if(leftlen >= 2)
			{
				buff[len++] = ProtectCellVol_Over.Trigger & 0xff;
				buff[len++] = ProtectCellVol_Over.Trigger >> 8 & 0xff;
			}
			break;
		case 2011:
			if(leftlen >= 2)
			{
				buff[len++] = ProtectCellVol_Over.Recovery & 0xff;
				buff[len++] = ProtectCellVol_Over.Recovery >> 8 & 0xff;
			}
			break;

		case 2012:
			if(leftlen >= 2)
			{
				buff[len++] = AlarmCellVol_Under.Trigger & 0xff;
				buff[len++] = AlarmCellVol_Under.Trigger >> 8 & 0xff;
			}
			break;
		case 2013:
			if(leftlen >= 2)
			{
				buff[len++] = AlarmCellVol_Under.Recovery & 0xff;
				buff[len++] = AlarmCellVol_Under.Recovery >> 8 & 0xff;
			}
			break;
		
		case 2014:
			if(leftlen >= 2)
			{
				buff[len++] = ProtectCellVol_Under.Trigger & 0xff;
				buff[len++] = ProtectCellVol_Under.Trigger >> 8 & 0xff;
			}
			break;
		case 2015:
			if(leftlen >= 2)
			{
				buff[len++] = ProtectCellVol_Under.Recovery & 0xff;
				buff[len++] = ProtectCellVol_Under.Recovery >> 8 & 0xff;
			}
			break;

		case 2016:
			if(leftlen >= 2)
			{
				buff[len++] = AlarmChgTemp_Over.Trigger & 0xff;
				buff[len++] = AlarmChgTemp_Over.Trigger >> 8 & 0xff;
			}
			break;
		case 2017:
			if(leftlen >= 2)
			{
				buff[len++] = AlarmChgTemp_Over.Recovery & 0xff;
				buff[len++] = AlarmChgTemp_Over.Recovery >> 8 & 0xff;
			}
			break;

		case 2018:
			if(leftlen >= 2)
			{
				buff[len++] = ProtectChgTemp_Over.Trigger & 0xff;
				buff[len++] = ProtectChgTemp_Over.Trigger >> 8 & 0xff;
			}
			break;
		case 2019:
			if(leftlen >= 2)
			{
				buff[len++] = ProtectChgTemp_Over.Recovery & 0xff;
				buff[len++] = ProtectChgTemp_Over.Recovery >> 8 & 0xff;
			}
			break;

		case 2020:
			if(leftlen >= 2)
			{
				buff[len++] = AlarmChgTemp_Under.Trigger & 0xff;
				buff[len++] = AlarmChgTemp_Under.Trigger >> 8 & 0xff;
			}
			break;
		case 2021:
			if(leftlen >= 2)
			{
				buff[len++] = AlarmChgTemp_Under.Recovery & 0xff;
				buff[len++] = AlarmChgTemp_Under.Recovery >> 8 & 0xff;
			}
			break;

		case 2022:
			if(leftlen >= 2)
			{
				buff[len++] = ProtectChgTemp_Under.Trigger & 0xff;
				buff[len++] = ProtectChgTemp_Under.Trigger >> 8 & 0xff;
			}
			break;
		case 2023:
			if(leftlen >= 2)
			{
				buff[len++] = ProtectChgTemp_Under.Recovery & 0xff;
				buff[len++] = ProtectChgTemp_Under.Recovery >> 8 & 0xff;
			}
			break;

		case 2024:
			if(leftlen >= 2)
			{
				buff[len++] = AlarmDchgTemp_Over.Trigger & 0xff;
				buff[len++] = AlarmDchgTemp_Over.Trigger >> 8 & 0xff;
			}
			break;
		case 2025:
			if(leftlen >= 2)
			{
				buff[len++] = AlarmDchgTemp_Over.Recovery & 0xff;
				buff[len++] = AlarmDchgTemp_Over.Recovery >> 8 & 0xff;
			}
			break;

		case 2026:
			if(leftlen >= 2)
			{
				buff[len++] = ProtectDchgTemp_Over.Trigger & 0xff;
				buff[len++] = ProtectDchgTemp_Over.Trigger >> 8 & 0xff;
			}
			break;
		case 2027:
			if(leftlen >= 2)
			{
				buff[len++] = ProtectDchgTemp_Over.Recovery & 0xff;
				buff[len++] = ProtectDchgTemp_Over.Recovery >> 8 & 0xff;
			}
			break;

		case 2028:
			if(leftlen >= 2)
			{
				buff[len++] = AlarmDchgTemp_Under.Trigger & 0xff;
				buff[len++] = AlarmDchgTemp_Under.Trigger >> 8 & 0xff;
			}
			break;
		case 2029:
			if(leftlen >= 2)
			{
				buff[len++] = AlarmDchgTemp_Under.Recovery & 0xff;
				buff[len++] = AlarmDchgTemp_Under.Recovery >> 8 & 0xff;
			}
			break;

		case 2030:
			if(leftlen >= 2)
			{
				buff[len++] = ProtectDchgTemp_Under.Trigger & 0xff;
				buff[len++] = ProtectDchgTemp_Under.Trigger >> 8 & 0xff;
			}
			break;
		case 2031:
			if(leftlen >= 2)
			{
				buff[len++] = ProtectDchgTemp_Under.Recovery & 0xff;
				buff[len++] = ProtectDchgTemp_Under.Recovery >> 8 & 0xff;
			}
			break;

		case 2032:
			if(leftlen >= 2)
			{
				buff[len++] = AlarmEnvirTemp_Over.Trigger & 0xff;
				buff[len++] = AlarmEnvirTemp_Over.Trigger >> 8 & 0xff;
			}
			break;
		case 2033:
			if(leftlen >= 2)
			{
				buff[len++] = AlarmEnvirTemp_Over.Recovery & 0xff;
				buff[len++] = AlarmEnvirTemp_Over.Recovery >> 8 & 0xff;
			}
			break;

		case 2034:
			if(leftlen >= 2)
			{
				buff[len++] = ProtectEnvirTemp_Over.Trigger & 0xff;
				buff[len++] = ProtectEnvirTemp_Over.Trigger >> 8 & 0xff;
			}
			break;
		case 2035:
			if(leftlen >= 2)
			{
				buff[len++] = ProtectEnvirTemp_Over.Recovery & 0xff;
				buff[len++] = ProtectEnvirTemp_Over.Recovery >> 8 & 0xff;
			}
			break;

		case 2036:
			if(leftlen >= 2)
			{
				buff[len++] = AlarmEnvirTemp_Under.Trigger & 0xff;
				buff[len++] = AlarmEnvirTemp_Under.Trigger >> 8 & 0xff;
			}
			break;
		case 2037:
			if(leftlen >= 2)
			{
				buff[len++] = AlarmEnvirTemp_Under.Recovery & 0xff;
				buff[len++] = AlarmEnvirTemp_Under.Recovery >> 8 & 0xff;
			}
			break;

		case 2038:
			if(leftlen >= 2)
			{
				buff[len++] = ProtectEnvirTemp_Under.Trigger & 0xff;
				buff[len++] = ProtectEnvirTemp_Under.Trigger >> 8 & 0xff;
			}
			break;
		case 2039:
			if(leftlen >= 2)
			{
				buff[len++] = ProtectEnvirTemp_Under.Recovery & 0xff;
				buff[len++] = ProtectEnvirTemp_Under.Recovery >> 8 & 0xff;
			}
			break;
		default:
			break;
	}


	return len;
}




static void ProcotolReadParams(uint8_t* rx,uint16_t rxlen,uint8_t* tx,uint16_t* txlen)
{
	uint16_t crc;
	uint8_t i;
	
	uint8_t	dat_cnt;			//参数个数
	uint8_t dat_val_len = 0;	//参数内容所占空间
	uint16_t dat_addr;			//参数地址

	uint8_t temp;
	uint8_t leftlen = PROCOTOL_SIZE - 9;	//剩余数据空间

	if (rxlen == rx[3] && rx[3] == 9)	//长度校验没问题
	{
		dat_addr = rx[4] | rx[3];	//参数地址
		dat_cnt  = rx[6];			//参数个数

		for(i = 0;i < dat_cnt;i++)
		{
			//返回当前地址的数据所占的空间大小
			temp = ProcotolReadParam((dat_addr + i) , (tx + 7 + dat_val_len) , (leftlen));

			if(temp == 0 || leftlen < temp)//剩余空间 < 当前地址的数据所占的空间大小
				break;

			dat_val_len += temp;	//参数内容占了多少空间
			leftlen 	-= temp; 	//计算还可以发送多少个参数
		}

		if(dat_val_len <= PROCOTOL_SIZE - 9)
		{
			tx[0] = PROCOTOL_SOI;	//SOI
			tx[1] = rx[1];			//DID
			tx[2] = rx[2];			//CID
			tx[3] = dat_val_len + 9;	//长度
			tx[4] = rx[4];			//参数起始地址
			tx[5] = rx[5];			//参数起始地址
			tx[6] = rx[6];			//参数个数
			//参数内容
			crc = UpperComputerProcotolCRC16(&rx[1],dat_val_len + 6);
			tx[7 + dat_val_len] = crc & 0xff;	//crc
			tx[8 + dat_val_len] = crc >> 8;		//crc			
		}
	}
}






void UpperComputerProtocolPro(uint8_t* rx,uint16_t rxlen,uint8_t* tx,uint16_t* txlen)
{
	switch(rx[2])
	{
		case PROCOTOL_CID_OTA_HANDSHAKE:
			break;
		case PROCOTOL_CID_OTA_TRANSFER:
			break;
		case PROCOTOL_CID_OTA_COMPLETE:
			break;
		case PROCOTOL_CID_WRITE_PARAMS:
			break;
		case PROCOTOL_CID_READ_PARAMS:
			ProcotolReadParams(rx,rxlen,tx,txlen);
			break;
		case PROCOTOL_CID_READ_RECORD:
			break;
		default:
			break;
	}
}



