#define button_pin 2
#define led 3

int time_1 = 1000;
unsigned long begin_time;
int button_status = 0;
int pressed = 0;


void setup(){
pinMode(led, OUTPUT);
pinMode(button_pin, INPUT);
Serial.begin(9600);

}
void loop(){
button_status = digitalRead(button_pin);
// bool value = digitalRead(button_pin);
if(button_status == 1){
  digitalWrite(led, HIGH); 
  if(pressed == 0){
  begin_time = millis();
  pressed = 1;
  }
  if (millis() - begin_time >= time_1){
    for(int i = 0; i < 5; i++){
      digitalWrite(led, HIGH);
      delay(250);
      digitalWrite(led, LOW);
      delay(250);
    }
    pressed = 0;
  }
} 
else{
  pressed = 0;
  digitalWrite(led, LOW);
}


//Serial.println(value);
  
}
