int outPin_front = 3;
int outPin_middle = 7;
int outPin_back = 12;
int ledPinfront = 2;
int ledPinmiddle = 6;
int ledPinback = 11;
bool statefront = false ;
bool statemiddle = false ;
bool stateback = false ;
unsigned long times1;
unsigned long times2;
unsigned long times3; 
unsigned long prev_time = 0;
int countf = 0 ;
int countm = 0;
int countb = 0;
int count_total = 0;

unsigned long currentTime = 0 


/* Sunay's thing
bool prevState1 = false;
bool prevState2 = false;
bool prevState3 = false;
*/

void setup() {
Serial.begin(9600);
pinMode(ledPinfront, OUTPUT);
pinMode(ledPinmiddle, OUTPUT);
pinMode(ledPinback, OUTPUT);
pinMode(outPin_front, INPUT);
pinMode(outPin_middle, INPUT);
pinMode(outPin_back, INPUT);
}
/*
bool switchState(bool x) {
  //return not x;
  if (x == true) {
    return false;
  }
  return true;
}

int wasChanged() {

  unsigned long currentTime = millis();
  
  bool opF = false;
  bool opM = false;
  bool opB = false;
  
  if (digitalRead(outPin_front) == HIGH) {
    opF = true;
  }
  if (digitalRead(outPin_middle) == HIGH) {
    opM = true;
  }
  if (digitalRead(outPin_back) == HIGH) {
    opB = true;
  }
  
  if (opF != prevState1) {

    if (currentTime - prevTime > 2000) {
      if (opM != prevState2) {
      prevState2 = switchState(prevState2);
      }
      if (opB != prevState3) {
       prevState3 = switchState(prevState3);
     }
      prevState1 = switchState(prevState1);
      return 1;
    }
        
  } else if (opM != prevState2) {

    if (currentTime - prevTime > 2000) {
      if (opB != prevState3) {
        prevState3 = switchState(prevState3);
      }
      prevState2 = switchState(prevState2);
      return 2;
    }
    
  } else if (opB != prevState3) {

    if (currentTime - prevTime > 2000) {
      prevState3 = switchState(prevState3);
      return 3;
    }
    
  }
  return 4;
}
*/
void loop() {


if (digitalRead(outPin_front) == HIGH and statefront == false){
  digitalWrite(ledPinfront, HIGH) ;
  
  Serial.print("Time front high:  ");
  times1 = millis() ; 
  Serial.println(times1); 
  statefront = true;
  if (times1 - prev_time > 330) {
    countf+= 1;
    count_total +=1;
    prev_time = times1;
  }
}

else if(digitalRead(outPin_front) == LOW and statefront == true){
  digitalWrite(ledPinfront, LOW) ;
  Serial.print("Time front low:  ");
  times1 = millis() ; 
  Serial.println(times1); 
  statefront = false;
  if (times1 - prev_time > 330) {
    countf+= 1;
    count_total +=1;
    prev_time = times1;
  }
}


else if (digitalRead(outPin_middle) == HIGH and statemiddle == false){
  digitalWrite(ledPinmiddle, HIGH) ;
  Serial.print("Time middle high:  ");
  times2 = millis();
  Serial.println(times2); 
  statemiddle = true ;
  if (times2 - prev_time > 330) {
    countm+= 1;
    count_total +=1;
    prev_time = times2;
  }
}

else if(digitalRead(outPin_middle) == LOW and statemiddle == true){
  digitalWrite(ledPinmiddle, LOW) ;
  Serial.print("Time middle low:  ");
  times2 = millis() ; 
  Serial.println(times2); 
  statemiddle = false;
  if (times2 - prev_time > 330) {
    countm+= 1;
    count_total +=1;
    prev_time = times2;
  }
}

else if (digitalRead(outPin_back) == HIGH and stateback == false){
  digitalWrite(ledPinback, HIGH) ;
  Serial.print("Time back high:  ");
  times3 = millis() ; 
  Serial.println(times3); 
  stateback = true ;
  if (times3 - prev_time > 330) {
    countb+= 1;
    count_total +=1;
    prev_time = times3;
  }
}

else if(digitalRead(outPin_back) == LOW and stateback == true){
  digitalWrite(ledPinback, LOW) ;
  Serial.print("Time back low:  ");
  times3 = millis() ; 
  Serial.println(times3); 
  stateback = false;
  if (times3 - prev_time > 330) {
    countb+= 1;
    count_total +=1;
    prev_time = times3;
  }
}
/*
// Sunay's thing
int changed = wasChanged();

if (changed == 1) {
  prevTime = millis();
  countf += 1;
  Serial.print("Countf is ");
  Serial.println(countf);
}

if (changed == 2) {
  prevTime = millis();
  countm += 1;
  Serial.print("Countm is ");
  Serial.println(countm);
}

if (changed == 3) {
  prevTime = millis();
  countb += 1;
  Serial.print("Countb is ");
  Serial.println(countb);
}
*/
}
