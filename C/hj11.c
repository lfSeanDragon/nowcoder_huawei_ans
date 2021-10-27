/*!
    \file      hj11.c
    \author    Archlizix (archlizix@qq.com)
    \brief     HJ11 数字颠倒
    \version   1.0
    \date      2021-10-28

    \copyright Copyright (C) 2021 Archlizix

    \note
*/

#include <stdio.h>

int main(void)
{
	int in;
	while (scanf("%d", &in) != EOF) {
		while (in) {
			printf("%d", in % 10);
			in /= 10;
		}
		printf("\n");
	}
	return 0;
}
