# RC-cars

In this project, a Wi-Fi controlled and a Bluetooth controlled two cars was designed.

In Wi-Fi controlled car, two RF24 modules and two Arduinos were used. In the transmitter part,  coordinates of joystick is read by the an Arduino Nano which defines which direction the car should go and then send it to the car using RF24. Based on the data recieved, the Arduino UNO gives the appropriate signals to the motors to move the car at the desired direction.

In Bluetooth controlled car, the car was connected to the phone and commands were sent using **Arduino BlueControl** app developed by BroXcode. The commands were recieved using HC06 Bluetooth module and based on the recieved data the car moves.
