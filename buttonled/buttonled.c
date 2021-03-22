/* Name: buttonled.c
 * Authors:
 * Description: Each of the 3 LEDs in the KL25z board are controlled by 3 push buttons
 */

//TODO[CODE][Task1] Leave GREEN LED toggling, and set RED LED to turn on when button is
//                  pressed and turned off when button is released
//TODO[CODE][Task2] Leave GREEN LED toggling, and set RED LED and BLUE LEDs to turn on
//                  when button0 and button1 are pressed respectively
//                  and turned off when buttons 0 and 1 are released. Create "function1" and
//                  move this task there and call it from main.
//TODO[CODE][Task3] Create function2 that turns on/off LEDs RED, GREEN, BLUE when their
//                  respective buttons are pressed/released, but when ALL THREE buttons are pressed,
//                  LED shall start blinking (any color).



#include "MKL25Z4.h"

#define GREEN_LED_BIT 19
#define GREEN_LED_PCR PORTB->PCR[GREEN_LED_BIT]

void delayMs(int n);

int main (void) {
  //Setup
    SIM->SCGC5 |= 0x400;
    
    GREEN_LED_PCR = 0x0100;
    GPIOB->PDDR |= 0x80000;          /* make PTB19 as output pin */

    while (1) {
      //Loop
        GPIOB->PDOR &= ~0x80000;     /* turn on green LED */
        delayMs(250);
        GPIOB->PDOR |= 0x80000;      /* turn off green LED */
        delayMs(250);
    }
}

/* Delay n milliseconds
 * The CPU core clock is set to MCGFLLCLK at 41.94 MHz in SystemInit().
 */
void delayMs(int n) {
    int i;
    int j;
    for(i = 0 ; i < n; i++)
        for (j = 0; j < 7000; j++) {}
}
