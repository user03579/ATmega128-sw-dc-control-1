#include "motor_io.h"

// DC 모터 드라이버가 연결된 포트 PB6과 PB7을 출력으로 설정, 모두 0 출력
void mtr_io_init(void)
{
	DDRB |= 0xC0;	// 1100_0000
	PORTB &= 0x3F;	// 0011_1111
}

// DC 모터 구동
void mtr_io_move(int iDir)
{
	switch(iDir) {
		case MOTOR_MOVE_CW:	PORTB = (PORTB & 0x3F) | MOTOR_CW; break;
		case MOTOR_MOVE_CCW:	PORTB = (PORTB & 0x3F) | MOTOR_CCW; break;
		default: PORTB = (PORTB & 0x3F) | MOTOR_STOP;
	}
}

// PWM파의 듀티비 제어 --> DC 모터 구동 속도 제어
// PWM파의 주기: 100[msec]
// uSpeed: (0 - 100) --> (듀티비: 0% - 100%)
void mtr_io_dir_spd(int iDir, uint uSpeed, float fSec)
{	
	int iTimes;

	if(uSpeed > 100) uSpeed = 100;	// 100으로 제한
	if(fSec < 0.1) fSec = 0.1;
	iTimes = fSec/0.1;	// for 루프 실행 횟수 = fSec[sec] / 100[msec]

	for(int i=0; i<iTimes; i++) {	// 루프 1회 실행 --> 약 100[msec]
		mtr_io_move(iDir);					// 모터 구동
		_delay_ms(uSpeed);	
		mtr_io_move(MOTOR_MOVE_STOP);	// 모터 정지
		_delay_ms(100 - uSpeed);	
	}
}
 