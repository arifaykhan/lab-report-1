void setup() {
  // put your setup code here, to run once:
  DDRB |= (1 << DDB5);

  asm volatile(
    "ldi r16, 5\n\t"
    "ldi r18, 8\n\t"
    "add r18, r16\n\t"
    
    "cpi r18, 13\n\t"
    "brne notequal\n\t"

    "sbi 0x05, 5\n\t"

    "rjmp done\n\t"

    "notequal:\n\t"
    "cbi 0x05, 5\n\t"

    "done:\n\t"
  );
}

void loop() {
  // put your main code here, to run repeatedly:

}
