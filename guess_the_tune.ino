/*
  Guess-The-Tune
  by: Mohammed Mushahid Qureshi
*/
#include <LiquidCrystal.h>
#include <stdlib.h>
#include <time.h>

// pitches.h
#define NOTE_B0  31
#define NOTE_C1  33
#define NOTE_CS1 35
#define NOTE_D1  37
#define NOTE_DS1 39
#define NOTE_E1  41
#define NOTE_F1  44
#define NOTE_FS1 46
#define NOTE_G1  49
#define NOTE_GS1 52
#define NOTE_A1  55
#define NOTE_AS1 58
#define NOTE_B1  62
#define NOTE_C2  65
#define NOTE_CS2 69
#define NOTE_D2  73
#define NOTE_DS2 78
#define NOTE_E2  82
#define NOTE_F2  87
#define NOTE_FS2 93
#define NOTE_G2  98
#define NOTE_GS2 104
#define NOTE_A2  110
#define NOTE_AS2 117
#define NOTE_B2  123
#define NOTE_C3  131
#define NOTE_CS3 139
#define NOTE_D3  147
#define NOTE_DS3 156
#define NOTE_E3  165
#define NOTE_F3  175
#define NOTE_FS3 185
#define NOTE_G3  196
#define NOTE_GS3 208
#define NOTE_A3  220
#define NOTE_AS3 233
#define NOTE_B3  247
#define NOTE_C4  262
#define NOTE_CS4 277
#define NOTE_D4  294
#define NOTE_DS4 311
#define NOTE_E4  330
#define NOTE_F4  349
#define NOTE_FS4 370
#define NOTE_G4  392
#define NOTE_GS4 415
#define NOTE_A4  440
#define NOTE_AS4 466
#define NOTE_B4  494
#define NOTE_C5  523
#define NOTE_CS5 554
#define NOTE_D5  587
#define NOTE_DS5 622
#define NOTE_E5  659
#define NOTE_F5  698
#define NOTE_FS5 740
#define NOTE_G5  784
#define NOTE_GS5 831
#define NOTE_A5  880
#define NOTE_AS5 932
#define NOTE_B5  988
#define NOTE_C6  1047
#define NOTE_CS6 1109
#define NOTE_D6  1175
#define NOTE_DS6 1245
#define NOTE_E6  1319
#define NOTE_F6  1397
#define NOTE_FS6 1480
#define NOTE_G6  1568
#define NOTE_GS6 1661
#define NOTE_A6  1760
#define NOTE_AS6 1865
#define NOTE_B6  1976
#define NOTE_C7  2093
#define NOTE_CS7 2217
#define NOTE_D7  2349
#define NOTE_DS7 2489
#define NOTE_E7  2637
#define NOTE_F7  2794
#define NOTE_FS7 2960
#define NOTE_G7  3136
#define NOTE_GS7 3322
#define NOTE_A7  3520
#define NOTE_AS7 3729
#define NOTE_B7  3951
#define NOTE_C8  4186
#define NOTE_CS8 4435
#define NOTE_D8  4699
#define NOTE_DS8 4978

//Peizo pin
#define melodyPin 10
#define BUZZER 10

// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

//Mario main theme melody
int melody[] = {
  NOTE_E7, NOTE_E7, 0, NOTE_E7, 
  0, NOTE_C7, NOTE_E7, 0,
  NOTE_G7, 0, 0,  0,
  NOTE_G6, 0, 0, 0, 

  NOTE_C7, 0, 0, NOTE_G6, 
  0, 0, NOTE_E6, 0, 
  0, NOTE_A6, 0, NOTE_B6, 
  0, NOTE_AS6, NOTE_A6, 0, 

  NOTE_G6, NOTE_E7, NOTE_G7, 
  NOTE_A7, 0, NOTE_F7, NOTE_G7, 
  0, NOTE_E7, 0,NOTE_C7, 
  NOTE_D7, NOTE_B6, 0, 0,

  NOTE_C7, 0, 0, NOTE_G6, 
  0, 0, NOTE_E6, 0, 
  0, NOTE_A6, 0, NOTE_B6, 
  0, NOTE_AS6, NOTE_A6, 0, 

  NOTE_G6, NOTE_E7, NOTE_G7, 
  NOTE_A7, 0, NOTE_F7, NOTE_G7, 
  0, NOTE_E7, 0,NOTE_C7, 
  NOTE_D7, NOTE_B6, 0, 0
};
//Mario main them tempo
int tempo[] = {
  12, 12, 12, 12, 
  12, 12, 12, 12,
  12, 12, 12, 12,
  12, 12, 12, 12, 

  12, 12, 12, 12,
  12, 12, 12, 12, 
  12, 12, 12, 12, 
  12, 12, 12, 12, 

  9, 9, 9,
  12, 12, 12, 12,
  12, 12, 12, 12,
  12, 12, 12, 12,

  12, 12, 12, 12,
  12, 12, 12, 12,
  12, 12, 12, 12,
  12, 12, 12, 12,

  9, 9, 9,
  12, 12, 12, 12,
  12, 12, 12, 12,
  12, 12, 12, 12,
};

