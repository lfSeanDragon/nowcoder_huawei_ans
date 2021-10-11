/*!
    \file      hj3.c
    \author    Archlizix (archlizix@qq.com)
    \brief     HJ3 明明的随机数
    \version   0.1
    \date      2021-10-11

    \copyright Copyright (C) 2021 Archlizix

*/

#include<stdio.h>

void quick_sort(int arr[], int left, int right);

int main(void)
{
	int N;
	int num[1000];
	int flag = 0;

	while (scanf("%d", &N) != EOF) {
		for (int i = 0; i < N; ++i) {
			scanf("%d", &num[i]);
		}

		quick_sort(num, 0, N - 1);

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

void swap(int *a, int *b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

int partition(int arr[], int left, int right, int pivot_index)
{
	int pivot_value = arr[pivot_index];
	swap(&arr[pivot_index], &arr[right]);
	int store_index = left;
	for (int i = left; i < right; ++i) {
		if (arr[i] <= pivot_value) {
			swap(&arr[store_index], &arr[i]);
			++store_index;
		}
	}
	swap(&arr[right], &arr[store_index]);
	return store_index;
}

void quick_sort(int arr[], int left, int right)
{
	if (right <= left) {
		return;
	}

	int pivot_index = right;

	int pivot_index_new  = partition(arr, left, right, pivot_index);

	quick_sort(arr, left, pivot_index_new - 1);
	quick_sort(arr, pivot_index_new + 1, right);
}