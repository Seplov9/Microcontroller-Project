#include "car.h"
#include "xunji.h"

void main ()
{
	Timer0_Init();
	car_go ();
	while (1)
	{
		xunji ();
	}
}