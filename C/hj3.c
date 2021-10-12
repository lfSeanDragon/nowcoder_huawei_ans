/*!
    \file      hj3.c
    \author    Archlizix (archlizix@qq.com)
    \brief     HJ3 明明的随机数
    \version   1.0
    \date      2021-10-11

    \copyright Copyright (C) 2021 Archlizix

*/

#include<stdio.h>

int main(void)
{
	int N;

	while (scanf("%d", &N) != EOF) {
		int num, buckets[1001] = {0};
		for (int i = 0; i < N; ++i) {
			scanf("%d", &num);
			buckets[num] = 1;
		}

		for (int i = 1; i <= 1000; ++i) {
			if (buckets[i]) {
				printf("%d\n", i);
			}
		}
	}

	return 0;
}