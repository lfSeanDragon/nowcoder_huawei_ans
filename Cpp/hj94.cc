/*!
    \file      hj94.cc
    \author    Archlizix (archlizix@qq.com)
    \brief     HJ94 记票统计
    \version   1.0
    \date      2021-11-13

    \copyright Copyright (C) 2021 Archlizix

    \note
*/

#include <iostream>
#include <unordered_map>
#include <vector>

int main(void)
{
	int n;
	while (std::cin >> n) {
		std::unordered_map<std::string, int> hashmap;
		std::vector<std::string> candidates;
		std::string tmp;
		for (int i = 0; i < n; i++) {
			std::cin >> tmp;
			candidates.push_back(tmp);
			hashmap[tmp]++;
		}
		int m, inv_count = 0;
		std::cin >> m;
		for (int i = 0; i < m; i++) {
			std::cin >> tmp;
			if (!hashmap.count(tmp))
				inv_count++;
			else
				hashmap[tmp]++;
		}
		for (auto s : candidates)
			std::cout << s << " : " << hashmap[s] - 1 << std::endl;
		std::cout << "Invalid : " << inv_count << std::endl;
	}
	return 0;
}
