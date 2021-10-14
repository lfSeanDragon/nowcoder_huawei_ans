/*!
    \file      hj6.c
    \author    Archlizix (archlizix@qq.com)
    \brief     HJ6 质数因子
    \version   1.0
    \date      2021-10-14

    \copyright Copyright (C) 2021 Archlizix

    \note      枚举到待分解数字的平方根即可，为减少浮点计算可枚举到原数的平方根。
*/

#include<stdio.h>

int main(void)
{
	long n, i;
	while (scanf("%ld", &n) != EOF) {
		i = 2;
		while (i * i <= n) {
			if (n % i) {
				++i;
				continue;
			}
			printf("%d ", i);
			n /= i;
		}
		if (n != 1) {
			printf("%d ", n);
		}
		printf("\n");
	}
	return 0;
}