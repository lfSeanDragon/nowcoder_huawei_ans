/*!
    \file      hj2.c
    \author    Archlizix (archlizix@qq.com)
    \brief     HJ2 计算某字母出现次数
    \version   0.1
    \date      2021-10-11

    \copyright Copyright (C) 2021 Archlizix

*/

#include<stdio.h>

int main(void)
{
	char str[500];
	char ch;
	int num = 0;

	for (int i = 0; i < 500; ++i) {
		scanf("%c", &str[i]);
		if (str[i] == '\n') {
			break;
		}
	}
	scanf("%c", &ch);
	if ('A' <= ch && ch <= 'Z') {
		ch += 32;
	}

	for (int i = 0; str[i] != '\n'; ++i) {
		num += (str[i] == ch || str[i] == ch - 32) ? 1 : 0;
	}

	printf("%d", num);
	return 0;
}