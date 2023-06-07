int k = 0, i = 0;
void setup() {
  pinMode(4,OUTPUT);
}
 
void loop(){

  if (k < 7)
  {
    k++;
    for(i = 0; i < k; i++)
    {
    digitalWrite(4,HIGH);
    delay(1000);
    digitalWrite(4,LOW);
    delay(500);
    }
    delay(3000);
  }
  
}