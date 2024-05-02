/*
 * dc_motor.h
 *
 *  Created on: Apr 22, 2024
 *      Author: shirbiny
 */

#ifndef DC_MOTOR_H_
#define DC_MOTOR_H_

#include "std_types.h"

#define ROTATE_LEFT    0
#define ROTATE_RIGHT   1
#define ROTATE_STOP    2

void Dc_Motor_Init(void);

void Dc_Motor_Rotate(uint8 direction);


#endif /* DC_MOTOR_H_ */
