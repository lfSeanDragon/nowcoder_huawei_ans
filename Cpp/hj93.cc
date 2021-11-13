/*!
    \file      hj93.cc
    \author    Archlizix (archlizix@qq.com)
    \brief     HJ93 数组分组
    \version   1.0
    \date      2021-11-13

    \copyright Copyright (C) 2021 Archlizix

    \note
*/

#include <iostream>
#include <vector>

bool dfs(const std::vector<int> &other, std::vector<bool> &isvisited, int target)
{
	if (target == 0)
		return true;
	for (size_t i = 0; i < other.size(); i++) {
		if (!isvisited[i]) {
			isvisited[i] = true;
			if (dfs(other, isvisited, target - other[i])) {
				return true;
			}
			isvisited[i] = false;
		}
	}
	return false;
}

int main(void)
{
	int n;
	while (std::cin >> n) {
		int tmp = 0;
		std::vector<int> arr3;
		std::vector<int> arr5;
		std::vector<int> other;
		for (int i = 0; i < n; ++i) {
			std::cin >> tmp;
			if (tmp % 5 == 0) {
				arr5.push_back(tmp);
			} else if (tmp % 3 == 0) {
				arr3.push_back(tmp);
			} else {
				other.push_back(tmp);
			}
		}

		int sum5 = 0;
		for (auto it : arr5)
			sum5 += it;
		int sum3 = 0;
		for (auto it : arr3)
			sum3 += it;
		int othsum = 0;
		for (auto it : other)
			othsum += it;

		if ((sum5 + othsum - sum3) % 2 != 0) {
			std::cout << "false" << std::endl;
			continue;
		}

		int target = (sum5 + othsum - sum3) / 2;
		std::vector<bool> isvisited(other.size(), false);
		if (true == dfs(other, isvisited, target))
			std::cout << "true" << std::endl;
		else
			std::cout << "false" << std::endl;
	}
	return 0;
}
