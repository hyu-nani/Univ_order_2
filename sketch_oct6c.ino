#define servo 5
const int echoPin = 12;
const int trigPin = 11;
const int pressSensor = A1;
const int servoPin = 5;

void setup() {
  Serial.begin(115200);        
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(pressSensor, INPUT);
  pinMode(servo, OUTPUT);
}

long sensor(){
  digitalWrite(trigPin,LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin,HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin,LOW);
  
  
  long timeDistance = pulseIn(echoPin,HIGH);
  long distance = (timeDistance/2) / 29.1; //[ cm ]
  return distance;
}

void servo(int angle)
{
  int val = map(angle,0,120,0,200);
  analogWrite(servo,i);
  delay(100);
}

void loop() {
  long distance = sensor();
  int Sensorvalue = analogRead(pressSensor);

  Serial.println(distance);
  if( distance <= 20)
  {
    servo(90);
    while(Sensorvalue >= 200)
    {
      delay(1000);
    }
    delay(3000);
    servo(0);
  }
  
  while (Sensorvalue <= 200)
  {
    if (distance <=20 ){ 
      for(int i = 0 ; i < angle; i++)
      {
      }
    } 
    break;

    while (distance >= 20)
    {
      for(int i = angle ; i > 0 ; i--)
      {
        analogWrite(servo,i);
        Serial.println(i);
        delay(10);
      }
    } 
    delay(3000); 
    break ;
  }
  }