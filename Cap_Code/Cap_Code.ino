#include <RGBmatrixPanel.h>

#define CLK  8   // USE THIS ON ARDUINO UNO, ADAFRUIT METRO M0, etc.
#define OE   9
#define LAT 10
#define A   A0
#define B   A1
#define C   A2
#define D   A3
RGBmatrixPanel matrix(A, B, C, D, CLK, LAT, OE, false);
const char message[] PROGMEM = "Thanks Mom & Dad!";
const char message1[] = "WE";
const char message2[] = "MADE";
const char message3[] = "IT!";
int16_t hue = 0;
int16_t textX = matrix.width();
int16_t textX1 = matrix.width();
int16_t textX2 = matrix.width();
int16_t textX3 = matrix.width();
int16_t textMin = sizeof(message) *-16;

#define F2(progmem_ptr) (const __FlashStringHelper *)progmem_ptr

void setup() {

  matrix.begin();
  matrix.fillRect(0, 0, 32, 32, matrix.Color333(7, 0, 7));


}

void loop() {
  //InfHorizontal(message);
  //EnterHorizontal(message1, message2, message3);
  
}

void EnterHorizontal(const char* message1, const char* message2, const char* message3){
  while(true){
    if (textX1 < 10) {
      if(textX2 < 5){
        if(textX3< 8){
          delay(10);
          --textX1;
          --textX2;
          --textX3;

          matrix.fillScreen(0);
          matrix.setTextColor(matrix.ColorHSV(hue, 255, 255, false));
          matrix.setCursor(textX1, 1);
          matrix.println(message1);
          matrix.setCursor(textX2, 9);
          matrix.println(message2);
          matrix.setCursor(textX3, 17);
          matrix.println(message3);

          if (textX1 == textMin){
          
            textX1 = matrix.width();
            textX2 = matrix.width();
            textX3 = matrix.width();
          break;
          }
          
        }

        else{
          matrix.fillScreen(0);
          matrix.setCursor(textX1, 1);    
          matrix.setTextSize(1);     // size 1 == 8 pixels high
          matrix.setTextWrap(false); // Don't wrap at end of line - will do ourselves
          matrix.setTextColor(matrix.ColorHSV(hue, 255, 255, false));
          matrix.println(message1);
        
          matrix.setCursor(textX2, 9);    
          matrix.setTextSize(1);     // size 1 == 8 pixels high
          matrix.setTextWrap(false); // Don't wrap at end of line - will do ourselves
          matrix.setTextColor(matrix.ColorHSV(hue, 255, 255, false));
          matrix.println(message2);

          matrix.setCursor(textX3, 17);    
          matrix.setTextSize(1);     // size 1 == 8 pixels high
          matrix.setTextWrap(false); // Don't wrap at end of line - will do ourselves
          matrix.setTextColor(matrix.ColorHSV(hue, 255, 255, false));
          matrix.println(message3);
          --textX3;
          
          if(textX3 < 8) delay(2000);
        }
      }

      else{
        matrix.fillScreen(0);
        matrix.setCursor(textX1, 0);    
        matrix.setTextSize(1);     // size 1 == 8 pixels high
        matrix.setTextWrap(false); // Don't wrap at end of line - will do ourselves
        matrix.setTextColor(matrix.ColorHSV(hue, 255, 255, false));
        matrix.println(message1);
        
        matrix.setCursor(textX2, 8);    
        matrix.setTextSize(1);     // size 1 == 8 pixels high
        matrix.setTextWrap(false); // Don't wrap at end of line - will do ourselves
        matrix.setTextColor(matrix.ColorHSV(hue, 255, 255, false));
        matrix.println(message2);
        --textX2;
      }

    }
    else {
      matrix.fillScreen(0);
      matrix.setCursor(textX1, 0);    
      matrix.setTextSize(1);     // size 1 == 8 pixels high
      matrix.setTextWrap(false); // Don't wrap at end of line - will do ourselves
      matrix.setTextColor(matrix.ColorHSV(hue, 255, 255, false));
      matrix.println(message1);
      --textX1;
    }

    hue += 7;
    if(hue >= 1536) hue -= 1536;

    delay(10);
  
    #if !defined(__AVR__)
      // On non-AVR boards, delay slightly so screen updates aren't too quick.
      delay(200);
    #endif

    // Update display
    matrix.swapBuffers(true);
  }
}

void InfHorizontal(const char* message){
  while(true){
    matrix.fillScreen(0);
    // draw some text!
    matrix.setCursor(textX, 7);    // start at top left, with one pixel of spacing
    matrix.setTextSize(2);     // size 1 == 8 pixels high
    matrix.setTextWrap(false); // Don't wrap at end of line - will do ourselves
  
    matrix.setTextColor(matrix.ColorHSV(hue, 255, 255, false));
    matrix.println(F2(message));
  
    if (textX < textMin) {
      hue=0;
      textX = matrix.width();
      break;
    }
    else --textX;

    hue += 7;
    if(hue >= 1536) hue -= 1536;

    delay(10);
  
    #if !defined(__AVR__)
      // On non-AVR boards, delay slightly so screen updates aren't too quick.
      delay(200);
    #endif

    // Update display
    matrix.swapBuffers(false);
  }
}

