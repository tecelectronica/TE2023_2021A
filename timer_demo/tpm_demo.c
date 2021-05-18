/* p5_4.c Toggling blue LED using TPM0 delay
 */

#include <MKL25Z4.H>
#include "system_MKL25Z4.h"


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
  TPM0->MOD = 32767;                //Set Modulo reg to 65535
  TPM0->SC |= TPM_SC_TOF_MASK;       //Clear TOF flag
  TPM0->SC |= TPM_SC_CMOD(1);        //Set TPM input clock and enable
    while (1) {
        for(i = 0; i < 320; i++) {  /* repeat timeout for 320 times */
            while((TPM0->SC & TPM_SC_TOF_MASK) == 0) { }/* wait until the TOF is set */
            TPM0->SC |= TPM_SC_TOF_MASK;   /* clear TOF */
        }
        PTD->PTOR = 0x02;       /* toggle blue LED */
    }
}

