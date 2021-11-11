/*!
    \file      hj42.cc
    \author    Archlizix (archlizix@qq.com)
    \brief     HJ42 学英语
    \version   1.0
    \date      2021-11-11

    \copyright Copyright (C) 2021 Archlizix

    \note
*/

#include <iostream>
#include <string>
#include <vector>

std::vector<std::string> to_abc = {
	"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "ten",
	"eleven", "twelve", "thirteen", "fourteen", "fifteen",
	"sixteen", "seventeen", "eighteen", "nineteen", "twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety",
};

std::string convert(long n)
{
	if (n < 20) {
		return to_abc[n];
	} else if (n < 100) {
		if (n % 10 == 0) {
			return to_abc[n / 10 + 18];
		} else {
			return convert(n / 10 * 10) + ' ' + convert(n % 10);
		}
	} else if (n < 1000) {
		if (n % 100 == 0) {
			return convert(n / 100) + " hundred";
		} else {
			return convert(n / 100) + " hundred and " + convert(n % 100);
		}
	} else if (n < 1000000) {
		if (n % 1000 == 0) {
			return convert(n / 1000) + " thousand";
		} else {
			return convert(n / 1000) + " thousand " + convert(n % 1000);
		}
	} else {
		if (n % 1000000 == 0) {
			return convert(n / 1000000) + " million";
		} else {
			return convert(n / 1000000) + " million " + convert(n % 1000000);
		}
	}
}

int main(void)
{
	long n;
	while (std::cin >> n)
		std::cout << convert(n) << std::endl;
	return 0;
}
