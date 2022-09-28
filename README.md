compile
`avr-g++ -O1 main.cpp isr.c AttinyLED.cpp -mmcu=attiny85 -std=c++11 -o blinkstern.elf`

download
`avrdude -p t85 -c stk500 -P /dev/ttyACM0 -U flash:w:blinkstern.elf:e`
 
