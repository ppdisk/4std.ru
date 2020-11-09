#pragma once
#include "Bounce.h"

class Encoder :
    public Bounce
{
public:
	Encoder(GPIO_TypeDef* PortButton, uint16_t PinButton, GPIO_TypeDef* PortSignal1, uint16_t PinSignal1, GPIO_TypeDef* PortSignal2, uint16_t PinSignal2)
		: Bounce(PortButton, PinButton) {
			this->PortSignal1 = PortSignal1;
			this->PinSignal1 = PinSignal1;
			this->PortSignal2 = PortSignal2;
			this->PinSignal2 = PinSignal2;
			this->StateSignal1 = 0;
			this->StateSignal2 = 0;
			this->maxState = 2;
			this->ValueSignal1 = 0;
			this->ValueSignal2 = 0;
			this->Direction = 0;
			this->state = 0;
		};
	
	
	void updateState(void);
	int8_t GetState(void);
private:
	GPIO_TypeDef* PortSignal1, *PortSignal2;
	uint16_t PinSignal1, PinSignal2;
	uint8_t StateSignal1, StateSignal2, maxState;
	uint32_t tickPrev;
	bool risingSignal1, fallingSignal1, risingSignal2, fallingSignal2, ValueSignal1, ValueSignal2;
	bool RisingEdge(uint8_t LineNumber);
	bool FallingEdge(uint8_t LineNumber);
	int8_t state;
	int8_t Direction;
};

