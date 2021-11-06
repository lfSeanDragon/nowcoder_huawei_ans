/*!
    \file      hj54.cc
    \author    Archlizix (archlizix@qq.com)
    \brief     HJ54 表达式求值
    \version   1.0
    \date      2021-11-06

    \copyright Copyright (C) 2021 Archlizix

    \note
*/

#include <iostream>
#include <string>
#include <stack>

void format(std::string &str)
{
	for (auto &ch : str) {
		switch (ch) {
		case '[':
		case '{':
			ch = '(';
			break;
		case ']':
		case '}':
			ch = ')';
			break;
		default:
			break;
		}
	}
	return;
}

void arithmetic(std::stack<int> &nums, std::stack<char> &ops)
{
	int b = nums.top();
	nums.pop();
	int a = nums.top();
	nums.pop();
	char operation = ops.top();
	ops.pop();

	int ans = 0;
	switch (operation) {
	case '+': ans = a + b; break;
	case '-': ans = a - b; break;
	case '*': ans = a * b; break;
	case '/': ans = a / b; break;
	}

	nums.push(ans);
}

int compute(std::string str)
{
	std::stack<int> nums;
	std::stack<char> ops;
	for (int i = 0, len = str.size(); i < len; ++i) {
		if (isdigit(str[i])) {
			int left = i, num = 0;
			while (i + 1 < len && isdigit(str[i + 1])) {
				++i;
			}
			std::string str_num = str.substr(left, i - left + 1);
			for (const auto &ch : str_num) {
				num = num * 10 + ch - '0';
			}
			if (left - 1 == 0 && str[left - 1] == '-' || (left - 1 > 0 && str[left - 2] == '(')) {
				num *= -1;
			}
			nums.push(num);
		} else if (str[i] == '*' || str[i] == '/' || str[i] == '(') {
			ops.push(str[i]);
		} else if (str[i] == '+' || str[i] == '-') {
			if (i != 0 && str[i - 1] != '(') {
				while (!ops.empty() && ops.top() != '(') {
					arithmetic(nums, ops);
				}
				ops.push(str[i]);
			}
		} else if (str[i] == ')') {
			while (ops.top() != '(') {
				arithmetic(nums, ops);
			}
			ops.pop();
		}
	}

	while (!ops.empty()) {
		arithmetic(nums, ops);
	}
	return nums.top();
}

int main()
{
	std::string str;
	while (std::cin >> str) {
		format(str);
		std::cout << compute(str) << std::endl;
	}
	return 0;
}
