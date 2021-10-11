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

	for (int i = 0; str[i] != '\0'; ++i) {
		if (str[i] >= 'A' && str[i] <= 'Z') {
			str[i] += 'a' - 'A';
		}
	}
	if (ch >= 'A' && ch <= 'Z') {
		ch += 'a' - 'A';
	}

	for (int i = 0; str[i] != '\0'; ++i) {
		num += (str[i] == ch) ? 1 : 0;
	}

	cout << num;
	return 0;
}