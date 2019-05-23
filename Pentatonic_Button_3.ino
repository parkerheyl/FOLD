/*
  
 
Sending pushputton data to MAX MSP

*/

// constants won't change. They're used here to set pin numbers:
const int buttonPin = 2;     // the number of the pushbutton pin
const int ledPin =  13;      // the number of the LED pin

// variables will change:
int buttonState = 0;         // variable for reading the pushbutton status
int to_max = 1;
int prevButtonState = LOW;


int sensorPin = A0;    // select the input pin for the LDR
int sensorValue = 0;  // variable to store the value coming from the sensor
int threshold = 500;  // sound is triggered when sensor goes over this value


void setup() {
  
  // initialize the LED pin as an output:
  pinMode(ledPin, OUTPUT);
  
  // initialize the pushbutton pin as an input:
  pinMode(buttonPin, INPUT);

  // set serial speed to 9600
  Serial.begin(9600);

  threshold = analogRead(sensorPin) + 200;  //stores the initial lighting conditions
}

void loop() {
  // read the state of the pushbutton:
  buttonState = digitalRead(buttonPin);

   // read the value from the sensor:
  sensorValue = analogRead(sensorPin);
  //Serial.println(sensorValue);



  if (sensorValue > threshold)  //if we are over the threshold, play sound
       {
        Serial.write(to_max);          //Send serial communication to MAX
       // Serial.print("  ");
       // Serial.println(sensorValue);


       } 
      
  if(buttonState == HIGH)    // check if the pushbutton is pressed. 
        {
        // turn LED on:
        digitalWrite(ledPin, HIGH);
        }
        else
        {
          digitalWrite(ledPin, LOW);
        }




  delay(20);
  prevButtonState = buttonState;    //this is to prevent sending multiple messages to max
}
