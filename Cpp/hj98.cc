/*!
    \file      hj98.cc
    \author    Archlizix (archlizix@qq.com)
    \brief     HJ98 自动售货系统
    \version   1.0
    \date      2021-11-13

    \copyright Copyright (C) 2021 Archlizix

    \note
*/

#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<sstream>

int price[6] = {2, 3, 4, 5, 8, 6}; // 商品价格
int money = 0; //投入的钱

std::vector<std::string> split(std::string str, const char c)
{
	std::vector<std::string> res;
	std::stringstream ss;
	std::string tmp = "";
	ss << str;
	while (std::getline(ss, tmp, c))
		res.push_back(tmp);
	return res;
}

void init(std::vector<int> &a, std::vector<int> &b, std::string &s)
{
	money = 0; //初始化投入的钱
	s = s.substr(2, s.length() - 2); //去掉前面的r和空格
	a[0] = a[1] = a[2] = a[3] = a[4] = a[5] = 0;
	b[0] = b[1] = b[2] = b[3] = 0;
	int i = 0;
	bool flag = false; //判别是前面部分商品价格还是后面部分零钱盒
	for (auto c : s) {
		if (isdigit(c) && !flag) //数字且是价格
			a[i] = a[i] * 10 + (c - ' 0'); //根据字符计算数字
		else if (isdigit(c) && flag) //数字且是零钱
			b[i] = b[i] * 10 + (c - '0'); //根据字符计算数字
		else if (c == ' ') { //遇到空格换成零钱
			flag = true;
			i = 0;
		} else if (c == '-') //遇到-后移一位商品或零钱
			i++;
	}
	std::cout << "S001:Initialization is successful" << std::endl;
}

void pay(std::vector<int> &a, std::vector<int> &b, std::string &s)  //投币函数
{
	int num = 0;
	for (auto &c : s)
		if (isdigit(c)) //只计算数字部分
			num = num * 10 + (c - '0'); //一次只投一张
	if (num == 1 || num == 2 || num == 5 || num == 10) { //投入合法的币种
		if (num > 2
			&& num > (b[0] + b[1] *
					  2)) //存钱盒中1元和2元面额钱币总额小于本次投入的钱币面额
			std::cout << "E003:Change is not enough, pay fail" << std::endl;
		else if ((a[0] || a[1] || a[2] || a[3] || a[4] || a[5]) == 0) //商品全部为0
			std::cout << "E005:All the goods sold out" << std::endl;
		else { //零钱盒中钱数增加
			if (num == 1 || num == 2)
				b[num - 1]++;
			else if (num == 5)
				b[2]++;
			else b[3]++;
			money += num; //投入的总钱数增加
			std::cout << "S002:Pay success,balance=" << money << std::endl;
		}
	} else //不合法币种
		std::cout << "E002:Denomination error" << std::endl;
}

void buy(std::vector<int> &a, std::vector<int> &b, std::string &s)  //购买函数
{
	//检查命令是否是4位，第三位是否为A，第四位是否数字1-6
	if (s.length() == 4 && (s[2] == 'A') && (s[3] - '0' < 7) && isdigit(s[3]) && (s[3] != '0')) {
		if (a[s[3] - '1'] == 0) //该商品的售罄
			std::cout << "E007:The goods sold out" << std::endl;
		else if (price[s[3] - '1'] > money) //该商品价格大于投入的钱
			std::cout << "E008:Lack of balance" << std::endl;
		else { //成功购买
			money -= price[s[3] - '1']; //投入的钱要减去买的商品
			std::cout << "S003:Buy success,balance=" << money << std::endl;
		}
	} else //输入命令不合法，商品不存在
		std::cout << "E006:Goods does not exist" << std::endl;
}

void back(std::vector<int> &coins) //退币函数
{
	int a = 0, b = 0, c = 0, d = 0; //四个币种
	if (money == 0) //投入的没有钱了，不用退
		std::cout << "E009:Work failure" << std::endl;
	else {
		d = money / 10; //优先退大币额的数量
		if (d <= coins[3]) { //10块的钱够退
			money = money % 10;
			coins[3] -= d;
		} else { //10块的钱不够退
			d = coins[3]; //全部退完
			coins[3] = 0;
			money -= d * 10; //剩余要退的
		}
		c = money / 5; //再计算要退的5块钱的数量
		if (c <= coins[2]) { //5块的钱够退
			money = money % 5;
			coins[2] -= c;
		} else { //5块的钱不够退
			c = coins[2]; //全部退完
			coins[2] = 0;
			money -= d * 5; //剩余要退的
		}
		b = money / 2; //再计算要退的2块钱的数量
		if (b <= coins[1]) { //2块的钱够退
			money = money % 2;
			coins[1] -= b;
		} else { //2块的钱不够退
			b = coins[1]; //全部退完
			coins[1] = 0;
			money -= d * 2; //剩余要退的
		}
		a = money;  //再计算要退的1块钱的数量
		if (a <= coins[0]) { //1块的钱够退
			coins[0] -= a;
			money = 0;
		} else { //1块的钱不够退
			coins[0] = 0;
			money -= a;
		}
		std::cout << "1 yuan coin number=" << a << std::endl << "2 yuan coin number=" << b << std::endl <<
				  "5 yuan coin number=" << c << std::endl << "10 yuan coin number=" << d << std::endl;
	}
}

void query(std::vector<int> &a, std::vector<int> &b, std::string &s)  //查询函数
{
	if (s[1] == ' ' && s.length() == 3) { //检查查询命令的合法性
		if (s[2] == 0) { //类别为0
			std::cout << "A1 " << price[0] << ' ' << a[0] << '\n'
					  << "A2 " << price[1] << ' ' << a[1] << '\n'
					  << "A3 " << price[2] << ' ' << a[2] << '\n'
					  << "A4 " << price[3] << ' ' << a[3] << '\n'
					  << "A5 " << price[4] << ' ' << a[4] << '\n'
					  << "A6 " << price[5] << ' ' << a[5] << '\n' << std::endl;
		} else if (s[2] == 1) { //类别为1
			std::cout << "1 yuan coin number=" << b[0] << std::endl
					  << "2 yuan coin number=" << b[1] << std::endl
					  << "5 yuan coin number=" << b[2] << std::endl
					  << "10 yuan coin number=" << b[3] << std::endl;
		} else
			std::cout << "E010:Parameter error" << std::endl;
	} else
		std::cout << "E010:Parameter error" << std::endl;
}

int main(void)
{
	std::string s;
	std::vector<int> goods(6, 0);
	std::vector<int> coins(4, 0);
	while (std::getline(std::cin, s)) {
		std::vector<std::string> orders = split(s, ';');
		for (auto c : orders) {
			switch (c[0]) {
			case 'r': //初始化
				init(goods, coins, c);
				break;
			case 'p': //投币
				pay(goods, coins, c);
				break;
			case 'b': //购买商品
				buy(goods, coins, c);
				break;
			case 'c': //退币
				back(coins);
				break;
			case 'q': //查询
				query(goods, coins, c);
				break;
			}
		}
	}
	return 0;
}
