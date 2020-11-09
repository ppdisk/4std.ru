#pragma once
#include "stm32f1xx_hal.h"
class Bounce
{

public:
	Bounce(GPIO_TypeDef*, uint16_t);
	void updateState();
	bool risingEdge();
	bool fallingEdge();
private:
	uint8_t State, maxState;
	GPIO_TypeDef *Port;
	uint16_t Pin;
	uint32_t tickPrev;
	bool rising, falling;
};

