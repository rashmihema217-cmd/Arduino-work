int ledpin = 6;        
int buttonpin = 8;     
int ir=5;

void setup ()
{
  pinMode(ledpin,OUTPUT);
  pinMode(buttonpin,INPUT);
  pinMode(ir,INPUT);

}

void loop()
{
int ir_value = digitalRead(ledpin);
 int buttonpin_value = digitalRead(buttonpin);
  if (ir_value == HIGH && buttonpin_value == HIGH)
  {
  digitalWrite(ledpin,HIGH);
  
  }
  else
  {
  digitalWrite(ledpin,LOW);

}
}