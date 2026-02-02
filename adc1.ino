 uint16_t  adc_data;
 void setup() {
  
  ADMUX = 0x50;  //SELECT ADC0 VIA MUX
  ADMUX |= (1<<6);  //VCC FOR REFERENCE VOLTAGE 
  ADCSRA |= (1<<7);
  ADCSRA |= (1<<2) | (1<<1) | (1<<0);
  Serial.begin(9600);

  DDRD &= (1<<2);  //configure as input
  //EIMSK |= (1<<0); //Enabling interrupts


}

void loop() {
  ADCSRA |= (1<<6) ;  //ADC START CONVERSION

  while(!(ADCSRA & (1<<6))) ; //for interrupt flag WAIT FOR CONVERSION COMPLETE
  
  ADCSRA |= (1<<4); //clear the flag 

  adc_data = ADC; //read the 10 bit data
  // adc_data = (ADCH << 8 ) | (ADCL);  //read the 10 bit data


  Serial.println(adc_data);

  

}


// instaed of while use interrupts so that it prints when the data is ready