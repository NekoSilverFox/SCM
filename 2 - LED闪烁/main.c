#include <reg52.h>

sbit LED = P2^0;
typedef unsigned char u8;
typedef unsigned int u16;

void delay(u16 i)
{
	while(i--);
}

void main()
{
	while(1)
	{
	 	LED = 0;
		delay(20000);
		LED = 1;
		delay(50000);
	}
}