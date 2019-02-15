//KEYBOARD SCHEMA
/*  
 gpio num   
  1      8 
  ######## 
  ########  
 16      9  
  
    6       5
    ^       ^  
    O-------O----10
    |       |
7 < O       O  > 11 
    
    O---O---O----6
    |   |   |
    O---O---O----5
    |   |   |
    O---O---O----7
    |   |   |
    O---O---O----11
    |   |   |
    4   3   14
*/    
//KEYS
#define KEY_0 0
#define KEY_1 1
#define KEY_2 2
#define KEY_3 3
#define KEY_4 4
#define KEY_5 5
#define KEY_6 6
#define KEY_7 7
#define KEY_8 8
#define KEY_9 9
#define KEY_STAR 10
#define KEY_HASH 11
#define KEY_RETURN 12
#define KEY_CLEAR 13
#define KEY_LEFT 14
#define KEY_RIGHT 15

//ARDUINO PINS
#define SIG_3 6
#define SIG_4 7
#define SIG_5 8
#define SIG_6 9
#define SIG_7 10
#define SIG_10 11
#define SIG_11 12
#define SIG_14 13

bool is_pressed = false;
int btn_value;

void setup() {
  Serial.begin(9600);
  pinMode(SIG_3, OUTPUT);
  pinMode(SIG_4, OUTPUT);
  pinMode(SIG_10, OUTPUT);
  pinMode(SIG_14, OUTPUT);
  digitalWrite(SIG_3, HIGH);
  digitalWrite(SIG_4, HIGH);
  digitalWrite(SIG_10, HIGH);
  digitalWrite(SIG_14, HIGH);        
  pinMode(SIG_5, INPUT);
  pinMode(SIG_6, INPUT);
  pinMode(SIG_7, INPUT);
  pinMode(SIG_11, INPUT);  
}

void loop() {
  btn_value = checkKey(SIG_4);
  if(btn_value != -1){
    is_pressed = true;
  }
  btn_value = checkKey(SIG_3);
  btn_value = checkKey(SIG_14);
  btn_value = checkKey(SIG_10);
}

int keyDecode(int a, int b){
  if((a == SIG_4)&&(b == SIG_6)) return KEY_1;
  if((a == SIG_4)&&(b == SIG_5)) return KEY_4;
  if((a == SIG_4)&&(b == SIG_7)) return KEY_7;
  if((a == SIG_4)&&(b == SIG_11)) return KEY_STAR;   

  if((a == SIG_3)&&(b == SIG_6)) return KEY_2;
  if((a == SIG_3)&&(b == SIG_5)) return KEY_5;
  if((a == SIG_3)&&(b == SIG_7)) return KEY_8;
  if((a == SIG_3)&&(b == SIG_11)) return KEY_0;   

  if((a == SIG_14)&&(b == SIG_6)) return KEY_3;
  if((a == SIG_14)&&(b == SIG_5)) return KEY_6;
  if((a == SIG_14)&&(b == SIG_7)) return KEY_9;
  if((a == SIG_14)&&(b == SIG_11)) return KEY_HASH;   

  if((a == SIG_10)&&(b == SIG_6)) return KEY_LEFT;
  if((a == SIG_10)&&(b == SIG_5)) return KEY_RIGHT;
  if((a == SIG_10)&&(b == SIG_7)) return KEY_RETURN;
  if((a == SIG_10)&&(b == SIG_11)) return KEY_CLEAR;
  
  return -1;
}

int checkKey(int a){
  int value = -1;
  digitalWrite(a, LOW);
  delay(1);  
  if(digitalRead(SIG_6) == LOW){
    //Serial.println(keyDecode(a,SIG_6));
    value = keyDecode(a,SIG_6);
  }
  if(digitalRead(SIG_5) == LOW){
    //Serial.println(keyDecode(a,SIG_5));
    value = keyDecode(a,SIG_5);
  }
  if(digitalRead(SIG_7) == LOW){
    //Serial.println(keyDecode(a,SIG_7));
    value = keyDecode(a,SIG_7);
  }
  if(digitalRead(SIG_11) == LOW){
    //Serial.println(keyDecode(a,SIG_11));
    value = keyDecode(a,SIG_11);    
  }
  digitalWrite(a, HIGH);
  return value;    
}


