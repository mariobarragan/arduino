// NeoPixel Ring simple sketch (c) 2013 Shae Erisson
// released under the GPLv3 license to match the rest of the AdaFruit NeoPixel library
// Modified by CraigColeman  for an 8x8 neopixel 160120
int clearPix ();
int cwc ();
#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
  #include <avr/power.h>
#endif

int  b[1280] = {
    1,2,2,1,1,1,1,1 ,
    1,1,1,1,1,1,1,1 ,
    1,3,1,1,1,1,1,1 ,
    1,3,1,1,1,1,1,1 ,
    1,3,1,1,1,1,1,1 ,
    5,5,5,5,5,1,1,3 ,
    1,1,1,1,1,1,1,3,
    4,4,4,4,1,1,1,3, 
////////////////////////
1,1,1,1,1,1,1,1,
3,1,1,3,1,1,1,1,
3,1,1,3,1,1,2,5,
3,1,1,3,1,1,2,1,
1,1,1,1,1,1,1,4,
1,1,1,1,1,1,1,4,
1,5,5,5,5,5,1,4,
1,1,1,1,1,1,1,4,
////////////////////
    1,1,1,1,1,1,1,1 ,
    1,4,1,1,3,3,3,1 ,
    1,4,5,1,1,1,1,1 ,
    1,4,5,1,1,1,1,1 ,
    1,4,5,1,3,3,3,1 ,
    1,1,5,1,1,2,1,1 ,
    1,1,5,1,1,2,1,1,
    1,1,1,1,1,1,1,1,
//////////////////////
    1,2,2,1,1,1,1,5 ,
    3,1,1,1,1,1,1,5 ,
    3,1,1,1,1,1,1,5 ,
    3,1,1,1,1,1,1,5 ,
    1,1,1,1,1,1,1,5 ,
    1,1,1,1,1,1,1,3 ,
    1,1,1,1,1,1,1,3,
    4,4,4,4,1,1,1,3, 
//////////////////////////
    3,1,1,1,2,1,1,5 ,
    3,1,1,1,2,1,1,5 ,
    3,1,1,1,1,1,1,5 ,
    1,1,1,1,1,1,1,5 ,
    4,1,1,1,1,3,1,5 ,
    4,1,1,1,1,3,1,1 ,
    4,1,1,1,1,3,1,1,
    4,1,1,1,1,1,1,1,
//////////////////////////
1,1,1,1,1,1,1,1,
1,4,4,4,4,3,1,1,
1,1,2,2,1,3,1,1,
1,1,3,3,3,3,1,1,
1,5,5,5,5,5,1,1,
1,1,1,1,1,1,1,1,
1,1,1,1,1,1,1,1,
1,1,1,1,1,1,1,1,
///////////////////////
    4,4,4,4,1,1,1,1,
    1,2,2,1,1,1,1,5,
    1,1,1,1,1,1,1,5,
    1,3,1,1,1,1,1,5,
    1,3,1,1,1,1,1,5,
    1,3,1,1,1,1,1,5,
    1,1,1,1,1,1,1,1,
    1,1,1,1,3,3,3,1,
///////////////////////////
    1,1,1,1,1,2,2,1 ,
    1,1,1,1,1,1,1,1 ,
    1,4,4,4,4,1,3,1 ,
    1,1,1,1,1,1,3,1 ,
    1,3,3,3,1,1,3,1 ,
    1,1,1,1,1,1,1,1 ,
    1,5,5,5,5,5,1,1,
    1,1,1,1,1,1,1,1,
/////////////////////////
    1,2,2,1,1,1,1,5 ,
    3,1,1,1,1,1,1,5 ,
    3,1,1,1,1,1,1,5 ,
    3,1,1,1,1,1,1,5 ,
    1,1,1,1,1,1,1,5 ,
    1,1,1,1,1,1,1,3 ,
    1,1,1,1,1,1,1,3,
    4,4,4,4,1,1,1,3,
///////////////////////
    1,2,2,1,1,1,1,5 ,
    1,1,1,1,1,3,1,5 ,
    3,1,1,1,1,3,1,5 ,
    3,1,1,1,1,3,1,5 ,
    3,1,1,4,1,1,1,5 ,
    1,1,1,4,1,1,1,1 ,
    1,1,1,4,1,1,1,1,
    1,1,1,4,1,1,1,1,
////////////////////////
    1,2,2,1,1,1,1,1 ,
    3,1,1,1,4,1,1,5 ,
    3,1,1,1,4,1,1,5 ,
    3,1,1,1,4,1,1,5 ,
    1,1,1,1,4,1,1,5 ,
    1,1,1,1,1,1,1,5 ,
    1,1,1,1,1,1,1,1,
    3,3,3,1,1,1,1,1,
/////////////////////////
    1,1,1,1,1,2,2,1 ,
    3,1,1,1,1,1,1,1 ,
    3,1,1,1,1,1,1,5 ,
    3,1,4,1,3,1,1,5 ,
    1,1,4,1,3,1,1,5 ,
    1,1,4,1,3,1,1,5 ,
    1,1,4,1,1,1,1,5,
    1,1,1,1,1,1,1,1, 
///////////////////////
   1,1,1,1,1,1,1,1 ,
   1,1,2,1,1,1,1,1 ,
   1,1,2,1,1,1,1,1 ,
   3,3,3,1,1,1,1,1 ,
   1,1,1,1,1,1,1,1 ,
   5,5,5,5,5,1,1,3 ,
   1,1,1,1,1,1,1,3,
   4,4,4,4,1,1,1,3,  
/////////////////////////
    2,2,5,5,5,5,5,3 ,
    3,3,3,4,4,4,4,3 ,
    1,1,1,1,1,1,1,3 ,
    1,1,1,1,1,1,1,1 ,
    1,1,1,1,1,1,1,1 ,
    1,1,1,1,1,1,1,1 ,
    1,1,1,1,1,1,1,1,
    1,1,1,1,1,1,1,1,
///////////////////////////
1,1,1,1,1,1,1,1,
1,5,5,5,5,5,1,1,
1,4,1,1,1,1,1,1,
1,4,1,2,2,3,1,1,
1,4,1,1,1,3,1,1,
1,4,3,3,3,3,1,1,
1,1,1,1,1,1,1,1,
1,1,1,1,1,1,1,1,
//////////////////////////
1,1,1,1,1,1,1,1,
1,5,3,3,3,1,1,1,
1,5,1,1,1,3,1,1,
1,5,1,1,1,3,1,1,
1,5,1,1,1,3,1,1,
1,5,1,1,1,1,1,1,
1,1,1,1,1,2,1,1,
1,1,1,1,1,2,1,1,
/////////////////////
1,1,1,1,1,1,1,1,
5,1,2,1,1,1,1,1,
5,1,2,3,3,3,1,1,
5,1,1,1,1,1,1,1,
5,1,1,1,1,1,1,1,
5,1,1,1,1,1,1,3,
4,4,4,4,1,1,1,3,
1,1,1,1,1,1,1,3,
//////////////////////
5,1,1,1,1,1,1,1,
5,1,1,1,1,1,1,2,
5,1,1,1,1,1,1,2,
5,1,1,1,1,1,1,1,
5,1,1,3,3,3,1,1,
1,1,1,1,1,1,1,1,
1,3,3,3,1,1,1,1,
1,1,1,1,1,1,1,1,
/////////////////////
1,1,1,1,1,1,1,1,
1,5,5,5,5,5,1,1,
1,1,1,1,1,1,1,1,
1,2,1,1,1,1,1,4,
1,2,1,1,1,1,3,4,
1,1,1,1,1,1,3,4,
1,1,3,3,3,1,3,4,
1,1,1,1,1,1,1,1,
///////////////////
1,1,1,1,1,1,2,1,
1,3,3,3,1,1,2,1,
1,1,1,1,1,1,1,1,
1,5,5,5,5,5,1,1,
4,1,1,1,1,1,1,1,
4,1,1,1,1,1,3,1,
4,1,1,1,1,1,3,1,
4,1,1,1,1,1,3,1
};

