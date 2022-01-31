#ifndef _UPPERCOMPUTERPROTOCOL_H_
#define _UPPERCOMPUTERPROTOCOL_H_

#include "includes.h"
#include "BMS_Parameter.h"


#define PROCOTOL_SIZE				(255)

#define PROCOTOL_SOI				(0x7E)
#define PROCOTOL_DID_RADIO			(0x00)
#define PROCOTOL_DID_BMS			(0x01)

//功能码
#define PROCOTOL_CID_OTA_HANDSHAKE	(0x01)	//升级握手
#define PROCOTOL_CID_OTA_TRANSFER	(0x02)	//升级数据传输
#define PROCOTOL_CID_OTA_COMPLETE	(0x03)	//升级完成
#define PROCOTOL_CID_WRITE_PARAMS	(0x04)	//设置一个或多个参数
#define PROCOTOL_CID_READ_PARAMS	(0x05)	//读取一个或多个参数
#define PROCOTOL_CID_READ_RECORD	(0x06)	//读取故障记录

//返回值
#define PROCOTOL_RES_SUCCESS		(0)	//正常
#define PROCOTOL_RES_EXEC_ERR		(1)	//指令执行失败
#define PROCOTOL_RES_FORMAT_ERR		(2)	//指令格式错误
#define PROCOTOL_RES_DATA_ERR		(3)	//数据错误
#define PROCOTOL_RES_DATA_INVALID	(4)	//数据无效
#define PROCOTOL_RES_BUSY			(5)	//设备忙
#define PROCOTOL_RES_OTHER			(6)	//其他错误

#endif

