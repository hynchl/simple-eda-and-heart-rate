# Simple Arduino Script for measure EDAand Heart Rate
This is a simple Arduino Script for measure EDA a.k.a. GSR and Heart Pulse


<!-- TODO: Add photo and schematic plan  -->

# It Does
- Send the value of EDA and Pulse via serial. 
```python
# example
512, 540\r\n
512, 512\r\n
512, 440\r\n
512, 112\r\n
512, 0\r\n
512, 480\r\n
```

- The value of EDA should converted to the human resistance. Check Below.

```python
# EDA Sensor Value => Human Resistance (ohm)
human resistance =  ((1024+2*eda_value)*10000)/(512-eda_value+1e-5)
```
# Sensor

## EDA Sensor
- Name: Grove - GSR Sensor v1.2
- More information:  https://wiki.seeedstudio.com/Grove-GSR_Sensor/
- NOTE: Check whether the default value of your sensor is 512. If not, you should adjust it.


## Pulse Sensor for Measuring Heart Rate
- Name: SZH-SSBH-035
- Size: 26mm $\times$ 15mm
- Tutorial : https://pulsesensor.com/pages/code-and-guide
- NOTE: If the value is 0 or more than 900, it is likely that the sensor is detached to the skin.


