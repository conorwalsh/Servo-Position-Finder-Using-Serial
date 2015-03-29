/*********************************************************************
**********************************************************************

 Conor Walsh 2015
  Website: http://www.conorwalsh.net
  GitHub:  https://github.com/conorwalsh
  
  Version 1.0
  
  First created: 28th March 2015
  Last modified: 29th March 2015

  Description: This code was created as a piece of testing software
               that I used to determine positions for a servo motor
               connected to an Arduino where the servo needed to be
               positioned very precisely. 
  
 *************************** LICENCE *****************************
 
 Copyright (c) 2015 Conor Walsh

 Permission is hereby granted, free of charge, to any person obtaining
 a copy of this software and associated documentation files (the
 "Software"), to deal in the Software without restriction, including
 without limitation the rights to use, copy, modify, merge, publish,
 distribute, sublicense, and/or sell copies of the Software, and to
 permit persons to whom the Software is furnished to do so, subject to
 the following conditions:

 The above copyright notice and this permission notice shall be included
 in all copies or substantial portions of the Software.

 THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS
 OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
 MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
 IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY
 CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT,
 TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE
 SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
  
******************************************************************
*****************************************************************/

//Include Servo libraries
#include <Servo.h> 

//Declare the servo
Servo myservo;
 
//Variable to store the servos position
int pos;

//The minimum servo motor value
int minpos = 1;

//The maximum servo motor value
int maxpos = 180;

void setup(){ 
  //Start Serial
  Serial.begin(9600);
  //Attach the servo to pin 5
  myservo.attach(5);
  Serial.println("Ready");
  Serial.println("");
} 
 
 
void loop(){ 
  
  //Check if Serial data is availible
  if (Serial.available()>0){
    
    //Set the position value to the value recieved
    pos = Serial.parseInt();
    
    //if the value is between the min and max values
    if(pos <= maxpos && pos >= minpos){
      //Print value to the serial monitor
      Serial.println("Position: " + String(pos));
      //Write the pos value to the servo
      myservo.write(pos);
    }
    //if the value is not between the min and max values
    else{
      //Print a warning to the serial monitor
      Serial.println("Invalid only entries between " + String(minpos) + " and " + String(maxpos));
    }
  }
}
