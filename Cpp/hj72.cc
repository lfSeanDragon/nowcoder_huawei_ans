/*!
    \file      hj72.cc
    \author    Archlizix (archlizix@qq.com)
    \brief     HJ72 百钱买百鸡问题
    \version   1.0
    \date      2021-11-06

    \copyright Copyright (C) 2021 Archlizix

    \note
*/

#include <iostream>

int main(void)
{
	for (int i = 0; i <= 20; ++i) {
		for (int j = 0; j <= (100 - 5 * i) / 3; ++j) {
			int k = 3 * (100 - 5 * i - 3 * j);
			if ((i + j + k) == 100)
				std::cout << i << " " << j << " " << k << std::endl;
		}
	}
	return 0;
}
