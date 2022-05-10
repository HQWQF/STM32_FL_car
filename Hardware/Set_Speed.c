#include "stm32f10x.h"                  // Device header
#include "PWM.h"  
#include "OLED.h"
void Set_R_Speed(int speed);
void Set_L_Speed(int speed);
void SpeedSet_Init()
{
	GPIO_InitTypeDef GPIOB_InitStructure;
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);////GPIOB
 	GPIOB_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIOB_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIOB_InitStructure.GPIO_Pin = GPIO_Pin_12|GPIO_Pin_13|GPIO_Pin_14|GPIO_Pin_15;///电机驱动引脚初始
 	GPIO_Init(GPIOB, &GPIOB_InitStructure);

}
void Set_R_Speed(int speed)
{
	if(speed>=0)
	{

		GPIO_WriteBit(GPIOB,GPIO_Pin_12,Bit_RESET);//电机模块设置
		GPIO_WriteBit(GPIOB,GPIO_Pin_13,Bit_SET);//正转
		PWMSet_R(speed);
	}
	else
	{

		GPIO_WriteBit(GPIOB,GPIO_Pin_13,Bit_RESET);//电机模块设置
		GPIO_WriteBit(GPIOB,GPIO_Pin_12,Bit_SET);//反转
		PWMSet_R(-speed);
	}
	
}
void Set_L_Speed(int speed)
{
	if(speed>=0)
	{
		GPIO_WriteBit(GPIOB,GPIO_Pin_14,Bit_RESET);//电机模块设置
		GPIO_WriteBit(GPIOB,GPIO_Pin_15,Bit_SET);//正转
		PWMSet_L(speed);

	}
	else
	{

		GPIO_WriteBit(GPIOB,GPIO_Pin_15,Bit_RESET);//电机模块设置
		GPIO_WriteBit(GPIOB,GPIO_Pin_14,Bit_SET);//反转
		PWMSet_L(-speed);
	}
	
}
