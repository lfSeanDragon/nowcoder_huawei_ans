/*!
    \file      hj12.c
    \author    Archlizix (archlizix@qq.com)
    \brief     HJ12 字符串反转
    \version   1.0
    \date      2021-10-28

    \copyright Copyright (C) 2021 Archlizix

    \note
*/

#include <stdio.h>
#include <string.h>

int main(void)
{
	char s[1000];
	while (scanf("%s", s) != EOF) {
		for (int i = strlen(s) - 1; i >= 0; --i) {
			printf("%c", s[i]);
		}
		printf("\n");
	}
	return 0;
}
