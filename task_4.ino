#include <EEPROM.h>

  uint8_t counter = 0;
  uint8_t counterbutton1 = 0;
  uint8_t counteraddress = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  DDRD &= ~(1 << DDD4);

  while (EECR & (1 << EEPE));
    EEAR = 0;
    EECR |= (1 << EERE);
    counter = EEDR;

  Serial.print("Counter in EEPROM: ");
  Serial.println(counter);
}

void loop() {
  // put your main code here, to run repeatedly:
  uint8_t counterbutton0 = PIND & (1 << PD4);
  if (PIND & (1 << PD4)){
    counter++;
    while (EECR & (1 << EEPE));
      EEAR = 0;
      EEDR = counter;
      EECR |= (1 << EEMPE);
      EECR |= (1 << EEPE);
    Serial.print("Counter in EEPROM: ");
    Serial.println(counter);
    delay(50);
  }
  counterbutton1 = counterbutton0;
  delay(50);
}
