volatile int  led;
void setup()
{
  DDRD &=  (1<<2);     //CONFIGURING IT AS INPUT
  EIMSK |= (1<<0);     //MASKING
  EICRA |= (1<<1) | (1<<0) ;         // to set intr0 as our interrupt(multiple bit change)
  sei();
  DDRB |= (1<<5);  //PIN-13 AS OUTPUT
  }
 void loop()
 {
  

 }
 ISR(INT0_vector)
 {
  led = !led;
  digitalWrite(13,led);
 }