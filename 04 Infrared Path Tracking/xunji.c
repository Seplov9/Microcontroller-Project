#include <REGX52.H>
#include "car.h"
#include <intrins.h>

sbit D1 = P2^7;
sbit D2 = P2^6;
sbit D3 = P2^5;
sbit D4 = P2^4;

void Delay50ms()		//@11.0592MHz
{
	unsigned char i, j;

	i = 90;
	j = 163;
	do
	{
		while (--j);
	} while (--i);
}


void xunji ()
{
	if(D1==1&&D2==1&&D3==1&&D4==1)  //ȫ��⵽����
	{car_go ();}
	if(D1==0&&D2==1&&D3==0&&D4==0)  //�м��Ҳ��⵽���ߣ�С��ƫ��С�������ƶ�
	{
		car_rightgo ();
		if(D1==0&&D2==0&&D3==0&&D4==0)
		{car_go ();}
	}
	if(D1==0&&D2==0&&D3==1&&D4==0)  //�м�����⵽���ߣ�С��ƫ�ң�С�������ƶ�
	{
		car_leftgo ();
		if(D1==0&&D2==0&&D3==0&&D4==0)
		{car_go ();}
	}
	if(D1==0&&D2==0&&D3==1&&D4==1)  //ֱ�����
	{
		car_go ();
		Delay50ms();
		if(D1==0&&D2==0&&D3==0&&D4==0)
		{
			car_stop();
			Delay50ms();
			car_leftstop ();
		}
	}
	if(D1==1&&D2==1&&D3==0&&D4==0)  //ֱ���ҹ�
	{
		car_go ();
		Delay50ms();
		if(D1==0&&D2==0&&D3==0&&D4==0)
		{
			car_stop();
			Delay50ms();
			car_rightstop ();
		}
	}
	if((D1==0&&D2==0&&D3==0&&D4==1)||(D1==0&&D2==1&&D3==0&&D4==1)||(D1==0&&D2==1&&D3==1&&D4==1))  //������
	{
		car_go ();
		Delay50ms();
		Delay50ms();
		if(D1==0&&D2==0&&D3==0&&D4==0)
		{
			car_stop();
			Delay50ms();
			car_leftstop ();
		}
	}	
	if((D1==1&&D2==0&&D3==0&&D4==0)||(D1==1&&D2==0&&D3==1&&D4==0)||(D1==1&&D2==1&&D3==1&&D4==0))  //����ҹ�
	{
		car_go ();
		Delay50ms();
		Delay50ms();
		if(D1==0&&D2==0&&D3==0&&D4==0)
		{
			car_stop();
			Delay50ms();
			car_rightstop ();
		}
	}
	if(D1==0&&D2==1&&D3==1&&D4==0)
	{
		if(D1==1)
		{
			car_rightstop ();
		}
	}
	
	if(D1==0&&D2==1&&D3==1&&D4==0)
	{
		if(D4==1)
		{
			car_rightstop ();
		}
	}
	
}

