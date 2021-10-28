/*!
    \file      hj14.c
    \author    Archlizix (archlizix@qq.com)
    \brief     HJ14 字符串排序
    \version   1.0
    \date      2021-10-28

    \copyright Copyright (C) 2021 Archlizix

    \note
*/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int cmp(const void *a, const void *b)
{
	return strcmp((char *)a, (char *)b);
}

int main(void)
{
	int n;
	char (*str)[101];

	while (scanf("%d", &n) != EOF) {
		str = (char **)malloc(sizeof(char [101]) * n);

		for (int i = 0; i < n; ++i) {
			scanf("%s", str[i]);
		}

		qsort(str, n, sizeof(str[0]), cmp);

		for (int i = 0; i < n; ++i) {
			printf("%s\n", str[i]);
		}

		free(str);
	}

	return 0;
}
