/*!
    \file      hj48.cc
    \author    Archlizix (archlizix@qq.com)
    \brief     HJ48 从单向链表中删除指定值的节点
    \version   1.0
    \date      2021-11-07

    \copyright Copyright (C) 2021 Archlizix

    \note
*/

#include <iostream>

struct ListNode {
	int val;
	ListNode *next;
	ListNode(): val(0), next(nullptr) {}
	ListNode(int val): val(val), next(nullptr) {}
	ListNode(int val, ListNode *next): val(val), next(next) {}
};

void list_insert(ListNode *pre, ListNode *cur)
{
	cur->next = pre->next;
	pre->next = cur;
}

void list_remove(ListNode *head, ListNode *target)
{
	if (head == target) {
		head = head->next;
		return;
	}

	while (head->next != target) {
		head = head->next;
	}
	head->next = head->next->next;
}

ListNode *list_find(ListNode *head, int val)
{
	while (head) {
		if (head->val == val) return head;
		head = head->next;
	}
	return nullptr;
}

int main(void)
{
	int n;
	while (std::cin >> n) {
		ListNode *head = new ListNode();
		std::cin >> head->val;
		for (int i = 0; i < n - 1; ++i) {
			int pre_val;
			ListNode *cur = new ListNode();
			std::cin  >>  cur->val >> pre_val;
			list_insert(list_find(head, pre_val), cur);
		}
		int del_val;
		std::cin >> del_val;
		list_remove(head, list_find(head, del_val));
		while (head) {
			std::cout << head->val << " ";
			head = head->next;
		}
		std::cout << std::endl;
	}
	return 0;
}
