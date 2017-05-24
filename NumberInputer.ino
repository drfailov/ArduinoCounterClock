int digits[] = {0,0,0,0,0,0,0,0};
int numberOfDigits = 8;
int selected = 0;

long inputNumber(int nOfDigits){
  if(nOfDigits > 8){
    println("Err: Only 8");
    return 0;
  }
  numberOfDigits = nOfDigits;
  selected = 0;
  for(int i=0; i<numberOfDigits; i++)
    digits[i] = 0;
  
  println("2 - SET");
  println("3 - MODE");
  println("4 - OK");

  printDigits();
  while(!isDown4()){
    if(isDown2()){
      incrementCurrent();
      printDigits();
      delay(100);
    }
    if(isDown3()){
      selectNext();
      printDigits();
      delay(100);
    }
  }
  return toNumber();
}

long toNumber(){
  long result = 0;
  long mult = 1;
  for(int i=numberOfDigits-1; i>= 0; i--){
    result += digits[i] * mult;
    mult *= 10;
  }
  return result;
}

void incrementCurrent(){
  digits[selected] ++;
  if(digits[selected] > 9)
    digits[selected] = 0;
}
void selectNext(){
  selected++;
  if(selected >= numberOfDigits)
    selected = 0;
}
void printDigits(){
  for(int i=0; i<numberOfDigits; i++){
    if(i == selected)
      print(">");
    print(digits[i]);
  }
  println("");
}

