void setup() {
  // put your setup code here, to run once:

  Serial.begin(9600);
  uint8_t res;
  asm volatile(
    "ldi r16, 1 \n\t"
    "ldi r17, 0 \n\t"
    "ldi r18, 10 \n\t"

    "counter: \n\t"
    "add r17, r16 \n\t"
    "inc r16 \n\t"
    "cp r17, r18 \n\t"
    "brne counter \n\t"
    "mov %[res], r17 \n\t"
    : [res] "=r" (res)
  );
  Serial.print("Result: ");
  Serial.println(res);
}

void loop() {
  // put your main code here, to run repeatedly:

}
