/*
This code allows you to make clock from mechanical counter, Nokia 5110 display, Arduino and 4 buttons.
*/

//This is pins connected directly to counter's motor coil
const int motor_pin1 = 10; //Pust be one of PWM pins
const int motor_pin2 = 3; //Pust be one of PWM pins

//This is settings buttons. 0 is released, 1 is pressed;
const int pinButPlus = 12; //<- This is digital pin. If you don't have enough free pins to connect 5V for buttons, you can use this pin instead.
const int pinBut1 = 0; //<- This is analog pins
const int pinBut2 = 1; //To be pressed, signal must be at least 20
const int pinBut3 = 2; //To be released signam bust me less than 20
const int pinBut4 = 3; //This setting stored in func isPressed() into Button file

//5110 DISPLAY Pin definitions:
/* Most of these pins can be moved to any digital or analog pin.
DN(MOSI)and SCLK should be left where they are (SPI pins). The 
LED (backlight) pin should remain on a PWM-capable pin. */
const int scePin = 7;   //pin 7 on UNO        pin 7 on MEGA         SCE - Chip select, pin 3 on LCD.
const int rstPin = 6;   //pin 6 on UNO        pin 6 on MEGA         RST - Reset, pin 4 on LCD.
const int dcPin = 5;    //pin 5 on UNO        pin 5 on MEGA         DC - Data/Command, pin 5 on LCD.
const int sdinPin = 11; //pin 11 on UNO       pin 51 on MEGA        DN(MOSI) - Serial data, pin 6 on LCD.
const int sclkPin = 13; //pin 13 on UNO       pin 52 on MEGA        SCLK - Serial clock, pin 7 on LCD.
const int blPin = 9;    //pin 9 on UNO        pin 9 on MEGA         LED - Backlight LED, pin 8 on LCD.
const int BL_ON = HIGH; //Some displays use inverse backlight control. If so, change this variables
const int BL_OFF = LOW; 

//How many steps need to do to change counter's number +1
const int stepsPerNumber = 20;


/*
 * =========== Startup sequence: ================
 * 1 - Calibrate undicator. 
 * If counter stuck between two numbers, you can  move counter by one step.
 * Also you can count number of steps needed to change one number
 * 
 * 2 - Enter current value from counter
 * Number (last 4 digits) currently displayed on counter.
 * Use button 2 to change value, button 3 to change position. When number is correct, press 4.
 * Example: if your counter dislpays 0038618.6 you have to enter 6186
 * 
 * 3 - Enter current time:
 * 4 numbers from 24hour time format.
 * Use button 2 to change value, button 3 to change position. When number is correct, press 4.
 * Example: If time 15:23, you have to enter 1523.
 * Time is set in moment when you press 4
*/


void setup()
{
  lcdBegin(); // This will setup our pins, and initialize the LCD
  setContrast(40); // Good values range from 40-60
  clearDisplay(0);
  updateDisplay();
  delay(500);
  pinMode(pinButPlus, OUTPUT); //HIGH FOR BUTTON
  digitalWrite(pinButPlus, HIGH);
  digitalWrite(blPin, BL_ON);//BL trigger
  println("Loading...");
  delay(500);

  initIndicator();
  initClock();
}


void loop()
{
  clockTick();
  delay(1000);
}


