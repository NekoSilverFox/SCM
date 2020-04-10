#include <reg52.h>
#include <intrins.h>

#define LED P2

sbit beep = P1^5;

typedef unsigned char u8;
typedef unsigned int u16;

void delay(u16 i)
{
	while(i--);
}

void rang(u16 time, u16 frequency)
{
	while(time--)
	{
		beep = ~beep;
		delay(frequency);
	}
}

void main()
{
	u16 i;
	u16 j;
	while(1)
	{

		// LED = 0;	  
		LED = 0xfe;	   // 1111 1110
		for(i = 0; i < 7; i++)
		{
			LED = _crol_(LED, 1);
			delay(10000);
		}
		for(i = 0; i < 7; i++)
		{
			LED = _cror_(LED, 1);
			delay(10000);
		}
//		LED = 0;
//		delay(10000);
//		LED = 1;
//		delay(30000);

		
		for(j = 10; j < 200; j++)
		{
		  rang(5, j);
		}
		for(j = 200; j > 10; j--)
		{
			rang(5, j);
		}
		
	}
}