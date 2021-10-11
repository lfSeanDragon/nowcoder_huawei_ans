/*!
    \file      hj1.c
    \author    Archlizix (archlizix@qq.com)
    \brief     HJ1 字符串最后一个单词的长度
    \version   2.0
    \date      2021-10-11

    \copyright Copyright (C) 2021 Archlizix

*/

#include<stdio.h>

int main(void)
{
	char str;
	int ans = -1;

	while (scanf("%c", &str) != EOF) {
		ans = (str == ' ') ? -1 : ans + 1;
	}

	printf("%d", ans);
	return 0;
}