// Which pin on the Arduino is connected to the NeoPixels?
// On a Trinket or Gemma we suggest changing this to 1
#define PIN            6

// How many NeoPixels are attached to the Arduino?
#define NUMPIXELS      64

// When we setup the NeoPixel library, we tell it how many pixels, and which pin to use to send signals.
// Note that for older NeoPixel strips you might need to change the third parameter--see the strandtest
// example for more information on possible values.
Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);
//  8x8 array

void setup() {
  Serial.begin(9600);      //ser up Serial.*
  randomSeed(analogRead(0));
  // This is for Trinket 5V 16MHz, you can remove these three lines if you are not using a Trinket
  #if defined (__AVR_ATtiny85__)
    if (F_CPU == 16000000) clock_prescale_set(clock_div_1);
  #endif
  // End of trinket special code
  pixels.begin(); // This initializes the NeoPixel library.
}
//  main loop ***  Add functions here. *********************************************************
// Global Variables
  int adj = 0;
//  ************************
void loop() {
// names
    switch ( adj ) {
          case 0:
            Serial.print(" mario's board ");
          break;
          case 64:
            Serial.print(" romeo's board ");
          break;
          case 128:
            Serial.print(" will's board ");
          break;
          case 192:
            Serial.print(" richard's board ");
          break;
          case 256:
            Serial.print(" raul's board ");
          break;
          case 320:
            Serial.print(" mitch's board ");
          break;
          case 384:
            Serial.print(" mikey's board");
          break;
          case 448:
            Serial.print(" josh's board");
          break;
          case 512:
            Serial.print(" david's board ");
          break;
          case 576:
            Serial.print(" christian's board ");
          break;
          case 640:
            Serial.print(" chase's board ");
          break;
          case 704:
            Serial.print(" adrian's board");
          break;
          case 768:
            Serial.print(" garret's board");
          break;
          case 832:
            Serial.print(" unknown board ");
          break;
          case 896:
            Serial.print(" fash ");
          break;
          case 960:
            Serial.print(" Board 16 ");
          break;
          case 1024:
            Serial.print(" Board 17 ");
          break;
          case 1088:
            Serial.print(" Board 18 ");
          break;
          case 1152:
            Serial.print(" Board 19 ");
          break;
          case 1216:
            Serial.print(" Board 20 ");
          break;
          default:
          Serial.print(" ****** ");
          break;}




////////////////////////////
 clearPix();uno(adj);   delay(3000);
adj = adj + 64;
if (adj > 1216) adj = 0;


}
//  end of main loop *********************************************************

