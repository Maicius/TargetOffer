#include<iostream>
using namespace std;
/**
 * 题目描述
输入一个复杂链表（每个节点中有节点值，以及两个指针，一个指向下一个节点，另一个特殊指针指向任意一个节点），返回结果为复制后复杂链表的head。
（注意，输出结果中请不要返回参数中的节点引用，否则判题程序会直接返回空）
 */ 
struct RandomListNode {
    int label;
    struct RandomListNode *next, *random;
    RandomListNode(int x) :
            label(x), next(NULL), random(NULL) {
    }
};

class Solution {
public:
    RandomListNode* Clone(RandomListNode* pHead)
    {
        if(!pHead) return NULL;
        RandomListNode *h = pHead;
        while (h) {
            RandomListNode *node = new RandomListNode(h->label);
            node -> next = h -> next;
            h -> next = node;
            h = node -> next;
        }
        h = pHead;
        while (h) {
            if (h -> random) {
                h -> next -> random = h -> random -> next;
            }
            h = h -> next -> next;
        }
        //拆分
        RandomListNode *pCloneHead = pHead->next;
        RandomListNode *tmp;
        h = pHead;
        while(h -> next){
            tmp = h -> next;
            h -> next = tmp -> next;
            h = tmp;
        }
        return pCloneHead;
    }

    RandomListNode *Clone2(RandomListNode *pHead) {
        if (!pHead)
            return NULL;
        RandomListNode *h = new RandomListNode(0);
        RandomListNode *curr_h = h;
        RandomListNode *curr = pHead;
        while (curr) {
            RandomListNode *node = new RandomListNode(curr -> label);
            curr_h -> next = node;
            curr_h = curr_h -> next;
            curr = curr -> next;
        }
        curr = pHead;
        curr_h = h -> next;
        while (curr) {
            if (curr -> random) {
                RandomListNode *node = new RandomListNode(curr -> random -> label);
                curr_h -> random = node;

            }
            curr_h = curr_h -> next;
            curr = curr -> next;
        }
    }
};