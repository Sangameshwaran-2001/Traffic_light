#include "pico/stdlib.h"
#include "hardware/gpio.h"
#include <string.h>
#define RS 0
#define RW 1
#define EN 2
const uint a[8]={0X17,0X14,0X14,0X1F,0X05,0X05,0X1D,0X00};
const uint Data_pin[8]={3,4,5,6,7,8,9,10};
//Pulse Enable
void lcd_pulse()
{
gpio_put(EN,1);
sleep_ms(1);
gpio_put(EN,0);
sleep_ms(1);
}
//Send command to lcd
void lcd_cmd(uint8_t cmd)
{
gpio_put(RS,0);
gpio_put(RW,0);
for(int i=0;i<8;i++)
{
gpio_put(Data_pin[i],(cmd>>i)&1);
}
lcd_pulse();
}
//Lcd data
void lcd_data(uint8_t data)
{
gpio_put(RS,1);
gpio_put(RW,0);
for(int i=0;i<8;i++)
{
gpio_put(Data_pin[i],(data>>i)&1);
}
lcd_pulse();
}
//lcd_string
void lcd_string(char *ptr)
{
lcd_cmd(0x01);
lcd_cmd(0X86);
while(*ptr!=0)
{
lcd_data(*ptr);
ptr++;
}
}
//Intializing of lcd
void lcd_init()
{
gpio_init(RS);
gpio_set_dir(RS,GPIO_OUT);
gpio_init(RW);
gpio_set_dir(RW,GPIO_OUT);
gpio_init(EN);
gpio_set_dir(EN,GPIO_OUT);
for(int i=0;i<8;i++)
{
gpio_init(Data_pin[i]);
gpio_set_dir(Data_pin[i],GPIO_OUT);
}
lcd_cmd(0X38);
lcd_cmd(0X0F);
}
//CG Ram
void lcd_cgram(void)
{
unsigned int i;
lcd_cmd(0X40)
for(i=0;i<16;i++)
lcd_data(a[i]);
}

