#include <TM1637Display.h>

// Module connection pins (Digital Pins)
#define CLK 2
#define DIOa 3
#define DIOb 4

// The amount of time (in milliseconds) between tests
#define TEST_DELAY   1000

const uint8_t SEG_DONE[] = {
	SEG_B | SEG_C | SEG_D | SEG_E | SEG_G,           // d
	SEG_A | SEG_B | SEG_C | SEG_D | SEG_E | SEG_F,   // O
	SEG_C | SEG_E | SEG_G,                           // n
	SEG_A | SEG_D | SEG_E | SEG_F | SEG_G            // E
	};

TM1637Display display_a(CLK, DIOa);
TM1637Display display_b(CLK, DIOb);

void setup()
{
}

void loop()
{
  uint8_t data[] = { 0xff, 0xff, 0xff, 0xff };
  display_a.setBrightness(0x00);
  display_b.setBrightness(0x00);

  // All segments on
  display_a.setSegments(data);
  display_b.setSegments(data);
  delay(TEST_DELAY);

  int secondONES;
  int secondTENS;
  int minuteONES;
  int minuteTENS;
  
  // minuteONES  
  //for(minuteONES = 9; minuteONES > -1; minuteONES -= 1)
  //{

      // secondTENS
    for(secondTENS = 5; secondTENS > -1; secondTENS -= 1)
    {
    // secondTENS
    for(secondTENS = 5; secondTENS > -1; secondTENS -= 1)
    {
     // secondONES
     for(secondONES = 9; secondONES > -1; secondONES -= 1)
     {
       int DISPLAY_A = minuteONES * 100 + secondTENS * 10 + secondONES;
       display_b.showNumberDec(DISPLAY_A);
       delay(TEST_DELAY);
     }
    }
    }
    
  // Done!
  display_a.setSegments(SEG_DONE);
  display_b.setSegments(SEG_DONE);

  while(1);
}
