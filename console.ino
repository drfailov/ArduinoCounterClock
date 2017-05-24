#define WHITE       0  // For drawing pixels. A 0 draws white.
#define BLACK       1  // A 1 draws black.

int line_height = 8;
int line_length = 14;
int current_y = line_height*5;
int current_x = 0;
#define LCD_WIDTH   84 // Note: x-coordinates go wide
#define LCD_HEIGHT  48 // Note: y-coordinates go high


void printTime(long ms){
  if(ms > (1000l*60l*60l)){
    long hours = ms/(1000l*60l*60l);
    ms -= hours * (1000l*60l*60l);
    print(hours);
    print("h ");
  }
  
  if(ms > (1000l*60l)){
    long min = ms/(1000l*60l);
    ms -= min * (1000l*60l);
    print(min);
    print("m ");
  }
  
  if(ms > 1000l){
    long sec = ms/(1000l);
    ms -= sec * (1000l);
    print(sec);
    print("s ");
  }
}


void print(bool number){
  if(number)
    print("true");
  else  
    print("false");
}
void print(double number){
  char* buf = new char[6];
  String(number).toCharArray(buf, 10);
  print(buf);
  delete buf;
}
void print(float number){
  char* buf = new char[6];
  String(number).toCharArray(buf, 10);
  print(buf);
  delete buf;
}
void print(int number){
  char* buf = new char[6];
  String(number).toCharArray(buf, 6);
  print(buf);
  delete buf;
}
void print(long number){
  char* buf = new char[10];
  String(number).toCharArray(buf, 10);
  print(buf);
  delete buf;
}





void print_animated(bool number){
  if(number)
    print_animated("true");
  else  
    print_animated("false");
}
void print_animated(double number){
  char* buf = new char[6];
  String(number).toCharArray(buf, 10);
  print_animated(buf);
  delete buf;
}
void print_animated(float number){
  char* buf = new char[6];
  String(number).toCharArray(buf, 10);
  print_animated(buf);
  delete buf;
}
void print_animated(int number){
  char* buf = new char[6];
  String(number).toCharArray(buf, 6);
  print_animated(buf);
  delete buf;
}





void println_animated(bool number){
  if(number)
    println_animated("true");
  else  
    println_animated("false");
}
void println_animated(double number){
  char* buf = new char[6];
  String(number).toCharArray(buf, 10);
  println_animated(buf);
  delete buf;
}
void println_animated(float number){
  char* buf = new char[6];
  String(number).toCharArray(buf, 10);
  println_animated(buf);
  delete buf;
}
void println_animated(int number){
  char* buf = new char[6];
  String(number).toCharArray(buf, 6);
  println_animated(buf);
  delete buf;
}






void println(bool number){
  if(number)
    println("true");
  else  
    println("false");
}
void println(double number){
  char* buf = new char[6];
  String(number).toCharArray(buf, 10);
  println(buf);
  delete buf;
}
void println(float number){
  char* buf = new char[6];
  String(number).toCharArray(buf, 10);
  println(buf);
  delete buf;
}
void println(int number){
  char* buf = new char[6];
  String(number).toCharArray(buf, 6);
  println(buf);
  delete buf;
}
void println(long number){
  char* buf = new char[10];
  String(number).toCharArray(buf, 10);
  println(buf);
  delete buf;
}
void println(char * dString){
  print(dString);
  print("\n");
}



void println_animated(char * dString){
  print_animated(dString);
  print_animated("\n");
}

void print(char * dString){
  bool bw = true;
  
  while (*dString != 0x00) // loop until null terminator
  {
    //переход на новую строку если символ перехода
    if(*dString == '\n'){
      dString++;
      pull_lines_up();
      current_x = 0;
    }
    else{
      //нарисовать символ
      setChar(*dString++, current_x, current_y, bw);
      current_x+=5;
  
      //один пиксель после сивкола
      for (int i=current_y; i<current_y+8; i++)
        setPixel(current_x, i, !bw);
      current_x++;
  
      //Переход на новую строку если конец строки
      if (current_x > (LCD_WIDTH - 5)) {
        pull_lines_up();
        current_x = 0;
      }
    }
  }
  updateDisplay();
}

void print_animated(char* dString){
  while (*dString != 0x00){
    char toPrint[2];
    char c = *dString;
    dString++;
    toPrint[0] = c;
    toPrint[1] = 0x00;
    print(toPrint);
    delay(50);
  }
}

