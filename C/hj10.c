/*!
    \file      hj10.c
    \author    Archlizix (archlizix@qq.com)
    \brief     HJ10 字符个数统计
    \version   1.0
    \date      2021-10-27

    \copyright Copyright (C) 2021 Archlizix

    \note      128 bytes, such a big deal.
*/

#include <stdio.h>

int main(void)
{
	char s[1000];

	while (scanf("%s", s) != EOF) {
		char asc[128] = {0};
		int count = 0;

		for (int i = 0; i < 1000 && s[i] != '\0'; ++i) {
			if (!asc[s[i]]) {
				asc[s[i]] = 1;
				++count;
			}
		}

		printf("%d\n", count);
	}

	return 0;
}
