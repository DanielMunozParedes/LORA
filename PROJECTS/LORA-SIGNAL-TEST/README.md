# LORA-SIGNAL-TEST
Using Lora technology to send signals using EBYTE E32 900T20D
EBYTE E32 900T20D SX1276
Had a couple of problems whit that one. Had to sue the old website of ebyte m which did not, and dont have currently, support. So we search for the new website of ebyte: https://www.cdebyte.com/

For these test we first need to isntall the drivers of the TTL TO USB CP2102

CP210x USB to UART Bridge VCP Drivers - Silicon Labs (silabs.com)

Download the universal drivers, and the zip file save in desktop. Then connect the pins to the Lora device,

CP2102    LORA E32
GND		GND
RX		TX
TX		RX
3.3V		VCC

Bassic connection. Insert the usb and in management devices, select the new COP recognized and searh updates from computer and select the zip file.

Next, from the cdebyte website, go to the respective model, in this case

E32-900T20D_SX12**_SPI/SOC/UART_Module_Chengdu Ebyte Electronic Technology Co., Ltd (cdebyte.com)

![1](https://github.com/user-attachments/assets/63cb95c9-ec53-43a8-b311-15ed976d1d31)






Most important program is the RF SETTING, which help us to config the device beforehand,

![2](https://github.com/user-attachments/assets/4b21172c-0146-4689-b2e9-7184c0e6c858)



The baud rate, 9600 for usb serial transmission, air rate, power etc.



WAKE UP MODE
RECEIVER
M0 				M1
LOW (GND)    		HIGH (WEAK ULL UP)

SENDER
M0			 	M1
HIGH(WEAK PULL UP) 	LOW(GND)



USING THE SERIAL LAB software we can automate the reps of package sended


![3](https://github.com/user-attachments/assets/a0e77899-7076-48c6-83d0-97a0d73e1751)











We did a test of how much spread frequency the lora e32 has. And is a lot. With the air rate in minimum, which means, long range of comms but slower data, 





Quality signal: good.Coonectyion with 300 mbs de air rate, reach the acianato, then we lost the signal

![4](https://github.com/user-attachments/assets/4b95e792-5dd0-41a0-bd8e-dbe57f9349f4)







Then we recover the connection again in the mercado
Quality signal: medium, we capture some packages but the uncertainty of capture another package is not reliable

![5](https://github.com/user-attachments/assets/636948b5-ce05-4ef7-91ca-1bf2839f0362)




Seems like the valle, or valley , in the city of pasto is the problem to wide spread air rate of 300, when we reach the mercado, we recover the signal because is like we were scaling a mountain and putting us in a place where the e32 can capture the signal.

Quality signal: medium - bad. Just one or 3 packages captured.


![6](https://github.com/user-attachments/assets/8bfd953b-116b-4192-9e93-e8404773d5a8)


 


In the center of the city the conection was bad, very bad, just 1 package captured in a random place.





Quality signal: medium - bad
Incredible, the signal was captured form this point. It was better than the panamericana. Its like in rural zones is better, is from logic, less obstacles and more free “air” space for the signal to travel 



![7](https://github.com/user-attachments/assets/3fa3f845-25e0-4343-a59b-19a93813858a)




The test with the 300mbs of air rate were outstanding, something to have in mind is that when we were coming close to the apartment, the signal should recover, but i had to restart the connection usb, disconnecting and connecting, again to recover the signal.

So we could say with security at least, that to places fair enough 600 mts and up, the air rate should be minmun or lower that the original state.

And for 550 mts and down the aerate can be the predefined 2400 kbs


All thist test were made been in motion, in  a car. And besides the antenna was no directed specifically to any point, it was radm and besides the gnd was not safe in the M1 of the receiver (it was a little loose), and besides the antenna was so little for the numbers it reached in distance. So to have in mind this device has great potential in another test with ideal conditions
