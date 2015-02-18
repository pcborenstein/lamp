#include <msp430.h> 
#include "util.h"
#include "halLED.h"
/*
 * main.c
 */


int main(void) {
    WDTCTL = WDTPW | WDTHOLD;	// Stop watchdog timer

	halFadeInit();
	halFade(LED1, 50);

	int i, j;
	j = 0;
	while(1){
		j += 1;
		if(j>100)
			j = 1;

		halFade(LED1, j);
		for(i=0;i<5000;i++);
	}
}
