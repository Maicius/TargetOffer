#include<iostream>
#include<string.h>
using namespace std;
/**
 * 题目描述
 * 操作给定的二叉树，将其变换为源二叉树的镜像。
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
    void Mirror(TreeNode *pRoot) {
        if(!pRoot){
            return;
        }
        TreeNode *tmp = pRoot->left;
        pRoot->left = pRoot->right;
        pRoot->right = tmp;
        Mirror(pRoot->left);
        Mirror(pRoot->right);
    }
};