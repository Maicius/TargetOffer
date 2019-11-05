#include<iostream>
#include<vector>
#include<queue>
using namespace std;
/**
 * 题目描述
从上到下按层打印二叉树，同一层结点从左至右输出。每一层输出一行。
 */ 
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};

class Solution {
public:
    vector<vector<int> > Print(TreeNode* pRoot) {
        queue<TreeNode *> stack1;
        queue<TreeNode *> stack2;
        vector<vector<int> > res;
        if (!pRoot) return res;
        stack1.push(pRoot);
        vector<int> temp;
        while (!stack1.empty() || !stack2.empty()) {
            if (!stack1.empty()) {
                while (!stack1.empty()) {
                    TreeNode * node = stack1.front();
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
                    TreeNode *node = stack2.front();
                    temp.push_back(node -> val);
                    stack2.pop();
                    if (node -> left) stack1.push(node -> left);
                    if (node -> right) stack1.push(node -> right);
                }
            }
            if (temp.size() > 0) res.push_back(temp);
            temp.clear();
        }
        return res;
    }
};