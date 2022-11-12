#include <avr/io.h>
#include <util/delay.h>

#define BLINK_DELAY_MS 1000         //define blink delay

int main(){
    DDRB = 0xFF;                    //initialize data direction register
    short int var = 0;              //initialize variable to count
    short int direction = 1;        //initialize a variable to identify the direction
    while(1){
        PORTB = PORTB | (1<<var);   //turn high each pin of port B
        _delay_ms(BLINK_DELAY_MS);  //provide a delay
        PORTB = PORTB &~(1<<var);   //turn low each pin of port B
        if(direction && var<4){     //if direction is 1 and count is less than 4 light bulbs in one direction
            var++;
            if(var>3){
                var = 2,
                direction = 0;
            }
        }else{                      //else light bulbs in other direction
            var--;
            if(var<0){
                direction = 1;
                var = 1;
            }
        }
    }
}

