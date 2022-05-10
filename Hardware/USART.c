#include "stm32f10x.h"     // Device header


void USARTsys_Init()
{
	GPIO_InitTypeDef GPIOA2_InitStructure; 
	NVIC_InitTypeDef NVIC_InitStructure;
	USART_InitTypeDef USART1_InitStructure;
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_USART1,ENABLE);//串口1使能
	GPIOA2_InitStructure.GPIO_Mode=GPIO_Mode_AF_PP;//初始化串口
	GPIOA2_InitStructure.GPIO_Pin=GPIO_Pin_9;
	GPIOA2_InitStructure.GPIO_Speed=GPIO_Speed_50MHz;
	GPIO_Init(GPIOA,&GPIOA2_InitStructure);
	
	GPIOA2_InitStructure.GPIO_Mode=GPIO_Mode_IN_FLOATING;//初始化串口
	GPIOA2_InitStructure.GPIO_Pin=GPIO_Pin_10;
	GPIOA2_InitStructure.GPIO_Speed=GPIO_Speed_50MHz;
	GPIO_Init(GPIOA,&GPIOA2_InitStructure);
	
	USART_StructInit(&USART1_InitStructure);//初始化串口
	USART_Init(USART1,&USART1_InitStructure);
	USART_Cmd(USART1,ENABLE);
	USART_ITConfig(USART1,USART_IT_RXNE,ENABLE);
	
	NVIC_InitStructure.NVIC_IRQChannel=USART1_IRQn;      //初始化串口优先级          
  NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority=1;
  NVIC_InitStructure.NVIC_IRQChannelSubPriority=1;        
  NVIC_InitStructure.NVIC_IRQChannelCmd=ENABLE;        
	NVIC_Init(&NVIC_InitStructure);
}

/*
void USART1_IRQHandler()//串口中断模板
{
  unsigned char data;
	if(USART_GetITStatus(USART1,USART_IT_RXNE)==SET)
	{
		data=USART_ReceiveData(USART1);//反馈发送的数据
		USART_SendData(USART1,data);
		
		
	}
*/
