/*!
    \file      hj9.cc
    \author    Archlizix (archlizix@qq.com)
    \brief     HJ9 提取不重复的整数
    \version   1.0
    \date      2021-10-27

    \copyright Copyright (C) 2021 Archlizix

    \note      元素只有0到9，直接映射到数组索引。
*/

#include<iostream>

int main(void)
{
	int in;
	int ans = 0;

	while (std::cin >> in) {
		int set[10] = {0};
		while (in) {
			if (!set[in % 10]) {
				set[in % 10] = 1;
				ans = ans * 10 + in % 10;
			}
			in /= 10;
		}

		std::cout << ans << std::endl;
	}

	return 0;
}
