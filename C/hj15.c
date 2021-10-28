/*!
    \file      hj15.c
    \author    Archlizix (archlizix@qq.com)
    \brief     HJ15 求int型正整数在内存中存储时1的个数
    \version   1.0
    \date      2021-10-28

    \copyright Copyright (C) 2021 Archlizix

    \note      位运算消除最后一个1。
*/

#include <stdio.h>

int main(void)
{
	int num;
	while (scanf("%d", &num) != EOF) {
		int count = 0;
		while (num) {
			++count;
			num = num & (num - 1);
		}
		printf("%d\n", count);
	}
	return 0;
}
