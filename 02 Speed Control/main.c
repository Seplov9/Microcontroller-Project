#include <REGX51.H>

sbit IN11 = P0^5;
sbit IN12 = P0^6;
sbit IN13 = P0^3;
sbit IN14 = P0^4;
sbit IN21 = P3^5;
sbit IN22 = P3^6;
sbit IN23 = P3^3;
sbit IN24 = P3^4;

sbit EN1A = P0^7;
sbit EN1B = P0^2;
sbit EN2A = P3^7;
sbit EN2B = P3^2;

unsigned char counter,compare;

void car_go ()
{
	IN11 = 0;
	IN12 = 1;
	IN13 = 0;
	IN14 = 1;
	IN21 = 1;
	IN22 = 0;
	IN23 = 1;
	IN24 = 0;
}

//定时器+中断

void Timer0_Init()		//100微秒@11.0592MHz
{
	TMOD &= 0xF0;		//设置定时器模式
	TMOD |= 0x01;		//设置定时器模式
	TL0 = 0xA4;		//设置定时初始值
	TH0 = 0xFF;		//设置定时初始值
	TF0 = 0;		//清除TF0标志
	TR0 = 1;		//定时器0开始计时
	ET0 = 1;  //定时器0中断允许开关
	EA = 1;  //定时器总开关
	PT0 = 0;  //定时器0中断优先级
}



void Timer0_Routine() interrupt 1  //中断函数
{

	TL0 = 0xA4;		
	TH0 = 0xFF;		
	compare = 13;
	counter++;
	if (counter >= 100)
	{
		counter = 0;
	}
	if (counter < compare)
	{
		EN1A = 1;
		EN1B = 1;
		EN2A = 1;
		EN2B = 1;
	}
	else
	{
		EN1A = 0;
		EN1B = 0;
		EN2A = 0;
		EN2B = 0;
	}
}

void main ()
{
	Timer0_Init();
	
	while (1)
	{
		car_go ();
	}
}