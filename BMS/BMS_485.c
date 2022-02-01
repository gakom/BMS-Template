#include "BMS_485.h"
#include "BMS_UpperComputerProtocol.h"





uint8_t tx485[256];
uint16_t txlen;
uint8_t rx485[256];
uint16_t rxlen;

void Comm485Pro(void)
{
	UpperComputerProtocolPro(tx485,txlen,rx485,&rxlen);
}


