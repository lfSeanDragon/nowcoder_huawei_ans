/*!
    \file      hj51.cc
    \author    Archlizix (archlizix@qq.com)
    \brief     HJ51 输出单向链表中倒数第k个结点
    \version   1.0
    \date      2021-11-11

    \copyright Copyright (C) 2021 Archlizix

    \note      快慢双指针实现单次遍历。
*/

struct ListNode {
	int val;
	ListNode *next;
	ListNode(): val(0), next(nullptr) {}
	ListNode(int val): val(val), next(nullptr) {}
	ListNode(int val, ListNode *next): val(val), next(next) {}
};

#include <iostream>

int main(void)
{
	int n;
	ListNode *head = new ListNode();
	ListNode *pre = head;

	while (std::cin >> n) {
		int tmp;
		for (int i = 0; i < n; ++i) {
			std::cin >> tmp;
			ListNode *tail = new ListNode(tmp);
			pre->next = tail;
			pre = tail;
		}
		std::cin >> tmp;
		if (tmp <= 0) {
			std::cout << 0 << std::endl;
			continue;
		}
		ListNode *fast = head, *slow = head;
		for (int i = 1; i < tmp; ++i) {
			fast = fast->next;
		}
		while (fast->next) {
			fast = fast->next;
			slow = slow->next;
		}
		std::cout << slow->val << std::endl;
	}
}
