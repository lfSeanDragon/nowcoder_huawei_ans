/*!
    \file      hj64.cc
    \author    Archlizix (archlizix@qq.com)
    \brief     HJ64 MP3光标位置
    \version   1.0
    \date      2021-11-12

    \copyright Copyright (C) 2021 Archlizix

    \note
*/

#include <iostream>
#include <string>

int main(void)
{
	int n;
	std::string order;
	while (std::cin >> n >> order) {
		int cur = 1, first = 1;
		if (n <= 4) {
			for (int i = 0; i < order.size(); i++) {
				if (cur == 1 && order[i] == 'U') cur = n;
				else if (cur == n && order[i] == 'D') cur = 1;
				else if (order[i] == 'U') cur--;
				else  cur++;
			}
			for (int i = 1; i <= n - 1; i++)
				std::cout << i << ' ';
			std::cout << n << std::endl;
			std::cout << cur << std::endl;
			continue;
		}
		for (int i = 0; i < order.size(); ++i) {
			if (first == 1 && cur == 1 && order[i] == 'U') {
				first = n - 3;
				cur = n;
			} else if (first == n - 3 && cur == n && order[i] == 'D') {
				first = 1;
				cur = 1;
			} else if (first != 1 && cur == first && order[i] == 'U') {
				first--;
				cur--;
			} else if (first != n - 3 && cur == first + 3 && order[i] == 'D') {
				first++;
				cur++;
			} else if (order[i] == 'U') {
				cur--;
			} else {
				cur++;
			}
		}
		for (int i = 0; i < 3; ++i) {
			std::cout << first + i << ' ';
		}
		std::cout << first + 3 << std::endl;
		std::cout << cur << std::endl;
	}
	return 0;
}
