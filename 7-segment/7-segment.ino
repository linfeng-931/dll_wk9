
byte seven_seg_digits[10][7] = { { 1,1,1,1,1,1,0 }, // = 0

{ 0,1,1,0,0,0,0 }, // = 1

{ 1,1,0,1,1,0,1 }, // = 2

{ 1,1,1,1,0,0,1 }, // = 3

{ 0,1,1,0,0,1,1 }, // = 4

{ 1,0,1,1,0,1,1 }, // = 5

{ 1,0,1,1,1,1,1 }, // = 6

{ 1,1,1,0,0,0,0 }, // = 7

{ 1,1,1,1,1,1,1 }, // = 8

{ 1,1,1,0,0,1,1 } // = 9

};
const int buttonPin = 12;
int buttonState = 0;
int num = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(buttonPin,INPUT);
  Serial.begin(9600);
}

void sevenSegWrite(byte digit) {
byte pin = 2;
for (byte seg = 0; seg < 7; ++seg) {
digitalWrite(pin,
1-seven_seg_digits[digit][seg]);
++pin;
}

}

void loop() {
  // put your main code here, to run repeatedly:
buttonState = digitalRead(buttonPin);
if(buttonState == HIGH){
  num ++;
  if(num > 9){
    num = 0;
  }
}
sevenSegWrite(num);
Serial.println(buttonState);
delay(1000);
}