/*!
    \file      hj5.cc
    \author    Archlizix (archlizix@qq.com)
    \brief     HJ5 进制转换
    \version   1.0
    \date      2021-10-14

    \copyright Copyright (C) 2021 Archlizix

    \note      大数运算，虽然测试用例中并没有大数。
*/

#include<iostream>
#include<string>
#include<algorithm>

char int_to_ch(int num)
{
	if (0 <= num && num <= 9) {
		return num + '0';
	} else if (10 <= num && num <= 15) {
		return num - 10 + 'a';
	}

	return -1;
}

int ch_to_int(char ch)
{
	if ('0' <= ch && ch <= '9') {
		return ch - '0';
	} else if ('a' <= ch && ch <= 'z') {
		return ch - 'a' + 10;
	} else if ('A' <= ch && ch <= 'Z') {
		return ch - 'A' + 10;
	}

	return -1;
}

void sys_convert(std::string &input, std::string &output, int from, int to)
{
	if (input.empty()) {
		output.clear();
		return;
	}
	if (input == "0") {
		output = "0";
		return;
	}

	int head = 0, tail = input.size() - 1;
	output.clear();

	while (head <= tail && input[head]) {
		int remainder = 0;
		if (input[head] == '0') {
			++head;
			continue;
		}

		for (int i = head; i <= tail; ++i) {
			remainder = remainder * from + ch_to_int(input[i]);
			input[i] = int_to_ch(remainder / to);
			remainder %= to;
		}
		output.push_back(int_to_ch(remainder));
	}

	reverse(output.begin(), output.end());

	return;
}

int main(void)
{
	std::string input, output;

	while (getline(std::cin, input)) {
		input = input.substr(2, input.size() - 2);
		sys_convert(input, output, 16, 10);
		std::cout << output << std::endl;
	}
}