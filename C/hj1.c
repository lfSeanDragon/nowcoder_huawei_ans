/*!
    \file      hj1.c
    \author    Archlizix (archlizix@qq.com)
    \brief     HJ1 字符串最后一个单词的长度
    \version   0.1
    \date      2021-10-11

    \copyright Copyright (C) 2021 Archlizix

*/

#include<stdio.h>

int main(void)
{
	char data[5000];
	while (scanf("%s", data) != EOF) {
	}

	int num = 0;
	while (data[num] != '\0') {
		++num;
	}

	printf("%d", num);
	return 0;
}