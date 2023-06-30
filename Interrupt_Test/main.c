#include <stdio.h>
#include <util/delay.h>

int main() {

  *((volatile unsigned char*)0x5F) &= ~(1 << 7);  //Set SREG Bit 7 to 0
  *((volatile unsigned char*)0x68) |= (1 << 0);   //Set PCICR Bit 0 to 1
  *((volatile unsigned char*)0x6B) |= (1 << 0);   //Set PCMSK0 Bit 0 to 1
  *((volatile unsigned char*)0x5F) |= (1 << 7);   //Set SREG Bit 7 to 1

  *((volatile unsigned char*)0x24) |= (1 << 5);  //Set DDRB Bit 5 to 1

  while (1) {
    *((volatile unsigned char*)0x25) |= (1 << 5);
    _delay_ms(50);
    *((volatile unsigned char*)0x25) &= ~(1 << 5);
    _delay_ms(4000);
  };



  return 0;
};

ISR(PCINT0_vect) {
  *((volatile unsigned char*)0x25) |= (1 << 5);
  _delay_ms(100);
  *((volatile unsigned char*)0x25) &= ~(1 << 5);
  _delay_ms(100);
  *((volatile unsigned char*)0x25) |= (1 << 5);
  _delay_ms(100);
  *((volatile unsigned char*)0x25) &= ~(1 << 5);
  _delay_ms(100);
};