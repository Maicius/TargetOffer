#include<iostream>
#include<vector>
using namespace std;
/**
 * 题目描述
输入一颗二叉树的根节点和一个整数，打印出二叉树中结点值的和为输入整数的所有路径。
路径定义为从树的根结点开始往下一直到叶结点所经过的结点形成一条路径。(注意: 在返回值的list中，数组长度大的数组靠前)
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
    void dfs(TreeNode* root, int n) {
        temp.push_back(root -> val);
        if (!root -> left && !root -> right && n - root->val == 0) {
            res.push_back(temp);
        }
        else {
            if (root -> left) {
                dfs(root -> left, n - root -> val);
            }
            if (root -> right) {
                dfs(root -> right, n - root -> val);
            }
        }
        temp.pop_back();
    }
    vector<vector<int> > FindPath(TreeNode* root,int expectNumber) {
        if (!root)
            return res;
        dfs(root, expectNumber);
        return res;
    }
private:
    vector<vector<int> > res;
    vector<int> temp;
};