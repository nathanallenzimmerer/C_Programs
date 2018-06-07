/*
 * Nathan Zimmerer
 * Program Name: Basic stepper motor driver
 * Program Description:
 * Basic stepper motor driver for a unipolar stepper motor with full steps using delays
 */

// Output pins
const int Pin1 = 10; // Arduino pin 10
const int Pin2 = 11; // Arduino pin 11
const int Pin3 = 12; // Arduino pin 12
const int Pin4 = 13; // Arduino pin 13

int _step = 0;
boolean dir = true;// false=clockwise, true=counter clockwise
void setup()
{
 pinMode(Pin1, OUTPUT);
 pinMode(Pin2, OUTPUT);
 pinMode(Pin3, OUTPUT);
 pinMode(Pin4, OUTPUT);
}
 void loop()
{
 switch(_step){
 case 0:
 digitalWrite(Pin1, LOW);
 digitalWrite(Pin2, LOW);
 digitalWrite(Pin3, HIGH);
 digitalWrite(Pin4, HIGH);
 break;
 case 1:
 digitalWrite(Pin1, LOW);
 digitalWrite(Pin2, HIGH);
 digitalWrite(Pin3, HIGH);
 digitalWrite(Pin4, LOW);
 break;
 case 2:
 digitalWrite(Pin1, HIGH);
 digitalWrite(Pin2, HIGH);
 digitalWrite(Pin3, LOW);
 digitalWrite(Pin4, LOW);
 break;
 case 3:
 digitalWrite(Pin1, HIGH);
 digitalWrite(Pin2, LOW);
 digitalWrite(Pin3, LOW);
 digitalWrite(Pin4, HIGH);
 break;
 default:
 digitalWrite(Pin1, LOW);
 digitalWrite(Pin2, LOW);
 digitalWrite(Pin3, LOW);
 digitalWrite(Pin4, LOW);
 break;
 }
 if(dir){
 _step++;
 }else{
 _step--;
 }
 if(_step>3){
 _step=0;
 }
 if(_step<0){
 _step=3;
 }
 delay(2);
}
