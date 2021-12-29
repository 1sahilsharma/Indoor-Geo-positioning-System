#include <SoftwareSerial.h>

int bluetoothTx = 9;  // TX pin of bluetooth HM10, Arduino D2
int bluetoothRx = 10;  // RX pin of bluetooth HM10, Arduino D3
int calibrationTime = 30;        
long unsigned int lowIn = 0;         
long unsigned int pause = 10000;  
boolean lockLow = true;
boolean takeLowTime;  
int pirPin = 3;
char incoming_char = 0;
char content[37]= " room:nicolas's_room motion_sensor:";
char ina[3] = " \n";
char ms;
SoftwareSerial bluetooth(bluetoothTx, bluetoothRx);
SoftwareSerial XBee(11, 12); // RX, TX

void setup()
{
  Serial.begin(9600);  // Begin the serial monitor at 115200bps
  XBee.begin(9600);
  pinMode(pirPin, INPUT);
  digitalWrite(pirPin, LOW);
  bluetooth.begin(9600);  // The Bluetooth  defaults to 9600
  //bluetooth.write("AT");
  delay(100);  // Short delay,
}
//
void loop()
{

  delay(5000);
    if(digitalRead(pirPin) == HIGH){
     ms = '1';
       }

     if(digitalRead(pirPin) == LOW ){ 

          ms = '0';
      }

// content = "room:nicolas's room\n motion_sensor:";
    
  bluetooth.write("AT+DISC?");
  delay(30);
  while(bluetooth.available())
  {
    incoming_char = bluetooth.read();
    if(incoming_char == 'O'){
      XBee.write(" ");
      }
    if(incoming_char == '\r'){
      continue;
      }  
    Serial.write(incoming_char);
    if(incoming_char == '\n'){
    XBee.write(content);
    XBee.write(ms);
    XBee.write(" \n");
    continue;
    }
    XBee.write(incoming_char);


  }

}
