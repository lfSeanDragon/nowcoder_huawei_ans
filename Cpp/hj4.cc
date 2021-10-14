/*!
    \file      hj4.cc
    \author    Archlizix (archlizix@qq.com)
    \brief     HJ4 字符串分隔
    \version   1.0
    \date      2021-10-12

    \copyright Copyright (C) 2021 Archlizix

	\note      string::substr()生成了新的对象，比指针实现耗资源，但胜在简单。
*/

#include<iostream>
#include<string>

int main(void)
{
	std::string s;

	while (getline(std::cin, s)) {
		int n = (s.size() - 1) / 8;

		for (int i = 0; i < n; ++i) {
			std::cout << s.substr(i * 8, 8) << std::endl;
		}

		std::cout << s.substr(n * 8, s.size() - n * 8);
		for (int i = 0; i < 8 - s.size() + n * 8; ++i) {
			std::cout << '0';
		}
		std::cout << std::endl;
	}

	return 0;
}