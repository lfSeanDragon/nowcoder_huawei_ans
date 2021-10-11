/*!
    \file      hj3.cpp
    \author    Archlizix (archlizix@qq.com)
    \brief     HJ3 明明的随机数
    \version   1.0
    \date      2021-10-11

    \copyright Copyright (C) 2021 Archlizix

*/

#include<iostream>
#include<set>

int main()
{
	int n;
	std::set<int> order;

	while (std::cin >> n) {
		order.clear();
		for (int i = 0; i < n; ++i) {
			int num;
			std::cin >> num;
			order.emplace(num);
		}

		for (const auto &factor : order) {
			std::cout << factor << std::endl;
		}
	}

	return 0;
}