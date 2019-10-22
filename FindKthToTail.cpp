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
    ListNode* FindKthToTail2(ListNode* pListHead, unsigned int k) {
        ListNode *curr = pListHead;
        ListNode *pre = curr;
        int count = 0;
        pre = pListHead;
        if (pListHead==NULL || k==0)
            return NULL;
        while (pListHead->next) {
            curr = pListHead->next;
            pListHead->next = curr ->next;
            curr -> next = pre;
            pre = curr;
        }
        while (count < k - 1 && pre -> next) {
            pre = pre -> next;
            count++;
        }
        return new ListNode(pre -> val);
    }

    ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) {
            if(pListHead==NULL||k==0)
                return NULL;
            ListNode*pTail = pListHead,*pHead = pListHead;
            for(int i = 1;i < k; ++i)
            {
                if(pHead->next!=NULL)
                    pHead=pHead->next;
                else
                    return NULL;
            }
            while(pHead->next!=NULL)
            {
                pHead = pHead->next;
                pTail = pTail->next;
            }
            return pTail;
    }
};

int main(){
    Solution *so = new Solution();
    ListNode *head;
    ListNode ln1 = ListNode(1);
    ListNode ln2 = ListNode(2);
    ListNode ln3 = ListNode(3);
    ListNode ln4 = ListNode(4);
    ListNode ln5 = ListNode(5);
    ln1.next = &ln2;
    ln2.next = &ln3;
    ln3.next = &ln4;
    ln4.next = &ln5;
    head = &ln1;
    cout << so->FindKthToTail(head, 1)->val<<endl;
}