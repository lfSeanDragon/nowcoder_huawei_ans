/*!
    \file      hj102.cc
    \author    Archlizix (archlizix@qq.com)
    \brief     HJ102 字符统计
    \version   1.0
    \date      2021-11-13

    \copyright Copyright (C) 2021 Archlizix

    \note
*/

#include <iostream>
#include <map>
#include <algorithm>
#include <vector>

bool is_bigger(const std::pair<char, int> &lhs, const std::pair<char, int> &rhs)
{
	return lhs.second > rhs.second;
}

int main(void)
{
	std::string str;
	while (std::cin >> str) {
		std::map<char, int> m;
		for (auto c : str)
			++m[c];

		std::vector<std::pair<char, int>> pvec(m.begin(), m.end());
		stable_sort(pvec.begin(), pvec.end(), is_bigger); // 使用稳定排序, 不能直接使用sort.

		for (auto &p : pvec)
			std::cout << p.first;
		std::cout << std::endl;
	}

	return 0;
}
