#include<iostream>
#include<stack>
/**
题目描述
输入一棵二叉搜索树，将该二叉搜索树转换成一个排序的双向链表。要求不能创建任何新的结点，只能调整树中结点指针的指向。
*/
using namespace std;
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
    TreeNode* Convert(TreeNode* root)
    {
        if (!root)
            return NULL;
        TreeNode *p = root;
        TreeNode *pre = NULL;
        stack<TreeNode*> stack1;
        bool first = true;
        while (p != NULL || !stack1.empty()) {
            while (p != NULL) {
                stack1.push(p);
                p = p -> left;
            }
            p = stack1.top();
            stack1.pop();
            if (first) {
                root = p;
                pre = root;
                first = false;
            } else {
                pre -> right = p;
                p -> left = pre;
                pre = p;
            }
            p = p -> right;
        }
        return root;
    }
};