#include <REGX51.H>

sbit IN11 = P0^5;  //左前轮位点
sbit IN12 = P0^6;

sbit IN13 = P0^3;  //右前轮
sbit IN14 = P0^4;

sbit IN21 = P3^5;  //左后轮
sbit IN22 = P3^6;

sbit IN23 = P3^3;  //右后轮
sbit IN24 = P3^4;


void main ()
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

//中文乱码
//判断车轮位置


