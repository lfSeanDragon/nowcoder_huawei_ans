/*!
    \file      hj41.cc
    \author    Archlizix (archlizix@qq.com)
    \brief     HJ41 称砝码
    \version   1.0
    \date      2021-11-10

    \copyright Copyright (C) 2021 Archlizix

    \note
*/

#include <iostream>
#include <vector>
#include <set>

int main(void)
{
	int n;
	while (std::cin >> n) {
		std::vector<int> m(n);
		int x;
		std::vector<int> v;
		std::set<int> s;
		for (int i = 0; i < n; ++i) std::cin >> m[i];
		for (int i = 0; i < n; ++i) {
			std::cin >> x;
			for (int j = 0; j < x; j++) v.push_back(m[i]);
		}
		s.insert(0);
		for (int i = 0; i < v.size(); ++i) {
			std::set<int> tmp(s);
			for (const auto &ele : tmp) {
				s.emplace(ele + v[i]);
			}
		}
		std::cout << s.size() << std::endl;
	}
	return 0;
}
