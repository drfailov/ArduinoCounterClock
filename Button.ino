bool lastData1;
bool lastData2;
bool lastData3;
bool lastData4;


boolean isDown1(){
  bool value = isPressed(pinBut1);
  bool result = value && !lastData1;
  lastData1 = value;
  return result;
}
boolean isDown2(){
  bool value = isPressed(pinBut2);
  bool result = value && !lastData2;
  lastData2 = value;
  return result;
}
boolean isDown3(){
  bool value = isPressed(pinBut3);
  bool result = value && !lastData3;
  lastData3 = value;
  return result;
}
boolean isDown4(){
  bool value = isPressed(pinBut4);
  bool result = value && !lastData4;
  lastData4 = value;
  return result;
}










//-----------------------------------------------------
bool isPressed(int pin)
{
  long sum = 0;
  long cnt = 0;
  long timeRead = 100;
  long time = micros();
  while(micros() - time < timeRead){
    sum += analogRead(pin);
    cnt ++;
  }
  long avg = sum / cnt;    
  return avg > 20;
}
