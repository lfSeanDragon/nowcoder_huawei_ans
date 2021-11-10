/*!
    \file      hj39.cc
    \author    Archlizix (archlizix@qq.com)
    \brief     HJ39 判断两个IP是否属于同一子网
    \version   1.0
    \date      2021-11-10

    \copyright Copyright (C) 2021 Archlizix

    \note
*/

#include <iostream>
#include <string>
#include <sstream>
#include <cstdint>

bool is_mask(std::string &str)
{
	std::stringstream ss;
	uint32_t a, b, c, d, sum;
	char ch;
	ss << str;
	ss >> a >> ch >> b >> ch >> c >> ch >> d;
	sum = (a << 24) | (b << 16) | (c << 8) | d;

	if (a < 0 || 255 < a || b < 0 || 255 < b ||
		c < 0 || 255 < c || d < 0 || 255 < d) {
		return false;
	}

	if (!sum || !(~sum)) {
		return false;
	}

	sum = ~sum + 1;
	if (sum & (sum - 1)) {
		return false;
	}

	return true;
}

bool is_ip(std::string &str)
{
	std::stringstream ss;
	uint32_t a, b, c, d, sum;
	char ch;
	ss << str;
	ss >> a >> ch >> b >> ch >> c >> ch >> d;
	sum = (a << 24) | (b << 16) | (c << 8) | d;

	if (a < 0 || 255 < a || b < 0 || 255 < b ||
		c < 0 || 255 < c || d < 0 || 255 < d) {
		return false;
	}

	return true;
}

bool is_match(std::string &mask, std::string &ip1, std::string &ip2)
{
	std::stringstream ss;
	uint32_t a, b, c, d, mm, ii1, ii2;
	char ch;
	ss << mask;
	ss >> a >> ch >> b >> ch >> c >> ch >> d;
	mm = (a << 24) | (b << 16) | (c << 8) | d;
	ss.clear();
	ss << ip1;
	ss >> a >> ch >> b >> ch >> c >> ch >> d;
	ii1 = (a << 24) | (b << 16) | (c << 8) | d;
	ss.clear();
	ss << ip2;
	ss >> a >> ch >> b >> ch >> c >> ch >> d;
	ii2 = (a << 24) | (b << 16) | (c << 8) | d;

	if ((mm & ii1) != (mm & ii2)) {
		return false;
	}

	return true;
}

int main(void)
{
	std::string mask, ip1, ip2;
	int res = 0;
	while (std::cin >> mask >> ip1 >> ip2) {
		if (!is_mask(mask) || !is_ip(ip1) || !is_ip(ip2)) {
			std::cout << 1 << std::endl;
			continue;
		}
		if (is_match(mask, ip1, ip2)) {
			std::cout << 0 << std::endl;
		} else {
			std::cout << 2 << std::endl;
		}
	}
	return 0;
}
