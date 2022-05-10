#include "stm32f10x.h"     // Device header
void PWM_Init()
{
	GPIO_InitTypeDef GPIOA_InitStructure;
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2,ENABLE);//TIM2使能
	TIM_InternalClockConfig(TIM2);//使用内部时钟
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA,ENABLE);//初始化GPIOA口
	GPIOA_InitStructure.GPIO_Speed=GPIO_Speed_50MHz;
	GPIOA_InitStructure.GPIO_Mode=GPIO_Mode_AF_PP;
	GPIOA_InitStructure.GPIO_Pin=GPIO_Pin_0|GPIO_Pin_1;
	GPIO_Init(GPIOA,&GPIOA_InitStructure);
	TIM_TimeBaseInitTypeDef TIM_TimeBaseInitStruct;
	TIM_TimeBaseInitStruct.TIM_ClockDivision = TIM_CKD_DIV1;
	TIM_TimeBaseInitStruct.TIM_CounterMode = TIM_CounterMode_Up;
	TIM_TimeBaseInitStruct.TIM_Period = 899- 1;//ARR
	TIM_TimeBaseInitStruct.TIM_Prescaler = 80- 1;//PSC
	TIM_TimeBaseInitStruct.TIM_RepetitionCounter = 0;
	TIM_TimeBaseInit(TIM2,&TIM_TimeBaseInitStruct);//初始化配置时基单元
	//PWM频率：1khz
	//PWM占空比满值：900/900
	TIM_OCInitTypeDef TIM_OCInitStruct;
	TIM_OCStructInit(&TIM_OCInitStruct);
	TIM_OCInitStruct.TIM_OCMode = TIM_OCMode_PWM1;
	TIM_OCInitStruct.TIM_OCIdleState = TIM_OCPolarity_High ;
	TIM_OCInitStruct.TIM_OutputState = TIM_OutputState_Enable;
	TIM_OCInitStruct.TIM_Pulse = 300;//CCR
	TIM_OC1Init(TIM2,&TIM_OCInitStruct);
	TIM_OCInitStruct.TIM_Pulse = 300;//CCR
	TIM_OC2Init(TIM2,&TIM_OCInitStruct);
	TIM_Cmd(TIM2,ENABLE);
}
void PWMSet_L(uint16_t compare1)
{
	TIM_SetCompare1(TIM2,compare1);
}
void PWMSet_R(uint16_t compare2)
{
	TIM_SetCompare2(TIM2,compare2);
	
}
