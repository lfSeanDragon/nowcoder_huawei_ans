/*!
    \file      hj3.c
    \author    Archlizix (archlizix@qq.com)
    \brief     HJ3 明明的随机数
    \version   0.1
    \date      2021-10-11

    \copyright Copyright (C) 2021 Archlizix

*/
#include<iostream>
#include<algorithm>

int main(void)
{
	int N;
	int num[1000];
	int flag = 0;

	while (std::cin >> N) {
		for (int i = 0; i < N; ++i) {
			std::cin >> num[i];
		}

		std::sort(num, num + N);

		int last = num[0];
		if (flag) {
			std::cout << std::endl;
		}
		flag = 1;
		std::cout << num[0];
		for (int i = 1; i < N; ++i) {
			if (num[i] != last) {
				std::cout << std::endl << num[i];
				last = num[i];
			}
		}
	}

	return 0;
}