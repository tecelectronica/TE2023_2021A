/* Name: buttonled.c
 * Authors:
 * Description: Each of the 3 LEDs in the KL25z board are controlled by 3 push buttons
 */

//[Task1] Leave GREEN LED toggling, and set RED LED to turn on when button is
//        pressed and turned off when button is released
//TODO[CODE][Task2] Leave GREEN LED toggling, and set RED LED and BLUE LEDs to turn on
//                  when button0 and button1 are pressed respectively
//                  and turned off when buttons 0 and 1 are released. Create "function1" and
//                  move this task there and call it from main.
//TODO[CODE][Task3] Create function2 that turns on/off LEDs RED, GREEN, BLUE when their
//                  respective buttons are pressed/released, but when ALL THREE buttons are pressed
//                  at the same time, LED shall start blinking (any color).


#include "MKL25Z4.h"

//GREEN LED IS IN PORTB PIN19
#define GREEN_LED_BIT 19
#define GREEN_LED_PCR PORTB->PCR[GREEN_LED_BIT]
#define RED_LED_BIT 18
#define RED_LED_PCR PORTB->PCR[RED_LED_BIT]
//Button0 is at PTA1
#define BUTTON0_BIT 1
#define BUTTON0_GPIO GPIOA
#define BUTTON0_PCR PORTA->PCR[BUTTON0_BIT]


void delayMs(int n);

int main (void) {
  //Setup
    //SIM->SCGC5 |= 0x400; //Enable PORTB clock gate
    SIM->SCGC5 |= SIM_SCGC5_PORTB(1); //Enable PORTB clock gate
    SIM->SCGC5 |= SIM_SCGC5_PORTA(1); //Enable PORTA clock gate
    
    //PORTB->PCR[19] = 0x0100;
    GREEN_LED_PCR = PORT_PCR_MUX(1); // Set GREEN_LED bit as GPIO
    RED_LED_PCR = PORT_PCR_MUX(1); // Set RED_LED bit as GPIO
    BUTTON0_PCR = PORT_PCR_MUX(1) | PORT_PCR_PE(1) | PORT_PCR_PS(1); // Set port pin as GPIO with pull up resistor enabled
    //GPIOB->PDDR |= 0x80000;          /* make PTB19 as output pin */
    GPIOB->PDDR |= (1<<GREEN_LED_BIT) | (1<<RED_LED_BIT); //Set GREEN_LED_BIT and RED_LED_BIT pin as output
    GPIOB->PDOR |= (1<<RED_LED_BIT); //Turn RED LED off
    BUTTON0_GPIO->PDDR &= ~(1<<BUTTON0_BIT); //Configure BUTTON0_BIT as input

    while (1) {
      //Loop
        GPIOB->PDOR &= ~(1<<GREEN_LED_BIT);     /* turn on green LED */
        delayMs(250);
        GPIOB->PDOR |= (1<<GREEN_LED_BIT);      /* turn off green LED */
        delayMs(250);

        if((BUTTON0_GPIO->PDIR & (1<<BUTTON0_BIT)) == (1<<BUTTON0_BIT)){ //BUTTON0 NOT PRESSSED
          GPIOB->PDOR |= (1<<RED_LED_BIT); //Turn RED LED off
        }else{ //BUTTON0 IS PRESSED
          GPIOB->PDOR &= ~(1<<RED_LED_BIT); //Turn RED LED on
        }
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
