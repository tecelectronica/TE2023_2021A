/*
 * Title: First Blink program
 * Author:
 * Description: Blink KL25z board LEDs at different speeds
 * */

// TODO[CODE][Task1] Blink Green LED. Green LED is connected to Port B19
// TODO[CODE][Task2] Blink Red LED. Red LED is connected to Port B18
// TODO[CODE][Task3] Replicate behaviour for Blue LED. Blue LED is connected to Port D1

/* SIM_SCGC5. System Integration Module System Clock Gating Control Register 5*/
#define SIM_SCGC5   (*((volatile unsigned int*)0x40048038))
#define SIM_SCGC5_PORTB 10
/* PORTB_PCR19. Port B Pin Control Register 19*/
#define PORTB_PCR19 (*((volatile unsigned int*)0x4004A04C))
#define PORTB_PCR19_MUX 8
/* GPIOB_PDDR. Port B Data Direction Register */
#define GPIOB_PDDR (*((volatile unsigned int*)0x400FF054))
#define GPIOB_PIN19 19
/* GPIOB_PDOR. Port B Data Output Register */
#define GPIOB_PDOR (*((volatile unsigned int*)0x400FF040))
/* TODO[DEFINE][Task2] PORTB_PCR18. Port B Pin Control Register 18*/

// TODO[DEFINE][Task1] GREEN_LED_PCR Constant for GREEN LED PCR based on PORTB_PCR18
// TODO[DEFINE][Task1] GREEN_LED_BIT Constant with RED LED position in register
// TODO[DEFINE][Task2] RED_LED_PCR Constant for RED LED PCR based on PORTB_PCR19
// TODO[DEFINE][Task2] RED_LED_BIT Constant with RED LED position in register

// NOTE: Function Declaration
void delay(int n);

int main (void) {
  //Setup phase

  //enable clock to Port B
  SIM_SCGC5 = SIM_SCGC5 | (1<<SIM_SCGC5_PORTB) ; // Write a 1 into bit 10 of register
  //make PTB19 pin as GPIO
  PORTB_PCR19 = (1 << PORTB_PCR19_MUX);
  //make PTB19 as output pin
  GPIOB_PDDR = GPIOB_PDDR | (1<<GPIOB_PIN19);

  //TODO[CODE][Task2] make PTB18 pin as GPIO
  //TODO[CODE][Task2] make PTB18 as output pin

  //Loop phase
  while (1) {
  //Turn on GREEN LED, delay, turn off GREEN LED, delay
    GPIOB_PDOR = GPIOB_PDOR & ~(1<<GPIOB_PIN19); //Turning on LED
    delay(500);
    GPIOB_PDOR = GPIOB_PDOR | (1<<GPIOB_PIN19); //Turning off LED
    delay(500);
  //TODO[CODE][Task2] Toggle RED LED at twice the speed of GREEN LED
  }
}

//Define delay function using for loops
// NOTE: Function definition
void delay(int n) {
  int i;
  int j;
  for(i = 0 ; i < n; i++)
      for (j = 0; j < 7000; j++) {}
}
