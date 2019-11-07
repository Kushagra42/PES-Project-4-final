/*
 * @file Delay_Function.c
 * author: kushagra Pandey & Vaidehi Salway
 * Date:10/14/2019
 *
 * This .c file contains a function to generate a delay
 */

#include "Delay_Function.h"


// Constant multiplier based on the clock frequency of frdm board
uint32_t cons_val=4000000;
uint32_t j=0;
extern uint32_t milli_sec_val;
int count=0;

/* This is a delay function with a parameter milli_sec_val
 * delay calculations are based on the clock frequency to
 * generate a delay equivalent to user input through delay function.
 */
void Delay_Time(uint32_t milli_sec_val)
{
	uint32_t Ticks_value= (cons_val * milli_sec_val)/(500);

	for( j=0;j<=Ticks_value;j++);

}


int TimeOut_Counter(int Time_out)
{
	int count1=0;
	for(count=0;count<(Time_out);count++)
	{
		count1=count1+1;
	}

return count1;

}




