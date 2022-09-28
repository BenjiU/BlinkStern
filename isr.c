//----------------------------------------------------------------------
// Titel : Interrupthandler
//----------------------------------------------------------------------
#define F_CPU 3686400 // Taktfrequenz / Frequency
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

//Program
#include "ILED.h"
#include "AttinyLED.h"
#include "IBlinkProgram.h"
#include "BlinkeLicht.h"

extern BlinkeLicht* gBL;
extern bool sleeping;

uint16_t sleepcounter = 0;

void isr_enable_int0()
{
    DDRB  &= ~(1 << PB2);   // set PB2/INT0 of Port B as input
    PORTB |= (1 << PB2);   // activate pullup PB2/INT0
   
    GIMSK |= (1<<INT0);   //Enable External Interrupts INT0
    MCUCR &= ~((1 << ISC01) | (1 << ISC00));  //Configure INT0 active low level triggered
}


void isr_enable_timer0()
{
    TCCR0B = (1<<CS02)|(0<<CS00);       // Start Timer 0 with prescaler 1024
    TIMSK  = (1<<TOIE0);                // Enable Timer 0 overflow interrupt
}

ISR (INT0_vect)          //External interrupt_zero ISR
{
    sleepcounter = 0;   //reset sleepcounter

    if(sleeping) {
        gBL->start();
        sleeping = false;
    } else {
        gBL->next();
    }
    
    //debouncing
    _delay_ms(10);
    do {
        //Wait until INT0 is released
    } while((PINB & (1<<PB2)) == 0);
    _delay_ms(10);
}

ISR (TIMER0_OVF_vect)
{
    gBL->step();
    
    //go to sleep after no button pressed
    sleepcounter++;
    if(sleepcounter == 0x00FF) {
        //deep sleep mode;
        gBL->stop();
        sleeping = true;
    }
}
