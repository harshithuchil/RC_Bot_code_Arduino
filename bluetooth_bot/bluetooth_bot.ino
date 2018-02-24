/*
    The following sketch is used to run a bluetooth controlled
    robot using an arduino of 2 motor configuration.

    BT module connections:
      RX of BT module -------> TX of Arduino
      TX of BT module--------> RX of Arduino
      Power suorce: 5V from arduino

  Harshith k
  harshithsaliyan02@gmail.com

*/


const int m1a = 2 ;                    // motors and its 2 terminals
const int m1b = 3;
const int m2a = 4;
const int m2b = 5;

const int m1P = 9;                    //  enable pins of motor
const int m2P = 10;



int i = 0;

char data;

void setup() {
  Serial.begin(9600);
  pinMode(m1a, OUTPUT);              //defining digital pins
  pinMode(m1b, OUTPUT);
  pinMode(m2a, OUTPUT);
  pinMode(m2b, OUTPUT);
}
void loop() {
  //if serial value is received
  while (Serial.available() > 0)     // if serial data is recieved via BT
  {
    //save it to character 'data'
    data = Serial.read();
    //print it on serial monitor
    Serial.println(data);             
    
    //forward
    if (data == 'F' && i != 1)
    {
      //at full speed
      analogWrite(m1P, 255);
      analogWrite(m2P, 255);

      digitalWrite(m1a, HIGH);
      digitalWrite(m1b, LOW);
      digitalWrite(m2a, HIGH);
      digitalWrite(m2b, LOW);

    }
    //backward
    if (data == 'B' && i != 1)
    {
      analogWrite(m1P, 255);
      analogWrite(m2P, 255);

      digitalWrite(m1a, LOW);
      digitalWrite(m1b, HIGH);
      digitalWrite(m2a, LOW);
      digitalWrite(m2b, HIGH);

    }
    //left
    if (data == 'L' && i != 1)
    {
      analogWrite(m1P, 255);
      analogWrite(m2P, 255);

      digitalWrite(m1a, LOW);
      digitalWrite(m1b, HIGH);
      digitalWrite(m2a, HIGH);
      digitalWrite(m2b, LOW);

    }
    //right
    if (data == 'R' && i != 1)
    {
      analogWrite(m1P, 255);
      analogWrite(m2P, 255);

      digitalWrite(m1a, HIGH);
      digitalWrite(m1b, LOW);
      digitalWrite(m2a, LOW);
      digitalWrite(m2b, HIGH);

    }


    //stop
    if ((data == 'S' || data == 'D') && i != 1)
    {
      digitalWrite(m1a, LOW);
      digitalWrite(m1b, LOW);
      digitalWrite(m2a, LOW);
      digitalWrite(m2b, LOW);

    }
    //counter clockwise
    //    if (data == '0' || data == '1' || data == '2' || data == '3')
    //    {
    //      //at medium speed
    //      analogWrite(m1P, 150);
    //      analogWrite(m2P, 150);
    //
    //      digitalWrite(m1a, LOW);
    //      digitalWrite(m1b, HIGH);
    //      digitalWrite(m2a, HIGH);
    //      digitalWrite(m2b, LOW);
    //
    //      i = 1;
    //    }
    //                                                                   //neutral
    //    if (data == '4' || data == '5' || data == '6')
    //    {
    //      digitalWrite(m1a, LOW);
    //      digitalWrite(m1b, LOW);
    //      digitalWrite(m2a, LOW);
    //      digitalWrite(m2b, LOW);
    //
    //      i = 0;
    //    }
    //                                                                   //clockwise
    //    if (data == '7' || data == '8' || data == '9' || data == 'q')
    //    {
    //      i = 1;
    //      analogWrite(m1P, 150);
    //      analogWrite(m2P, 150);
    //
    //      Serial.println("CLOCKWISE");
    //      digitalWrite(m1a, HIGH);
    //      digitalWrite(m1b, LOW);
    //      digitalWrite(m2a, LOW);
    //      digitalWrite(m2b, HIGH);
    //
    //
    //    }
    //

  }
}
