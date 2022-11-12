#include <avr/io.h>
#include <util/delay.h>
#define BLINK_DELAY_MS 100
int main (void){
    DDRB = 0xFF; /* configure pin 5 of PORTB for output*/
    while(1){
    PORTB = 0xFF; /* set pin 5 high to turn led on */
    _delay_ms(BLINK_DELAY_MS);
    PORTB = 0x00; /* set pin 5 low to turn led off */
    _delay_ms(BLINK_DELAY_MS);
    }
}


