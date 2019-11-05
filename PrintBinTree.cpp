#include<iostream>
#include<stack>
#include<vector>
using namespace std;
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};
/**
 * 题目描述
请实现一个函数按照之字形打印二叉树，即第一行按照从左到右的顺序打印，第二层按照从右至左的顺序打印，第三行按照从左到右的顺序打印，其他行以此类推。
 */ 
class Solution {
public:
    vector<vector<int> > Print(TreeNode* pRoot) {
        stack<TreeNode *> stack1;
        stack<TreeNode *> stack2;
        vector<vector<int> > res;
        if (!pRoot) return res;
        stack1.push(pRoot);
        vector<int> temp;
        while (!stack1.empty() || !stack2.empty()) {
            if (!stack1.empty()) {
                while (!stack1.empty()) {
                    TreeNode * node = stack1.top();
                    temp.push_back(node -> val);
                    stack1.pop();
                    if (node -> left) stack2.push(node -> left);
                    if (node -> right) stack2.push(node -> right);
                }
            }
            if (temp.size() > 0) res.push_back(temp);
            temp.clear();
            if (!stack2.empty()) {
                while (!stack2.empty()) {
                    TreeNode *node = stack2.top();
                    temp.push_back(node -> val);
                    stack2.pop();
                    if (node -> right) stack1.push(node -> right);
                    if (node -> left) stack1.push(node -> left);
                }
            }
            if (temp.size() > 0) res.push_back(temp);
            temp.clear();
        }
        return res;
    }
};