//
//Underworld melody
int underworld_melody[] = {
  NOTE_C4, NOTE_C5, NOTE_A3, NOTE_A4, 
  NOTE_AS3, NOTE_AS4, 0,
  0,
  NOTE_C4, NOTE_C5, NOTE_A3, NOTE_A4, 
  NOTE_AS3, NOTE_AS4, 0,
  0,
  NOTE_F3, NOTE_F4, NOTE_D3, NOTE_D4,
  NOTE_DS3, NOTE_DS4, 0,
  0,
  NOTE_F3, NOTE_F4, NOTE_D3, NOTE_D4,
  NOTE_DS3, NOTE_DS4, 0,
  0, NOTE_DS4, NOTE_CS4, NOTE_D4,
  NOTE_CS4, NOTE_DS4, 
  NOTE_DS4, NOTE_GS3,
  NOTE_G3, NOTE_CS4,
  NOTE_C4, NOTE_FS4,NOTE_F4, NOTE_E3, NOTE_AS4, NOTE_A4,
  NOTE_GS4, NOTE_DS4, NOTE_B3,
  NOTE_AS3, NOTE_A3, NOTE_GS3,
  0, 0, 0
};
//Underwolrd tempo
int underworld_tempo[] = {
  12, 12, 12, 12, 
  12, 12, 6,
  3,
  12, 12, 12, 12, 
  12, 12, 6,
  3,
  12, 12, 12, 12, 
  12, 12, 6,
  3,
  12, 12, 12, 12, 
  12, 12, 6,
  6, 18, 18, 18,
  6, 6,
  6, 6,
  6, 6,
  18, 18, 18,18, 18, 18,
  10, 10, 10,
  10, 10, 10,
  3, 3, 3
};

