
# Engineering Documentation | Team Sketchy Drivers | Bangladesh
----

In the 2023 season of the WRO Future Engineers competition, this repository houses engineering materials related to Felice-bot, an autonomous vehicle model created by Team Sketchy Drivers from Bangladesh.

----

## Team Members:

- Hossain Muhammad Seyan Zawad - email: <muhammadseyan7@gmail.com>, Discord: seyan5454
-  Rakibul Islam - email: <rxrohan21@gmail.com>
- Mohammad Al Muhtasim - email : almuhtasim22@gmail.com, Discord: labib5260

![Imgur](https://i.imgur.com/UZjrQyx.jpg)

## Repository Overview


+ `chassis` - Within this directory, you can find comprehensive information regarding the chassis that has been employed in our project.
+ `models` - Changes made on our chassis to fit electric parts and sensors
+ `schemes` - Schematics for the electrical systems.
+ `src` - Contains the primary programs and control software for the project.
+ `t-photos` - You will discover serious and lighthearted photographs of our team.
+ `v-photos` -Explore a comprehensive collection of images capturing our robot from all required angles and perspectives, providing a comprehensive visual overview.
+ `video` - This directory contains a link to a YouTube video where our robot is showcased in action, allowing you to witness its performance firsthand.
+ `others` - other essential photos

---- 





# Structuring Programs and Planning Algorithms

Our robot runs on an Arduino UNO R3 board which handles all the robot's actions and helps it understand its surroundings.

The robot uses Huskylens to see red and green obstacles. This helps it make decisions while moving. To know where it's going and how many laps it has done, the robot has an MPU6050 sensor and two ultrasonic sensors which help the robot stay on the right path.

When we turn on the robot with a battery, it gets ready by setting up its parts and talking to the Huskylens and the sensors. It also centers its servo motor and waits for a user command. The user starts the robot by pushing a button.

The robot's code is split into three parts. This makes it work better and easier to control. 


![Imgur](https://i.imgur.com/TmlsZI7.png)


### Part 1 - Determining Run Direction with Sonar Sensors for the first round

We used PID (proportional, integral, derivative) algorithm code which tries to keep the robot in the middle of the track. The rear motor is slowed down while the vehicle is turning.  If any of the ultrasonic sensors from the sides get a value greater than 200cm,  the robot determines the inner wall placed on that side e.g. if the ultrasonic sensor on the left side gets 250 cm, the logic tends to keep the robot at a safe distance which is 30 cm from the inner wall. 


### Part 2 - Rest of the first round:

After detecting the inner wall. The robot through the track whilst keeping a safe distance from the inner wall. We calculated a standard speed that allows stable laps.

### **Avoiding wall collisions**
If the robot gets dangerously close to a wall, we steer it in the other direction.


### Part 3: Detecting if it's the 2nd round 
We rotate the husky lens with a servo motor when we start the robot to detect obstacles. If the huskylens pick up reading of Red or Green obstacles when navigating the starting section, it goes into the 2nd round logic. And never gets out. If no object is detected the robot follows the 1st robot code. 

### Part 4: 2nd round obstacle avoidance

When the huskylens detect an object, we check which color it is and how far away it is (by height and width). If it is within 20cm the robot goes into manual mode and steers according to the object color until it has passed the object and returned to its neutral position or close to it. If the object is green it steers to the left and if the object is red it steers to the right.

### Part 5 - Detecting the end of 3 laps:

We detect the orange and blue colors of the corner sections through Husky Lens and count the number of times it comes in contact with the colors. This allows us to count total lap numbers and stop after exactly 3 laps. 

# Electrical Systems Design

## Parts List
We tried to keep our parts list simple and affordable. Although it could've been better. We faced some problems with the sonar sensors.  ,

+ Arduino Uno r3
+ Huskylens: Embedded Vision Sensor
+ HC-SR04 Ultrasonic Sensors
+ 12V 800 RPM DC Geared Motor
+ SG90 (Servo for Huskylens)
+ MG90s (Servo for steering)
+ L293D Motor Driver
+ MPU6050
+ mt3608 Boost Converter
+  lm2596 buck module
+ 2S 1100 mAh LiPo battery  

## Engineering Design 
+ Arduino Uno R3: We use it as our main microcontroller for controlling the robot and getting input from the sensors.
+ Huskylens: We use this module for detecting object color and turning points.
 + Chassis: We customized an RC car chassis which was more affordable and customizable for our needs. Initially, we used a 9-inch-long RC car but later we went with a slim and smaller one which allowed us to negotiate the challenges easily. 
 
+ 12V 800RPM N20: This provided enough speed and torque for our robot. 

- MG90S: We used this servo motor for steering the robot.

- L293D motor driver: This motor driver provided enough functionality for what we were trying to achieve.

-   HC-SR04 sonar sensors: We're using these sensors to measure distance from both the left and right walls. We mounted it at an angle so it could see changes in walls before the car passed it.  
  
- MT3608: We use this boost converter to boost our battery input from 7.4 volts to 12 volts to power our motor.
 
- LM2596 buck converters: For powering up all 5v components of our board. Including our microcontroller, servo, motor driver IC, huskylens, and MPU6050.

- MPU6050: was used to know the orientation of the robot in real-time. This data is later used to count laps.
- 1100mAh battery


----


# Mechanical Design

We have modified the chassis of an RC car to meet our requirement to build a light and slim chassis. 


## Design 

![Imgur](https://i.imgur.com/DTjnj6a.png)

We have angled the ultrasonic sensors at a 30-degree angle so that we can detect the turns earlier and efficiently navigate our robot.

# **Videos of the robot working**

Here are the YouTube links to our robot negotiating the game challenges:

1. First round: https://youtu.be/ZwHFC70GCvk?si=jDrG2atMgLqJFHXc
2. Second round: https://youtu.be/_tO85gQGAt0?si=w_3HogFRJlBmsNNz
