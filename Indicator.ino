long currentValue = 0;
int nOfDigits = 4;
long oneStepTime = 1457;

void initIndicator(){
  initCalibration();
  initStartingValue();
}

void initCalibration(){
  println("Calibration");
  println("1 - step");
  println("4 - OK");
  while(!isDown4()){
    if(isDown1()){
      stepIndicator();
      delay(100);
    }
  }
  println("Calib. finish");
  delay(2000);
}

void initStartingValue(){
  println("Inp curr val:");
  currentValue = inputNumber(nOfDigits);
  println("Received:");
  println(currentValue);
  delay(2000);
}



void showNumber(long toShow){
  print("Show ");
  println(toShow);  
  long difference = toShow - currentValue;
  if(difference == 0)
    return;
  if(difference < 0)
    difference = pow(10, nOfDigits) + difference;
  
  print("Make ");
  print(difference);
  println("stp");
  //Enable backlight in case of long distance, to control progress
  if(difference > 10)
    digitalWrite(blPin, HIGH);//BL trigger  

  long pause = 10;//ms
  for(int i=0; i<difference; i++){
    delay(pause);
    nextNumberIndicator();
    println("");
    long remaining = (difference - i)*(oneStepTime + pause);  
    if(difference > 10){
      print(difference - i);
      println(" left...");
      printTime(remaining);
      println("");
    }
  }
  println("Reached.");
  //DISABLE backlight when reached
  digitalWrite(blPin, LOW);//BL trigger  
}

//---------------------------------------------------------------------------------------------------------------------
boolean initialized = false;
void initIndicatorPort(){
  if(initialized)
    return;
  pinMode(motor_pin1, OUTPUT); //MOTOR 1
  pinMode(motor_pin2, OUTPUT); //MOTOR 2
  analogWrite(motor_pin1, 0);
  analogWrite(motor_pin2, 0);
  initialized = true;
}
void nextNumberIndicator(){
  currentValue ++;
  if(currentValue >= pow(10, nOfDigits))
    currentValue = 0;
  print("Step -> ");
  println(currentValue);
  
  for(int i=0; i<stepsPerNumber; i++)
    stepIndicator();
}
void stepIndicator(){
  initIndicatorPort();
  for(int i=0; i<255; i+=7){//7i     1ms
    analogWrite(motor_pin1, i);
    analogWrite(motor_pin2, 255-i);
    delay(1);
  }
  for(int i=0; i<255; i+=7){
    analogWrite(motor_pin1, 255-i);
    analogWrite(motor_pin2, i);
    delay(1);
  }
}

