#include "DigitLed.h"
#define OffAllSegments HAL_GPIO_WritePin(Segment1_Port, Pin_Segment1, GPIO_PIN_RESET); HAL_GPIO_WritePin(Segment2_Port, Pin_Segment2, GPIO_PIN_RESET); HAL_GPIO_WritePin(Segment3_Port, Pin_Segment3, GPIO_PIN_RESET); HAL_GPIO_WritePin(Segment4_Port, Pin_Segment4, GPIO_PIN_RESET);
	
DigitLed::DigitLed(GPIO_TypeDef *A_Port,	uint16_t Pin_A,
	GPIO_TypeDef *B_Port,	uint16_t Pin_B,
	GPIO_TypeDef *C_Port,	uint16_t Pin_C,
	GPIO_TypeDef *D_Port,	uint16_t Pin_D,
	GPIO_TypeDef *E_Port,	uint16_t Pin_E,
	GPIO_TypeDef *F_Port,	uint16_t Pin_F,
	GPIO_TypeDef *G_Port,	uint16_t Pin_G,
	GPIO_TypeDef *DP_Port,	uint16_t Pin_DP,
	GPIO_TypeDef *Segment1_Port,	uint16_t Pin_Segment1,
	GPIO_TypeDef *Segment2_Port,	uint16_t Pin_Segment2,
	GPIO_TypeDef *Segment3_Port,	uint16_t Pin_Segment3,
	GPIO_TypeDef *Segment4_Port,	uint16_t Pin_Segment4)
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
	this->Segment1_Port = Segment1_Port;
	this->Pin_Segment1 = Pin_Segment1;
	this->Segment2_Port = Segment2_Port;
	this->Pin_Segment2 = Pin_Segment2;
	this->Segment3_Port = Segment3_Port;
	this->Pin_Segment3 = Pin_Segment3;
	this->Segment4_Port = Segment4_Port;
	this->Pin_Segment4 = Pin_Segment4;
	print(10000);
	EnablePoint(false);
}


void DigitLed::print(uint16_t Number)
{
	uint16_t TempNumber = Number;
	uint8_t RemDivision = TempNumber % 10;
	OffAllSegments
	PrintSymbol(RemDivision);
	HAL_GPIO_WritePin(Segment1_Port, Pin_Segment1, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(Segment2_Port, Pin_Segment2, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(Segment3_Port, Pin_Segment3, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(Segment4_Port, Pin_Segment4, GPIO_PIN_SET);


	TempNumber = (TempNumber - RemDivision)/10;
	RemDivision = TempNumber % 10;
	OffAllSegments
	if (Number>10)
		PrintSymbol(RemDivision);
	else
		PrintSymbol(99);
	HAL_GPIO_WritePin(Segment1_Port, Pin_Segment1, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(Segment2_Port, Pin_Segment2, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(Segment3_Port, Pin_Segment3, GPIO_PIN_SET);
	HAL_GPIO_WritePin(Segment4_Port, Pin_Segment4, GPIO_PIN_RESET);
	
	TempNumber = (TempNumber - RemDivision) / 10;
	RemDivision = TempNumber % 10;
	OffAllSegments
	if (Number > 100)
		PrintSymbol(RemDivision);
	else
		PrintSymbol(99);
	HAL_GPIO_WritePin(Segment1_Port, Pin_Segment1, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(Segment2_Port, Pin_Segment2, GPIO_PIN_SET);
	HAL_GPIO_WritePin(Segment3_Port, Pin_Segment3, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(Segment4_Port, Pin_Segment4, GPIO_PIN_RESET);
	
	TempNumber = (TempNumber - RemDivision) / 10;
	RemDivision = TempNumber;
	OffAllSegments
	if (Number > 1000)
		PrintSymbol(RemDivision);
	else
		PrintSymbol(99);
	HAL_GPIO_WritePin(Segment1_Port, Pin_Segment1, GPIO_PIN_SET);
	HAL_GPIO_WritePin(Segment2_Port, Pin_Segment2, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(Segment3_Port, Pin_Segment3, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(Segment4_Port, Pin_Segment4, GPIO_PIN_RESET);
}

void DigitLed::PrintSymbol(uint8_t Digit)
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
