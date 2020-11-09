#include "Encoder.h"


void Encoder::updateState(void)
{
	Bounce::updateState();
	
	
	uint32_t tickCur = HAL_GetTick();
	//	Проверяем что прошло более 2 мсек
	if((tickCur - tickPrev) > 2)
	{
		tickPrev = tickCur;
		//Обновление состояние первой сигнальной линии
		GPIO_PinState Pin1State = HAL_GPIO_ReadPin(PortSignal1, PinSignal1);
		if (Pin1State == GPIO_PIN_SET)
		{
			if (StateSignal1 == (maxState - 1))
			{
				risingSignal1 = 1;
			}
			if (StateSignal1 < maxState)
				StateSignal1++;
		}
		else
		{
			if (StateSignal1 == 1)
			{
				fallingSignal1 = 1;
			}
			if (StateSignal1 > 0)
				StateSignal1--;
		}
		
		//Обновление состояние второй сигнальной линии
		GPIO_PinState Pin2State = HAL_GPIO_ReadPin(PortSignal2, PinSignal2);
		if (Pin2State == GPIO_PIN_SET)
		{
			if (StateSignal2 == (maxState - 1))
			{
				risingSignal2 = 1;
			}
			if (StateSignal2 < maxState)
				StateSignal2++;
		}
		else
		{
			if (StateSignal2 == 1)
			{
				fallingSignal2 = 1;
			}
			if (StateSignal2 > 0)
				StateSignal2--;
		}
		
		//Обновляем информацию о том, в каком состоянии сейчас пины
			if(RisingEdge(1) == true)
				ValueSignal1 = 1;
			if(RisingEdge(2) == true)
				ValueSignal2 = 1;
			if(FallingEdge(1) == true) 
				ValueSignal1 = 0;
			if (FallingEdge(2) == true) 
				ValueSignal2 = 0;
		
		//Рассчитываем в какую сторону повернули энкодер
		// Если на первой линии высокий уровень, а на второй линии - низкий, то вращаем в одну сторону
		if(ValueSignal1 == 1 && ValueSignal2 == 0)
		{
			Direction = 1;
		}
		// Если на первой линии низкий уровень, а на второй линии - высокий, то вращаем в другую сторону
		if(ValueSignal1 == 0 && ValueSignal2 == 1)
		{
			Direction = -1;
		}
		// как определились с направлением - ждём когда оба сигнала поднимутся в высокий уровень, фиксируем шаг, и сбрасываем флаг направления.
		if(Direction != 0 && ValueSignal1 == 1 && ValueSignal2 == 1)
		{
			state = state + Direction;
			Direction = 0;
		}
	}
	
}



bool Encoder::RisingEdge(uint8_t LineNumber)
{
	if (LineNumber == 1)
	{
		if (risingSignal1 == 1)
		{
			risingSignal1 = 0;
			return 1;
		}
		return 0;
	}
	else
	{
		if (risingSignal2 == 1)
		{
			risingSignal2 = 0;
			return 1;
		}
		return 0;
	}
}

bool Encoder::FallingEdge(uint8_t LineNumber)
{
	if (LineNumber == 1)
	{
		if (fallingSignal1 == 1)
		{
			fallingSignal1 = 0;
			return 1;
		}
		return 0;
	}
	else
	{
		if (fallingSignal2 == 1)
		{
			fallingSignal2 = 0;
			return 1;
		}
		return 0;
	}
}


int8_t Encoder::GetState(void)
{
	int8_t  ValueToReturn = this->state;
	this->state = 0;
	return ValueToReturn;
}
