# IOT-communication-with-the-server-using-Arduino-Nano-Board

Task Description: The task of the lab is to develop the WLAN
communication link between the IOT device and the sever. In this task, the
light-dependent resistor (LDR) is setup with aka Pretzel IoT WiFi Board with
a built in ESP 8266 WiFi module to send light-level of an environment to the
server via the internet. In order to connect light-dependent resistor (LDR)
with the Pretzel board, the other components are also required. LDR is connected to the Arduino based NanoESP Board using breadboard.
Also, LDR is used with 10kOhms resistor to form a voltage divider. Since the
divider output is analogue, it is connected with the analogue pin on the
Arduino based NanoESP Board to get the light-level information of an
environment. The analogue to digital converter on the Arduino based
NanoESP converts the analogue data into 12-bits digital data accordingly.
Similarly, the 5V DC voltage input as well as GND are used from the same Arduino based NanoESP Board. At the end,
the setup is connected to the power supply through micro USB wire.

Arduino Sketch Description: The Arduino sketch is created using Arduino IDE and is compiled on the Arduino
based NanoESP Board accordingly. Firstly, the serial communication channel is created between the Arduino Nano and
the ESP 8266 module within Pretzel IoT WiFi Board using pins 11 and 12 (TX, RX pins) respectively. The baud rate is
set to 19200 for the serial communication between the Arduino Nano and the ESP 8266 module. The WLAN connection
between the IoT and the server is set up through the wireless access point using different AT Commands are used. The
command “AT+RST” is used to reset the WLAN in the start. Afterwards, ESP 8266 module is configured as client
using “AT+CWMOD”. Then, “AT+CWJAP” is sent to the ESP 8266 module to connect with the WLAN access point
using SSID and password. The “AT+CIFSR” enables the ESP 8266 module to get the DHCP ip address from the
WLAN access point. The UDP connection is started using “AT+CIPSTART” with the server after successfully
configuring the ESP 8266 module. The “AT+CIPSTART” consists of ip address of the server and the UPD ports
numbers to send the data bytes.

Once the connection is setup, the UPD payload is accepted by the ESP 8266 module in the form of data bytes. The
delay of 1 sec is given after each data byte to prepare ESP8266 board to accept the next byte. By using the
“AT+CIPSEND” command, the data byte is send to server. The server received the data packets after every 5 seconds
of time delay.

Data Collection and Analysis: In order to receive UDP data payload, the server is created using netcat udp
server. The server and the ESP 8266 module are connected to the same access point. The command used is “nc -u -l
9999 > upd.txt”. Therefore, the server will listen the UDP port 9999 and saved the received data packets in the udp.txt
file accordingly. The packet capture tool “Wireshark” is used to confirm the reception the UDP packets on the server.
The UDP packets sent consist of Matriculation Number; Sequence Number; LDR Value. The analysis of the file udp.txt
shows that the server receives the data packets with increasing sequence number from 1 to 100. This sequence numbers
shows the number of packets received at the server. 
