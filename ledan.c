//----------------------------------------------------------------------
// Titel : myAVR Beispiel "LED an" fuer den ATmega8 / LED on for ATmega8
//----------------------------------------------------------------------
// Funktion : LED wird angeschalten / LED is turned on
// Schaltung : PortB.0=LED1
//----------------------------------------------------------------------
#define F_CPU 3686400 // Taktfrequenz / Frequency
#include <avr/io.h>
#include "timer.h"
#include "BlinkeStern.h"

BlinkeStern BS;

//----------------------------------------------------------------------
int main()
{
    timer0_start();
    timer0_interrupt_enable();

    BS.start();
    
    do
	{
        
	}
	while (true);
}
//----------------------------------------------------------------------

