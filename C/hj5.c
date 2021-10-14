/*!
    \file      hj5.c
    \author    Archlizix (archlizix@qq.com)
    \brief     HJ5 进制转换
    \version   1.0
    \date      2021-10-12

    \copyright Copyright (C) 2021 Archlizix

	\note      大数运算，虽然测试用例并没有大数。
*/

#include <stdio.h>
#include <string.h>

char int_to_ch(int num)
{
	if (0 <= num && num <= 9) {
		return num + '0';
	} else if (10 <= num && num <= 15) {
		return num - 10 + 'a';
	}

	return -1;
}

int ch_to_int(char ch)
{
	if ('0' <= ch && ch <= '9') {
		return ch - '0';
	} else if ('a' <= ch && ch <= 'z') {
		return ch - 'a' + 10;
	} else if ('A' <= ch && ch <= 'Z') {
		return ch - 'A' + 10;
	}

	return -1;
}

void reverse(char *arr, int left, int right)
{
	char tmp;
	while (left < right) {
		tmp = arr[left];
		arr[left] = arr[right];
		arr[right] = tmp;
		++left;
		--right;
	}
}

void sys_convert(char input[], char output[], int from, int to)
{
	if (!input[0]) {
		output[0] = '\0';
		return;
	}

	int head = 0, tail = strlen(input) - 1;
	int p = 0;

	while (head <= tail && input[head]) {
		int remainder = 0;
		if (input[head] == '0') {
			++head;
			continue;
		}

		for (int i = head; i <= tail; ++i) {
			remainder = remainder * from + ch_to_int(input[i]);
			input[i] = int_to_ch(remainder / to);
			remainder %= to;
		}
		output[p++] = int_to_ch(remainder);
	}
	if (!p) {
		output[p++] = '0';
	}
	output[p] = '\0';

	reverse(output, 0, strlen(output) - 1);

	return;
}

int main(void)
{
	char input[100];
	char output[100];

	while (scanf("%s", input) != EOF) {

		sys_convert(input + 2, output, 16, 10);

		printf("%s\n", output);
	}
}