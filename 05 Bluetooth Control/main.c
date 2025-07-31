#include <REGX52.H>
#include "car.h"

unsigned char receiveData;  //接收到的数据存放变量

void receive(unsigned char m)  //执行函数
{
	 switch(m)
		{
			case '2':       //前进
			car_go ();
			break;
			
		  case '4':       //向前左转
			car_leftgo ();
			break;
			
		  case '6':       //向前右转
		  car_rightgo ();
			break;
			
			case '8':       //后退
		  car_back ();
			break;
			
		  case '5':       //停止
		  car_stop ();
		  break;
			
			case '7':       //原地左拐
		  car_leftstop ();
		  break;
						
			case '9':       //原地右拐
		  car_rightstop ();
		  break;
		}
}
void Uart_Init()		//9600bps@11.0592MHz
{
	PCON=0x00;    //关倍频 
	SCON = 0x50;		//8位数据,可变波特率
	TMOD = 0x20;		//设置定时器模式
	TL1 = 0xFd;		//设置定时初始值
	TH1 = 0xFd;		//设置定时初始值
	ET1 = 0;		//禁止定时器1中断
	TR1 = 1;		//定时器1开始计时
	EA=1;  //总中断
	ES=1;  //打开串口中断
}
void Uart_Routine() interrupt 4      //中断函数
{
	car_stop ();
	RI = 0;                   //清除接收中断标志位
	receiveData=SBUF;         //出去接收到的数据
	receive(receiveData);
}
void main ()
{
	Timer0_Init();
	Uart_Init();
	while (1);
}