const uint8_t dutysteps[4] = {64, 128, 192, 255};

void setup() {
  // put your setup code here, to run once:
  DDRD |= (1 << PD6) | (1 << PD3);
  DDRB |= (1 << PB3);
  DDRD &= ~(1 << PD5);

  TCCR0A = (1 << COM0A1) | (1 << WGM01) | (1 << WGM00);
  TCCR0B = (1 << CS01) | (1 << CS00);
  OCR0A  = 0;

  TCCR2A = (1 << COM2A1) | (1 << COM2B1) | (1 << WGM21) | (1 << WGM20);
  TCCR2B = (1 << CS22);
  OCR2A  = 0;
  OCR2B  = 0;

  TCCR1A = 0;
  TCCR1B = (1 << CS12) | (1 << CS11) | (1 << CS10);
  TCNT1  = 0;

  TIFR0 |= (1 << TOV0);
}

void loop() {
  // put your main code here, to run repeatedly:
  static uint8_t state = 0;
  static bool waiting_release = false;
  static uint8_t release_count = 0;

  if (!waiting_release) {
    if (TCNT1 != 0) {
      TCNT1 = 0;
      state = (state + 1) % 13;
      waiting_release = true;
      release_count = 0;
    }
  } 
  else {
    if ((PIND & (1 << PD5)) != 0) {
      if (release_count < 255) ++release_count;
    } 
    else release_count = 0;
    if (release_count >= 5) waiting_release = false;
  }

  uint8_t dutypd6 = 0, dutypb3 = 0, dutypd3 = 0;

  if (state == 0) dutypd6 = dutypb3 = dutypd3 = 0;
  else {
    uint8_t state1 = state - 1;
    uint8_t group = state1 / 4;
    uint8_t index = state1 % 4;
    uint8_t duty = dutysteps[index];

  if (group == 0) dutypd6 = duty;
  else if (group == 1) {
      dutypd6 = dutysteps[3];
      dutypb3 = duty;
  } 
  else {
      dutypd6 = dutysteps[3];
      dutypb3 = dutysteps[3];
      dutypd3 = duty;
  }
}
  OCR0A = dutypd6;
  OCR2A = dutypb3;
  OCR2B = dutypd3;
}
