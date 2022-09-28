#define F_CPU 3686400 // Taktfrequenz / Frequency
#include <avr/io.h>

#include "ILED.h"
#include "AttinyLED.h"

AttinyLED::AttinyLED(uint8_t gpio) {
    mGPIO = gpio;
    DDRB |= (1 << mGPIO);   // set pin of Port B as output
    off();
}

void AttinyLED::on() {
    PORTB |= (1 << mGPIO);  // set pin of Port B high
}

void AttinyLED::off() {
    PORTB &= ~(1 << mGPIO); // set pin of Port B low
}
