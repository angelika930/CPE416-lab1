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
                _delay_ms(1);
                count ++;
        }
}



void display_tiltable_text()
{
    //start position
    print_num(416);

    int row = 0;
    int col = 4;

    while(1)
    {
        if ((get_accel_y() > 30 && get_accel_y()< 70 ) & (col > 0) )
        {//to the left
            col--;
        }
        if ( (get_accel_y() > 200 && get_accel_y()  < 250 ) & (col < 5) ) 
        {//to the right
            col++;
        }

        if ((get_accel_x() > 200 && get_accel_x()< 230 ))
        {// move down
            row = 1;
        }
        if ( (get_accel_x() > 20 && get_accel_x() < 70 ) ) 
        {//move up
            row = 0;
        }

        //print 416
        clear_screen();
        lcd_cursor(col, row);
        print_num(416);
        delay(50);

    }

}



int main(void) {
   init();  //initialize board hardware

    display_tiltable_text();


   return 0;
}

