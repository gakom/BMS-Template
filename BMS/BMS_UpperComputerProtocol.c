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





static uint8_t ProcotolReadParam(uint16_t addr,uint8_t *buff)
{

}




static void ProcotolReadParams(uint8_t* rx,uint16_t rxlen,uint8_t* tx,uint16_t* txlen)
{
	uint16_t crc;
	uint8_t i;
	uint8_t	dat_cnt;
	uint8_t dat_len;
	uint16_t dat_addr;
	uint8_t* buff;

	if (rxlen == rx[3] && rx[3] == 9)
	{
		dat_addr = rx[4] | rx[3];
		dat_cnt  = rx[6];

		buff = tx + 7;

		dat_len = 0;
		for(i = 0;i < dat_cnt;i++)
		{
			dat_len += ProcotolReadParam(dat_addr + i,buff);
		}

		tx[0] = PROCOTOL_SOI;	//SOI
		tx[1] = rx[1];			//DID
		tx[2] = rx[2];			//CID
		tx[3] = dat_len + 9;	//长度
		tx[4] = rx[4];			//参数起始地址
		tx[5] = rx[5];			//参数起始地址
		tx[6] = rx[6];			//参数个数
		//参数内容
		crc = UpperComputerProcotolCRC16(&rx[1],dat_len + 6);
		tx[7 + dat_len] = crc & 0xff;	//crc
		tx[8 + dat_len] = crc >> 8;		//crc
		
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
			break;
		case PROCOTOL_CID_READ_RECORD:
			break;
		default:
			break;
	}
}



