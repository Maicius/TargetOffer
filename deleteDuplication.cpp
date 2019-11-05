/**
 * 题目描述
在一个排序的链表中，存在重复的结点，请删除该链表中重复的结点，重复的结点不保留，返回链表头指针。 
例如，链表1->2->3->3->4->4->5 处理后为 1->2->5
 */ 
#include<iostream>

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
    ListNode* deleteDuplication(ListNode* pHead)
    {
        if (!pHead) return NULL;
        ListNode *cur, *pre;
        ListNode *head = new ListNode(-1);
        head -> next = pHead;
        cur = head;
        pre = cur;
        while (cur -> next) {
            cur = cur -> next;
            if (cur -> next && cur -> val == cur -> next -> val) {
                while (cur -> next && cur -> val == cur -> next -> val) {
                    cur = cur -> next;
                }
                pre -> next = cur -> next;
                cur = pre;
            } else {
                pre = cur;
            }
        }
        return head -> next;
    }
};