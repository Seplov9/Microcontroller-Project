/************小车移动方向*************/
/* 向前直行【四电机正转】			   		 */
/* 向后直行【四电机反转】			  		 */
/* 向前左拐【右电机正转，左电机停止】*/
/* 向前右拐【右电机停止，左电机正转】*/
/* 向后左拐【右电机反转，左电机停止】*/
/* 向后右拐【右电机停止，左电机反转】*/
/* 停    止【四电机停止】		       	 */
/************小车移动方向*************/

#include <REGX52.H>
#include "motor.h"

sbit EN1A = P0^7;//左前
sbit EN1B = P0^2;//右前
sbit EN2A = P3^7;//左后
sbit EN2B = P3^2;//右后

unsigned char counter1,speed;	//计数值和比较值，用于输出PWM

void Timer0_Init()		//100微秒@11.0592MHz
{
	TMOD = 0x11;	//设置定时器模式
	TL0 = 0xA4;		//设置定时初始值
	TH0 = 0xFF;		//设置定时初始值
	TF0 = 0;			//清除TF0标志
	TR0 = 1;			//定时器0开始计时
	ET0 = 1;      //定时器0的中端允许开关
	EA  = 1;      //定时器总开关
	PT0 = 1;      //设置定时器为高低控制优先级，1为高优先级，0为低优先级
}
void Timer0_Routine() interrupt 1  //中断函数
{

	TL0 = 0xA4;		//设置定时初始值
	TH0 = 0xFF;		//设置定时初始值
	
	counter1++;
	if (counter1 >= 100)
	{
		counter1 = 0;
	}
	if (counter1 < speed)
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
void car_go ()        //小车向前直行
{
	speed = 20;
	LF_motor_go ();
	RF_motor_go ();
	LR_motor_go ();
	RR_motor_go ();
}
void car_back ()      //小车向后直行
{
	speed = 18;
	LF_motor_back ();
	RF_motor_back ();
	LR_motor_back ();
	RR_motor_back ();
}
void car_stop ()      //小车停止
{
	speed = 0;
	RR_motor_stop ();
	LR_motor_stop ();
	RF_motor_stop ();
	LF_motor_stop ();
}
void car_leftgo ()    //小车向前左拐
{
	speed = 18;
	RF_motor_go ();
	RR_motor_go ();
	LF_motor_stop ();
	LR_motor_stop ();
}
void car_rightgo ()   //小车向前右拐
{
	speed = 18;
	LF_motor_go ();
	LR_motor_go ();
	RF_motor_stop ();
	RR_motor_stop ();
}
void car_leftback ()  //小车向后左拐
{
	speed = 18;
	RR_motor_back ();
	RF_motor_back ();
	LF_motor_stop ();
	LR_motor_stop ();
}
void car_rightback () //小车向后右拐	
{
	speed = 18;
	LF_motor_back ();
	LR_motor_back ();
	RF_motor_stop ();
	RR_motor_stop ();
}
void car_rightstop () //小车原地右拐
{
	speed = 20;
	LF_motor_go ();
	LR_motor_go ();
	RF_motor_back ();
	RR_motor_back ();
}
void car_leftstop () //小车原地左拐
{
	speed = 20;
	LF_motor_back ();
	LR_motor_back ();
	RF_motor_go ();
	RR_motor_go ();
}