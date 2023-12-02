#ifndef MOTOR_IO_H_
#define MOTOR_IO_H_

#include "main.h"

// 포트 PB7과 PB6에 출력할 값
#define MOTOR_CW	(0x2 << 6)	// "10", 시계 방향(clockwise)
#define MOTOR_CCW	(0x1 << 6)	// "01", 반시계 방향(counterclockwise)
#define MOTOR_STOP	(0x0 << 6)	// "00", 정지

// mtr_io_move() 함수에 전달될 값
#define MOTOR_MOVE_STOP	0	// 정지
#define MOTOR_MOVE_CW	1	// 시계 방향(clockwise) 구동
#define MOTOR_MOVE_CCW	2	// 반시계 방향(counterclockwise) 구동

void mtr_io_init(void);
void mtr_io_move(int iDir);
void mtr_io_dir_spd(int iDir, uint uSpeed, float fSec);

#endif /* MOTOR_IO_H_ */ 