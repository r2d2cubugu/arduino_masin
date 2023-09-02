// #include <QTRSensors.h>

// Qirmizi en yaxin 100
// 10sm, ucun 220


// Yasil en yaxin 50-60
// 10sm ucun 80-95

//45 RED YAXIN
//18sm 400
//10sm 270-290 arasi sm
//10sm GRE 700-800 arasi
//Yaxinda 200 220

#define S1 A5
#define S0 8
#define S3 A2
#define S2 A1
#define sensorOut 12
#define solpwm1 11
#define solpwm2 3
#define sagpwm1 9
#define sagpwm2 10
#define sagsensor A3
#define solsensor A4
#define onsensor A0
#define DS1 4
#define DS2 5
#define DS3 6

// // QTRSensors qtr;
// const uint8_t SensorCount = 1;
// uint16_t sensorValues[SensorCount];

// int blue = 140;
// int white = 0;
int redFrequency = 0;
int greenFrequency = 0;
int blueFrequency = 0;
int nofilter = 0;
int redColor = 0;
int greenColor = 0;
int blueColor = 0;
int nofilterColor = 0;
int Round=0;
// int blueFrequency = 0;
void setup() {
// put your setup code here, to run once:
// qtr.setTypeAnalog();
// qtr.setSensorPins((const uint8_t[]){ A0 }, 1);
// qtr.setEmitterPin(1);
// pinMode(yer, INPUT_PULLUP);
  pinMode(S0, OUTPUT);
  pinMode(S1, OUTPUT);
  pinMode(S2, OUTPUT);
  pinMode(S3, OUTPUT);
  pinMode(DS1, INPUT_PULLUP);
  pinMode(DS2, INPUT_PULLUP);
  pinMode(DS3, INPUT_PULLUP);
  
  // Setting the sensorOut as an input
  pinMode(sensorOut, INPUT);
  pinMode(solpwm1, OUTPUT);
  pinMode(solpwm2, OUTPUT);
  pinMode(sagpwm1, OUTPUT);
  pinMode(sagpwm2, OUTPUT);
  pinMode(sagsensor, INPUT_PULLUP);
  pinMode(solsensor, INPUT_PULLUP);
  pinMode(onsensor, INPUT_PULLUP);
  digitalWrite(S0, HIGH);
  digitalWrite(S1, LOW);
  Serial.begin(9600);

  delay(2000);
}
int donmeistiqameti=0; //0 olanda sola dönür 1 olanda sağa dönür
int donmevaxti = 200;

void loop() {
  if (digitalRead(DS1) == 1 && digitalRead(DS2) == 1) {
donmeistiqameti=0;
   }else if(digitalRead(DS1) == 0 && digitalRead(DS2) == 0){
     donmeistiqameti=1;
   }

if(digitalRead(DS3) == 0){
  Round=1 ;
}else{
  Round=2 ;
}
  digitalWrite(S2, LOW);
  digitalWrite(S3, LOW);

  redFrequency = pulseIn(sensorOut, LOW);
   redColor = map(redFrequency, 253, 750, 255,0);

  Serial.print("R = ");
  Serial.print(redColor);
    Serial.print("  ");
  Serial.print(redFrequency);
  
  delay(100);

  digitalWrite(S2, HIGH);
  digitalWrite(S3, HIGH);

  greenFrequency = pulseIn(sensorOut, LOW);
  greenColor = map(greenFrequency, 200, 880, 255, 0);

  Serial.print(" G = ");
  Serial.print(greenColor);
    Serial.print("  ");
  Serial.print(greenFrequency);
  delay(100);

  digitalWrite(S2, LOW);
  digitalWrite(S3, HIGH);
  
  // Reading the output frequency
  blueFrequency = pulseIn(sensorOut, LOW);
  blueColor = map(blueFrequency, 269, 855, 255, 0);
  // Printing the BLUE (B) value 
  Serial.print(" B = ");
  Serial.print(blueColor);
  Serial.print("  ");
  Serial.println(blueFrequency);
  
  delay(100);

  digitalWrite(S2, HIGH );
  digitalWrite(S3, LOW);
  
  // Reading the output frequency

 

  get(100, 100);
  if (digitalRead(onsensor) == LOW) {
    if(round==1){
      if(donmeistiqameti==0){
        Soladon(1200);
      }else if(donmeistiqameti==1){
        Sagadon(1200);
      }
}else if(round==2){
   if(redColor>greenColor&&blueColor>redColor){
    Sagadon(400);
  }else if(blueColor>redColor&&blueColor>greenColor){
     if(donmeistiqameti==0){
        Soladon(1200);
      }else if(donmeistiqameti==1){
        Sagadon(1200);
      }
  }else{
    Soladon(400);
  }
}
    }
  if(digitalRead(solsensor) == LOW&&digitalRead(sagsensor) == LOW){
    get(-50,1);
    if(donmeistiqameti==0){
      Soladon(400);
    }else{
      Sagadon(400);
    }
    get(100,100);
    
  }
 else if (digitalRead(solsensor) == LOW) {
    Sagadon(donmevaxti);
    get(50, 1);

  } else if (digitalRead(sagsensor) == LOW) {
    Soladon(donmevaxti);
    get(50, 1);
  }


}

void Soladon(int time) {
  don(-30, 150);
  don(0, time);
  don(30, 75);
  don(0, 1);
}

void Sagadon(int time) {
  don(30, 150);
  don(0, time);
  don(-30, 75);
  don(0, 1);
}
void get(float suret, int timex) {
  suret = suret * 2.5;
  if (suret >= 0) {
    analogWrite(sagpwm1, suret);
    digitalWrite(sagpwm2, LOW);
  } else {
    suret = abs(suret);
    digitalWrite(sagpwm1, LOW);
    analogWrite(sagpwm2, suret);
  }
  delay(timex);
}
void don(float suret, int timex) {
  suret = suret * 2.5;

  if (suret >= 0) {
    analogWrite(solpwm1, suret);
    digitalWrite(solpwm2, LOW);
  } else {
    suret = abs(suret);
    digitalWrite(solpwm1, LOW);
    analogWrite(solpwm2, suret);
  }
  delay(timex);
}