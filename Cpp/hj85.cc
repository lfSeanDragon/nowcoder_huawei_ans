/*!
    \file      hj85.cc
    \author    Archlizix (archlizix@qq.com)
    \brief     HJ85 最长回文子串
    \version   1.0
    \date      2021-11-07

    \copyright Copyright (C) 2021 Archlizix

    \note
*/

#include <iostream>
#include <string>

bool is_valid(std::string str, int p, int q)
{
	while (p <= q) {
		if (str[p] != str[q])
			return false;
		p++;
		q--;
	}
	return true;
}

int get_max_len(std::string str)
{
	int len = str.size();
	int res = 0;
	for (int i = 0; i < len; i++) {
		for (int j = len - 1; j >= i; j--) {
			if (is_valid(str, i, j) && j - i + 1 > res) {
				res =  j - i + 1;
			}
		}
	}
	return res;
}

int main(void)
{
	std::string str;
	while (std::getline(std::cin, str)) {
		int ans;
		ans = get_max_len(str);
		std::cout << ans << std::endl;
	}
	return 0;
}
