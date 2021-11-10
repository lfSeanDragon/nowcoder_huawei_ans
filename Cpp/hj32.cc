/*!
    \file      hj32.cc
    \author    Archlizix (archlizix@qq.com)
    \brief     HJ32 密码截取
    \version   1.0
    \date      2021-11-10

    \copyright Copyright (C) 2021 Archlizix

    \note
*/

#include <iostream>
#include <string>

bool is_valid(std::string &str, int left, int right)
{
	while (left < right) {
		if (str[left++] != str[right--]) {
			return false;
		}
	}
	return true;
}

int main(void)
{
	std::string str;
	while (std::cin >> str) {
		int maxlength = 0;
		for (int i = 0, n = str.size(); i < n; ++i) {
			//odd
			int left = i, right = i;
			while (left >= 0 && right < n) {
				if (is_valid(str, left, right)) {
					maxlength = std::max(maxlength, right - left + 1);
				}
				--left;
				++right;
			}
			//even
			left = i, right = i + 1;
			while (left >= 0 && right < n) {
				if (is_valid(str, left, right)) {
					maxlength = std::max(maxlength, right - left + 1);
				}
				--left;
				++right;
			}
		}
		std::cout << maxlength << std::endl;
	}
	return 0;
}
