#include "globals.h"
#include <util/delay.h>
#include <avr/io.h>
#include <avr/interrupt.h>
#include <stdio.h>
#include <stdbool.h>
#include<string.h>

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
        int brightness = 0; //brightness = 0, darkest at = 99
        led_on(led_num);
        
        while (brightness < 100)
        {
                int pause_count = 0; 
                while (pause_count < 100) 
                {       // Adjusts how long the brightness level stays
                        led_on(led_num);
                        delay(100-brightness);
                        led_off(led_num);
                        delay(brightness);
                        pause_count++;
                }
                brightness++;
        }


}

void brighten(int led_num) 
{
        int brightness = 100; //brightess = 0, darkest at = 99
        led_off(led_num);
        
        while (brightness > 0)
        {
                int pause_count = 0;
                while (pause_count < 100) 
                {       // Adjusts how long the brightness level stays
                        led_on(led_num);
                        delay(100-brightness);
                        led_off(led_num);
                        delay(brightness);
                        pause_count++;
                }
                brightness--;
        }


}


void display() {
	
	clear_screen();
	print_string("Angelika");
	bool flag = false;
	char one[50] = " Angelika Canete ";
	char two[50] = " Christine Choi ";
	while (1) {

		if (flag == false) {

			clear_screen();
			while (get_btn() != 1) {
				for (int i = 0; i < 16; i++) {
				//	lcd_cursor(i % 8, 0);
				//	print_string(two + (i % 16));
					lcd_cursor(0,0);
					print_string(two+i);
					_delay_ms(200);
					if (get_btn() == 1) {
						flag = true;
						break;
					}
				}
				if (flag) { break; }

			}
		}

		else if (flag) {
			
			flag = false;
			clear_screen();
			while (get_btn() != 1) {
				for (int i = 0; i < 17; i++) {
					lcd_cursor(0, 0);
					print_string(one + i);
					_delay_ms(200);
					if (get_btn() == 1) {
						flag = false;
						break;
					}
				}

				if (flag == false) { break; }
			}

		}
	}

}


int main(void) {
   init();  //initialize board hardware

/*
while(1) 
{
   brighten(0);
   dim(0);
   brighten(1);
   dim(1);

}
*/
display(); 



   return 0;
}
