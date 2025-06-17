#include "pico/stdlib.h"
#include "header.h"
int main()
{
const uint LED_PIN1=16;
const uint LED_PIN2=17;
const uint LED_PIN3=18;
gpio_init(LED_PIN1);
gpio_init(LED_PIN2);
gpio_init(LED_PIN3);
gpio_set_dir(LED_PIN1,GPIO_OUT);
gpio_set_dir(LED_PIN2,GPIO_OUT);
gpio_set_dir(LED_PIN3,GPIO_OUT);
lcd_init();
lcd_cgram();
while(true)
{
gpio_put(LED_PIN1,1);
lcd_string("Stop");
lcd_data(0x00);
Sevensegment(0);
gpio_put(LED_PIN1,0);
gpio_put(LED_PIN2,1);
lcd_string("Ready");
sleep_ms(2000);
//Sevensegment(6);
gpio_put(LED_PIN2,0);
gpio_put(LED_PIN3,1);
lcd_string("Go");
Sevensegment(0);
gpio_put(LED_PIN3,0);
sleep_ms(1000);
}
}
