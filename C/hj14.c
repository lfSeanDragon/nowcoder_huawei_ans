/*!
    \file      hj14.c
    \author    Archlizix (archlizix@qq.com)
    \brief     HJ14 字符串排序
    \version   1.1
    \date      2021-10-28

    \copyright Copyright (C) 2021 Archlizix

    \note      C语言的比较方法中，应用了void*可以接受任意类型指针的特性。
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
