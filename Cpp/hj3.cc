/*!
    \file      hj3.cc
    \author    Archlizix (archlizix@qq.com)
    \brief     HJ3 明明的随机数
    \version   1.0
    \date      2021-10-11

    \copyright Copyright (C) 2021 Archlizix

*/

#include<iostream>

int main(void)
{
	int N;

	while (std::cin >> N) {
		int num, buckets[1001] = {0};
		for (int i = 0; i < N; ++i) {
			std::cin >> num;
			buckets[num] = 1;
		}

		for (int i = 1; i <= 1000; ++i) {
			if (buckets[i]) {
				std::cout << i << std::endl;
			}
		}
	}

	return 0;
}