#include <iostream>
#include <vector>
using namespace std;
/**
 * 题目描述
输入一个链表，按链表从尾到头的顺序返回一个ArrayList。
 **/
 
struct ListNode {
        int val;
        struct ListNode *next;
        ListNode(int x) :
              val(x), next(NULL) {
        }
};
class Solution {
public:
    //递归
    vector<int> printListFromTailToHead(ListNode* head) {
        vector<int> res;
        if (head != NULL)
            res.insert(res.begin(), head->val);
            if (head->next != NULL){
                vector<int> temp = printListFromTailToHead(head->next);
                if (temp.size() > 0){
                    res.insert(res.begin(), temp.begin(), temp.end());
                }
            }
        return res;
    }
    // 原地反转链表
    vector<int> printListFromTailToHead2(ListNode* head) {
        vector<int> res;
        ListNode *curr = head;
        ListNode *pre = curr;
        if (head == NULL)
            return res;
        while (head -> next != NULL){
            curr = head -> next;
            head->next = curr -> next;
            curr->next = pre;
            pre = curr;
        }
         while (curr){
             res.push_back(curr->val);
             curr = curr -> next;
         }
        return res;
    }
};
int main(){
    Solution *so = new Solution();
    ListNode *head;
    ListNode ln1 = ListNode(67);
    ListNode ln2 = ListNode(0);
    ListNode ln3 = ListNode(24);
    ListNode ln4 = ListNode(58);
    ln1.next = &ln2;
    ln2.next = &ln3;
    ln3.next = &ln4;
    head = &ln1;
    vector<int> res = so->printListFromTailToHead(head);
    for (int i=0; i < res.size(); i++){
        cout << res[i] <<endl;
    }
    return 0;
}