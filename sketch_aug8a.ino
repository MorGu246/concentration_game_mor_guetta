#define RedLed 2
#define YellowLed 3
#define GreenLed 4
#define BlueLed 12
#define RedBtn 5
#define YellowBtn 6
#define GreenBtn 7
#define BlueBtn 8
#define buzzerPin 10
#define NUM_OF_LEDS 4
int Leds[NUM_OF_LEDS]={RedLed,YellowLed,GreenLed,BlueLed};
int Btns[NUM_OF_LEDS]={RedBtn,YellowBtn,GreenBtn,BlueBtn};
int rnd;
int CurrBtn;
int LastBtn;
unsigned long LastPressTime;
int score=0;
void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
randomSeed(analogRead(A1));
for(int i=0;i<NUM_OF_LEDS;i++){
  pinMode(Leds[i],OUTPUT);
}
for(int i=0;i<NUM_OF_LEDS;i++){
  pinMode(Btns[i],INPUT_PULLUP);
}

LastPressTime=millis();


rnd=random(0,NUM_OF_LEDS);
for(int i=0;i<NUM_OF_LEDS;i++){
  if(i==rnd){
    digitalWrite(Leds[i],LOW);
  } else{
    digitalWrite(Leds[i],HIGH);
  }
}
delay(1000);
for(int i=0;i<NUM_OF_LEDS;i++){
 digitalWrite(Leds[i],LOW); 
}
delay(500);
tone(buzzerPin, 500, 300);
delay(300);

}

void Victory(){
  digitalWrite(GreenLed,HIGH);
  tone(buzzerPin, 784,300);
  delay(500);
  digitalWrite(GreenLed,LOW);
  noTone(buzzerPin);
  delay(500);
}


void loop() {
  // put your main code here, to run repeatedly:

for(int i=0;i<NUM_OF_LEDS;i++){
CurrBtn=digitalRead(Btns[i]);
if((CurrBtn==LOW)&&(LastBtn==HIGH)&&(millis()-LastPressTime>50)){
  LastPressTime=millis();
  if(i==rnd){
    digitalWrite(RedLed,HIGH);
    tone(buzzerPin, 400, 300);
    delay(500);
    digitalWrite(RedLed,LOW);
  } else {
    score++;
    Serial.println(score);
    delay(200);
  }
}
LastBtn=CurrBtn;
}
if(score==3){
  Victory();
if(digitalRead(GreenBtn)==LOW){
  score=4;
  for(int i=0;i<NUM_OF_LEDS;i++){
    digitalWrite(Leds[i],LOW);
  }
}
}
}

