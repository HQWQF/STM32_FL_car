#include "stm32f10x.h"     // Device header
void GPIO_Initset()
{
		GPIO_InitTypeDef GPIOA_InitStructure;
		RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA,ENABLE);
		GPIOA_InitStructure.GPIO_Mode=GPIO_Mode_Out_PP;
		GPIOA_InitStructure.GPIO_Pin=GPIO_Pin_All;
		GPIOA_InitStructure.GPIO_Speed=GPIO_Speed_50MHz;
		GPIO_Init(GPIOA,&GPIOA_InitStructure);
}