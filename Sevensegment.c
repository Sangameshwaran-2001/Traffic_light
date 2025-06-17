#include "pico/stdlib.h"
const uint segement_pins[8]={11,12,13,14,15,19,20,21};
const uint8_t digits[11]={0X3F,0X06,0X5B,0X4F,0X66,0X6D,0X7D,0X07,0X7F,0X6F,0X80};
void display_digit(uint8_t value)
{
for(int i=0;i<8;i++)
{
bool segement_on=(value>>i)&1;
gpio_put(segement_pins[i],segement_on);
}
}
void Sevensegment(int a)
{
for(int i=0;i<8;i++)
{
gpio_init(segement_pins[i]);
gpio_set_dir(segement_pins[i],GPIO_OUT);
}
for(int i=9-a;i>0;i--)
{
display_digit(digits[i]);
sleep_ms(1000);
display_digit(0x00);
sleep_ms(200);
}
}
