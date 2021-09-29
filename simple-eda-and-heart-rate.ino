const int GSR=A0;
const int HR=A1;

int sensorValue=0;
int gsr_average=0;
 
void setup(){
  Serial.begin(9600);
}
 
void loop(){

    // Read EDA Sensor 
    // [Reference] (https://wiki.seeedstudio.com/Grove-GSR_Sensor/)
    long sum=0;
    for (int i=0;i<10;i++) {//Average the 10 measurements to remove the glitch
        sensorValue=analogRead(GSR);
        sum += sensorValue;
        delay(5);}
    gsr_average = sum/10;

   // Read Pulse Sensor
   // [Reference] (https://pulsesensor.com/pages/code-and-guide)
   int hr = analogRead(HR);

   // Formatting
   char msg[40];
   sprintf(msg, "%d, %d", gsr_average, hr); 
   
   Serial.println(msg);
   
}