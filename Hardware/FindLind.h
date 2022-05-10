
#ifndef _FindLind_H_
#define _FindLind_H_
uint8_t GETFindLineState(void);
void FLSensor_Init(void);
void Run_Forward(int Speed);
void Run_Stop(void);
void Run_Left(int Speed);
void Run_Right(int Speed);
void Run_TurnRight(int Speed);
void Run_TurnLeft(int Speed);
void Run_Big_TurnRight(int Speed);
void Run_Big_TurnLeft(int Speed);
#endif
