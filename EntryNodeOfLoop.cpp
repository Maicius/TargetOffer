#include<iostream>
using namespace std;
/**
 * 题目描述
给一个链表，若其中包含环，请找出该链表的环的入口结点，否则，输出null。
 */ 
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) :
        val(x), next(NULL) {
    }
};

class Solution {
public:
    ListNode* EntryNodeOfLoop(ListNode* pHead)
    {
        ListNode *slow, *fast;
        if (!pHead || !pHead -> next || !pHead -> next -> next)
            return NULL;
        slow = pHead -> next;
        fast = pHead -> next -> next;
        while (fast != slow) {
            if (fast -> next && fast -> next->next) {
                slow = slow -> next;
                fast = fast -> next -> next;
            } else {
                return NULL;
            }
        }
        fast = pHead;
        while (fast != slow) {
            fast = fast -> next;
            slow = slow -> next;
        }
        
        return fast;
    }
};