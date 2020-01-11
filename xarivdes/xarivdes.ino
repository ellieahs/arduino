const int trig = 13;
const int echo = 12;

int duration=0;
int distance=0;
int hp=0; 
int a=0;

int duration2=0;
int distance2=0;
int hp2=0; 
int b=0;
int c=0;
int height=28; //height of the container
int amount=-200; //Set your limit of water usage, it should be in ml, the value should be negative, this is for 200 ml
void setup()
{
  Serial.begin(9600);
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT); 
  pinMode (5, OUTPUT); //(red LED)
  pinMode (6, OUTPUT); //(green LED)
}

void loop()
{
  digitalWrite(trig, LOW);
  delayMicroseconds(2);
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);
  duration = pulseIn(echo, HIGH);
  distance = duration / height ;
  distance = distance - 6;  
  distance = 50 - distance;  //water height 0-50cm
  hp = 2 * distance; //distance in %
  a = hp*10 ; 
  Serial.print("Reading 1 \n");
  Serial.print(a);
  Serial.print(" ml \n");
  
  delay(15000); // reading will take after 15 seconds


  digitalWrite(trig, LOW);
  delayMicroseconds(2);
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);
  duration2 = pulseIn(echo, HIGH);
  distance2 = duration2 / height;
  distance2 = distance2 - 6;  
  distance2 = 50 - distance2;  //water height 0-50cm
  hp2 = 2 * distance2; //distance2 in %
  b = hp2*10;
  Serial.print("Reading 2 \n");
  Serial.print(b);
  Serial.print(" ml \n");
  delay(3600);
  Serial.print("AMOUNT OF WATER DECREASED \n");
  c = c+(b-a);
  Serial.print(c);
  Serial.print(" ml \n");
  delay(1000);

  if (c <= amount)
  {
    digitalWrite(5, HIGH);
    digitalWrite(6, LOW);
  }
  else
  {
    digitalWrite(6, HIGH);
    digitalWrite(5, LOW);
    }
}
