/*
 * Title: First Blink program
 * Author:
 * Description: Blink KL25z board LEDs at different speeds
 * */

// TODO[CODE][Task3] Replicate behaviour for Blue LED

/* TODO[DEFINE][Task1] SIM_SCGC5. System Integration Module System Clock Gating Control Register 5*/
/* TODO[DEFINE][Task1] PORTB_PCR18. Port B Pin Control Register 18*/
/* TODO[DEFINE][Task1] GPIOB_PDDR. Port B Data Direction Register */
/* TODO[DEFINE][Task1] GPIOB_PDOR. Port B Data Output Register */
/* TODO[DEFINE][Task2] PORTB_PCR19. Port B Pin Control Register 19*/

// TODO[DEFINE][Task1] GREEN_LED_PCR Constant for GREEN LED PCR based on PORTB_PCR18
// TODO[DEFINE][Task1] GREEN_LED_BIT Constant with RED LED position in register
// TODO[DEFINE][Task2] RED_LED_PCR Constant for RED LED PCR based on PORTB_PCR19
// TODO[DEFINE][Task2] RED_LED_BIT Constant with RED LED position in register

// NOTE: Function Declaration
void delay(int n);

int main (void) {
    //TODO[CODE][Task1] enable clock to Port B
    //TODO[CODE][Task1] make PTB19 pin as GPIO
    //TODO[CODE][Task1] make PTB19 as output pin

    //TODO[CODE][Task2] make PTB18 pin as GPIO
    //TODO[CODE][Task2] make PTB18 as output pin
    
    while (1) {
      //TODO[CODE][Task1] Turn on GREEN LED, delay, turn off GREEN LED, delay
      //TODO[CODE][Task2] Toggle RED LED at twice the speed of GREEN LED
    }
}

//TODO[CODE][Task1] Define delay function using for loops
// NOTE: Function definition
void delay(int n) {
}
