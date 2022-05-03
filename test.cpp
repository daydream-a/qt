#include "modbusClient.h"
#include "mod_send.h"
#include "test.h"

#include "stdio.h"
#include "cstringt.h"
#include "iostream"
using namespace std;

#define on 0xFF00
#define off 0x0000

int receve[32];
//string str[4][6] = { {"00787", "00788", "00789", "00790", "00791", "00792"},
//							{"10786", "10787", "10788", "", "", ""},
//							{"30812", "30813", "", "", "", ""},
//							{"40787", "", "", "", "", ""}};

QString send(int add,int choose,int num_or_reg) {
	initMODBUS();
	unsigned short* t;
	int flag = 0;
	switch(choose)
	{
	case 1:
		t = read0xxxx_01(1, add, num_or_reg);
		if (t == 0) {
			return "no";
		}
		else {
			for (int i = 0; i < num_or_reg; i++) {
				receve[i] = t[i];
			}
			//dump_name(0, add, num_or_reg);
			
			return dump(num_or_reg);
		}
		break;
	case 2:
		t = read1xxxx_02(1, add, num_or_reg);
		if (t == 0) {
			printf("Connect failed\n");
		}
		else {
			for (int i = 0; i < num_or_reg; i++) {
				receve[i] = t[i];
			}
			return dump(num_or_reg);
			
		}
		break;
	case 3:
		t = read4xxxx_03(1, 787, 1);
		if (t == 0) {
			printf("Connect failed\n");
		}
		else {
			receve[0] = t[0];
			return dump(1);
		}
		break;
	case 4:
		t = read3xxxx_04(1, add, num_or_reg);
		if (t == 0) {
			printf("Connect failed\n");
		}
		else {
			for (int i = 0; i < num_or_reg; i++) {
				receve[i] = t[i];
			}
			return dump(num_or_reg);
		}
		break;
	case 5:

		if (num_or_reg == 0)
			flag = writeSingle0xxxx_05(1, add, off);
		else
			flag = writeSingle0xxxx_05(1, add, on);
		if (flag == 0) {
			return "Connect failed";
		}
		else {
			char str1[] = "connect success\n";
			char str2[] = "send success\n";
			strcat(str1, str2);
			return str1;
		}
		break;
	case 6:
		if (writeSingle4xxxx_06(1, 787, num_or_reg) == 0) {
			return "Connect failed";
		}
		else {
			char str1[] = "connect success\n";
			char str2[] = "send success\n";
			strcat(str1, str2);
			return str1;
		}
	}
	return "0";
}

QString dump(int n) {
	char str1[] = "";
	char str2[] = "";
	char a[] = "	";
	const char b[] = {0x0A, 0x00};
	if (receve == 0) {
		return "error";
	}
	else {
		for (int i = 0; i < n; i++) {
			itoa(receve[i], str1, 10);
			strcat(str2, str1);
			strcat(str2, a);
		}
		strcat(str2, b);
		return str2;
	}
}

QString dump_name(int function, int add, int num) {
	if (receve == 0) {
		printf("error\n");
	}
	else {
		for (int i = 0; i < num; i++) {
			printf("%dx%d\t", function, add + i);
		}
		printf("\n");
	}
	return 0;
}

int check(int function, int add, int num) {
	int flag = 0;
	switch (function) {
	case 1:
		if ((add < 787) || (add > 792) || (add + num - 1 > 792))
			flag = 0;
		else
			flag = 1;
		break;
	case 2:
		if ((add < 786) || (add > 798) || (add + num - 1 > 788))
			flag = 0;
		else
			flag = 1;
		break;
	case 4:
		if ((add < 812) || (add > 813) || (add + num - 1 > 813))
			flag = 0;
		else
			flag = 1;
		break;
	case 5:
		if ((add < 787) || (add > 792) || (num > 1))
			flag = 0;
		else
			flag = 1;
		break;
	case 6:
		if (num > 10000)
			flag = 0;
		else
			flag = 1;
		break;
	}
	return flag;
}