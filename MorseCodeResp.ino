/* Morse Code Response 
  10/22/24  Lloyd Johnson
  2/15/25 Lloyd Johnson - Modified to repeat random message 3 times before a new message
                        - Also. the delay time before response is reduced from 30 seconds to 10 seconds
*/


#include <Wire.h>    // For RTC
#include <ds3231.h>  // For RTC
#define RLY_ON LOW
#define RLY_OFF HIGH
#define dit_del 200
#define TRUE 1
#define FALSE 0


int K2 = 2;         // Relay Module connections
int K1 = 3;         // Relay Module connections
int K3=  4;         // Relay Module connections

// Global Variables
struct ts t;        // Time Structure

// Optical Isolator variables
int oip=2;  // analog pin connected to optical isolator
int oiv;   // Optical Isolator Value
int dtc;   // dead time count 
int cst = FALSE;   // Counter Start Flag
int mrc = 3;  // Message Response Count - Initialized to 3 so 
              // a new message is selected.
int i;   // increment variable
int msel;  // Message Selected

void setup() {
  // RTC Stuff
  Serial.begin(9600);
  Wire.begin();
  DS3231_init(DS3231_CONTROL_INTCN);

  // Relay Module Stuff
  pinMode(K3, OUTPUT);
  pinMode(K2, OUTPUT);
  pinMode(K1, OUTPUT);
  digitalWrite(K1, RLY_OFF);
  digitalWrite(K2, RLY_OFF);
  digitalWrite(K3, RLY_OFF);

  randomSeed(analogRead(0));  // Reading an analog pin with nothing connected.

}

