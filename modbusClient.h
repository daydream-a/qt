#ifndef _MODBUSCLIENT_H_
#define _MODBUSCLIENT_H_


#include <stdio.h>
#include "mod_send.h"

#include <Windows.h>

#define _MODBUSDEBUG_


#define MODBUSRAUDRATE   9600
#define SERVERLOSTTIME   3000
#define MODBUSRESEND     3


void initMODBUS(void);
// int initCom(char * comNum);
// void closeCom(void);


unsigned short* read0xxxx_01(unsigned char station, unsigned short mbAddr, unsigned short quantityOfReg);
unsigned short* read1xxxx_02(unsigned char station, unsigned short mbAddr, unsigned short quantityOfReg);
unsigned short* read4xxxx_03(unsigned char station, unsigned short mbAddr, unsigned short quantityOfReg);
unsigned short* read3xxxx_04(unsigned char station, unsigned short mbAddr, unsigned short quantityOfReg);

int writeSingle0xxxx_05(unsigned char station, unsigned short mbAddr, unsigned short data);
int writeSingle4xxxx_06(unsigned char station, unsigned short mbAddr, unsigned short data);

int modbusSend(unsigned char* frame, unsigned char len, int r_w);
unsigned short calcCRC(unsigned char* puchMsg, unsigned char usDataLen);
// int FrameIsGood(unsigned char * frame, DWORD len);


#endif //_MODBUSCLIENT_H_
#pragma once
