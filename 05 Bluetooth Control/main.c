#include <REGX52.H>
#include "car.h"

unsigned char receiveData;  //���յ������ݴ�ű���

void receive(unsigned char m)  //ִ�к���
{
	 switch(m)
		{
			case '2':       //ǰ��
			car_go ();
			break;
			
		  case '4':       //��ǰ��ת
			car_leftgo ();
			break;
			
		  case '6':       //��ǰ��ת
		  car_rightgo ();
			break;
			
			case '8':       //����
		  car_back ();
			break;
			
		  case '5':       //ֹͣ
		  car_stop ();
		  break;
			
			case '7':       //ԭ�����
		  car_leftstop ();
		  break;
						
			case '9':       //ԭ���ҹ�
		  car_rightstop ();
		  break;
		}
}
void Uart_Init()		//9600bps@11.0592MHz
{
	PCON=0x00;    //�ر�Ƶ 
	SCON = 0x50;		//8λ����,�ɱ䲨����
	TMOD = 0x20;		//���ö�ʱ��ģʽ
	TL1 = 0xFd;		//���ö�ʱ��ʼֵ
	TH1 = 0xFd;		//���ö�ʱ��ʼֵ
	ET1 = 0;		//��ֹ��ʱ��1�ж�
	TR1 = 1;		//��ʱ��1��ʼ��ʱ
	EA=1;  //���ж�
	ES=1;  //�򿪴����ж�
}
void Uart_Routine() interrupt 4      //�жϺ���
{
	car_stop ();
	RI = 0;                   //��������жϱ�־λ
	receiveData=SBUF;         //��ȥ���յ�������
	receive(receiveData);
}
void main ()
{
	Timer0_Init();
	Uart_Init();
	while (1);
}