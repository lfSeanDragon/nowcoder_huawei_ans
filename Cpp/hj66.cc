/*!
    \file      hj66.cc
    \author    Archlizix (archlizix@qq.com)
    \brief     HJ66 配置文件恢复
    \version   1.0
    \date      2021-11-06

    \copyright Copyright (C) 2021 Archlizix

    \note
*/

#include <iostream>
#include <string>
#include <vector>

std::vector<std::string> cmdh = {"reset", "board", "board", "reboot", "backplane"};
std::vector<std::string> cmdl = {"board", "add", "delete", "backplane", "abort"};
std::vector<std::string> cmdout = {"board fault",
								   "where to add",
								   "no board at all",
								   "impossible",
								   "install first"
								  };

template<typename T, typename U>
int cmp(T &&a, U &&b, int n)
{
	for (int i = 0; i < n; ++i) {
		if (a[i] > b[i])return 1;
		else if (a[i] < b[i])return -1;
	}
	return 0;
}

int main(void)
{
	std::string cmdin;

	while (std::getline(std::cin, cmdin)) {
		int len = cmdin.size();
		int flag = 0, pos = 0;

		for (int i = 0; i < len; ++i) {
			if (cmdin[i] == ' ') {
				flag = 1;
				pos = i;
				break;
			}
		}

		if (flag == 1) {
			int index = 0, cnt = 0;
			for (int i = 0; i < 5; ++i) {
				if (cmp(cmdin, cmdh[i], pos) == 0
					&& cmp(cmdin.substr(pos + 1, cmdin.size()), cmdl[i], len - pos - 1) == 0) {
					cnt++;
					index = i;
				}
			}
			if (cnt == 1)std::cout << cmdout[index] << std::endl;
			else std::cout << "unknown command" << std::endl;
		} else {
			if (cmp(cmdin, "reset", len) == 0) {
				std::cout << "reset what" << std::endl;
			} else {
				std::cout << "unknown command" << std::endl;
			}
		}
	}
	return 0;
}
