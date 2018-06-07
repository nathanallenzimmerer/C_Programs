/*
 Hello World
 
CMD:  E  RW  RS 5V 0V   V0 Bit0-7 BL +/-
LCD:  6   5   4  2  1    3  7-14  15/16
UNO: 10   9   8 5V GND GND  0-7   


 */

#include <avr/io.h>            // registers locations and some other things
#define F_CPU 16000000UL      // tells compiler the freq of your processor
#include <util/delay.h>     // software delay functions

int lcd_wr_cmd (char);
int lcd_wr_char (char);

int main(void)
{
DDRB = 0b00000111;   // set E, RW, RS and data as output;
DDRD = 0xFF;       

  UCSR0B &= ~(1<<TXEN0);  //disable TX   

_delay_ms(40);     // start initialization
lcd_wr_cmd(0x38);  // function set
_delay_us(80);
lcd_wr_cmd(0x0F);  // display control
_delay_us(80);
lcd_wr_cmd(0x01);  // display clear
//vclcd_wr_cmd(0x06);  // entry mode

_delay_us(2000);
// HELLO WORLD!
lcd_wr_char('H');
_delay_us(40); 
lcd_wr_char('E');
_delay_us(40);
lcd_wr_char('L');
_delay_us(40);
lcd_wr_char('L');
_delay_us(40);
lcd_wr_char('O');
_delay_us(40);
lcd_wr_char(' ');
_delay_us(40);
lcd_wr_char('W');
_delay_us(40);
lcd_wr_char('O');
_delay_us(40);
lcd_wr_char('R');
_delay_us(40);
lcd_wr_char('L');
_delay_us(40);
lcd_wr_char('D');



//  LED BLINK LOOP 
DDRB |= (1<<PB5);         //digital pin13/PORTB5 = output
while(1){             // infinite loop
PORTB |= (1<<PB5);     // write a 1 to B5
_delay_ms(1000);     //Wait 1 second
PORTB &= ~(1<<PB5);        //Turn led off
_delay_ms(1000);     //Wait another second
}
return 0;
}

int lcd_wr_cmd(char cmd){ //write
PORTB = 0b00000000; // 0, 0, 0
_delay_us(40); 
PORTB = 0b00000100; // 1, 0, 0
PORTD = cmd;        // function set
_delay_us(40);       // tw delay
PORTB = 0b00000000; // 0, 0, 0
_delay_us(40); 
return 0;
}

int lcd_wr_char(char CharOut){ //display
PORTB = 0b00000001; // 0, 0, 1
_delay_us(40); 
PORTB = 0b00000101; // 1, 0, 1
_delay_us(40); 
PORTD = CharOut;  // function set
_delay_us(40);       // tw delay
PORTB = 0b00000001; // 0, 0, 0
_delay_us(40); 
return 0;
}

