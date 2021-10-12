/*!
    \file      hj4.c
    \author    Archlizix (archlizix@qq.com)
    \brief     HJ4 字符串分隔
    \version   1.0
    \date      2021-10-12

    \copyright Copyright (C) 2021 Archlizix

*/

#include<stdio.h>
#include<string.h>

int main(void)
{
	char str[100];
	char *str_p;
	int str_len;

	while (scanf("%s", str) != EOF) {
		str_p = str;
		str_len = strlen(str);

		for (int i = 0, n = (str_len - 1) / 8; i < n; ++i) {
			for (int j = 0; j < 8; ++j) {
				printf("%c", *str_p);
				str_p++;
			}
			printf("\n");
		}
		for (int i = 0; i < 8; ++i) {
			if (*str_p != '\0') {
				printf("%c", *str_p);
				str_p++;
			} else {
				printf("0");
			}
		}
		printf("\n");
	}
}