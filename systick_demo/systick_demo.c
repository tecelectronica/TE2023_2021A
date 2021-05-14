/*
 * SysTick Demo
 */

#include "MKL25Z4.h"
#include "system_MKL25Z4.h"


void delayMs(int n);

int main(void)
{
  SystemCoreClockUpdate(); //Setting clock to 20.97MHz
  for(;;)
  {
  }
}


/* Delay n milliseconds
 * The CPU core clock is set to MCGFLLCLK at 41.94 MHz in SystemInit().
 */
void delayMs(int n) {
    int i;
    int j;
    for(i = 0 ; i < n; i++)
        for(j = 0 ; j < 7000; j++) { }
}
