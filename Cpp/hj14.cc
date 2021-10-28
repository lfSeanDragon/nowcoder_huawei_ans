/*!
    \file      hj14.cc
    \author    Archlizix (archlizix@qq.com)
    \brief     HJ14 字符串排序
    \version   1.0
    \date      2021-10-28

    \copyright Copyright (C) 2021 Archlizix

    \note
*/

#include <iostream>
#include <algorithm>
#include <vector>

int cmp(std::string a, std::string b)
{
	return a < b;
}

int main(void)
{
	int n;
	std::vector<std::string> s;

	while (std::cin >> n) {
		std::string tmp;
		s.clear();
		for (int i = 0; i < n; ++i) {
			std::cin >> tmp;
			s.push_back(tmp);
		}

		sort(s.begin(), s.end(), cmp);

		for (const auto &x : s) {
			std::cout << x << std::endl;
		}
	}

	return 0;
}
