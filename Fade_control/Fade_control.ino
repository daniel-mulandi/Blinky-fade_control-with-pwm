/*
this programs allows a user to fade a blinky 
and halt the bightness of blinky when a button is pressed
Author: Daniel Mulandi
Linkedln: @daniel mulandi 
*/
byte buttonPin = 2;
int potPin = A0;
byte ledPin = 9;
boolean lastButtonState = 0; 
boolean currentButtonState = 0;
int fadeAmount;

void setup() {
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);
  pinMode(buttonPin, INPUT_PULLUP);
  pinMode(potPin, INPUT);
}

void loop() {
currentButtonState = debounce(lastButtonState);

if(currentButtonState){
  int potRead = analogRead(potPin);
  //fadeAmount = map(potRead, 0,1023, 0, 20);
  analogWrite(ledPin,potRead);//replace potRead with fadeAmount for different range of brightness
  Serial.println(potRead);
  delay(1); 
  } 
else{
  while (true){
    //TODO : know how to print once in the serial monitor
    Serial.println("Brightness SET!");
    delay(500);
    break;
    }
    
  }
  delay(1000);
}

boolean debounce(bool last){
  boolean current = digitalRead(buttonPin);
  if(last != current){
    delay(5);
    current = digitalRead(buttonPin);}
  return current;
 }
