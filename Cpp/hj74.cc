/*!
    \file      hj74.cc
    \author    Archlizix (archlizix@qq.com)
    \brief     HJ74 参数解析
    \version   1.0
    \date      2021-11-06

    \copyright Copyright (C) 2021 Archlizix

    \note
*/

#include <iostream>
#include <string>
#include <vector>

int main(void)
{
	std::string str;
	while (std::getline(std::cin, str)) {
		std::vector<std::string> ans;
		std::string tmp;
		for (int i = 0, len = str.size(), flag = 0; i < len; ++i) {
			if (str[i] == '"') {
				flag = !flag;
			} else if (str[i] == ' ' && !flag) {
				ans.push_back(tmp);
				tmp.clear();
			} else {
				tmp.push_back(str[i]);
			}
		}
		ans.push_back(tmp);

		std::cout << ans.size() << std::endl;
		for (const auto &x : ans) {
			std::cout << x << std::endl;
		}
	}
	return 0;
}
