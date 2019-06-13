

int led1_1 = 8;
int led2_1 = 9;
int led3_1= 10;
int led1_2 = 11;
int led2_2 = 12;
int led3_2 = 13;

int tDelay = 1000;
int rotateNumber = 3;

void setup() {     
  Serial.begin(115200);  
  pinMode(led1_1, OUTPUT);
  pinMode(led2_1, OUTPUT);     
  pinMode(led3_1, OUTPUT);     
  pinMode(led1_2, OUTPUT);     
  pinMode(led2_2, OUTPUT);     
  pinMode(led3_2, OUTPUT);    
  Serial.println("U to speed up  | Any key to slow down"); 
}

void speedControl(boolean up = false){
    if (!up) tDelay += 50;
    else tDelay -= 50;
    if(tDelay<10) tDelay = 10;
    Serial.print("CurrentDelay");
    Serial.println(tDelay);
}

void clearDiodes(){
  digitalWrite(led1_1, LOW);   
  digitalWrite(led1_2, LOW);    
  digitalWrite(led2_1, LOW);    
  digitalWrite(led2_2, LOW);   
  digitalWrite(led3_1, LOW);   
  digitalWrite(led3_2, LOW);

}

void turnSchema() {
  clearDiodes();
  if(rotateNumber == 3){
    digitalWrite(led1_1, HIGH);  
    digitalWrite(led1_2, HIGH);    
  }
   else if(rotateNumber == 2){
    digitalWrite(led2_1, HIGH);  
    digitalWrite(led2_2, HIGH);    
  }
   else if(rotateNumber == 1){
    digitalWrite(led3_1, HIGH);  
    digitalWrite(led3_2, HIGH);    
  }
  rotateNumber--;
  if(rotateNumber == 0) rotateNumber = 3;
}

void loop() {
  if (Serial.available()) speedControl(Serial.read() == 'U');
  turnSchema();
  delay(tDelay);               
  delay(tDelay);   
}

