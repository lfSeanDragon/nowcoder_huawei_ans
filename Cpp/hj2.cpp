#include<iostream>
#include<string>

using namespace std;

int main(void)
{
	constexpr int max_str_size = 500;
	char str[max_str_size];
	char ch;
	int num = 0;

	cin.getline(str, max_str_size);
	cin >> ch;
	if ('A' <= ch && ch <= 'Z') {
		ch += 32;
	}

	for (int i = 0; str[i] != '\0'; ++i) {
		num += (str[i] == ch || str[i] == ch - 32) ? 1 : 0;
	}

	cout << num;
	return 0;
}