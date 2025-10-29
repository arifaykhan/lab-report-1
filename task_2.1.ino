void setup() {
  // put your setup code here, to run once:
  DDRB |= (1 << DDB5);
  DDRD &= ~(1 << DDD2);
}

void loop() {
  // put your main code here, to run repeatedly:
  if(PIND & B00000100){
    PORTB ^= (1 << PORTB5);
    delay(100);
  }
}