void setup(void)
{
  	int gameOver = 0;
	int code = 0101;
  	char secret[] = "Congratulaions! You discovered the secret ;)";
    
	pinMode(10, OUTPUT);//piezo pin
   	pinMode(13, OUTPUT);//led indicator when singing a note
    // set up the LCD's number of columns and rows:
    lcd.begin(16, 2);
    // Print a message to the LCD.
    lcd.print("hello, world!");
  Serial.begin(9600);
  srand (time(NULL));
}
void loop()
{
  	lcd.print("Guess the tune being played..");
  	int song = rand()% 9;
  	int ans;
  	lcd.clear();
    switch(song) {
      case 0:
      	//closer();
      	lcd.print("0:MarioTheme  1:Closer  2:PPAP  3:StarWarsTheme");
      	ans = 1;
      	break;
      case 1:
      	ppap();
      	lcd.print("0:MarioTheme  1:Closer  2:PPAP  3:StarWarsTheme");
      	ans = 1;
      	break;
      case 2:
      	lcd.print("0:MarioTheme  1:Closer  2:PPAP  3:StarWarsTheme");
      	ans = 1;
      	break;
      case 3:
      	lcd.print("0:MarioTheme  1:Closer  2:PPAP  3:StarWarsTheme");
      	ans = 1;
      	break;
      case 4:
      	lcd.print("0:MarioTheme");
      	delay(1000);
      	lcd.clear();
      	lcd.print("1:Closer  2:PPAP  3:StarWarsTheme");
      	delay(1000);
      	lcd.clear();
      	lcd.print("2:PPAP");
      	delay(1000);
      	lcd.clear();
      	lcd.print("3:StarWarsTheme");
      	closer();
      	ans = 1;
      	break;
      case 5:
      	lcd.print("0:MarioTheme  1:Closer  2:PPAP  3:StarWarsTheme");
      	ans = 1;
	    break;
      case 6:
      	lcd.print("0:MarioTheme  1:Closer  2:PPAP  3:StarWarsTheme");
      	ans = 1;
      	break;
      case 7:
      	lcd.print("0:MarioTheme  1:Closer  2:PPAP  3:StarWarsTheme");
      	ans = 1;
      	break;
      case 8:
      	lcd.print("0:MarioTheme  1:Closer  2:PPAP  3:StarWarsTheme");
      	ans = 1;
      	break;
      case 9:
      	lcd.print("0:MarioTheme  1:Closer  2:PPAP  3:StarWarsTheme");
      	ans = 1;
      	break;
    }
  	Serial.println(song);
  	delay(100);
    int input;
    input = analogRead(A1);
    delay(100);
    if (input>850)
    {
        Serial.print("Key Pressed : ");
        Serial.println("1");
      	lcd.clear();
      	lcd.print("You're correct");
        delay(100);
    }
  	else if (input>510 && input<850)
    {
    	Serial.print("Key Pressed : ");
        Serial.println("2");
        delay(100);
    }
    else if ( input>300  && input<350)
    {
        Serial.print("Key Pressed : ");
        Serial.println("3");
        delay(100);
    }
    else if ( input>230  && input<270)
    {
        Serial.print("Key Pressed : ");
        Serial.println("A");
        delay(100);
    }
    else if ( input>160  && input<180)
    {
        Serial.print("Key Pressed : ");
        Serial.println("4");
        delay(100);
    }
    else if ( input>145  && input<155)
    {
        Serial.print("Key Pressed : ");
        Serial.println("5");
        delay(100);
    }
    else if ( input>125  && input<135)
    {
        Serial.print("Key Pressed : ");
        Serial.println("6");
        delay(100);
    }
    else if ( input>105  && input<120)
    {
        Serial.print("Key Pressed : ");
        Serial.println("B");
        delay(100);
    }
    else if ( input>92  && input<99)
    {
        Serial.print("Key Pressed : ");
        Serial.println("7");
        delay(100);
    }
  	else if ( input>89 && input<92)
    {
      	Serial.print("Key Pressed : ");
        Serial.println("8");
        delay(100);
    }
    else if ( input>82  && input<89)
    {
        Serial.print("Key Pressed : ");
        Serial.println("9");
        delay(100);
    }
    else if ( input>75  && input<81)
    {
        Serial.print("Key Pressed : ");
        Serial.println("C");
        delay(100);
    }
    else if ( input>67  && input<76)
    {
        Serial.print("Key Pressed : ");
        Serial.println("*");
        delay(100);
    }
    else if ( input>63  && input<67)
    {
        Serial.print("Key Pressed : ");
        Serial.println("0");
        delay(100);
    }
    else if ( input>59  && input<62)
    {
        Serial.print("Key Pressed : ");
        Serial.println("#");
        delay(100);
    }
    else if ( input>56  && input<59)
    {
        Serial.print("Key Pressed : ");
        Serial.println("D");
        delay(100);
    }
    else
    {   
    }
    delay(100);
    //sing(1);
    //sing(1);
    //sing(2);
}
int song = 0;

void sing(int s){      
   // iterate over the notes of the melody:
   song = s;
   if(song==2){
     Serial.println(" 'Underworld Theme'");
     int size = sizeof(underworld_melody) / sizeof(int);
     for (int thisNote = 0; thisNote < size; thisNote++) {

       // to calculate the note duration, take one second
       // divided by the note type.
       //e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.
       int noteDuration = 1000/underworld_tempo[thisNote];

       buzz(melodyPin, underworld_melody[thisNote],noteDuration);

       // to distinguish the notes, set a minimum time between them.
       // the note's duration + 30% seems to work well:
       int pauseBetweenNotes = noteDuration * 1.30;
       delay(pauseBetweenNotes);

       // stop the tone playing:
       buzz(melodyPin, 0,noteDuration);

    }

   }else{

     Serial.println(" 'Mario Theme'");
     int size = sizeof(melody) / sizeof(int);
     for (int thisNote = 0; thisNote < size; thisNote++) {

       // to calculate the note duration, take one second
       // divided by the note type.
       //e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.
       int noteDuration = 1000/tempo[thisNote];

       buzz(melodyPin, melody[thisNote],noteDuration);

       // to distinguish the notes, set a minimum time between them.
       // the note's duration + 30% seems to work well:
       int pauseBetweenNotes = noteDuration * 1.30;
       delay(pauseBetweenNotes);

       // stop the tone playing:
       buzz(melodyPin, 0,noteDuration);

    }
  }
}

