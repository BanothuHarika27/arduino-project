int trigger_right = A4;
  int echo_right = A5;
  
  
  void setup() {
    // put your setup code here, to run once:
    pinMode(motor_lA,OUTPUT);   //left motors forward
    pinMode(motor_lB,OUTPUT);   //left motors reverse
    // Initialize motor control pins
    pinMode(motor_lA, OUTPUT);
    pinMode(motor_lB, OUTPUT);
    pinMode(motor_enableA, OUTPUT);
  
    pinMode(motor_rA,OUTPUT);   //right motors forward
    pinMode(motor_rB,OUTPUT);   //rignt motors reverse
    pinMode(motor_rA, OUTPUT);
    pinMode(motor_rB, OUTPUT);
    pinMode(motor_enableB, OUTPUT);
  
    pinMode(trigger_front,OUTPUT);
    pinMode(echo_front,INPUT);
    // Initialize ultrasonic sensor pins
    pinMode(trigger_front, OUTPUT);
    pinMode(echo_front, INPUT);
    pinMode(trigger_left, OUTPUT);
    pinMode(echo_left, INPUT);
    pinMode(trigger_right, OUTPUT);
    pinMode(echo_right, INPUT);
  
    pinMode(trigger_left,OUTPUT);
    pinMode(echo_left,INPUT);
  
    pinMode(trigger_right,OUTPUT);
    pinMode(echo_right,INPUT);
    
    // Set initial motor speed
    analogWrite(motor_enableA, 80);
    analogWrite(motor_enableB, 88);
  
    // Initialize serial communication
    Serial.begin(9600);
  }
  
  void loop() {
    // put your main code here, to run repeatedly:
    Serial.begin(9600);
    long duration_front, distance_front, duration_left, distance_left, duration_right, distance_right;
      
    //Calculating distance
    
    digitalWrite(trigger_front, LOW);
    delayMicroseconds(2);
    digitalWrite(trigger_front, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigger_front, LOW);
    duration_front = pulseIn(echo_front, HIGH);
    distance_front= duration_front*0.034/2;
  
    digitalWrite(trigger_left, LOW);
    delayMicroseconds(2);
    digitalWrite(trigger_left, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigger_left, LOW);
    duration_left = pulseIn(echo_left, HIGH);
    distance_left= duration_left*0.034/2;
  
    digitalWrite(trigger_right, LOW);
    delayMicroseconds(2);
    digitalWrite(trigger_right, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigger_right, LOW);
    duration_right = pulseIn(echo_right, HIGH);
    distance_right= duration_right*0.034/2;
    // Calculate distances
    distance_front = calculateDistance(trigger_front, echo_front);
    distance_left = calculateDistance(trigger_left, echo_left);
    distance_right = calculateDistance(trigger_right, echo_right);
  
    // Print distances to Serial Monitor
    Serial.print("front = ");
    Serial.println(distance_front);
    Serial.print("Left = ");
    Serial.println(distance_left);
    Serial.print("Right = ");
    Serial.println(distance_right);  
    Serial.println(distance_right);
    delay(50);
  
  
    if (distance_front >20){
  
    // Navigation logic
    if (distance_front > 20) {
      forward();
      
      if(distance_left > 10&& distance_left<20){
      if (distance_left > 10 && distance_left < 20) {
        forward();
      }
      if(distance_left >=20){
         left();
         delay(30);
         forward();
      }
      if(distance_left<10 && distance_left>0){
      } else if (distance_left >= 20) {
        left();
        delay(30);
        forward();
      } else if (distance_left < 10 && distance_left > 0) {
        right();
        delay(30);
        forward();
      }
   } 
    
    if(distance_front<=20&& distance_right > 20){
    } else if (distance_front <= 20 && distance_right > 20) {
      Stop();
      delay(1000);
      right();
      delay(400);
      
    }
  
    if(distance_front<=20 && distance_right<20){
    } else if (distance_front <= 20 && distance_right < 20) {
      Stop();
      delay(1000);
      left();
      right();
      delay(800);
     
    }
    
    
  }
  
  void forward()
  {
    digitalWrite(motor_lA,HIGH);
    digitalWrite(motor_lB,LOW);
    digitalWrite(motor_rA,HIGH);
    digitalWrite(motor_rB,LOW);
    delay(1000);
  long calculateDistance(int triggerPin, int echoPin) {
    digitalWrite(triggerPin, LOW);
    delayMicroseconds(2);
    digitalWrite(triggerPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(triggerPin, LOW);
    long duration = pulseIn(echoPin, HIGH);
    long distance = duration * 0.034 / 2;
    return distance;
  }
  
  
  void right(){
    digitalWrite(motor_lA,HIGH);
    digitalWrite(motor_lB,LOW);
    digitalWrite(motor_rA,LOW);
    digitalWrite(motor_rB,HIGH);
   delay(10);
  void forward() {
    digitalWrite(motor_lA, HIGH);
    digitalWrite(motor_lB, LOW);
    digitalWrite(motor_rA, HIGH);
    digitalWrite(motor_rB, LOW);
  }
  
  
  void left(){
    digitalWrite(motor_lA,LOW);
    digitalWrite(motor_lB,HIGH);
    digitalWrite(motor_rA,HIGH);
    digitalWrite(motor_rB,LOW);
    delay(10);
  void right() {
    digitalWrite(motor_lA, HIGH);
    digitalWrite(motor_lB, LOW);
    digitalWrite(motor_rA, LOW);
    digitalWrite(motor_rB, HIGH);
  }
  
  
  
  void Stop(){
    digitalWrite(motor_lA,LOW);
    digitalWrite(motor_lB,LOW);
    digitalWrite(motor_rA,LOW);
    digitalWrite(motor_rB,LOW);
    delay(300);
  void left() {
    digitalWrite(motor_lA, LOW);
    digitalWrite(motor_lB, HIGH);
    digitalWrite(motor_rA, HIGH);
    digitalWrite(motor_rB, LOW);
  }
  
  
    
    
      
  
     
  void Stop() {
    digitalWrite(motor_lA, LOW);
    digitalWrite(motor_lB, LOW);
    digitalWrite(motor_rA, LOW);
    digitalWrite(motor_rB, LOW);
  }