void loop() {
  // put your main code here, to run repeatedly:
  int hour_val;   // hour value
  int chimeTime;

  chimeTime=FALSE;

  DS3231_get(&t);
  Serial.print("Date : ");
  Serial.print(t.mday);
  Serial.print("/");
  Serial.print(t.mon);
  Serial.print("/");
  Serial.print(t.year);
  Serial.print("\t Hour : ");
  Serial.print(t.hour);
  Serial.print(":");
  Serial.print(t.min);
  Serial.print(".");
  Serial.println(t.sec);

  if((t.min==0)&& (t.sec==0)) chimeTime=TRUE;

  if ((cst==TRUE) && (dtc>100)) {  // Using 10 seconds now
    // Time for a message
    cst=FALSE;

    if (mrc==3) {
      msel=random(10)+1;  // Random number from 1 to 10
      mrc=1;   
    } else {
      mrc++;
    }

    switch (msel) {
      case 1:
        Msg01();
        break;
      case 2:
        Msg02();
        break;
      case 3:
        Msg03();
        break;
      case 4:
        Msg04();
        break;
      case 5:
        Msg05();
        break;
      case 6:
        Msg06();
        break;
      case 7:
        Msg07();
        break;
      case 8:
        Msg08();
        break;
      case 9:
        Msg09();
        break;
      case 10:
        Msg10();
        break;
    }
  } 


  hour_val=t.hour;
  if (chimeTime){

    switch(hour_val)  {
      case 0:
        dah();dah();dah();dah();dah(); // -----
        delay(dit_del*3);
        dah();dah();dah();dah();dah(); // -----
        delay(dit_del*3);
        break;
      case 1:
        dah();dah();dah();dah();dah(); // -----
        delay(dit_del*3);
        dit();dah();dah();dah();dah(); // .----
        delay(dit_del*3);
        break;
      case 2:
        dah();dah();dah();dah();dah(); // -----
        delay(dit_del*3);
        dit();dit();dah();dah();dah(); // ..---
        delay(dit_del*3);
        break;
      case 3:
        dah();dah();dah();dah();dah(); // -----
        delay(dit_del*3);
        dit();dit();dit();dah();dah(); // ...--
        delay(dit_del*3);
        break;
      case 4:
        dah();dah();dah();dah();dah(); // -----
        delay(dit_del*3);
        dit();dit();dit();dit();dah(); // ....-
        delay(dit_del*3);
        break;
      case 5:
        dah();dah();dah();dah();dah(); // -----
        delay(dit_del*3);
        dit();dit();dit();dit();dit(); // .....
        delay(dit_del*3);
        break;
      case 6:
        dah();dah();dah();dah();dah(); // -----
        delay(dit_del*3);
        dah();dit();dit();dit();dit(); // -....
        delay(dit_del*3);
        break;
      case 7:
        dah();dah();dah();dah();dah(); // -----
        delay(dit_del*3);
        dah();dah();dit();dit();dit(); // --...
        delay(dit_del*3);
        break;
      case 8:
        dah();dah();dah();dah();dah(); // -----
        delay(dit_del*3);
        dah();dah();dah();dit();dit(); // ---..
        delay(dit_del*3);
        break;
      case 9:
        dah();dah();dah();dah();dah(); // -----
        delay(dit_del*3);
        dah();dah();dah();dah();dit(); // ----.
        delay(dit_del*3);
        break;
      case 10:
        dit();dah();dah();dah();dah(); // .----
        delay(dit_del*3);
        dah();dah();dah();dah();dah(); // -----
        delay(dit_del*3);
        break;
      case 11:
        dit();dah();dah();dah();dah(); // .----
        delay(dit_del*3);
        dit();dah();dah();dah();dah(); // .----
        delay(dit_del*3);
        break;
      case 12:
        dit();dah();dah();dah();dah(); // .----
        delay(dit_del*3);
        dit();dit();dah();dah();dah(); // ..---
        delay(dit_del*3);
        break;
      case 13:
        dit();dah();dah();dah();dah(); // .----
        delay(dit_del*3);
        dit();dit();dit();dah();dah(); // ...--
        delay(dit_del*3);
        break;
      case 14:
        dit();dah();dah();dah();dah(); // .----
        delay(dit_del*3);
        dit();dit();dit();dit();dah(); // ....-
        delay(dit_del*3);
        break;
      case 15:
        dit();dah();dah();dah();dah(); // .----
        delay(dit_del*3);
        dit();dit();dit();dit();dit(); // .....
        delay(dit_del*3);
        break;
      case 16:
        dit();dah();dah();dah();dah(); // .----
        delay(dit_del*3);
        dah();dit();dit();dit();dit(); // -....
        delay(dit_del*3);
        break;
      case 17:
        dit();dah();dah();dah();dah(); // .----
        delay(dit_del*3);
        dah();dah();dit();dit();dit(); // --...
        delay(dit_del*3);
        break;
      case 18:
        dit();dah();dah();dah();dah(); // .----
        delay(dit_del*3);
        dah();dah();dah();dit();dit(); // ---..
        delay(dit_del*3);
        break;
      case 19:
        dit();dah();dah();dah();dah(); // .----
        delay(dit_del*3);
        dah();dah();dah();dah();dit(); // ----.
        delay(dit_del*3);
        break;
      case 20:
        dit();dit();dah();dah();dah(); // ..---
        delay(dit_del*3);
        dah();dah();dah();dah();dah(); // -----
        delay(dit_del*3);
        break;
      case 21:
        dit();dit();dah();dah();dah(); // ..---
        delay(dit_del*3);
        dah();dah();dah();dah();dah(); // -----
        delay(dit_del*3);
        break;
      case 22:
        dit();dit();dah();dah();dah(); // ..---
        delay(dit_del*3);
        dit();dit();dah();dah();dah(); // ..---
        delay(dit_del*3);
        break;
      case 23:
        dit();dit();dah();dah();dah(); // ..---
        delay(dit_del*3);
        dit();dit();dit();dah();dah(); // ...--
        delay(dit_del*3);
        break;
    }  // End switch

    for (i=0;i<99;i++) {  // 10 second monitored delay
      tp100ms();
    }
  } // if (chimeTime){
    for (i=0;i<9;i++) {  // 1 second monitored delay
      tp100ms();
    }

}
void dit() {
    digitalWrite(K3, RLY_ON);
    delay(dit_del);
    digitalWrite(K3, RLY_OFF);
    delay(dit_del);
}

void dah() {
    digitalWrite(K3, RLY_ON);
    delay(3*dit_del);
    digitalWrite(K3, RLY_OFF);
    delay(dit_del);
}

void Msg01() {
  T();H();E(); 
    delay(9*dit_del);
  Q();U();I();C();K();
      delay(9*dit_del);
  B();R();O();W();N();
      delay(9*dit_del);
  f();O();X();
      delay(9*dit_del);
}
void Msg02() {
  J();U();M();P();E();D(); 
    delay(9*dit_del);
  O();V();E();R();
      delay(9*dit_del);
  T();H();E();
      delay(9*dit_del);
}

