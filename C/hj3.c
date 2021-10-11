/*!
    \file      hj3.c
    \author    Archlizix (archlizix@qq.com)
    \brief     HJ3 明明的随机数
    \version   0.1
    \date      2021-10-11

    \copyright Copyright (C) 2021 Archlizix

*/

#include<stdio.h>

void bubble_sort(int arr[], int len)
{
	int i, j, temp;
	int exchanged = 1;

	for (i = 0; exchanged && i < len - 1; i++) {
		exchanged = 0;
		for (j = 0; j < len - 1 - i; j++) {
			if (arr[j] > arr[j + 1]) {
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
				exchanged = 1;
			}
		}
	}
}

int main(void)
{
	int N;
	int num[1000];
	int flag = 0;

	while (scanf("%d", &N) != EOF) {
		for (int i = 0; i < N; ++i) {
			scanf("%d", &num[i]);
		}

		bubble_sort(num, N);

		int last = num[0];
		if (flag) {
			printf("\n");
		}
		flag = 1;
		printf("%d", num[0]);
		for (int i = 1; i < N; ++i) {
			if (num[i] != last) {
				printf("\n%d", num[i]);
				last = num[i];
			}
		}
	}

	return 0;
}