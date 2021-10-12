/*!
    \file      hj1.c
    \author    Archlizix (archlizix@qq.com)
    \brief     HJ1 字符串最后一个单词的长度
    \version   2.1
    \date      2021-10-11

    \copyright Copyright (C) 2021 Archlizix

*/

#include<stdio.h>

int main(void)
{
	char ch;
	int count = 0;

	while (scanf("%c", &ch) != EOF) {
		count = (ch == ' ') ? 0 : count + 1;
	}
	--count;

	printf("%d", count);
	return 0;
}