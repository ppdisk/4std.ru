#include "Bounce.h"


Bounce::Bounce(GPIO_TypeDef *GPIOx, uint16_t GPIO_Pin)
{
	this->Pin = GPIO_Pin;
	this->Port = GPIOx;
	this->State = 0;
	this->maxState = 10;
	updateState();
}

void Bounce::updateState()
{
	uint32_t tickCur = HAL_GetTick();
	//	Проверяем что прошло более 10 мсек
	if ((tickCur - tickPrev) > 10)
	{
		tickPrev = tickCur;
		if (HAL_GPIO_ReadPin(Port, Pin) == GPIO_PIN_SET)
		{
			if (State == (maxState - 1))
			{
				rising = 1;
			}
			if(State<maxState)
				State++;
		}
		else
		{
			if (State == 1)
			{
				falling = 1;
			}
			if(State>0)
				State--;
		}
		
	}
}

bool Bounce::risingEdge()
{
	if (rising == 1)
	{
		rising = 0;
		return 1;
	}
	return 0;
}


bool Bounce::fallingEdge()
{
	if (falling == 1)
	{
		falling = 0;
		return 1;
	}
	return 0;
}
