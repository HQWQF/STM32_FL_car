#include "stm32f10x.h"     // Device header
#include "PWM.h"  
#include "OLED.h"
#include "FindLind.h"
#include "Set_Speed.h"
#include "USART.h"
#include "Delay.h"

uint16_t time=0;
//循迹模块读取宏
#define F_Right_3 GPIO_ReadInputDataBit(GPIOA,GPIO_Pin_6)
#define	F_Right_2 GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_11)
#define	F_Right_1 GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_10)
#define	F_Md GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_1)
#define	F_Left_1 GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_0)
#define	F_Left_2 GPIO_ReadInputDataBit(GPIOA,GPIO_Pin_7)
#define	F_Left_3  GPIO_ReadInputDataBit(GPIOA,GPIO_Pin_5)
int main()/////开发平台：STM32F103C8T6,使用标准库
{
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);//设置中断分组
	OLED_Init();
	FLSensor_Init();
	PWM_Init();
	SpeedSet_Init();
	USARTsys_Init();
		while(1)
	{
	 if(F_Right_1==1&&F_Left_1==1)   //R?1?1?L全部占线（交叉线）正常前进
		{
			Run_Forward(200);
			Delay_ms(100);
		}
		
		else if(F_Left_3==1)//向L转弯R??????1L
		{
			Run_Stop();
			Delay_ms(100);
			Run_Big_TurnLeft(230);
			Delay_ms(320);
			while(1)
				{		
					
					if(F_Left_1==1||F_Md==1)break;
					//if(F_Left_1==1||F_Md==1)break;
				}	
		}
		else if(F_Right_3==1)//向R转弯R1??????L
		{
		
			Run_Stop();
			Delay_ms(100);
			Run_Big_TurnRight(230);
			Delay_ms(320);
			while(1)
				{		
					if(F_Right_1==1||F_Md==1){break;}
					//if(F_Right_1==1||F_Md==1){Run_Stop();break;}
				}	
		}
		
		
			else if(F_Right_2==1)//向R转弯 R1????L
		{
			Run_TurnRight(135);
			
			while(1)
				{		
					if((F_Right_3==1)||(F_Right_1==1)){break;}
				}	
			
		}

	
		else if(F_Left_2==1)//向L转弯 R????1L
		{
			Run_TurnLeft(135);
			
			while(1)
				{		
					if(F_Left_3==1||F_Left_1==1){break;}
				}	
			
		}
		else if(F_Right_2==0&&F_Right_1==1&&F_Left_1==0&&F_Left_2==0)//R01?00L
		{
			Run_Right(130);
		}
		
	
		else if(F_Right_2==0&&F_Right_1==0&&F_Left_1==1&&F_Left_2==0)//R00?10L
		{
			Run_Left(130);
		}
		if(F_Right_2==0&&F_Right_1==0&&F_Md==1&&F_Left_1==0&&F_Left_2==0)   //R00100L 中间占线正常前进
		{
			Run_Forward(220);
		}
		
	}
}

