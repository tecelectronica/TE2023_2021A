/*
 * SysTick Demo
 * ARM Cortex M0 SysTick Timer
 */

#include "MKL25Z4.h"

#define GREEN_LED_BIT 19
#define GREEN_LED_PCR PORTB->PCR[GREEN_LED_BIT]
#define GREEN_LED_PORT_OUT GPIOB->PDOR

void delayMs(int n);
void delay1Ms(void);

int main(void)
{
  SIM->SCGC5 |= SIM_SCGC5_PORTB(1); //Enable PORTB clock gate
  GREEN_LED_PCR = PORT_PCR_MUX(1); // Set GREEN_LED bit as GPIO
  GPIOB->PDDR |= (1<<GREEN_LED_BIT); //Set GREEN_LED_BIT pin as output

  for(;;)
  {
    GREEN_LED_PORT_OUT ^= (1<<GREEN_LED_BIT);
    delayMs(1000);
  }
}


/* ARM SysTick Delay n milliseconds
 * The CPU core clock is set to MCGFLLCLK at 20.97 MHz in SystemInit().
 */
void delayMs(int n) {
  SysTick->CTRL = 0; //Disable SysTick
  SysTick->LOAD = 20970;
  SysTick->CTRL = SysTick_CTRL_CLKSOURCE_Msk | SysTick_CTRL_ENABLE_Msk; //0x05
  for(int i=0; i<n; i++){
    while((SysTick->CTRL & SysTick_CTRL_COUNTFLAG_Msk) != SysTick_CTRL_COUNTFLAG_Msk);
  }
  SysTick->CTRL = 0; //Disable SysTick
}


void delay1Ms(void) {
  SysTick->CTRL = 0; //Disable SysTick
  SysTick->LOAD = 20970;
  SysTick->CTRL = SysTick_CTRL_CLKSOURCE_Msk | SysTick_CTRL_ENABLE_Msk; //0x05
  while((SysTick->CTRL & SysTick_CTRL_COUNTFLAG_Msk) != SysTick_CTRL_COUNTFLAG_Msk);
  SysTick->CTRL = 0; //Disable SysTick
}











