/*!
    \file      hj7.c
    \author    Archlizix (archlizix@qq.com)
    \brief     HJ7 取近似值
    \version   1.0
    \date      2021-10-14

    \copyright Copyright (C) 2021 Archlizix

    \note      照此解法，对负数应减0.5。
*/

#include<stdio.h>

int main(void)
{
	double n;

	while (scanf("%lf", &n) != EOF) {
		printf("%d", (int)(n + 0.5));
	}

	return 0;
}