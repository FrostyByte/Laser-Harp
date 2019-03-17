
/* stepper motor control code for DRV8825
 * 
 */

 // define pin used
 
 const int ldr=A0;
 const int ldr1=A1;
 const int stepPin = 9;
 const int dirPin = 8;
 int d=24;          //// If you increase this, the laser will be brighter, but the harp will be less fluid
 int sens =18;     //reference value for the LDR readings
 int t=800;       //time delay between two consecutive steps
 int a=3;        //no. of steps the motor takes before when moving from one laser beam to another. It controls the angle between the beams.
 int a1, b1, c1, d1, e1, f1, g1, h1, i1 = 0; //Counters for different notes. These determine whether the note is played or not. 
 
 // below are the variables denoting different notes. 60 corresponds to the middle C.
 int n1=60;       //c4
 int n2=62;      //d4
 int n3=64;     //e4
 int n4=65;    //f4
 int n5=67;   //g4
 int n6=61;  //c4#
 int n7=58; //A3#
 void setup() {
 Serial.begin(38400); //  Start a serial communication channel for MIDI. Needs to match with baud rate on the recieving end.
 
  //Setup for different pins
  
  pinMode(ldr,INPUT);         
  pinMode(A1,INPUT);
  pinMode( 1, OUTPUT);
  pinMode(stepPin,OUTPUT);
  pinMode(dirPin,OUTPUT);

}
void loop() {


    
  //1

  if ( ((analogRead(A0)+analogRead(A1)) > sens ) && (a1 == 0) ) // If the sensor gets a signal, and the not is not playing: 
  {
        
    playNote(1, n1, 100);    // Play note 1
    a1++;                          // Change the status variable to one.
  }


  else if((analogRead(A0)+analogRead(A1)) < sens )             // If the sensor does not get a signal:

  {
           
    playNote(1, n1, 0);     // Stop playing note 1.
    a1 = 0;                 // Change the status variable to zero.
  }
  
  forw();
  delay(d);
  //2


  if (( (analogRead(A0)+analogRead(A1)) > sens ) && (b1 == 0) ) // If the sensor gets a signal, and the not is not playing: 

  {
         
    playNote(1, n2, 100);    // Play note 2
    b1++;                     // Change the status variable to one.
  }


  else if((analogRead(A0)+analogRead(A1)) < sens )     // If the sensor does not get a signal:         

  {
            
    playNote(1, n2, 0);     // Stop playing note 1.
    b1 = 0;                 // Change the status variable to zero. 
  }
  forw();
  delay(d);
  //3

  if ( ((analogRead(A0)+analogRead(A1)) > sens ) && (c1 == 0) ) // If the sensor gets a signal, and the not is not playing: 

  {
   
    playNote(1, n3, 100);    // Play note 3
    c1++;                          // Change the status variable to one.
  }


  else if((analogRead(A0)+analogRead(A1)) < sens )             // If the sensor does not get a signal:

  {
    
    playNote(1, n3, 0);     // Stop playing note 1.
    c1 = 0;                         // Change the status variable to zero.
  }
  forw();
  delay(d);
  
  //4

  
  if ( ((analogRead(A0)+analogRead(A1)) > sens ) && (d1 == 0) ) // If the sensor gets a signal, and the not is not playing: 

  {
    
    playNote(1, n4, 100);    // Play note 4
    d1++;                          // Change the status variable to one.
  }


  else if((analogRead(A0)+analogRead(A1)) < sens )             // If the sensor does not get a signal:

  {
    
    playNote(1, n4, 0);     // Stop playing note 4.
    d1 = 0;                         // Change the status variable to zero.
  }
  forw();
  delay(1.5*d);           //increased the delay for the last beam
  //5

  if ( ((analogRead(A0)+analogRead(A1)) > sens ) && (e1 == 0) ) // If the sensor gets a signal, and the not is not playing: 

  {
    
    playNote(1, n5, 100);    // Play note 5
    e1++;                          // Change the status variable to one.
  }


  else if((analogRead(A0)+analogRead(A1)) < sens )             // If the sensor does not get a signal:

  {
    
    playNote(1, n5, 0);     // Stop playing note 5.
    e1 = 0;                         // Change the status variable to zero.
  }
  

  back();
  delay(d);
  
  //4
 
  if ( ((analogRead(A0)+analogRead(A1)) > sens ) && (d1 == 0) )  // If the sensor gets a signal, and the not is not playing: 

  {
    
    playNote(1, n4, 100);    
    d1++;                          
  }


  else if((analogRead(A0)+analogRead(A1)) < sens )             

  {
            
    playNote(1, n4, 0);     
    d1 = 0;                         
  }
back();
delay(d);
  //3
 
  if ( ((analogRead(A0)+analogRead(A1)) > sens ) && (c1 == 0) )  // If the sensor gets a signal, and the not is not playing: 

  {
    
    playNote(1, n3, 100);    // Play note 3
    c1++;                          // Change the status variable to one.
  }


  else if((analogRead(A0)+analogRead(A1)) < sens )             // If the sensor does not get a signal:

  {
    
    playNote(1, n3, 0);     // Stop playing note 3.
    c1 = 0;                         // Change the status variable to zero.
  }
back();
delay(d);

  //2
 
  if ( ((analogRead(A0)+analogRead(A1)) > sens ) && (b1 == 0) )  // If the sensor gets a signal, and the not is not playing: 

  {
    
    playNote(1, n2, 100);    // Play note 2
    b1++;                          // Change the status variable to one.
  }


  else if((analogRead(A0)+analogRead(A1)) < sens )             // If the sensor does not get a signal:

  {
    
    playNote(1, n2, 0);     // Stop playing note 2.
    b1 = 0;                         // Change the status variable to zero.
  }
 back;
 delay(1.5*d); 
}

//:::::::::::::::::::::::::::::::::::::::::::::::::::::::::
void forw()    // Function to rotate the motor by a steps in a direction.
{ 
  digitalWrite(dirPin,HIGH); //controls the direction of rotation.
  for(int x = 0; x < a; x++)
  {
    digitalWrite(stepPin,HIGH);
    delayMicroseconds(t);   
    digitalWrite(stepPin,LOW);
    delayMicroseconds(t);
  }
}
void back()  // Function to rotate the motor by a steps in opposite direction.
{
  digitalWrite(dirPin,LOW);
  for(int x = 0; x < a; x++)
  {
    digitalWrite(stepPin,HIGH);
    delayMicroseconds(t);   
    digitalWrite(stepPin,LOW);
    delayMicroseconds(t);
  }
}



void playNote(byte channel, byte note, byte velocity)//function to play a note 
{
    
    byte noteOnStatus=0x90 + (channel-1);  
    
    
    Serial.write(noteOnStatus);
    Serial.write(note);
    Serial.write(velocity);
}
