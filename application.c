/* 
 * File:   application.c
 * Author: Abdelrahman Mansour
 *
 * Created on August 4, 2024, 4:38 AM
 */


#include "application.h"

void tmr0_isr(void);
void init(void);



Std_ReturnType ret = E_NOT_OK;
uint8 seconds = 10;
uint8 color =0;
typedef enum {
  RED,
  YELLOW,
  GREEN,
}colors;



segment_t seven_seg_obj = {
.segment_type = SEGMENT_COMMON_ANODE,
.segment_pin[0].port = PORTA_INDEX,
.segment_pin[0].pin = PIN0,
.segment_pin[0].direction = GPIO_OUTPUT,
.segment_pin[0].logic = LOW,
.segment_pin[1].port = PORTA_INDEX,
.segment_pin[1].pin = PIN1,
.segment_pin[1].direction = GPIO_OUTPUT,
.segment_pin[1].logic = LOW,
.segment_pin[2].port = PORTA_INDEX,
.segment_pin[2].pin = PIN2,
.segment_pin[2].direction = GPIO_OUTPUT,
.segment_pin[2].logic = LOW,
.segment_pin[3].port = PORTA_INDEX,
.segment_pin[3].pin = PIN3,
.segment_pin[3].direction = GPIO_OUTPUT,
.segment_pin[3].logic = LOW,
};


 timer0_t timer0_obj ={
 .Timer0_InterruptHandler = tmr0_isr,
 .prescaler_enable = TIMER0_PRESCALER_ENABLE,
 .prescaler_val = TIMER0_PRESCALER_VALUE_DIV_BY_32,
 .timer0_mode = TIMER0_TIMER_MODE,
 .timer0_reg_size = TIMER0_REGESTER_SIZE_16BIT,
 .timer0_preload_val = 3036,
 
 };
 led_t red_led ={
   .port = PORTD_INDEX,
   .pin = PIN0,
   .status = LOW,
 };

  led_t yellow_led ={
   .port = PORTD_INDEX,
   .pin = PIN1,
   .status = LOW,
 };
  
 led_t green_led ={
   .port = PORTD_INDEX,
   .pin = PIN2,
   .status = LOW,
 };
 pin_config_t pin0 = {
   .port = PORTC_INDEX,
   .pin = PIN0,
   .direction = GPIO_OUTPUT,
   .logic = LOW,
 };
  pin_config_t pin1 = {
   .port = PORTC_INDEX,
   .pin = PIN1,
   .direction = GPIO_OUTPUT,
   .logic = LOW,
 };

int main() {
    init();

    while(1){
            ret = gpio_port_write_logic(PORTC_INDEX, 0x01); // 0000 0001
            ret = gpio_port_write_logic(PORTA_INDEX, ((uint8)(seconds/10)));
            __delay_ms(10);
            ret = gpio_port_write_logic(PORTC_INDEX, 0x02); // 0000 0010
            ret = gpio_port_write_logic(PORTA_INDEX, ((uint8)(seconds%10)));
            __delay_ms(10);
            if(color == RED){
            ret = led_turn_on(&red_led);
            if(seconds == 0){
                ret = led_turn_off(&red_led); 
                seconds = 5;
                color = YELLOW;
            }
            else{/*Nothing*/}
            }
            else if (color == YELLOW){
                 ret = led_turn_on(&yellow_led);
                 if(seconds == 0){
                 ret = led_turn_off(&yellow_led); 
                 seconds = 10;
                 color = GREEN;
            }
            else{/*Nothing*/}
            }
            else if (color == GREEN){
                 ret = led_turn_on(&green_led);
                 if(seconds == 0){
                 ret = led_turn_off(&green_led); 
                 seconds = 10;
                 color = RED;
            }
            else{/*Nothing*/}
            }
            else{/*Nothing*/}
    
    }
    
    return (EXIT_SUCCESS);
}

void init(void){
    ret = led_init(&red_led);
    ret = led_init(&yellow_led);
    ret = led_init(&green_led);
    ret = seven_segment_init(&seven_seg_obj);
    ret = Timer0_Init(&timer0_obj);
    ret = gpio_pin_direction_init(&pin0);
    ret = gpio_pin_direction_init(&pin1);
}

 void tmr0_isr(void){ 
     seconds--;
 }