void buzz(int targetPin, long frequency, long length) {
  digitalWrite(13,HIGH);
  long delayValue = 1000000/frequency/2; // calculate the delay value between transitions
  //// 1 second's worth of microseconds, divided by the frequency, then split in half since
  //// there are two phases to each cycle
  long numCycles = frequency * length/ 1000; // calculate the number of cycles for proper timing
  //// multiply frequency, which is really cycles per second, by the number of seconds to 
  //// get the total number of cycles to produce
  for (long i=0; i < numCycles; i++){ // for the calculated length of time...
    digitalWrite(targetPin,HIGH); // write the buzzer pin high to push out the diaphram
    delayMicroseconds(delayValue); // wait for the calculated delay value
    digitalWrite(targetPin,LOW); // write the buzzer pin low to pull back the diaphram
    delayMicroseconds(delayValue); // wait again or the calculated delay value
  }
  digitalWrite(13,LOW);

}

void closer(){
	tone(BUZZER,NOTE_GS5,130); 
  	delay(  158);
	tone(BUZZER,NOTE_GS5,130); 
  	delay(  158);
	tone(BUZZER,NOTE_GS5,158); 
  	delay(  158);
	tone(BUZZER,NOTE_GS5,310); 
  	delay(316);
    tone(BUZZER,NOTE_AS5,316);
    delay(316);
     tone(BUZZER,NOTE_AS5,225); 
    delay(474);
  tone(BUZZER,NOTE_GS5,70); 
    delay(79);
   tone(BUZZER,NOTE_GS5,130); 
    delay(  158);
     tone(BUZZER,NOTE_GS5,158); 
    delay(  158);
     tone(BUZZER,NOTE_GS5,130); 
    delay(  158);
     tone(BUZZER,NOTE_GS5,130); 
    delay(  158);
     tone(BUZZER,NOTE_GS5,130); 
    delay(  158);
     tone(BUZZER,NOTE_GS5,130); 
    delay(  158);
     tone(BUZZER,NOTE_GS5,130); 
    delay(  158);
     tone(BUZZER,NOTE_GS5,130); 
    delay(  158);
     tone(BUZZER,NOTE_GS5,130); 
    delay(  158);
    tone(BUZZER,NOTE_GS5,158); 
    delay(  158);
    tone(BUZZER,NOTE_GS5,130); 
    delay(  158);
     tone(BUZZER,NOTE_AS5,300); 
    delay(316);

  tone(BUZZER,NOTE_AS5,300); 
    delay(316);
    tone(BUZZER,NOTE_GS5,600); 
    delay(1264);

   tone(BUZZER,NOTE_GS5,300); 
    delay(316);
     tone(BUZZER,NOTE_GS5,300); 
    delay(316);
  tone(BUZZER,NOTE_AS5,300); 
    delay(316);
    tone(BUZZER,NOTE_AS5,225); 
    delay(474);


    tone(BUZZER,NOTE_GS5,70); 
    delay(79);
   tone(BUZZER,NOTE_GS5,158); 
    delay(  158);
     tone(BUZZER,NOTE_GS5,158); 
    delay(  158);
    tone(BUZZER,NOTE_GS5,130); 
    delay(  158);
     tone(BUZZER,NOTE_GS5,130); 
    delay(  158);
     tone(BUZZER,NOTE_GS5,130); 
    delay(  158);
     tone(BUZZER,NOTE_GS5,130); 
    delay(  158);
     tone(BUZZER,NOTE_GS5,130); 
    delay(  158);
     tone(BUZZER,NOTE_GS5,130); 
    delay(  158);
     tone(BUZZER,NOTE_GS5,130); 
    delay(  158);
     tone(BUZZER,NOTE_GS5,130); 
    delay(  158);
   tone(BUZZER,NOTE_AS5,300); 
    delay(316);

  tone(BUZZER,NOTE_AS5,300); 
    delay(316);
  tone(BUZZER,NOTE_GS5,310); 
    delay(316);
      tone(BUZZER,NOTE_AS5,225); 
    delay(500);
  tone(BUZZER,NOTE_C6,95); 
    delay(95);
  tone(BUZZER,NOTE_AS5,225); 
    delay(500);
    tone(BUZZER,NOTE_GS5,95); 
    delay(95);
  tone(BUZZER,NOTE_DS5,620); 
    delay(632);
  tone(BUZZER,NOTE_C6,474); 
    delay(500);
    tone(BUZZER,NOTE_AS5,2307); 
    delay(2607);
    tone(BUZZER,NOTE_GS5,316); 
    delay(316);
    tone(BUZZER,NOTE_AS5,225); 
    delay(500);
  tone(BUZZER,NOTE_C6,95); 
    delay(95);
  tone(BUZZER,NOTE_AS5,225); 
    delay(500);
    tone(BUZZER,NOTE_GS5,95); 
    delay(95);
  tone(BUZZER,NOTE_DS5,620); 
    delay(632);
  tone(BUZZER,NOTE_C6,474); 
    delay(474);
    tone(BUZZER,NOTE_AS5,1303); 
    delay(1615);
  tone(BUZZER,NOTE_GS5,650); 
    delay(1100);

      tone(BUZZER,NOTE_AS5,300); 
    delay(316);

  tone(BUZZER,NOTE_AS5,300); 
    delay(316);

    tone(BUZZER,NOTE_C6,300); 
    delay(316);

      tone(BUZZER,NOTE_GS5,300); 
    delay(316);
      tone(BUZZER,NOTE_AS5,300); 
    delay(316);
      tone(BUZZER,NOTE_AS5,300); 
    delay(316);
      tone(BUZZER,NOTE_C6,300); 
    delay(316);

     tone(BUZZER,NOTE_GS5,300); 
    delay(316);
   tone(BUZZER,NOTE_AS5,300); 
    delay(316);

  tone(BUZZER,NOTE_AS5,300); 
    delay(316);

    tone(BUZZER,NOTE_C6,300); 
    delay(316);

      tone(BUZZER,NOTE_GS5,300); 
    delay(316);
      tone(BUZZER,NOTE_AS5,300); 
    delay(316);
      tone(BUZZER,NOTE_AS5,300); 
    delay(316);
      tone(BUZZER,NOTE_GS5,200); 
    delay(316);

   tone(BUZZER,NOTE_GS5,300); 
    delay(316);
      tone(BUZZER,NOTE_AS5,300); 
    delay(316);
      tone(BUZZER,NOTE_AS5,300); 
    delay(316);

  tone(BUZZER,NOTE_C6,300); 
    delay(316);


   tone(BUZZER,NOTE_GS5,300); 
    delay(316);
      tone(BUZZER,NOTE_AS5,316); 
    delay(316);
      tone(BUZZER,NOTE_AS5,300); 
    delay(632);
  tone(BUZZER,NOTE_GS5,300); 
    delay(316);
   tone(BUZZER,NOTE_AS5,316); 
    delay(316);
      tone(BUZZER,NOTE_AS5,316); 
    delay(316);
    tone(BUZZER,NOTE_GS5,300); 
    delay(316);
  tone(BUZZER,NOTE_GS5,300); 
    delay(316);
   tone(BUZZER,NOTE_AS5,316); 
    delay(316); 
    tone(BUZZER,NOTE_AS5,316); 
    delay(316);
     tone(BUZZER,NOTE_GS5,300); 
    delay(316);
    tone(BUZZER,NOTE_GS5,300); 
    delay(316);
    tone(BUZZER,NOTE_GS5,300); 
    delay(316);
   tone(BUZZER,NOTE_AS5,316); 
    delay(316);
   tone(BUZZER,NOTE_C6,300); 
    delay(316);
   tone(BUZZER,NOTE_GS5,300); 
    delay(316);
     tone(BUZZER,NOTE_AS5,316); 
    delay(316);
   tone(BUZZER,NOTE_AS5,316); 
    delay(316);
  tone(BUZZER,NOTE_C6,300); 
    delay(316);
  tone(BUZZER,NOTE_GS5,300); 
    delay(316);
     tone(BUZZER,NOTE_AS5,316); 
    delay(316);
   tone(BUZZER,NOTE_AS5,316); 
    delay(316);
  tone(BUZZER,NOTE_C6,300); 
    delay(316);
    tone(BUZZER,NOTE_GS5,300); 
    delay(316);
     tone(BUZZER,NOTE_AS5,316); 
    delay(316);
   tone(BUZZER,NOTE_AS5,316); 
    delay(632);

    tone(BUZZER,NOTE_GS5,300); 
    delay(316);
     tone(BUZZER,NOTE_GS5,300); 
    delay(316);
    tone(BUZZER,NOTE_GS5,26); 
    delay(26);
   tone(BUZZER,NOTE_AS5,290); 
    delay(290);
    tone(BUZZER,NOTE_GS5,300); 
    delay(316);
     tone(BUZZER,NOTE_GS5,300); 
    delay(316);
  tone(BUZZER,NOTE_AS5,316); 
    delay(316);
   tone(BUZZER,NOTE_AS5,316); 
    delay(316);
    tone(BUZZER,NOTE_GS5,200); 
    delay(316);
     tone(BUZZER,NOTE_GS5,300); 
    delay(316);
    tone(BUZZER,NOTE_C6,300); 
    delay(316);
    tone(BUZZER,NOTE_C6,300); 
    delay(316);
    tone(BUZZER,NOTE_GS5,300); 
    delay(316);
    tone(BUZZER,NOTE_GS5,300); 
    delay(316);
    tone(BUZZER,NOTE_AS5,316); 
    delay(316);
    tone(BUZZER,NOTE_AS5,316); 
    delay(316);
     tone(BUZZER,NOTE_GS5,3000); 
    delay(3160);
}

