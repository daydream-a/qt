#ifndef _MOD_SEND_H_
#define _MOD_SEND_H_

#include <WinSock2.h>
#include <stdio.h>
#include <WS2tcpip.h>

char* mod_send(char* frame, int len, int r_w);

#endif
