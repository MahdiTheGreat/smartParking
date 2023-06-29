# smartParking
A certain commercial complex has asked us to design a smart parking lot that will ease the work of the parking attendants.
The parking lot should include the following features:
1- The light (LED) above each parking lot should show the empty or full status of the parking lot.
2- The number of empty spaces in each parking floor and the total number of empty spaces in the monitor (LED)
must be shown.
3- To enter the parking lot, each car first enters the ID and password on the keypad. 
If the information is confirmed and at least one parking space is empty, the parking door (servo motor)
will open and the appropriate message will be displayed on the monitor.
If the information is confirmed. or there was no parking space in the parking lot, 
the parking lot door does not open and the appropriate message is displayed on the monitor.
4- When leaving, each car also enters the information (ID and password) in the keypad, if the information is confirmed,
the calculated payment amount is displayed on the monitor and then the parking lot door is opened.
5- To calculate the parking fee, get the time that each car was in the parking lot and display an amount on the LCD based on that.

![image](https://github.com/MahdiTheGreat/smartParking/assets/47212121/f5d048f8-f566-4f71-a754-b0bf271c60f6)

We must Pay attention to the following points for implementation:
•	Consider a parking lot with 3 floors and 3 parking spaces on each floor.
•	you can use LM041L LCD to show the parking capacity information in the first 2 lines
information during entry and exit or the appropriate message in the last 2 lines. (As in the figure below,
the floors should be shown with the letters A, B, C, and the total empty capacity with the letter t).

![image](https://github.com/MahdiTheGreat/smartParking/assets/47212121/0ab21351-70ab-497f-be59-72a7ea271781)

Use the PIR sensor to detect the car in each pocket and set its input (testPin) to 0 or 1.
•	In this project, we use the Arduino Mega 2560 so as not to be limited by the number of pins.
•	The user must use the keypad to specify that he is entering or leaving the parking lot.
•	we put the saved ID and password in your code (we can save it in an array or in a file) 
and enter the same ID and password in the Keypad to test the scenario.
