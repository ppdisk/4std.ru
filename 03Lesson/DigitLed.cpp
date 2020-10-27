#include "DigitLed.h"

	
DigitLed::DigitLed(GPIO_TypeDef *A_Port,	uint16_t Pin_A,
	GPIO_TypeDef *B_Port,	uint16_t Pin_B,
	GPIO_TypeDef *C_Port,	uint16_t Pin_C,
	GPIO_TypeDef *D_Port,	uint16_t Pin_D,
	GPIO_TypeDef *E_Port,	uint16_t Pin_E,
	GPIO_TypeDef *F_Port,	uint16_t Pin_F,
	GPIO_TypeDef *G_Port,	uint16_t Pin_G,
	GPIO_TypeDef *DP_Port,	uint16_t Pin_DP)
{
	this->A_Port = A_Port;
	this->Pin_A = Pin_A;
	this->B_Port = B_Port;
	this->Pin_B = Pin_B;
	this->C_Port = C_Port;
	this->Pin_C = Pin_C;
	this->D_Port = D_Port;
	this->Pin_D = Pin_D;
	this->E_Port = E_Port;
	this->Pin_E = Pin_E;
	this->F_Port = F_Port;
	this->Pin_F = Pin_F;
	this->G_Port = G_Port;
	this->Pin_G = Pin_G;
	this->DP_Port = DP_Port;
	this->Pin_DP = Pin_DP;
	print(10);
	EnablePoint(false);
}

void DigitLed::print(uint8_t Digit)
{
	switch (Digit)
	{
	case 0:
		HAL_GPIO_WritePin(A_Port, Pin_A, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(B_Port, Pin_B, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(C_Port, Pin_C, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(D_Port, Pin_D, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(E_Port, Pin_E, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(F_Port, Pin_F, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(G_Port, Pin_G, GPIO_PIN_SET);
		break;
	case 1:
		HAL_GPIO_WritePin(A_Port, Pin_A, GPIO_PIN_SET);
		HAL_GPIO_WritePin(B_Port, Pin_B, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(C_Port, Pin_C, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(D_Port, Pin_D, GPIO_PIN_SET);
		HAL_GPIO_WritePin(E_Port, Pin_E, GPIO_PIN_SET);
		HAL_GPIO_WritePin(F_Port, Pin_F, GPIO_PIN_SET);
		HAL_GPIO_WritePin(G_Port, Pin_G, GPIO_PIN_SET);
		break;
	case 2:
		HAL_GPIO_WritePin(A_Port, Pin_A, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(B_Port, Pin_B, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(C_Port, Pin_C, GPIO_PIN_SET);
		HAL_GPIO_WritePin(D_Port, Pin_D, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(E_Port, Pin_E, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(F_Port, Pin_F, GPIO_PIN_SET);
		HAL_GPIO_WritePin(G_Port, Pin_G, GPIO_PIN_RESET);
		break;
	case 3:
		HAL_GPIO_WritePin(A_Port, Pin_A, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(B_Port, Pin_B, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(C_Port, Pin_C, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(D_Port, Pin_D, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(E_Port, Pin_E, GPIO_PIN_SET);
		HAL_GPIO_WritePin(F_Port, Pin_F, GPIO_PIN_SET);
		HAL_GPIO_WritePin(G_Port, Pin_G, GPIO_PIN_RESET);
		break;
	case 4:
		HAL_GPIO_WritePin(A_Port, Pin_A, GPIO_PIN_SET);
		HAL_GPIO_WritePin(B_Port, Pin_B, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(C_Port, Pin_C, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(D_Port, Pin_D, GPIO_PIN_SET);
		HAL_GPIO_WritePin(E_Port, Pin_E, GPIO_PIN_SET);
		HAL_GPIO_WritePin(F_Port, Pin_F, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(G_Port, Pin_G, GPIO_PIN_RESET);
		break;
	case 5:
		HAL_GPIO_WritePin(A_Port, Pin_A, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(B_Port, Pin_B, GPIO_PIN_SET);
		HAL_GPIO_WritePin(C_Port, Pin_C, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(D_Port, Pin_D, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(E_Port, Pin_E, GPIO_PIN_SET);
		HAL_GPIO_WritePin(F_Port, Pin_F, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(G_Port, Pin_G, GPIO_PIN_RESET);
		break;
	case 6:
		HAL_GPIO_WritePin(A_Port, Pin_A, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(B_Port, Pin_B, GPIO_PIN_SET);
		HAL_GPIO_WritePin(C_Port, Pin_C, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(D_Port, Pin_D, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(E_Port, Pin_E, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(F_Port, Pin_F, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(G_Port, Pin_G, GPIO_PIN_RESET);
		break;
	case 7:
		HAL_GPIO_WritePin(A_Port, Pin_A, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(B_Port, Pin_B, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(C_Port, Pin_C, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(D_Port, Pin_D, GPIO_PIN_SET);
		HAL_GPIO_WritePin(E_Port, Pin_E, GPIO_PIN_SET);
		HAL_GPIO_WritePin(F_Port, Pin_F, GPIO_PIN_SET);
		HAL_GPIO_WritePin(G_Port, Pin_G, GPIO_PIN_SET);
		break;
	case 8:
		HAL_GPIO_WritePin(A_Port, Pin_A, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(B_Port, Pin_B, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(C_Port, Pin_C, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(D_Port, Pin_D, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(E_Port, Pin_E, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(F_Port, Pin_F, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(G_Port, Pin_G, GPIO_PIN_RESET);
		break;
	case 9:
		HAL_GPIO_WritePin(A_Port, Pin_A, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(B_Port, Pin_B, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(C_Port, Pin_C, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(D_Port, Pin_D, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(E_Port, Pin_E, GPIO_PIN_SET);
		HAL_GPIO_WritePin(F_Port, Pin_F, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(G_Port, Pin_G, GPIO_PIN_RESET);
		break;
	default:
		HAL_GPIO_WritePin(A_Port, Pin_A, GPIO_PIN_SET);
		HAL_GPIO_WritePin(B_Port, Pin_B, GPIO_PIN_SET);
		HAL_GPIO_WritePin(C_Port, Pin_C, GPIO_PIN_SET);
		HAL_GPIO_WritePin(D_Port, Pin_D, GPIO_PIN_SET);
		HAL_GPIO_WritePin(E_Port, Pin_E, GPIO_PIN_SET);
		HAL_GPIO_WritePin(F_Port, Pin_F, GPIO_PIN_SET);
		HAL_GPIO_WritePin(G_Port, Pin_G, GPIO_PIN_SET);
		break;
	}
}


void DigitLed::EnablePoint(bool enable)
{
	if (enable == true)
	{
		HAL_GPIO_WritePin(DP_Port, Pin_DP, GPIO_PIN_RESET);
		
	}
	else
	{
		HAL_GPIO_WritePin(DP_Port, Pin_DP, GPIO_PIN_SET);
	}
}
