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
        int brightness = 0; //brightess = 0, darkest at = 99
        led_on(led_num);
        
        while (brightness < 100)
        {
                int pause_count = 0; 
                while (pause_count < 100) 
                {       // Adjusts how long the brightness level stays
                        led_on(led_num);
                        delay(100-a);
                        led_off(led_num);
                        delay(a);
                        pause_count++;
                }
                brightness++;
        }


}

void brighten(int led_num) 
{
        int brightness = 0; //brightess = 0, darkest at = 99
        led_on(led_num);
        
        while (brightness > 0)
        {
                int pause_count = 0;
                while (pause_count < 100) 
                {       // Adjusts how long the brightness level stays
                        led_on(led_num);
                        delay(100-a);
                        led_off(led_num);
                        delay(a);
                        pause_count++;
                }
                brightness--;
        }


}


int main(void) {
   init();  //initialize board hardware
   led_on(1);
   led_on(0);

   while(1){
        dim(0);
        brighten(0);
        dim(1);
        brighten(1);
   }
   return 0;
}