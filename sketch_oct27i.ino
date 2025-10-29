void setup() {
  // put your setup code here, to run once:
  DDRB |= (1 << PB3);
  DDRB |= (1 << PB2); 
  DDRD |= (1 << PD6); 

  TCCR0A = (1 << WGM01) | (1 << COM0A0); //CTC | toggle on compare match
  OCR0A  = 250;                        
  TCCR0B = (1 << CS02) | (1 << CS00);  //101 = prescaler 1024

  TCCR1A = (1 << COM1B0); //toggle on compare match
  TCCR1B = (1 << WGM12); //CTC
  OCR1A  = 3905;           
  OCR1B  = 3905;
  TCCR1B = (1 << CS11) | (1 << CS10); //prescaler 64


  TCCR2A = (1 << WGM21) | (1 << COM2A0);
  OCR2A  = 255;
  TCCR2B = (1 << CS22) | (1 << CS21); //prescaler 256
  
}

void loop() {
  // put your main code here, to run repeatedly:

}


