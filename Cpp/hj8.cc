/*!
    \file      hj8.cc
    \author    Archlizix (archlizix@qq.com)
    \brief     HJ8 合并表记录
    \version   1.0
    \date      2021-10-15

    \copyright Copyright (C) 2021 Archlizix

    \note      索引值范围大，不适用桶排序法。
*/

#include<iostream>
#include<map>

int main(void)
{
	int n;
	while (std::cin >> n) {
		std::map<int, int> mp;
		int index, value;
		for (int i = 0; i < n; ++i) {
			std::cin >> index >> value;
			if (mp.find(index) != mp.end()) {
				mp[index] += value;
			} else {
				mp[index] = value;
			}
		}

		for (auto &pair : mp) {
			std::cout << pair.first << " " << pair.second << std::endl;
		}
	}
	return 0;
}