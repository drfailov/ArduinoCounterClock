long offset = 0;
long last = 0;

void initClock(){
  println("");
  println("");
  println("Inp cur time:");
  long currentTime = inputNumber(4);
  long currTimestamp = millis();
  print("Rcvd: ");
  println(currentTime);
  delay(200);
  
  long hour = currentTime/100l;
  print("Hour: ");
  println(hour);
  if(hour > 23){
    print("Err! Hour > 23.");
    return;
  }
  delay(200);
  
  long min = currentTime - (hour*100l);
  print("Min: ");
  println(min);
  if(min > 59){
    print("Err! Min > 59.");
    return;
  }
  delay(200);

  long daylyTimestamp = min * (1000l*60l) + hour * (1000l*60l*60l);
  println("dTS: ");
  println(daylyTimestamp );
  delay(200);

  println("cTS: ");
  println(currTimestamp );
  delay(200);

  offset = daylyTimestamp - currTimestamp;
  println("offset: ");
  println(offset);
  delay(200);

  println_animated("-------------");
  long number = getNumber();
  println_animated("-------------");
  print("Numb: ");
  println(number);
  println_animated("==== GO! ====");
}
void clockTick(){
  if(offset == 0)
    return;

  int number = getNumber();
  println_animated("-------------");
  showNumber(number);
}

//------------------------------------------------------------------------------------------------------------------------------------------------------------
long getNumber(){
  long currTimestamp = millis();
  println("cTimestamp:");
  println(currTimestamp );
  delay(300);
  
  long daylyTimestamp = currTimestamp + offset;  
  long maxdaylyTimestamp = 24l*60l*60l*1000l;
  daylyTimestamp = daylyTimestamp % maxdaylyTimestamp;
  println("dTimestamp: ");
  println(daylyTimestamp );
  delay(300);
  
  long hour = daylyTimestamp / (60l*60l*1000l);
  print("Hours: ");
  println(hour);
  delay(300);
  
  long min = (daylyTimestamp - (hour * (60l*60l*1000l)))/(60l*1000l);
  print("Minutes: ");
  println(min);
  delay(300);

  long result = hour * 100l + min;
  print("Result: ");
  println(result);
  delay(300);
  return result;
}

