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
		GPIO_TypeDef*, uint16_t,
		GPIO_TypeDef*, uint16_t, 
		GPIO_TypeDef*, uint16_t, 
		GPIO_TypeDef*, uint16_t, 
		GPIO_TypeDef*, uint16_t);
	void print(uint16_t);
	void EnablePoint(bool enable);
private:
	GPIO_TypeDef *A_Port, *B_Port, *C_Port, *D_Port, *E_Port, *F_Port, *G_Port, *DP_Port;
	GPIO_TypeDef *Segment1_Port, *Segment2_Port, *Segment3_Port, *Segment4_Port;
	uint16_t Pin_A, Pin_B, Pin_C, Pin_D, Pin_E, Pin_F, Pin_G, Pin_DP;
	uint16_t Pin_Segment1, Pin_Segment2, Pin_Segment3, Pin_Segment4;
	void PrintSymbol(uint8_t Symbol);
};

