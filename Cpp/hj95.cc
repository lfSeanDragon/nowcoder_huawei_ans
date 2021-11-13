/*!
    \file      hj95.cc
    \author    Archlizix (archlizix@qq.com)
    \brief     HJ95 人民币转换
    \version   1.0
    \date      2021-11-13

    \copyright Copyright (C) 2021 Archlizix

    \note
*/

#include <iostream>
#include <string>
#include <vector>

const std::vector<std::string> helper1 = {"零", "壹", "贰", "叁", "肆", "伍", "陆", "柒", "捌", "玖"};
const std::vector<std::string> helper2 = {"元", "万", "亿", "万亿"};
const std::vector<std::string> helper3 = {"", "拾", "佰", "仟"};

std::string function(int num)
{
	std::string str;
	if (num > 0 && num <= 9) //只有个位
		str += helper1[num];
	else if (num >= 10 && num <= 19) { //10到19
		if (num % 10 == 0) //整十
			str += helper3[1];
		else
			str += helper3[1] + helper1[num % 10];
	} else if (num >= 20 && num <= 99) { //20到99
		if (num % 10 == 0) //整十
			str += helper1[num / 10] + helper3[1];
		else
			str += helper1[num / 10] + helper3[1] + helper1[num % 10];
	} else if (num >= 100 && num <= 999) { //三位数
		if (num % 100 == 0) //整百
			str += helper1[num / 100] + helper3[2];
		else if (num % 100 <= 9) //整十
			str += helper1[num / 100] + helper1[0] + helper1[num % 100];
		else //后续进入递归
			str += helper1[num / 100] + helper3[2] + function(num % 100);
	} else if (num >= 1000 && num <= 9999) { //四位数
		if (num % 1000 == 0) //整千
			str += helper1[num / 1000] + helper3[3];
		else if (num % 1000 <= 99) //后续进入递归
			str += helper1[num / 1000] + helper3[3] + helper1[0] + function(num % 1000);
		else //后续进入递归
			str += helper1[num / 1000] + helper3[3] + function(num % 1000);
	}
	return str;
}

int main(void)
{
	double money;
	while (std::cin >> money) {
		int integer = static_cast<int>(money);
		std::vector<int> vec;
		std::string res = "人民币";
		while (integer) {
			vec.push_back(integer % 10000);
			integer /= 10000;
		}
		for (int i = vec.size() - 1; i >= 0; i--) {
			res += function(vec[i]);
			res += helper2[i];
			if (i != 0 && i - 1 >= 0 && vec[i - 1] <= 999 && vec[i - 1] != 0)
				res += helper1[0];
		}

		money += 0.0001;
		int decimal = static_cast<int>((money - static_cast<int>(money)) * 100);
		if (decimal == 0) //小数部分为0
			res += "整";
		else if (decimal < 10) //没有角
			res += helper1[decimal] + "分";
		else if (decimal % 10 == 0) //没有分
			res += helper1[decimal / 10] + "角";
		else //分角都有
			res += helper1[decimal / 10] + "角" + helper1[decimal % 10] + "分";
		std::cout << res << std::endl;
	}
	return 0;
}
