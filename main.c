/*
 * main.c
 */

#include <msp430.h>
#include "util.h"
#include "halLED.h"
#include "halSwitch.h"

int main(void) {
    WDTCTL = WDTPW | WDTHOLD;	// Stop watchdog timer

    switchInit();

	halFadeInit();
	halFade(LED1, 0);

	//global interrupt
	_BIS_SR(GIE);

	while(1);
}

