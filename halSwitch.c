/*
 * halSwitch.c
 *
 *  Created on: Feb 23, 2015
 *      Author: peter
 */

#include <msp430.h>
#include "util.h"
#include "halSwitch.h"
#include "halLED.h"

void switchInit(void){
	//direction
	P1DIR &= BV(0);
	//enable pull up
	P1REN |= BV(0);
	P1OUT |= BV(0);

	//IO function
	P1SEL &= BV(0);
	P1SEL2 &= BV(0);

	//falling edge triggered
	P1IES |= BV(0);

	//enable the interrupt
	P1IE |= BV(0);

}

#if defined(__TI_COMPILER_VERSION__) || defined(__IAR_SYSTEMS_ICC__)
#pragma vector=PORT1_VECTOR
__interrupt void Port1_ISR(void)
#elif defined(__GNUC__)
void __attribute__ ((interrupt(PORT1_VECTOR))) Port1_ISR (void)
#else
#error Compiler not supported!
#endif
{
	static int level = 50;
	level += 10;
	if(level >100)
		level = 0;

	halFade(LED1, level);

	//clear IF
	P1IFG = 0;
}
