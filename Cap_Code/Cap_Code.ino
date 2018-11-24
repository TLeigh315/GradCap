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
const char AGGIES[] PROGMEM = "AGGIES";
const char WHOOP[] PROGMEM = "WHOOP!!!";
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
}

void loop() {
  /*
  Intro();
  delay(5000);
  
  InfHorizontal(message,2,7,5555,10); //Thankyou message, Size 2 Font, 7 dots down, Rainbow 
  
  moveMsPacMan();
  delay(500);
  */
  Superheros();
  
  //EnterHorizontal(message1, message2, message3);
  
}

void Superheros(){
  matrix.fillScreen(0);
  matrix.fillCircle(24,8, 4, matrix.Color333(7, 0, 0)); 
  matrix.fillCircle(8,8, 4, matrix.Color333(0, 0, 7)); 
}
void Intro (){
  matrix.fillScreen(matrix.ColorHSV(1375, 255, 100, true));
  matrix.setTextColor(matrix.Color333(7, 7, 7));
  matrix.setTextSize(2);
  matrix.setCursor(11, 7); 
  matrix.println("T");
  
  matrix.setTextSize(1);   
  matrix.setCursor(6, 14);
  matrix.println("A");
  matrix.setCursor(22, 14);
  matrix.println("M");
}

void MsPacMan(){
  // fill a Yellow circle
  matrix.fillCircle(16, 16, 7, matrix.Color333(7, 7, 0));
  matrix.fillRect(7, 11, 4, 4, matrix.Color333(7, 0, 0));
  matrix.fillRect(11, 7, 4, 4, matrix.Color333(7, 0, 0));

  // draw an 'X' in black
  matrix.drawLine(16, 16, 31, 12, matrix.Color333(0, 0, 0));
  matrix.drawLine(16, 16, 31, 20, matrix.Color333(0, 0, 0));
  matrix.drawLine(18, 16, 21, 16, matrix.Color333(0, 0, 0));
  matrix.drawLine(22, 15, 22, 17, matrix.Color333(0, 0, 0));
  matrix.fillRect(23, 15, 24, 17, matrix.Color333(0, 0, 0));

  delay(500);
}

void moveMsPacMan(){
  int x=5;
  int y = 4;
  while (true){
   
    if (x >= 16){
      matrix.fillScreen(0);
      // fill a Yellow circle
      matrix.fillCircle(x, 16, 7, matrix.Color333(7, 7, 0));
      matrix.fillRect(x-9, 11, 4, 4, matrix.Color333(7, 0, 0));
      matrix.fillRect(x-5, 7, 4, 4, matrix.Color333(7, 0, 0));
      
      if( x > matrix.width() + 9)
        break;
    }
    else {
      matrix.fillScreen(0);
      matrix.fillCircle(matrix.width()-x,16, 4, matrix.Color333(7,7,7)); //The ball she eats
      // fill a Yellow circle
      matrix.fillCircle(x, 16, 7, matrix.Color333(7, 7, 0));
      matrix.fillRect(x-9, 11, 4, 4, matrix.Color333(7, 0, 0));
      matrix.fillRect(x-5, 7, 4, 4, matrix.Color333(7, 0, 0));
      // draw an 'X' in black
      //matrix.drawLine(x, 16, x+5, 16+y, matrix.Color333(0, 0, 0));
      //matrix.drawLine(x, 16, x+5, 16-y, matrix.Color333(0, 0, 0));

      //matrix.drawLine(x+1, 16, x+7, 16, matrix.Color333(0, 0, 0));
      //matrix.drawLine(x+4, 15-y, x+4, 17-y, matrix.Color333(0, 0, 0));
      //matrix.fillRect(x+5, 15-y, x+6, 17-y, matrix.Color333(0, 0, 0));

    }

    delay(100);
    x += 2;
    
    if (y < -4){
      y +=2; 
    }
    else y -= 2;
  }

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

void InfHorizontal(const char* message, int textsize, int textY, int color, int textSpeed){
  hue = 0;
  while(true){
    matrix.fillScreen(0);
    
    // draw some text!
    matrix.setCursor(textX, textY);    // start at top left, with one pixel of spacing
    matrix.setTextSize(textsize);     // size 1 == 8 pixels high
    matrix.setTextWrap(false); // Don't wrap at end of line - will do ourselves

    matrix.ColorHSV(hue, 255, 255, false);
    
    if (color == 5555) matrix.setTextColor(matrix.ColorHSV(hue, 255, 255, false));
    else matrix.setTextColor(color);
    matrix.println(F2(message));
  
    if (textX < textMin) {
      hue=0;
      textX = matrix.width();
      break;
    }
    else --textX;

    hue += 7;
    if(hue >= 1536) hue -= 1536;

    delay(textSpeed);
  
    #if !defined(__AVR__)
      // On non-AVR boards, delay slightly so screen updates aren't too quick.
      delay(200);
    #endif

    // Update display
    matrix.swapBuffers(false);
  }
}

