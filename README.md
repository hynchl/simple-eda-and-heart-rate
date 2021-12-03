# Simple Arduino Script for measure EDAand Heart Rate
This is a simple Arduino Script for measure EDA a.k.a. GSR and Heart Pulse
<!-- 
![image](/photo.jpg)
- RED -> 5V
- BLACK -> Ground
- Bronw -> A0
- Purple -> A1

!! this photo will be  -->

# It Does
- Send the value of GSR and pulse count via serial. 

#### Serial Example
```python
1, 111234, 512, 0*\r\n
2, 111334, 512, 0*\r\n
3, 111634, 512, 0*\r\n
4, 112214, 512, 1*\r\n
5, 112724, 512, 1*\r\n
6, 112924, 512, 2*\r\n
```

- First number is message count.
- Second number is number of milliseconds passed since the program started; `millis()`
- First number is a GSR sensor value.
- Second number is pulse count.
- `*` is added to check the end of the message.


The value of GSR should be converted to the human resistance.

```python
# EDA Sensor Value => Human Resistance (ohm)
human resistance =  ((1024+2*eda_value)*10000)/(512-eda_value+1e-5)
```


# Reference

## EDA Sensor
- Name: Grove - GSR Sensor v1.2
- More information:  https://wiki.seeedstudio.com/Grove-GSR_Sensor/
- NOTE: Check whether the default value of your sensor is 512. If not, you should adjust it.


## Pulse Sensor for Measuring Heart Rate
- Name: Grove - Ear-clip Heart Rate Sensor
- Tutorial : https://wiki.seeedstudio.com/Grove-Ear-clip_Heart_Rate_Sensor/


