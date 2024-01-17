#include "globals.h"
#include <util/delay.h>
#include <avr/io.h>
#include <avr/interrupt.h>
#include <stdio.h>
#include <stdbool.h>
#include<string.h>

u16 button_delay_check(u16 loop)
{
    //acts as a delay_ms function that also checks for a button press

        u16 count = 0;
        int button_flag = 0;
        while (count < loop)
        {
            if (get_btn()==1)
            {
                button_flag = 1;
            }
            _delay_ms(1);
            count ++;
        }
        return button_flag;
}



void display() {
	
	clear_screen();
	print_string("Angelika");
	bool flag = false;
	char one[50] = "         Angelika Canete ";
	char two[50] = "          Christine Choi ";
	while (1) {

		if (flag == false) {

			clear_screen();
			while (get_btn() != 1) {
                lcd_cursor(7,0);
              
			
				for (int i = 0; i < 25; i++) {
				   	lcd_cursor(0,0);
					print_string(two+i);
                    if (button_delay_check(300) == 1) {
                        flag = true;
                        break;
                    }
			

				}
               
				
				
				if (flag) { break; }

			}
		}

		else if (flag) {
			
			clear_screen();
			while (get_btn() != 1) {
				for (int i = 0; i < 26; i++) {
					lcd_cursor(0, 0);
					print_string(one + i);
					_delay_ms(300);
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


display(); 



   return 0;
}