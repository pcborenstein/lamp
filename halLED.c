/*
 * halLED.c
 *
 *  Created on: Feb 18, 2015
 *      Author: peter
 */
#include <msp430.h>
#include "util.h"
#include "halLED.h"


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


#define LED1_dir	P1DIR
#define LED2_dir	P1DIR
#define LED1_bit	BV(6)
#define LED1_sel	P1SEL

void halFadeInit(void){
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

uint8 halFade(uint8 LED, uint8 duty){
	uint8 ret = SUCCESS;

	if(duty <= 100){

		uint8 set = 101 - duty;

		switch(LED){
		case LED1:
			TACCR1 = set;
		break;
		default:
			ret = 1;
		break;
		}
	}else{
		ret = 1;
	}
	return ret;
}
