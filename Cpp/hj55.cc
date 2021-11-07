/*!
    \file      hj55.cc
    \author    Archlizix (archlizix@qq.com)
    \brief     HJ55 挑7
    \version   1.0
    \date      2021-11-07

    \copyright Copyright (C) 2021 Archlizix

    \note
*/

#include<iostream>

bool is_valid(int n)
{
	if (n % 7 == 0) {
		return true;
	}
	while (n) {
		if (n % 10 == 7) {
			return true;
		}
		n /= 10;
	}
	return false;
}

int main(void)
{
	int n;
	while (std::cin >> n) {
		int count = 0;
		for (int i = 1; i <= n; ++i) {
			if (is_valid(i)) ++count;
		}
		std::cout << count << std::endl;
	}
}
