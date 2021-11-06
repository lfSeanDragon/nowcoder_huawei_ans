/*!
    \file      hj37.cc
    \author    Archlizix (archlizix@qq.com)
    \brief     HJ37 统计每个月兔子的总数
    \version   1.0
    \date      2021-11-06

    \copyright Copyright (C) 2021 Archlizix

    \note
*/

#include <iostream>

int main(void)
{
	int n;
	while (std::cin >> n) {
		if (n < 3) {
			std::cout << 1 << std::endl;
			continue;
		}
		int tmp[3] = {1, 0, 0};
		for (int i = 2; i <= n; ++i) {
			tmp[2] += tmp[1];
			tmp[1] = tmp[0];
			tmp[0] = tmp[2];
		}
		std::cout << tmp[0] + tmp[1] + tmp[2] << std::endl;
	}
	return 0;
}
