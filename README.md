# ProjectConnect
# Introduction 
Project Connect is an attempt to create the biggest IoT data server for remote operations in Bangladesh. With a goal to spread IoT in last mile we want to bring some revolutionary changes in the IoT environment in Bangladesh. Our project plan includes user end hardware implementation and web service to manage the data efficiently.<br>
# System Description 
Includes : <br>
Hardware implementation : code documentation <br>
Wb service. visit: http://connect.arthor.com.bd/  <br>
# Compatible Hardware List 
N.B: this list is made based on what devices has been tested so far by our team. So this list will get updated periodically <br>
*NodeMCU<br> 
*ESP8266<br>
*ESP32<br>
# Software compatibility Issues 
* If you do not have the <ESP8266WiFi.h> then get the library from, here : https://github.com/esp8266/Arduino/tree/master/libraries/ESP8266WiFi <br>
# Code analysis 
*Put your SID and auth key in the beginning part of this code. See the commented areas. <br>
*After that put your wifi name and password to access the internet <br> 
*No other things need to be changed. Now in the void loop() you can use max 5 variables to send to server. You can rename and use 
your variables. Then just send it via send2server() function. Also put your code and algorithm in as usual places in void loop(). 
# Guide 
Step 1: Create an account in Project Connect <br>
Step 2: Create a service from [Create Service] option<br>
Step 3: Note down the SID[service ID] and the auth key <br>
Step 4: Download the code file from this repository <br>
Step 5: make few variable changes <br>
Step 6: upload in any above mentioned compatible hardware <br>
Step 7: now you can access your data in your web service's data table <br>
