/*!
    \file      hj8.c
    \author    Archlizix (archlizix@qq.com)
    \brief     HJ8 合并表记录
    \version   1.0
    \date      2021-10-14

    \copyright Copyright (C) 2021 Archlizix

    \note      索引值范围大，不适用桶排序法。
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Pair {
	int index;
	int value;
};

#define map_init(m)\
	memset(m, 0, sizeof(*(m)))

#define map_deinit(m)\
	map_deinit_(&(m)->base)

int map_find(struct Pair *pairs, int index, int record_num)
{
	for (int i = 0; i < record_num; i++) {
		if (pairs[i].index == index) {
			return i;
		}
	}
	return -1;
}

void display(struct Pair *pairs, int record_num)
{
	for (int i = 0; i < record_num; i++) {
		printf("%d %d\n", pairs[i].index, pairs[i].value);
	}
}

int cmp(void *a, void *b)
{
	return (*(int *)a - * (int *)b);
}

int main(void)
{
	int n;
	struct Pair *pairs;

	while (scanf("%d", &n) != EOF) {
		pairs = (struct Pair *)malloc(sizeof(struct Pair) * n);
		int record_num = 0, index_tmp = 0, value_tmp  = 0;

		while (scanf("%d %d", &index_tmp, &value_tmp) == 2) {
			int rer = 0;
			rer = map_find(pairs, index_tmp, record_num);
			if (rer == -1) {
				pairs[record_num].index = index_tmp;
				pairs[record_num].value = value_tmp;
				record_num++;
			} else {
				pairs[rer].value += value_tmp;
			}
		}
		qsort(pairs, record_num, sizeof(struct Pair), cmp);
		display(pairs, record_num);

		free(pairs);
	}

	return 0;
}