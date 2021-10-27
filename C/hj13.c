/*!
    \file      hj13.c
    \author    Archlizix (archlizix@qq.com)
    \brief     HJ13 句子逆序
    \version   1.0
    \date      2021-10-28

    \copyright Copyright (C) 2021 Archlizix

    \note      整句读取可以用双指针扫描，逐词读取只需要简单地反转。
*/

#include <stdio.h>
#include <string.h>

void reverse(char s[], int begin, int end)
{
	char tmp;
	while (begin < end - 1) {
		tmp = s[begin];
		s[begin++] = s[end - 1];
		s[end-- - 1] = tmp;
	}
}

int main()
{
	char s[1000];
	gets(s);
	reverse(s, 0, strlen(s));
	int left = 0, right = 0;
	while (left < strlen(s)) {
		while (s[left] == ' ') {
			++left;
		}
		right = left;
		while (s[right] != ' ' && s[right] != '\0') {
			++right;
		}
		reverse(s, left, right);
		left = right;
	}
	printf("%s\n", s);
	return 0;
}
