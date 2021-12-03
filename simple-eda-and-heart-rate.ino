const int GSR=A0;
const int HR=A1;

int sensorValue=0;
int gsr_average=0;
unsigned long count = 0;
unsigned long pulseCount = 0;

#define LED 4//indicator, Grove - LED is connected with D4 of Arduino
boolean led_state = LOW;//state of LED, each time an external interrupt 
                                //will change the state of LED
unsigned char counter;
unsigned long temp[21];
unsigned long sub;
bool data_effect=true;
unsigned int heart_rate;//the measurement result of heart rate
const int max_heartpluse_duty = 2000;//you can change it follow your system's request.
                        //2000 meams 2 seconds. System return error 
                        //if the duty overtrip 2 second.
                            

void setup(){
  Serial.begin(9600);
  pinMode(LED, OUTPUT);
  Serial.begin(9600);
//  Serial.println("Please ready your chest belt.");
  delay(5000);
  arrayInit();
//  Serial.println("Heart rate test begin.");
  attachInterrupt(0, interrupt, RISING);//set interrupt 0,digital port 2
  
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
   sprintf(msg, "%ld,%ld,%d,%d*", count, millis(), gsr_average, pulseCount); 
   
   Serial.println(msg);
//   delay(50);
   count += 1;
}

    /*Function: calculate the heart rate*/
    void sum()
    {
     if(data_effect)
        {
          heart_rate=1200000/(temp[20]-temp[0]);//60*20*1000/20_total_time 
//          Serial.print("Heart_rate_is:\t");
//          Serial.println(heart_rate);
        }
       data_effect=1;//sign bit
    }
    /*Function: Interrupt service routine.Get the sigal from the external interrupt*/
    void interrupt()
    {
        temp[counter]=millis();
//        Serial.println(counter,DEC);
//        Serial.println(temp[counter]);
        switch(counter)
        {
            case 0:
                sub=temp[counter]-temp[20];
//                Serial.println(sub);
                break;
            default:
                sub=temp[counter]-temp[counter-1];
//                Serial.println(sub);
                break;
        }
        if(sub>max_heartpluse_duty)//set 2 seconds as max heart pluse duty
        {
            data_effect=0;//sign bit
            counter=0;
//            Serial.println("Heart rate measure error,test will restart!" );
            arrayInit();
        }
        pulseCount++;
        if (counter==20&&data_effect)
        {
            counter=0;
            sum();
        }
        else if(counter!=20&&data_effect)
        counter++;
        else 
        {
            counter=0;
            data_effect=1;
        }
 
    }
    
/*Function: Initialization for the array(temp)*/
void arrayInit()
{
    for(unsigned char i=0;i < 20;i ++)
    {
        temp[i]=0;
    }
    temp[20]=millis();
}
