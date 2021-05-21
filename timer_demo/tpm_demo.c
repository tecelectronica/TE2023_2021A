/* TPM Demo:
 * Toggling blue LED using TPM0 delay
 * MCGFLLCLK = 20.97MHz
 */

#include "MKL25Z4.h"

//163.840kHz
//32768
//5

//20.97MHz
//65536
//320

int main(){
  int i=0;
  //Enable Blue LED
  SIM->SCGC5 |= 0x1000;       /* enable clock to Port D */
  PORTD->PCR[1] = 0x100;      /* make PTD1 pin as GPIO */
  PTD->PDDR |= 0x02;          /* make PTD1 as output pin */
  //Enable timer
  SIM->SCGC6 |= SIM_SCGC6_TPM0_MASK; //Enable TPM0 Clock gate
  SIM->SOPT2 = SIM_SOPT2_TPMSRC(1);  //MCGFLLCLK
  TPM0->SC = 0;                      //Disable timer
  TPM0->MOD = 32768-1;                //Set Modulo reg to 32768
  TPM0->SC |= TPM_SC_TOF_MASK | TPM_SC_PS(7);       //Clear TOF flag and Prescaler to clk/128
  TPM0->SC |= TPM_SC_CMOD(1);        //Set TPM input clock and enable
    while (1) {
        for(i = 0; i < 5; i++) {  /* repeat timeout for 5 times */
            while((TPM0->SC & TPM_SC_TOF_MASK) == 0) { }/* wait until the TOF is set */
            TPM0->SC |= TPM_SC_TOF_MASK;   /* clear TOF */
        }
        PTD->PTOR = 0x02;       /* toggle blue LED */
    }
}

