//----------------------------------------------------------------------
// Titel : myAVR Beispiel "LED an" fuer den ATmega8 / LED on for ATmega8
//----------------------------------------------------------------------
// Funktion : LED wird angeschalten / LED is turned on
// Schaltung : PortB.0=LED1
//----------------------------------------------------------------------
#define F_CPU 3686400 // Taktfrequenz / Frequency
#include <avr/io.h>
#include "timer.h"

//Program
#include "ILED.h"
#include "AttinyLED.h"

#include "IBlinkProgram.h"
#include "BPLeuchten.h"
//#include "BPBlinken.h"

#include "BlinkeLicht.h"

BlinkeLicht* gBL;

//----------------------------------------------------------------------
int main()
{
    AttinyLED ATLEDGruen(PB0);
    AttinyLED ATLEDBlau(PB1);
    AttinyLED ATLEDRot(PB3);
    
    ILED* LEDGruen = &ATLEDGruen;
    ILED* LEDBlau = &ATLEDBlau;
    ILED* LEDRot = &ATLEDRot;
    
    ILED* LEDs[3];
    LEDs[0] = LEDRot;
    LEDs[1] = LEDGruen;
    LEDs[2] = LEDBlau;


    BlinkeLicht BL;
    gBL = &BL;

    BPLeuchten ProgramLeuchten(LEDs);
    BL.addProgramm(&ProgramLeuchten);

    /*   
    BL->addProgramm(new BPBlinken(&LEDs,1));
    BL->addProgramm(new BPBlinken(&LEDs,10));
    */
   
    BL.start();

    //timer0_start();
    //timer0_interrupt_enable();

    do
	{
        
	}
	while (true);
}
//----------------------------------------------------------------------
extern "C" void __cxa_pure_virtual() { while (1); } //exception handler

