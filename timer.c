//----------------------------------------------------------------------
// Titel : TimerInterface
//----------------------------------------------------------------------
#include <avr/io.h>

// Timer 0
void timer0_start() {
    TCCR0B = (5<<CS00); // Prescaler 1024
}

void timer0_stop() {
    TCCR0B = 0; // Timer disabled
}

void timer0_interrupt_enable() {
    TIFR |= (1<<TOV0); // Clear the overflow int flag
    TIMSK |= (1<<TOIE0); // Timer overflow interrupt enable
}

void timer0_interrupt_disable() {
    TIMSK &= ~(1<<TOIE0); // Timer overflow interrupt disable
}
