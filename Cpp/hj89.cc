/*!
    \file      hj89.cc
    \author    Archlizix (archlizix@qq.com)
    \brief     HJ89 24点运算
    \version   1.0
    \date      2021-11-10

    \copyright Copyright (C) 2021 Archlizix

    \note
*/

#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<unordered_map>

std::unordered_map<std::string, int> card_to_num = {{"A", 1}, {"2", 2}, {"3", 3}, {"4", 4}, {"5", 5}, {"6", 6},
	{"7", 7}, {"8", 8}, {"9", 9}, {"10", 10}, {"J", 11}, {"Q", 12}, {"K", 13}
};
std::unordered_map<int, std::string> num_to_card = {{1, "A"}, {2, "2"}, {3, "3"}, {4, "4"}, {5, "5"}, {6, "6"},
	{7, "7"}, {8, "8"}, {9, "9"}, {10, "10"}, {11, "J"}, {12, "Q"}, {13, "K"}
};
const std::vector<char> Op = {'+', '-', '*', '/'};

bool cal24(std::vector<int> &a, std::vector<int> &op)
{
	int tmp = a[0];
	for (int i = 0; i < op.size(); ++i) {
		switch (op[i]) {
		case 0:
			tmp = tmp + a[i + 1];
			break;
		case 1:
			tmp = tmp - a[i + 1];
			break;
		case 2:
			tmp = tmp * a[i + 1];
			break;
		case 3:
			tmp = tmp / a[i + 1];
			break;
		default:
			break;
		}
	}
	if (tmp == 24)
		return true;
	else
		return false;
}

bool check(std::vector<int> &nums)
{
	bool flag = false;
	std::vector<int> op(3);
	sort(nums.begin(), nums.end());
	do {
		for (int i = 0; i < 4 && !flag; ++i) {
			op[0] = i;
			for (int j = 0; j < 4 && !flag; ++j) {
				op[1] = j;
				for (int k = 0; k < 4 && !flag; ++k) {
					op[2] = k;
					if (cal24(nums, op)) {
						for (int m = 0; m < 3; m++)
							std::cout << num_to_card[nums[m]] << Op[op[m]];
						std::cout <<  num_to_card[nums[3]]  << std::endl;
						flag = true;
					}
				}
			}
		}
	} while (next_permutation(nums.begin(), nums.end()) && !flag);
	return flag;
}

int main(void)
{
	std::vector<std::string> s(4);
	std::cin >> s[0] >> s[1] >> s[2] >> s[3];
	std::vector<int> nums(4);
	for (int i = 0; i < 4; ++i) {
		if (s[i] == "joker" || s[i] == "JOKER") {
			std::cout << "ERROR" << std::endl;
			return 0;
		}
		nums[i] = card_to_num[s[i]];
	}
	if (!check(nums)) std::cout << "NONE" << std::endl;
	return 0;
}
