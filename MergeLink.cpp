#include<iostream>
/**
 * 题目描述
 * 输入两个单调递增的链表，输出两个链表合成后的链表，当然我们需要合成后的链表满足单调不减规则。
 */ 
using namespace std;
struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};
class Solution {
public:
    ListNode* Merge(ListNode* pHead1, ListNode* pHead2)
    {    
        if (!pHead1) {
            return pHead2;
        }
        if (!pHead2) {
            return pHead1;
        }
        ListNode * ln = new ListNode(0);
        ListNode *head = ln;
        while (pHead1 && pHead2) {
            if (pHead1 -> val <= pHead2 -> val) {
                ln -> next = pHead1;
                pHead1 = pHead1 -> next;
            } else {
                ln -> next = pHead2;
                pHead2 = pHead2 -> next;
            }
            ln = ln -> next;
        }
        while (pHead1) {
            ln -> next = pHead1;
            ln = ln -> next;
            pHead1 = pHead1 -> next;
        }
        while (pHead2) {
            ln -> next = pHead2;
            ln = ln -> next;
            pHead2 = pHead2 -> next;
        }
        return head->next;
    }
};