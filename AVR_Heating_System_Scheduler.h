/*
 * AVR_Heating_System_Scheduler.h
 *
 *  Created on: Dec 1, 2014
 *      Author: sherpa
 */

#ifndef AVR_HEATING_SYSTEM_SCHEDULER_H_
#define AVR_HEATING_SYSTEM_SCHEDULER_H_



#include <avr/io.h>
#include <avr/interrupt.h>
#include <avr/sleep.h>



#include <AVR_USART_lib.h>
#include <AVR_ADC_lib.h>



#undef PDEBUG_INIT
#undef PDEBUG



#ifdef DEBUG
	#define PDEBUG_INIT( BR ) USART_Init( BR )
	// no need of a terminal \n. put by default
	#define PDEBUG( ... ) printf( __VA_ARGS__ )
#else /* DEBUG */
	#define PDEBUG_INIT( BR ) /* not debugging: nothing */
	#define PDEBUG( ... ) /* not debugging: nothing */
#endif /* DEBUG */



#endif /* AVR_HEATING_SYSTEM_SCHEDULER_H_ */
