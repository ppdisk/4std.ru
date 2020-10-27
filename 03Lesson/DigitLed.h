#pragma once
#include "stm32f1xx_hal.h"
class DigitLed
{
public:
	DigitLed(GPIO_TypeDef*, uint16_t, 
		GPIO_TypeDef*, uint16_t, 
		GPIO_TypeDef*, uint16_t, 
		GPIO_TypeDef*, uint16_t, 
		GPIO_TypeDef*, uint16_t, 
		GPIO_TypeDef*, uint16_t, 
		GPIO_TypeDef*, uint16_t, 
		GPIO_TypeDef*, uint16_t);
	void print(uint8_t);
	void EnablePoint(bool enable);
private:
	GPIO_TypeDef *A_Port, *B_Port, *C_Port, *D_Port, *E_Port, *F_Port, *G_Port, *DP_Port;
	uint16_t Pin_A, Pin_B, Pin_C, Pin_D, Pin_E, Pin_F, Pin_G, Pin_DP;
};

