/*!
    \file      hj68.cc
    \author    Archlizix (archlizix@qq.com)
    \brief     HJ68 成绩排序
    \version   1.0
    \date      2021-11-12

    \copyright Copyright (C) 2021 Archlizix

    \note
*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

struct Info {
	friend bool operator<(const Info &lhs, const Info &rhs);
	std::string name;
	int score;
};

bool operator<(const Info &lhs, const Info &rhs)
{
	return (lhs.score < rhs.score);
}

int main(void)
{
	int n, flag;
	while (std::cin >> n >> flag) {
		Info tmp;
		std::vector<Info> v;
		for (int i = 0; i < n; ++i) {
			std::cin >> tmp.name >> tmp.score;
			v.push_back(tmp);
		}

		if (flag == 0)
			stable_sort(v.rbegin(), v.rend());
		else
			stable_sort(v.begin(), v.end());

		for (int i = 0; i < v.size(); ++i)
			std::cout << v[i].name << " " << v[i].score << std::endl;
	}
	return 0;
}