void Msg03() {
  L();A();Z();Y();
      delay(9*dit_del);
  B();L();A();C();K();
      delay(9*dit_del);
  D();O();G();
      delay(9*dit_del);
}
void Msg04() {
  W();H();O();
      delay(9*dit_del);
  A();R();E();
      delay(9*dit_del);
  Y();O();U();
      delay(9*dit_del);
}
void Msg05() {
  W();H();E();R();E();
      delay(9*dit_del);
  A();R();E();
      delay(9*dit_del);
  Y();O();U();
      delay(9*dit_del);
}
void Msg06() {
  I();
      delay(9*dit_del);
  A();M();
      delay(9*dit_del);
  A();N();
      delay(9*dit_del);  
  A();R();D();U();I();N();O();
      delay(9*dit_del);
}
void Msg07() {
  P();L();E();A();S();E();
      delay(9*dit_del);
  R();E();P();E();A();T();
      delay(9*dit_del);
  L();A();S();T();
      delay(9*dit_del);  
  M();E();S();S();A();G();E();
      delay(9*dit_del);
}
void Msg08() {
  W();H();A();T();
      delay(9*dit_del);
  Y();E();A();R();
      delay(9*dit_del);
  I();S();
      delay(9*dit_del);  
  T();H();I();S();
      delay(9*dit_del);
}

void Msg09() {
  I();
      delay(9*dit_del);
  D();O();
      delay(9*dit_del);
  N();O();T();
      delay(9*dit_del);  
  U();N();D();E();R();S();T();A();N();D();
      delay(9*dit_del);
}
void Msg10() {
  A();R();E();
      delay(9*dit_del);
  Y();O();U();
      delay(9*dit_del);
  A();L();I();V();E();
      delay(9*dit_del);  
}
void A() {
  dit();dah();  // .-
  delay(dit_del*3);
}
void B() {
  dah();dit();dit();dit();  // -...
  delay(dit_del*3);
}
void C() {
  dah();dit();dah();dit();  // -.-.
  delay(dit_del*3);
}
void D() {
  dah();dit();dit();  // -..
  delay(dit_del*3);
}
void E() {
  dit();  // .  
  delay(dit_del*3);
}
void f() {
  dit();dit();dah();dit();  // ..-.
  delay(dit_del*3);
}
void G() {
  dah();dah();dit();  // --.
  delay(dit_del*3);
}
void H() {
  dit();dit();dit();dit();  // ....
  delay(dit_del*3);
}
void I() {
  dit();dit();  // ..
  delay(dit_del*3);
}
void J() {
  dit();dah();dah();dah();  // .---
  delay(dit_del*3);
}
void K() {
  dah();dit();dah();  // -.-
  delay(dit_del*3);
}
void L() {
  dit();dah();dit();dit();  // .-..
  delay(dit_del*3);
}
void M() {
  dah();dah();  // --
  delay(dit_del*3);
}
void N() {
  dah();dit(); // -.
  delay(dit_del*3);
}
void O() {
  dah();dah();dah();  // ---
  delay(dit_del*3);
}
void P() {
  dit();dah();dah();dit();  // .--.
  delay(dit_del*3);
}
void Q() {
  dah();dah();dit();dah(); // --.-
  delay(dit_del*3);
}
void R() {
  dit();dah();dit();  // .-.
  delay(dit_del*3);
}
void S() {
  dit();dit();dit();  // ...
  delay(dit_del*3);
}
void T() {
  dah(); // -
  delay(dit_del*3);
}
void U() {
  dit();dit();dah();  // ..-
  delay(dit_del*3);
}
void V() {
  dit();dit();dit();dah();  // ...-
  delay(dit_del*3);
}
void W() {
  dit();dah();dah(); // .--
  delay(dit_del*3);
}
void X() {
  dah();dit();dit();dah();  // -..-
  delay(dit_del*3);
}
void Y() {
  dah();dit();dah();dah();  // -.--
  delay(dit_del*3);
}
void Z() {
  dah();dah();dit();dit(); // --..
  delay(dit_del*3);
}

void tp100ms() {
  oiv=analogRead(oip);
  if (oiv>15) {  //Key press detected
    cst = TRUE;  // Start Counter
    dtc = 0;   // zero dead time count
  }
  if (cst) dtc=dtc+1;  // increment dead time
  delay(100);  // A 100 millisecond delay
}
