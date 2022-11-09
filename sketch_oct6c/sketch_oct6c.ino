#define servo 5
const int echoPin = 12;
const int trigPin = 11;
const int pressSensor = A1;
const int servoPin = 5;

void setup() 
{
  Serial.begin(115200);        
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(pressSensor, INPUT);
  pinMode(servo, OUTPUT);
}

long sensor()
{
  digitalWrite(trigPin,LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin,HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin,LOW);
  
  long timeDistance = pulseIn(echoPin,HIGH);
  long distance = (timeDistance/2) / 29.1; //[ cm ]
  return distance;
}

// 이동평균 필터
const float filter = 100;
float Sensorvalue = 0;
float pressRead()
{
    Sensorvalue = ( analogRead(pressSensor) / filter + ( filter - 1 ) * Sensorvalue) / filter;
    return Sensorvalue;
}

int prePWM = 0;
void actionServo(int angle)
{
  if(angle > prePWM)
  {
    for(int i =0; i< angle; i++)
    {
      analogWrite(servo,i);
      delay(10);
      prePWM = i;
    }
  } else {
    for(int i =prePWM; i> angle; i--)
    {
      analogWrite(servo,i);
      delay(10);
      prePWM = i;
    }
  }
  Serial.print("action servo:");
  Serial.println(angle);
  delay(100);
}


void loop() {
  long distance = sensor();
  Sensorvalue = pressRead();

  Serial.print(distance);
  Serial.print("/");
  Serial.println(Sensorvalue);
  if( distance <= 20)
  {
    actionServo(90);
    while(Sensorvalue >= 200)
    {
      Sensorvalue = pressRead();
      delay(100);
    }
    delay(3000);
    actionServo(0);
  }
}