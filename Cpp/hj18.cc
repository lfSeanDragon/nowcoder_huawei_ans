/*!
    \file      hj18.cc
    \author    Archlizix (archlizix@qq.com)
    \brief     HJ18 识别有效的IP地址和掩码并进行分类统计
    \version   1.0
    \date      2021-11-05

    \copyright Copyright (C) 2021 Archlizix

    \note
*/

#include<iostream>
#include<string>
#include<cstdint>

bool should_ignore(std::string ipstr)
{
	std::string::size_type pos = ipstr.find('.');
	int addr = stoi(ipstr.substr(0, pos));

	if (addr == 0 || addr == 127) {
		return true;
	}
	return false;
}

bool is_valid_mask(std::string maskstr)
{
	std::string::size_type pos;
	uint32_t maskint = 0;

	while ((pos  = maskstr.find('.')) != std::string::npos) {
		maskint += stoi(maskstr.substr(0, pos));
		maskint <<= 8;
		maskstr = maskstr.substr(pos + 1);
	}
	maskint += stoi(maskstr);

	if (maskint == 0xFFFFFFFFU || maskint == 0U) {
		return false;
	}
	maskint = (~maskint) + 1;
	if ((maskint & (maskint - 1)) == 0) {
		return true;
	}
	return false;
}

bool is_valid_ip(std::string ipstr)
{
	std::string::size_type pos;
	while ((pos = ipstr.find('.')) != std::string::npos) {
		if (pos == 0) {
			return false;
		}
		ipstr = ipstr.substr(pos + 1, ipstr.size());
	}
	if (ipstr.size() == 0) {
		return false;
	}
	return true;
}

int get_iptype(std::string ipstr)
{
	std::string::size_type pos = ipstr.find('.');
	std::string tmp = ipstr.substr(0, pos);
	unsigned part1 = stoi(tmp);

	if (1 <= part1 && part1 <= 126) {
		return 1;
	} else if (128 <= part1 && part1 <= 191) {
		return 2;
	} else if (192 <= part1 && part1 <= 223) {
		return 3;
	} else if (224 <= part1 && part1 <= 239) {
		return 4;
	} else if (240 <= part1 && part1 <= 255) {
		return 5;
	}

	return -1;
}

bool is_private_ip(std::string ipstr)
{
	std::string::size_type pos = ipstr.find('.');
	std::string tmp = ipstr.substr(0, pos);
	unsigned part1 = stoi(tmp);
	ipstr = ipstr.substr(pos + 1);
	pos = ipstr.find('.');
	tmp = ipstr.substr(0, pos);
	unsigned part2 = stoi(tmp);

	if (part1 == 10) {
		return true;
	}
	if (part1 == 172 && (16 <= part2 && part2 <= 31)) {
		return true;
	}
	if ((part1 == 192) && (part2 == 168)) {
		return true;
	}
	return false;
}

int main(void)
{
	std::string str;
	int A = 0, B = 0, C = 0, D = 0, E = 0, err = 0, prv = 0;

	while (getline(std::cin, str)) {
		std::string ipstr, maskstr;
		std::string::size_type divpos = str.find('~');
		ipstr = str.substr(0, divpos);
		maskstr = str.substr(divpos + 1, str.length());
		if (should_ignore(ipstr)) {
			continue;
		}
		if (!is_valid_mask(maskstr) || !is_valid_ip(ipstr)) {
			++err;
			continue;
		}
		switch (get_iptype(ipstr)) {
		case 1:
			++A;
			break;
		case 2:
			++B;
			break;
		case 3:
			++C;
			break;
		case 4:
			++D;
			break;
		case 5:
			++E;
			break;
		default:
			++err;
			continue;
		}
		if (is_private_ip(ipstr)) {
			++prv;
		}
	}

	std::cout << A << " " << B << " " << C << " " << D << " " << E << " "
			  << err << " " << prv << std::endl;
	return 0;
}
