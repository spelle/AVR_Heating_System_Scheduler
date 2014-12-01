/*
 * AVR_Heating_System_Scheduler.c
 *
 *  Created on: Nov 30, 2014
 *      Author: sherpa
 */

#include "AVR_Heating_System_Scheduler.h"

int main( void )
{
	// Set Port B Data Direction Register
	DDRB	|= (1<<DDB5) ; // For LED on Pin PORTB5
	// Set Port D Data Direction Register
	DDRD	|= (1<<DDD5) ; // For LED on Pin PORTD5

	// Configure the Timer/Counter1 Control Register A
	TCCR1A	= 0 ;
	// Configure the Timer/Counter1 Control Register B
	TCCR1B	= (1 << WGM12) ; // Configure timer 1 for CTC mode
	TIMSK1	= (1 << OCIE1A); // Enable CTC interrupt
	OCR1A	= 62499 ; // Set CTC compare value to 1Hz at 1MHz AVR clock, with a prescaler of 64
	sei(); //  Enable global interrupts

	PDEBUG_INIT( 9600 ) ;

	TCCR1B |= (1 << CS12) ; // Start timer at Fcpu/64

	while( 1 )
	{
		sleep_mode();
	}

	return( 0 ) ;
}
