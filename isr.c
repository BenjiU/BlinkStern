//----------------------------------------------------------------------
// Titel : Interrupthandler
//----------------------------------------------------------------------
#include <avr/interrupt.h>
#include "BlinkeStern.h"
extern BlinkeStern BS;

ISR (TIMER0_OVF_vect)
{
    static uint8_t scaler = 0;
    scaler++;
    if(scaler == 10) {
        PORTB ^=0x01;
        scaler = 0;
        BS.onNotifyButtonPressed();
    }
}
