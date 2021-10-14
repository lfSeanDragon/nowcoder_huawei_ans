/*!
    \file      hj7.c
    \author    Archlizix (archlizix@qq.com)
    \brief     HJ7 取近似值
    \version   2.0
    \date      2021-10-14

    \copyright Copyright (C) 2021 Archlizix

    \note      正数与负数舍入方向不同。
*/

#include<stdio.h>

int main(void)
{
	double a;
	int b;

	while (scanf("%lf", &a) != EOF) {
		b = (int)a;
		if (a - b >= 0.5) {
			printf("%d\n", b + 1);
		} else if (a - b <= -0.5) {
			printf("%d\n", b - 1);
		} else {
			printf("%d\n", b);
		}
	}

	return 0;
}