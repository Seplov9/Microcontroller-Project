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

//��ʱ��+�ж�

void Timer0_Init()		//100΢��@11.0592MHz
{
	TMOD &= 0xF0;		//���ö�ʱ��ģʽ
	TMOD |= 0x01;		//���ö�ʱ��ģʽ
	TL0 = 0xA4;		//���ö�ʱ��ʼֵ
	TH0 = 0xFF;		//���ö�ʱ��ʼֵ
	TF0 = 0;		//���TF0��־
	TR0 = 1;		//��ʱ��0��ʼ��ʱ
	ET0 = 1;  //��ʱ��0�ж�������
	EA = 1;  //��ʱ���ܿ���
	PT0 = 0;  //��ʱ��0�ж����ȼ�
}



void Timer0_Routine() interrupt 1  //�жϺ���
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