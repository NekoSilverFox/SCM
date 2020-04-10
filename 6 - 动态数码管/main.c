#include <reg52.h>

typedef unsigned int u16;

sbit LSA = P2^2;
sbit LSB = P2^3;
sbit LSC = P2^4;

u16 smgduan[] = {0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,
			  0x7f,0x6f,0x77,0x7c,0x39,0x5e,0x79,0x71};

void delay(u16 i )
{
	while(i--);
}

void LEDDisplay()
{
	static u16 i;
	for(i = 0; i < 8 ; i++)
	{
		switch(i)  // 位选 - 选择点亮的数码管
		{
		case 0 : LSA = 0; LSB = 0; LSC = 0; break;
		case 1 : LSA = 1; LSB = 0; LSC = 0; break;
		case 2 : LSA = 0; LSB = 1; LSC = 0; break;
		case 3 : LSA = 1; LSB = 1; LSC = 0; break;
		case 4 : LSA = 0; LSB = 0; LSC = 1; break;
		case 5 : LSA = 1; LSB = 0; LSC = 1; break;
		case 6 : LSA = 0; LSB = 1; LSC = 1; break;
		case 7 : LSA = 1; LSB = 1; LSC = 1; break;
		}

		P0 = smgduan[i]; // 发送段码
		delay(7000);	// 间隔一段时间扫描
		P0 = 0x00; // 消隐

	}

}

void main()
{
	while(1)
	{
   		LEDDisplay();
	}
}