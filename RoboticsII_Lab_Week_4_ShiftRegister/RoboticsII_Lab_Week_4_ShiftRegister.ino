/*
Shift Register & Parallel Data Transfer Demo

This Arduino code is for a SN7420N shift register. 

The purpose of this code:
The purpose of this code is to demonstrate the parallel transfer of binary data.
This is demonstarted through the sequence in wich the 8 LEDs attached to the shift register illuminate.
The purpose is also to demonstarte how a shift rg+egister can increase the amount of outputs of a logic controller like an arduino. 

How sysytem this code is for works:
The shift register receives serial data from the Arduino and outputs parallel data to control LEDs. 
The shiftOut() function sends data serially to the shift register. 
Each bit of the data corresponds to an LED. 
The code counts from 0 to 255 and displays the binary representation of each number on the LEDs connected to the shift register. 

What each pin does: 
The clearPin is used to clear the shift register at startup. 
The shiftClock and latchClock control the shifting and latching operations of the shift register. 
The serialData pin is connected to the serial input of the shift register.

Result:
The LEDs connected to the shift register will turn on in a sequence that displays the binary representation of numbers from 0 to 255. 
With a delay of 500 milliseconds between each number.
*/


int clearPin   = 5;  //Arduino pin 5 connected to Pin 10, SRCLR(Clear/Reset) of SN7420N
int serialData = 6;  //Arduino pin 6 connected to Pin 14, SER(serial input) of SN7420N
int shiftClock = 7;  //Arduino pin 7 connected to Pin 11, SRCK(shift clock) of SN7420N
int latchClock = 8;  //Arduino pin 8 connected to Pin 12, RCK(storage/latch clock) of SN7420N 


void setup() {   
  // put your setup code here, to run once:
  //set pins to output so you can control the shift register
  pinMode(clearPin, OUTPUT);
  pinMode(shiftClock, OUTPUT);
  pinMode(latchClock, OUTPUT);
  pinMode(serialData, OUTPUT);

  digitalWrite(clearPin, LOW);   //Pin is active-low, this clears the shift register
  digitalWrite(clearPin, HIGH);  //Clear pin is inactive
}

void loop() { 
  // put your main code here, to run repeatedly:  
    for (int shiftCount = 0; shiftCount < 256;shiftCount++) {  // count from 0 to 255 and display the number on the LEDs
   
   digitalWrite(latchClock, LOW);                              // take the latchClock low so the LEDs don't change while you're sending in bits:
         
   shiftOut(serialData, shiftClock, MSBFIRST, shiftCount);     // shift out the bits
   digitalWrite(latchClock, HIGH);                             //take the latch pin high so the LEDs will light up
   delay(500);                                                 // pause before next value
   }
}
