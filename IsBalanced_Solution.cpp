/**
 * 题目描述
输入一棵二叉树，判断该二叉树是否是平衡二叉树。
 */ 
#include<iostream>

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
    //普通递归
    bool IsBalanced(TreeNode* pRoot) {
        if (!pRoot)
            return true;
        return (abs(getTreeDepth(pRoot -> left) - getTreeDepth(pRoot -> right)) <= 1) && (IsBalanced(pRoot -> left) && (IsBalanced(pRoot -> right)));
    }
    int getTreeDepth(TreeNode *root) {
        if (!root)
            return 0;
        return max(1 + getTreeDepth(root -> left), 1 + getTreeDepth(root -> right));
    }
    //自上而下遍历，剪枝
    bool IsBalanced2(TreeNode* pRoot) {
        if (!pRoot)
            return true;
        return getTreeDepth2(pRoot) != -1;
    }
    int getTreeDepth2(TreeNode *root) {
        if (!root)
            return 0;
        int left = getTreeDepth2(root -> left);
        if (left == -1) return -1;
        int right = getTreeDepth2(root -> right);
        if (right == -1) return -1;
        return abs(left - right) > 1 ? -1 : 1 + max(left, right);
    }
};