//start clearPix() *********************************************************
int clearPix (){
  for(int i=0;i<NUMPIXELS;i++){
      pixels.setPixelColor(i, pixels.Color(0,0,0)); 
    }
    pixels.show();
  }
//end clearPix  *********************************************************

// start uno *********************************************************
  int uno(int num){
  int i, val, newhit, countColors, r,c,x,y;
  int done = 0;
  int red = 0, green = 0, blue = 0;
  int totalBombs = 0;
//change this array use 1 as the water
int m[8][8];
int count = 0;

 for (r = 0; r < 8; r++){
    for (c = 0; c < 8; c++){
       m[r][c] = b[count+num];
       count++;
    }//end c
 }//end r
int s[8][8] = {  
    {0,0,0.0,0,0,0,0} ,
    {0,0,0,0,0,0,0,0} ,
    {0,0,0,0,0,0,0,0} ,
    {0,0,0,0,0,0,0,0} ,
    {0,0,0,0,0,0,0,0} ,
    {0,0,0,0,0,0,0,0} ,
    {0,0,0,0,0,0,0,0} ,
    {0,0,0,0,0,0,0,0}
};

while(done == 0){
   i = 0;// set neo-pixel number to zero
  countColors = 0;;// set count colors to 0 to count bomb hits
  for (r = 0; r < 8; r++){
    for (c = 0; c < 8; c++){
      // set the color for red green and blue using a switch statement
      // *********************************************************
      val = m[r][c];
      switch ( val ) {
          case -1://hit ship  (RED)
            red = 70; green = 0; blue = 0;
          break;
          case 0://hit water  (BLACK)
            red = 0; green = 0; blue = 0;
          break;
          case 1://water  (BLUE)
            red = 0; green = 0; blue =70;
          break;
           case 2://ships are 2,3,4, and 5
          red = 0; green = 50; blue =0;
          break;
            case 3:
          red = 50; green = 25; blue =0;
          break;
            case 4:
          red = 25; green = 50; blue =0;
          break;
          case 5:
          red =32; green = 32; blue =1;
          break;
          default:
          red = 0; green = 0; blue = 0;
          break;
    }//end switch
      // end of set the color *********************************************************
      pixels.setPixelColor(i, pixels.Color(red,green,blue));
      pixels.show(); 
      i++;
       if(val > 1)countColors++;//count is a color is a boat
    }//end c
}//end r    
   if (countColors == 0){done = 1;}  // this check if all the boats were hit
 
//generate random numbers
  newhit =0;
  while((newhit == 0)&& (countColors != 0)){
    x= random(8);
    y = random(8);
    if( s[x][y]== 0){
        s[x][y] = 1;
        newhit = 1;
        totalBombs++;
    }
  }//end generating random numbers

    if ( m[x][y] == 1){  m[x][y] = 0;}  //set a hit to 0 when hitting water
    if ( m[x][y]> 1) { m[x][y] = -1;}  //set a hit to -1 whren hitting a boat
   
    }//end while
    //Serial.print(num);
    Serial.print(" Total Bombs = ");  //type your intials here
    Serial.println(totalBombs);
 
}//end cwc *******************************************************************

