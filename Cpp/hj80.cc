/*!
    \file      hj80.cc
    \author    Archlizix (archlizix@qq.com)
    \brief     HJ80 整型数组合并
    \version   1.0
    \date      2021-11-13

    \copyright Copyright (C) 2021 Archlizix

    \note
*/

#include<iostream>
#include<set>

int main(void)
{
	int n, tmp, m;
	while (std::cin >> n) {
		std::set<int> vec;
		for (int i = 0; i < n; i++) {
			std::cin >> tmp;
			vec.insert(tmp);
		}
		std::cin >> m;
		for (int i = 0; i < m; i++) {
			std::cin >> tmp;
			vec.insert(tmp);
		}
		for (auto x : vec)
			std::cout << x;
		std::cout << std::endl;
	}
	return 0;
}
