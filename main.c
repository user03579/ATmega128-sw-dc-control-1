#include "main.h"
#include "motor_io.h"
#include "led_sw.h"
void main(void)
{
	mtr_io_init();
	sw_init();
	led_init();
	
	int iMoveCW = FALSE;
	int iMoveCCW = FALSE;
	while(TRUE){
		if(!iMoveCCW && sw_onoff(SW1)){
			iMoveCW = !iMoveCW;
		}
		if(!iMoveCW && sw_onoff(SW2)){
			iMoveCCW = !iMoveCCW;
		}
		if(iMoveCW){
			mtr_io_move(MOTOR_MOVE_CW);
			led_on(LED1_4);
			_delay_ms(100);
			if(sw_onoff(SW1)){
				iMoveCW = FALSE;
				led_off(LED1_4);
				continue;
			}
			led_off(LED1_4);
			_delay_ms(100);
		}
		else if(iMoveCCW){
			mtr_io_move(MOTOR_MOVE_CCW);
			led_on(LED5_8);
			_delay_ms(100);
			if(sw_onoff(SW2)){
				iMoveCCW = FALSE;
				led_off(LED5_8);
				continue;
			}
			led_off(LED5_8);
			_delay_ms(100);
		}
		else{
			mtr_io_move(MOTOR_MOVE_STOP);
		}
		
	}

}
