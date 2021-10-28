/*!
    \file      hj15.cc
    \author    Archlizix (archlizix@qq.com)
    \brief
    \version   1.0
    \date      2021-10-28

    \copyright Copyright (C) 2021 Archlizix

    \note      位运算消除最后一个1。
*/

#include <iostream>

int main(void)
{
	int num;
	while (std::cin >> num) {
		int count = 0;
		while (num) {
			++count;
			num = num & (num - 1);
		}
		std::cout << count << std::endl;
	}
	return 0;
}
