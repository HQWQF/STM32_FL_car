#include "stm32f10x.h"                  // Device header
#include "Set_Speed.h"
extern uint8_t F_Left_1;
extern uint8_t F_Left_2;
extern uint8_t F_Left_3;
extern uint8_t F_Md;
extern uint8_t F_Right_1;
extern uint8_t F_Right_2;
extern uint8_t F_Right_3;
void FLSensor_Init(void)//循迹模块初始化
{
	GPIO_InitTypeDef GPIOB_InitStructure;
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB,ENABLE);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA,ENABLE);
	GPIOB_InitStructure.GPIO_Mode=GPIO_Mode_IPU;
	GPIOB_InitStructure.GPIO_Pin=GPIO_Pin_11|GPIO_Pin_10|GPIO_Pin_0|GPIO_Pin_1;
	GPIOB_InitStructure.GPIO_Speed=GPIO_Speed_50MHz;
	GPIO_Init(GPIOB,&GPIOB_InitStructure);
	GPIOB_InitStructure.GPIO_Pin=GPIO_Pin_7|GPIO_Pin_6|GPIO_Pin_5;
	GPIO_Init(GPIOA,&GPIOB_InitStructure);
}
//调试用，显示循迹状态
uint8_t GETFindLineState(void)
{
	uint8_t State=0x00;
	State|=GPIO_ReadInputDataBit(GPIOA,GPIO_Pin_6)<<6;
	State|=GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_11)<<5;
	State|=GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_10)<<4;
	State|=GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_1)<<3;
	State|=GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_0)<<2;
	State|=GPIO_ReadInputDataBit(GPIOA,GPIO_Pin_7)<<1;
	State|=GPIO_ReadInputDataBit(GPIOA,GPIO_Pin_5);
	
	return State;
}
void Run_Forward(int Speed)
{
	Set_L_Speed(Speed);
	Set_R_Speed(Speed);

}
void Run_Stop(void)
{
	Set_L_Speed(0);
	Set_R_Speed(0);

}

void Run_Left(int Speed)
{
	Set_L_Speed(Speed);
	Set_R_Speed(Speed+140);
}
void Run_Right(int Speed)
{
	Set_L_Speed(Speed+140);
	Set_R_Speed(Speed);
}
void Run_TurnRight(int Speed)
{
	Set_L_Speed(2*Speed+40);
	Set_R_Speed(Speed);

}

void Run_TurnLeft(int Speed)
{
	Set_L_Speed(Speed);
	Set_R_Speed(2*Speed+40);
}
void Run_Big_TurnRight(int Speed)
{
	Set_L_Speed(Speed);
	Set_R_Speed(-Speed);

}

void Run_Big_TurnLeft(int Speed)
{
	Set_L_Speed(-Speed);
	Set_R_Speed(Speed);

}
