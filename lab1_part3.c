#include "globals.h"
#include <util/delay.h>
#include <avr/io.h>
#include <avr/interrupt.h>
#include <stdio.h>


//from bottom to top, pin 1, 2, 3, 4, 7 
#define led_1 1
#define led_2 2
#define led_3 3
#define led_4 4
#define led_5 7

void delay_ms(u16 loop)
{
        u16 count = 0;
        while (count < loop)
        {
            _delay_ms(1);
            count ++;
        }
}

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


void led_init()
{
    //set leds to outputs
    digital_dir(led_1, 1);
    digital_dir(led_2, 1);
    digital_dir(led_3, 1);
    digital_dir(led_4, 1);    
    digital_dir(led_5, 1);


    //turn all leds off
    digital_out(led_1, 0);
    digital_out(led_2, 0);
    digital_out(led_3, 0);
    digital_out(led_4, 0);
    digital_out(led_5, 0);
}

void led_game()
{
    int delay_time = 1000;
    digital_out(led_1, 1);
    button_delay_check(delay_time);

    while(1)
    {

        digital_out(led_1, 0);
        digital_out(led_2, 1);
        if (button_delay_check(delay_time))
        {
            //end the game if button was pressed outside of edge pin
            break;
        }

        digital_out(led_2, 0);
        digital_out(led_3, 1);
                if (button_delay_check(delay_time))
        {
            //end the game if button was pressed outside of edge pin
            break;
        }

        digital_out(led_3, 0);
        digital_out(led_4, 1);
        if (button_delay_check(delay_time))
        {
            //end the game if button was pressed outside of edge pin
            break;
        }


        //edge pin (5)
        digital_out(led_4, 0);
        digital_out(led_5, 1);
        if (button_delay_check(delay_time))
        {
            delay_time = delay_time - 50;
        }
        else
        {
            break;
        }


        digital_out(led_5, 0);
        digital_out(led_4, 1);
        if (button_delay_check(delay_time))
        {
            //end the game if button was pressed outside of edge pin
            break;
        }

        digital_out(led_4, 0);
        digital_out(led_3, 1);
        if (button_delay_check(delay_time))
        {
            //end the game if button was pressed outside of edge pin
            break;
        }

        digital_out(led_3, 0);
        digital_out(led_2, 1);
         if (button_delay_check(delay_time))
        {
            //end the game if button was pressed outside of edge pin
            break;
        }

        //edge pin (1)
        digital_out(led_2, 0);
        digital_out(led_1, 1);
        if (button_delay_check(delay_time))
        {
            delay_time = delay_time - 50;
        }
        else
        {
            break;
        }
    }

    //game end
    clear_screen();
    print_string("gameover");
    lcd_cursor(0, 1);
    print_num(delay_time);


}


int main(void) {
   init();  //initialize board hardware
   led_init();


   led_game();


   return 0;
}
