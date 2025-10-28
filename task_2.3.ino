void setup() {
  Serial.begin(9600);

  uint8_t res;
  uint8_t sreg;

  asm volatile(
    "ldi r16, 50 \n\t"   
    "ldi r17, 200 \n\t"
    "sub r16, r17 \n\t"   
    "mov r18, r16 \n\t"   
    "mov %[res], r18 \n\t"   
    "in  %[sreg], __SREG__ \n\t"   
    : [res] "=r" (res), [sreg] "=r" (sreg)
    :
    : "r16", "r17", "r18"
  );

  Serial.print("Result (R18): ");
  Serial.println(res);

  bool Z = sreg & (1 << 1); // Zero flag bit
  bool C = sreg & (1 << 0); // Carry flag bit

  Serial.print("Zero flag: ");
  Serial.println(Z);
  Serial.print("Carry flag: ");
  Serial.println(C);
}

void loop() {
  // put your main code here, to run repeatedly:

}
