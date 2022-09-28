//----------------------------------------------------------------------
// Titel : myAVR Beispiel "LED an" fuer den ATmega8 / LED on for ATmega8
//----------------------------------------------------------------------
// Funktion : LED wird angeschalten / LED is turned on
// Schaltung : PortB.0=LED1
//----------------------------------------------------------------------
#define F_CPU 3686400 // Taktfrequenz / Frequency
#include <avr/io.h>
#include <avr/interrupt.h>
#include <avr/sleep.h>

//Program
#include "ILED.h"
#include "AttinyLED.h"

#include "IBlinkProgram.h"
#include "BPLeuchten.h"
#include "BPBlinken.h"

#include "BlinkeLicht.h"

void isr_enable_int0();
void isr_enable_timer0();

BlinkeLicht* gBL;
volatile bool sleeping = true;
//----------------------------------------------------------------------
int main()
{
   
    AttinyLED ATLEDGruen(PB1);   
    AttinyLED ATLEDBlau(PB4);
    AttinyLED ATLEDRot(PB0);
   
    ILED* LEDGruen = &ATLEDGruen;
    ILED* LEDBlau = &ATLEDBlau;
    ILED* LEDRot = &ATLEDRot;
    
    ILED* LEDs[3];
    LEDs[0] = &ATLEDRot;
    LEDs[1] = LEDGruen;
    LEDs[2] = LEDBlau;

    BlinkeLicht BL;

    BPLeuchten ProgramLeuchten(LEDs);
    BL.addProgramm(&ProgramLeuchten);

    BPBlinken  ProgramBlinkenSchnell(LEDs,1);
    BL.addProgramm(&ProgramBlinkenSchnell);

    BPBlinken  ProgramBlinkenLangsam(LEDs,10);
    BL.addProgramm(&ProgramBlinkenLangsam);
   
    gBL = &BL;

    isr_enable_int0();
    isr_enable_timer0();
    
    GIFR |= (1<<INTF0);
    sei();
    
    do
	{
        if(sleeping) {
            MCUCR |= (1 << SM1) & ~(1 << SM0); // Sleep-Modus = Power Down
            MCUCR |= (1 << SE); // set sleep enable
            sleep_cpu(); // sleep
            MCUCR &= ~(1 << SE); // reset sleep enable
        }
	}
	while (true);
}
//----------------------------------------------------------------------
extern "C" void __cxa_pure_virtual() { while (1); } //exception handler

