/*
 * halLED.h
 *
 *  Created on: Feb 18, 2015
 *      Author: peter
 */

#ifndef HALLED_H_
#define HALLED_H_


#define LED1		1
#define LED2		2


extern uint8 halFade(uint8 LED, uint8 duty);

extern void halFadeInit(void);



#endif /* HALLED_H_ */
