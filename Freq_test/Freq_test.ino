char val; // Data received from the serial port

#define pi 3.14159
#define period  10000
#define random 


void setup() {

 //pinMode(ledPin, OUTPUT); // Set pin as OUTPUT
  //initialize serial communications at a 9600 baud rate
  Serial.begin(9600);
  establishContact();  // send a byte to establish contact until receiver responds 
}

void loop() {
   

  if(Serial.available()>0)
  {
     val = Serial.read();    
    
    if(val == '3')
    {
      for(int j =0; j<=1; j++){
       for(int i = 0; i<=period; i++)
       {
        int freq = 440 + 220*sin(i*pi/period);
        tone(8,freq);
       }
       
       noTone(8);
      }
   
    }
     
 
     if(val == '2')
    {
      for(int j =0; j<=1; j++){
       for(int i = 0; i<=period; i++)
       {
        int freq = 400 + 220*int(2*i/period);
        tone(8,freq);
       }
       
       noTone(8);
      }
   
    }

    
      }
}
    
  
  



void establishContact() {
  while (Serial.available() <= 0) {
  Serial.println("A");   // send a capital A
  delay(300);
  }
}
