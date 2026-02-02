 uint16_t  adc_data;
 int volatile conversion_done;
 void setup() {
  
  ADMUX = 0x50;  //SELECT ADC0 VIA MUX
  ADMUX |= (1<<6);  //VCC FOR REFERENCE VOLTAGE 
  ADCSRA |= (1<<7);
  ADCSRA |= (1<<2) | (1<<1) | (1<<0);
  Serial.begin(9600);

  
  ADCSRA |= (1<<3); // adc interupt enable
  ADCSRA |= (1<<6); //ADC start conversion 

 

}

void loop() {
 if (conversion_done){
  adc_data = ADC; //read the 10 bit data
  // adc_data = (ADCH << 8 ) | (ADCL);  //read the 10 bit data


  Serial.println(adc_data);
  conversion_done =0;
  ADCSRA |= (1<<6); //ADC start conversion 

 }
}

ISR(ADC_vect){
  conversion_done = 1;

}
