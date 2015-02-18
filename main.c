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
//reset when you hit tccrx, reset when you hit tccr0
#define RST_SET		BV(7) | BV(6) | BV(5)
#define SET_RST		BV(6) | BV(5)
#define	OUT_HIGH	BV(2)

#define uint8		unsigned char
#define int8		signed char
#define uint16		unsigned short
#define int16		signed short

#define LED1		1
#define LED2		2

#define LED1_dir	P1DIR
#define LED2_dir	P1DIR
#define LED1_bit	BV(1)
#define LED1_sel		P1SEL

void halFade(uint8 LED, uint8 duty);

int main(void) {
    WDTCTL = WDTPW | WDTHOLD;	// Stop watchdog timer
	P1DIR |= BV(1);


	//set timer 0
	TACCR0 = 100;
	TACCR1 = 10;
	//TACCR2 = 0x80;
	TACTL = SMCLK | DIV_8 | UP_MODE;
	//TACCTL0 = CMP_MODE | TOG | OUT_HIGH;
	TACCTL1 = CMP_MODE | RST_SET | OUT_HIGH;
	P1DIR |= BV(6);
	P1SEL |= BV(6);



	int i;
	while(1){
	
		//P1OUT ^= BV(6);
		for(i=0;i<10000;i++);
	}
}

void halFadeInt(void){
	//io settings
	LED1_dir |= LED1_bit;
	LED1_sel |= LED1_bit;

	//set timer period for 100 and pwdm settings
	TACCR0 = 100;
	TACCR1 = 101;
	TACCR2 = 101;
	TACTL = SMCLK | DIV_8 | UP_MODE;
	TACCTL1 = CMP_MODE | SET_RST | OUT_HIGH;

}
void halFade(uint8 LED, uint8 duty){


}
