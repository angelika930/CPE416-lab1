#include "globals.h"
#include <util/delay.h>
#include <avr/io.h>
#include <avr/interrupt.h>
#include <stdio.h>

void dim() {
        int a = 0;
        led_on(0);
        while (a < 6) {
                if (a == 1) {
                        led_on(0);
                        _delay_us(300);
                        led_off(0);
                        _delay_us(350);
                }
                else if (a == 2) {
                        led_on(0);
                        _delay_us(350);
                        led_off(0);
                        _delay_us(300);
                }
                else if (a == 3) {
                        led_on(0);
                        _delay_us(400);
                        led_off(0);
                        _delay_us(250);
                }
                else if (a == 4) {
                        led_on(0);
                        _delay_us(450);
                        led_off(0);
                        _delay_us(200);
                }
                else if (a == 5) {
                        led_on(0);
                        _delay_us(500);
                        led_off(0);
                        _delay_us(150);
                }
                a++;
        }
}
int main(void) {
   init();  //initialize board hardware
   led_on(1);
   dim();
   return 0;
