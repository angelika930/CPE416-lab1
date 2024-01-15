#include "globals.h"
#include <util/delay.h>
#include <avr/io.h>
#include <avr/interrupt.h>
#include <stdio.h>

void delay(u16 loop)
{
        u16 count = 0;
        while (count < loop)
        {
                _delay_us(1);
                count ++;
        }
}



void dim(int led_num) 
{
        int brightness = 0; //0 = 
        led_on(led_num);
        
        while (a < 100)
        {
                int b = 0;
                while (b < 100) 
                {       // Adjusts how long the brightness level stays
                        led_on(led_num);
                        delay(100-a);
                        led_off(led_num);
                        delay(a);
                        b++;
                }
                a++;
        }


}

void brighten() 
{
        int a = 100;
        led_on(0);
        
        while (a > 0)
        {
                int b = 0;
                while (b < 100) 
                {       // Adjusts how long the brightness level stays
                        led_on(1);
                        delay(100-a);
                        led_off(1);
                        delay(a);
                        b++;
                }
                a--;
        }


}


int main(void) {
   init();  //initialize board hardware
   led_on(1);
   led_on(0);

   while(1){
        dim(0);
        dim(1);

   }
   return 0;
}