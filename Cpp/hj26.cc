/*!
    \file      hj26.cc
    \author    Archlizix (archlizix@qq.com)
    \brief     HJ26 字符串排序
    \version   1.0
    \date      2021-11-07

    \copyright Copyright (C) 2021 Archlizix

    \note      冒泡排序是稳定排序。
*/

#include <iostream>
#include <string>
#include <utility>
#include <vector>

int cmp(char a, char b)
{
	a = tolower(a);
	b = tolower(b);

	if (a == b) {
		return 0;
	} else if (a > b) {
		return 1;
	} else {
		return -1;
	}
}

int main(void)
{
	std::string str;
	while (std::getline(std::cin, str)) {
		std::vector<int> vt(str.size(), 0);
		std::string tmp;

		for (int i = 0, len = str.size(); i < len; ++i) {
			if (isalpha(str[i])) {
				tmp.push_back(str[i]);
			} else {
				vt[i] = 1;
			}
		}

		int n = tmp.size();
		for (int i = 0; i < n - 1; ++i) {
			for (int j = 0; j < n - i - 1; ++j) {
				if (cmp(tmp[j], tmp[j + 1]) > 0) {
					std::swap(tmp[j], tmp[j + 1]);
				}
			}
		}

		for (int i = str.size() - 1; i >= 0; --i) {
			if (vt[i]) {
				continue;
			}
			str[i] = tmp.back();
			tmp.pop_back();
		}
		std::cout << str << std::endl;
	}
	return 0;
}
