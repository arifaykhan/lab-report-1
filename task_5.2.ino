void setup() {
  // put your setup code here, to run once:
  DDRB |= (1 << PB3);
  DDRB |= (1 << PB2); 
  DDRD |= (1 << PD6); 

  //PD6
  TCCR0A = (1 << WGM01) | (1 << WGM00) | (1 << COM0A1); //fast PWM | toggle on compare match
  OCR0A  = 204;                        
  TCCR0B = (1 << WGM02) | (1 << CS01) | (1 << CS00);  //prescaler 64

  //PB1 for A, PB2 for B
  TCCR1A = (1 << WGM11) | (1 << WGM10) | (1 << COM1B1); //fast PWM | toggle on compare match
  TCCR1B = (1 << WGM13) | (1 << WGM12) | (1 << CS11) | (1 << CS10); //CTC | prescaler 64
  OCR1B  = 128;

  //PB3
  TCCR2A = (1 << WGM21) | (1 << WGM20) | (1 << COM2A1);
  OCR2A  = 77;
  TCCR2B = (1 << WGM22) | (1 << CS22); //prescaler 64
  
}

void loop() {
  // put your main code here, to run repeatedly:

}