void ppap() {
tone(BUZZER,NOTE_CS7,200); // Sets pin 7 with a frequency of 300Hz 
  delay(220);
tone(BUZZER,NOTE_B6,200); // Sets pin 7 with a frequency of 300Hz 
  delay(220);
tone(BUZZER,NOTE_GS6,200); // Sets pin 7 with a frequency of 300Hz 
  delay(220);
tone(BUZZER,NOTE_FS6,200); // Sets pin 7 with a frequency of 300Hz 
  delay(220);
  tone(BUZZER,NOTE_CS6,200); // Sets pin 7 with a frequency of 300Hz 
  delay(220);
tone(BUZZER,NOTE_B5,200); // Sets pin 7 with a frequency of 300Hz 
  delay(220);
tone(BUZZER,NOTE_GS5,200); // Sets pin 7 with a frequency of 300Hz 
  delay(220);
tone(BUZZER,NOTE_FS5,200); // Sets pin 7 with a frequency of 300Hz 
  delay(220);


tone(BUZZER,NOTE_CS5,200); // Sets pin 7 with a frequency of 300Hz 
  delay(220);
tone(BUZZER,NOTE_B4,200); // Sets pin 7 with a frequency of 300Hz 
  delay(220);
tone(BUZZER,NOTE_GS4,200); // Sets pin 7 with a frequency of 300Hz 
  delay(220);
tone(BUZZER,NOTE_FS4,200); // Sets pin 7 with a frequency of 300Hz 
  delay(220);
  tone(BUZZER,NOTE_CS4,200); // Sets pin 7 with a frequency of 300Hz 
  delay(220);
tone(BUZZER,NOTE_B3,200); // Sets pin 7 with a frequency of 300Hz 
  delay(220);
tone(BUZZER,NOTE_GS3,200); // Sets pin 7 with a frequency of 300Hz 
  delay(220);
tone(BUZZER,NOTE_FS3,200); // Sets pin 7 with a frequency of 300Hz 
  delay(220);

  
tone(BUZZER,NOTE_CS4,55); 
  delay(55);
tone(BUZZER,NOTE_DS4,55); 
  delay(55);
tone(BUZZER,NOTE_E4,55); 
  delay(55);
tone(BUZZER,NOTE_FS4,55); 
  delay(55);
tone(BUZZER,NOTE_GS4,55); 
  delay(55);
tone(BUZZER,NOTE_A4,55); 
  delay(55);
tone(BUZZER,NOTE_B4,55); 
  delay(55);

tone(BUZZER,NOTE_CS5,55); 
  delay(55);
tone(BUZZER,NOTE_DS5,55); 
  delay(55);
tone(BUZZER,NOTE_E5,55); 
  delay(55);
tone(BUZZER,NOTE_FS5,55); 
  delay(55);
tone(BUZZER,NOTE_GS5,55); 
  delay(55);
tone(BUZZER,NOTE_A5,55); 
  delay(55);
tone(BUZZER,NOTE_B5,55); 
  delay(55);
tone(BUZZER,NOTE_CS6,55); 
  delay(55);
tone(BUZZER,NOTE_DS6,55); 
  delay(55);

tone(BUZZER,NOTE_CS7,110); 
  delay(882);

tone(BUZZER,NOTE_CS7,110); 
  delay(882);


  tone(BUZZER,NOTE_CS7,55); 
  delay(441);
  tone(BUZZER,NOTE_CS7,40); 
  delay(1323);




tone(BUZZER,NOTE_CS5,110); 
  delay(220);
tone(BUZZER,NOTE_CS5,110); 
  delay(220);
tone(BUZZER,NOTE_CS6,110); 
  delay(220);
tone(BUZZER,NOTE_CS5,110); 
  delay(220);
tone(BUZZER,NOTE_CS5,110); 
  delay(220);
  tone(BUZZER,NOTE_CS5,110); 
  delay(220);
  tone(BUZZER,NOTE_CS6,110); 
  delay(220);
tone(BUZZER,NOTE_CS5,110); 
  delay(220);
tone(BUZZER,NOTE_CS5,110); 
  delay(220);
  tone(BUZZER,NOTE_CS5,110); 
  delay(220);
  tone(BUZZER,NOTE_CS6,110); 
  delay(220);
  tone(BUZZER,NOTE_CS5,110); 
  delay(441);

tone(BUZZER,NOTE_GS5,110); 
  delay(220);
tone(BUZZER,NOTE_B5,110); 
  delay(220);
  tone(BUZZER,NOTE_B5,110); 
  delay(220);


tone(BUZZER,NOTE_CS5,110); 
  delay(220);
tone(BUZZER,NOTE_CS5,110); 
  delay(220);
tone(BUZZER,NOTE_CS6,110); 
  delay(220);
tone(BUZZER,NOTE_CS5,110); 
  delay(220);
tone(BUZZER,NOTE_CS5,110); 
  delay(220);
  tone(BUZZER,NOTE_CS5,110); 
  delay(220);
  tone(BUZZER,NOTE_CS6,110); 
  delay(220);
tone(BUZZER,NOTE_CS5,110); 
  delay(220);
tone(BUZZER,NOTE_CS5,110); 
  delay(220);
  tone(BUZZER,NOTE_CS5,110); 
  delay(220);
  tone(BUZZER,NOTE_CS6,110); 
  delay(220);
  tone(BUZZER,NOTE_CS5,110); 
  delay(441);

tone(BUZZER,NOTE_B4,110); 
  delay(220);
tone(BUZZER,NOTE_B4,110); 
  delay(220);
  tone(BUZZER,NOTE_B4,110); 
  delay(220);

  tone(BUZZER,NOTE_CS5,110); 
  delay(220);
tone(BUZZER,NOTE_CS5,110); 
  delay(220);
tone(BUZZER,NOTE_CS6,110); 
  delay(220);
tone(BUZZER,NOTE_CS5,110); 
  delay(220);
tone(BUZZER,NOTE_CS5,110); 
  delay(220);
  tone(BUZZER,NOTE_CS5,110); 
  delay(220);
  tone(BUZZER,NOTE_CS6,110); 
  delay(220);
tone(BUZZER,NOTE_CS5,110); 
  delay(220);
tone(BUZZER,NOTE_CS5,110); 
  delay(220);
  tone(BUZZER,NOTE_CS5,110); 
  delay(220);
  tone(BUZZER,NOTE_CS6,110); 
  delay(220);
  tone(BUZZER,NOTE_CS5,110); 
  delay(441);

tone(BUZZER,NOTE_GS5,110); 
  delay(220);
tone(BUZZER,NOTE_B5,110); 
  delay(220);
  tone(BUZZER,NOTE_B5,110); 
  delay(220);


tone(BUZZER,NOTE_CS5,110); 
  delay(220);
tone(BUZZER,NOTE_CS5,110); 
  delay(220);
tone(BUZZER,NOTE_CS6,110); 
  delay(220);
tone(BUZZER,NOTE_CS5,110); 
  delay(220);
tone(BUZZER,NOTE_CS5,110); 
  delay(220);
  tone(BUZZER,NOTE_CS5,110); 
  delay(220);
  tone(BUZZER,NOTE_CS6,110); 
  delay(220);
tone(BUZZER,NOTE_CS5,110); 
  delay(220);
tone(BUZZER,NOTE_CS5,110); 
  delay(220);
  tone(BUZZER,NOTE_CS5,110); 
  delay(220);
  tone(BUZZER,NOTE_CS6,110); 
  delay(220);
  tone(BUZZER,NOTE_CS5,110); 
  delay(441);

tone(BUZZER,NOTE_B4,110); 
  delay(220);
tone(BUZZER,NOTE_B4,110); 
  delay(220);
  tone(BUZZER,NOTE_B4,110); 
  delay(220);


  tone(BUZZER,NOTE_CS5,110); 
  delay(220);
tone(BUZZER,NOTE_CS5,110); 
  delay(220);
tone(BUZZER,NOTE_CS6,110); 
  delay(220);
tone(BUZZER,NOTE_CS5,110); 
  delay(220);
tone(BUZZER,NOTE_CS5,110); 
  delay(220);
  tone(BUZZER,NOTE_CS5,110); 
  delay(220);
  tone(BUZZER,NOTE_CS6,110); 
  delay(220);
tone(BUZZER,NOTE_CS5,110); 
  delay(220);
tone(BUZZER,NOTE_CS5,110); 
  delay(220);
  tone(BUZZER,NOTE_CS5,110); 
  delay(220);
  tone(BUZZER,NOTE_CS6,110); 
  delay(220);
  tone(BUZZER,NOTE_CS5,110); 
  delay(441);

tone(BUZZER,NOTE_GS5,110); 
  delay(220);
tone(BUZZER,NOTE_B5,110); 
  delay(220);
  tone(BUZZER,NOTE_B5,110); 
  delay(220);


tone(BUZZER,NOTE_CS5,110); 
  delay(220);
tone(BUZZER,NOTE_CS5,110); 
  delay(220);
tone(BUZZER,NOTE_CS6,110); 
  delay(220);
tone(BUZZER,NOTE_CS5,110); 
  delay(220);
tone(BUZZER,NOTE_CS5,110); 
  delay(220);
  tone(BUZZER,NOTE_CS5,110); 
  delay(220);
  tone(BUZZER,NOTE_CS6,110); 
  delay(220);
tone(BUZZER,NOTE_CS5,110); 
  delay(220);
tone(BUZZER,NOTE_CS5,110); 
  delay(220);
  tone(BUZZER,NOTE_CS5,110); 
  delay(220);
  tone(BUZZER,NOTE_CS6,110); 
  delay(220);
  tone(BUZZER,NOTE_CS5,110); 
  delay(441);

tone(BUZZER,NOTE_B4,110); 
  delay(220);
tone(BUZZER,NOTE_B4,110); 
  delay(220);
  tone(BUZZER,NOTE_B4,110); 
  delay(220);

  tone(BUZZER,NOTE_CS5,110); 
  delay(220);
tone(BUZZER,NOTE_CS5,110); 
  delay(220);
tone(BUZZER,NOTE_CS6,110); 
  delay(220);
tone(BUZZER,NOTE_CS5,110); 
  delay(220);
tone(BUZZER,NOTE_CS5,110); 
  delay(220);
  tone(BUZZER,NOTE_CS5,110); 
  delay(220);
  tone(BUZZER,NOTE_CS6,110); 
  delay(220);
tone(BUZZER,NOTE_CS5,110); 
  delay(220);
tone(BUZZER,NOTE_CS5,110); 
  delay(220);
  tone(BUZZER,NOTE_CS5,110); 
  delay(220);
  tone(BUZZER,NOTE_CS6,110); 
  delay(220);
  tone(BUZZER,NOTE_CS5,110); 
  delay(441);

tone(BUZZER,NOTE_GS5,110); 
  delay(220);
tone(BUZZER,NOTE_B5,110); 
  delay(220);
  tone(BUZZER,NOTE_B5,110); 
  delay(220);


tone(BUZZER,NOTE_CS5,110); 
  delay(220);
tone(BUZZER,NOTE_CS5,110); 
  delay(220);
tone(BUZZER,NOTE_CS6,110); 
  delay(220);
tone(BUZZER,NOTE_CS5,110); 
  delay(220);
tone(BUZZER,NOTE_CS5,110); 
  delay(220);
  tone(BUZZER,NOTE_CS5,110); 
  delay(220);
  tone(BUZZER,NOTE_CS6,110); 
  delay(220);
tone(BUZZER,NOTE_CS5,110); 
  delay(220);
tone(BUZZER,NOTE_CS5,110); 
  delay(220);
  tone(BUZZER,NOTE_CS5,110); 
  delay(220);
  tone(BUZZER,NOTE_CS6,110); 
  delay(220);
  tone(BUZZER,NOTE_CS5,110); 
  delay(441);

tone(BUZZER,NOTE_B4,110); 
  delay(220);
tone(BUZZER,NOTE_B4,110); 
  delay(220);
  tone(BUZZER,NOTE_B4,110); 
  delay(220);
}
