#include <msp430.h> 
#include "util.h"
/*
 * main.c
 */
//tactl defines
#define SMCLK	BV(9)
#define DIV_1	0
#define DIV_2	BV(6)
#define DIV_4	BV(7)
#define DIV_8	BV(6) | BV(7)
#define UP_MODE		BV(4)
#define CONT_MODE	BV(5)
//tacctlx defines
#define CMP_MODE	0
#define CPT_MODE	BV(8)
#define TOG			BV(7)
#define	OUT_HIGH	BV(2)

int main(void) {
    WDTCTL = WDTPW | WDTHOLD;	// Stop watchdog timer
	P1DIR |= BV(1);


	//set timer 0
	//TACCR0 = 0x8000;
	TACCR1 = 0x1000;
	//TACCR2 = 0x80;
	TACTL = SMCLK | DIV_8 | CONT_MODE;
	//TACCTL0 = CMP_MODE | TOG | OUT_HIGH;
	TACCTL1 = CMP_MODE | TOG | OUT_HIGH;
	P1DIR |= BV(6);
	P1SEL |= BV(6);



	int i;
	while(1){
	
		//P1OUT ^= BV(6);
		for(i=0;i<10000;i++);
	}
	return 0;
}
