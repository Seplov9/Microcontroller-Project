/**********���������ת**********/
/*															*/
/*LF��ǰ  RF��ǰ  LR���  RR�Һ�*/
/*															*/
/**********���������ת**********/

#include <REGX52.H>
//λ����
sbit IN11 = P0^5;//��ǰ
sbit IN12 = P0^6;
sbit IN13 = P0^3;//��ǰ
sbit IN14 = P0^4;
sbit IN21 = P3^5;//���
sbit IN22 = P3^6;
sbit IN23 = P3^3;//�Һ�
sbit IN24 = P3^4;

void LF_motor_go ()    //��ǰ�����ת
{IN11 = 0;IN12 = 1;}
void LF_motor_back ()  //��ǰ�����ת
{IN11 = 1;IN12 = 0;}
void LF_motor_stop ()  //��ǰ���ֹͣ
{IN11 = 1;IN12 = 1;}
void RF_motor_go ()    //��ǰ�����ת
{IN13 = 0;IN14 = 1;}
void RF_motor_back ()  //��ǰ�����ת
{IN13 = 1;IN14 = 0;}
void RF_motor_stop ()  //��ǰ���ֹͣ
{IN13 = 1;IN14 = 1;}
void LR_motor_go ()    //�������ת
{IN21 = 1;IN22 = 0;}
void LR_motor_back ()  //�������ת
{IN21 = 0;IN22 = 1;}
void LR_motor_stop ()  //�����ֹͣ
{IN21 = 1;IN22 = 1;}
void RR_motor_go ()    //�Һ�����ת
{IN23 = 1;IN24 = 0;}
void RR_motor_back ()  //�Һ�����ת
{IN23 = 0;IN24 = 1;}
void RR_motor_stop ()  //�Һ���ֹͣ
{IN23 = 1;IN24 = 1;}



