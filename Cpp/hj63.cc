/*!
    \file      hj63.cc
    \author    Archlizix (archlizix@qq.com)
    \brief     HJ63 DNA序列
    \version   1.0
    \date      2021-11-07

    \copyright Copyright (C) 2021 Archlizix

    \note
*/

#include<iostream>

int main(void)
{
	std::string str;
	int len;
	while (std::cin >> str >> len) {
		int left = 0, max = 0;
		for (int i = 0; i <= str.size() - len; ++i) {
			int count = 0;
			for (int j = i; j < i + len; ++j) {
				if (str[j] == 'G' || str[j] == 'C')
					count ++;
			}
			if (count > max) {
				max = count;
				left = i;
			}
		}
		std::cout << str.substr(left, len) << std::endl;
	}
	return 0;
}
