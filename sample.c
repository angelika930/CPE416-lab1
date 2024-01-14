#include "globals.h"
#include <util/delay.h>
#include <avr/io.h>
#include <avr/interrupt.h>
#include <stdio.h>

void delay(int loops)
{
        while (count < loop)
        {
                _delay_us(100);
                count ++;
        }
}


void dim() 
{
        int a = 0;
        led_on(0);
        
        if (a < 10)
        {
                led_on(1);
                delay(10-a);

                led_off(1);
                delay(a);

                a++
        }



}
int main(void) {
   init();  //initialize board hardware
   led_on(1);
   dim();
   return 0;
}