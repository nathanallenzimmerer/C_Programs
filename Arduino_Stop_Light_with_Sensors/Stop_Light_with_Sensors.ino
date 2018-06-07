/*
 * Project_3_Stop_and_Go_Station.c
 *
 * Created: 5/14/2013 3:33:17 PM
 *  Author: Nathan Zimmerer
 */

#defineF_CPU16000000//ATmega328p clock speed
//Include headers
#include<avr/io.h>
#include<util/delay.h>
#include<avr/interrupt.h>
#include<string.h>

//Global variables
intlight_signal;//Red, Yellow, or Green
intcar_wait;//active low (0 if there is a car blocking photoresistor)
intprevious_state;
intdirection;//1 for North-South, 0 for East-West

//Signal FSM
#defineRED0//used for light_signal
#defineYELLOW1//used for light_signal
#defineGREEN2//used for light_signal

//Car stuff
#defineCAR0//active low, used for car_wait
#defineNO_CAR1//used for car_wait
#defineroad_speed1000//road_speed in mph
#defineN0//North
#defineE2//East
#defineS1//South
#defineW3//West

//Function declarations
intlight_MainControl(intcar_wait);//main program, probes outputs then checks to see if needs action
intlight_DispControl(intlight_signal);//logic for which light to display
intDisp_Red(intdirection);//display red
intDisp_Yellow(intdirection);//display yellow
intDisp_Green(intdirection);//display green
voidInitialize_ADC0(void);//input logic

//4 way intersection functions
intInput_Logic_Check(intlane);//lane logic

intmain(void)
{
  DDRD=0xFF;    //set PORTD as output 
  DDRB=0x00;    //set PORTB as input
  PORTB=0x00;
  
  Initialize_ADC0();
  
while(1)
{
  Input_Logic_Check(N);
    light_MainControl(car_wait);
    Input_Logic_Check(E);
    light_MainControl(car_wait);
    Input_Logic_Check(S);
    light_MainControl(car_wait);
    Input_Logic_Check(W);
    light_MainControl(car_wait);
}
}


////////////////////////////
////Function definitions////
////////////////////////////

//Overall light control functions
intlight_MainControl(intcar_wait){
  if(car_wait==CAR){
    light_DispControl(GREEN);//display green light  
    previous_state=GREEN;
  } 
  elseif(car_wait==NO_CAR&&previous_state==GREEN){
    light_DispControl(YELLOW);
    previous_state=YELLOW;
  }
  else{
    light_DispControl(RED);
    previous_state=RED; 
  } 
}

intlight_DispControl(intlight_signal){
  if(light_signal==GREEN){
    Disp_Green(direction);
  } 
  elseif(light_signal==YELLOW){
    Disp_Yellow(direction);
  } 
  else{
    Disp_Red(direction);
  } 
}

//Light Color Functions
intDisp_Red(intdirection){
  if(direction==N||direction==S){
    PORTD=1<<7|0<<6|0<<5|1<<4|0<<3|0<<2;
    //      NS_RD  NS_YLW NS_GRN EW_RED EW_YLW EW_GRN 
  }
  else{
    PORTD=1<<7|0<<6|0<<5|1<<4|0<<3|0<<2;
  }
  _delay_ms(1000);
}

intDisp_Yellow(direction){
  if(direction==N||direction==S)
  {
    PORTD=1<<7|0<<6|0<<5|0<<4|1<<3|0<<2;
  }
  else
  {
    PORTD=0<<7|1<<6|0<<5|1<<4|0<<3|0<<2;
  }
  _delay_ms(1000);
  
}

intDisp_Green(direction){
  if(direction==N||direction==S)
  {
    PORTD=0<<7|0<<6|1<<5|1<<4|0<<3|0<<2;
  }
  else
  {
    PORTD=1<<7|0<<6|0<<5|0<<4|0<<3|1<<2;  
  } 
  _delay_ms(4000);
}

voidInitialize_ADC0(void)
{
  ADCSRA=0x87;  // Turn On ADC and set prescaler (CLK/128--62 kHz)
  // MAX A/D conversion rate 5 kHz @ 62 kHz frequency
  ADCSRB=0x00;  // turn off auto-trigger
}

intInput_Logic_Check(lane){

  ADMUX=lane; //Set ADC channel ADC1 and AREF input (wire to 5V)
  direction=lane;
  ADCSRA=0xC7;// start conversion
  _delay_us(260); // ensure max sampling rate not exceeded
  
    if(ADC<0x19A)
    {
      car_wait=NO_CAR;
    }
    else
    {
      car_wait=CAR;
    }
  
}

