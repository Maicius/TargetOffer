#include<iostream>
using namespace std;
/**
 * 题目描述
 * 输入两棵二叉树A，B，判断B是不是A的子结构。（ps：我们约定空树不是任意一个树的子结构）
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
    bool HasSubtree(TreeNode* pRoot1, TreeNode* pRoot2)
    {
        if (!pRoot2 || !pRoot1)
            return false;
        return compare(pRoot1, pRoot2) || HasSubtree(pRoot1->left, pRoot2) || HasSubtree(pRoot1 -> right, pRoot2);
    }
    bool compare(TreeNode *r1, TreeNode *r2) {
        if (!r2)
            return true;
        if (!r1)
            return false;
        if (r1->val == r2->val) {
              bool l = compare(r1->left, r2->left);
              bool r = compare(r1->right, r2->right);
              return l && r;
        } else 
              return false;
    }
};