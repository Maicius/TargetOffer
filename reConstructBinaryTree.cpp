#include <iostream>
#include <vector>
using namespace std;

 /**
  * 题目描述
输入某二叉树的前序遍历和中序遍历的结果，请重建出该二叉树。假设输入的前序遍历和中序遍历的结果中都不含重复的数字。例如输入前序遍历序列{1,2,4,7,3,5,6,8}和中序遍历序列{4,7,2,1,5,3,8,6}，则重建二叉树并返回。

  * 思想如下：

    a、根据前序遍历结果，第一个元素为二叉树的根结点；

    b、观察中序遍历结果，根结点左侧的为左子树，若左子树根结点前（后）再无任何元素，则左（右）子树的左分支为空；根结点右侧的为右子树，若右子树根结点前（后）再无任何元素，则左（右）子树的左分支为空；

    c、上面的过程是递归的。先找到当前树的根结点，然后划分为左右子树，再进入左子树重复上面的过程，最后进入右子树重复上面的过程，最终还原一棵树。
  **/

  //Definition for binary tree
 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };
class Solution {
public:
    TreeNode* reConstructBinaryTree(vector<int> pre,vector<int> vin) {
        return doReConstructBinaryTree(pre, vin);
    }

    TreeNode* doReConstructBinaryTree(vector<int> pre, vector<int> vin){
        if (vin.size() == 0)
            return NULL;
        TreeNode *root = new TreeNode(pre[0]);
        bool flag = true;
        vector<int> pre_left, pre_right;
        vector<int> vin_left, vin_right;

        for(int i=0; i < vin.size(); i++){
            if (vin[i] == pre[0]){
                flag = false;
                continue;
            }
            if (flag) {
                vin_left.push_back(vin[i]);
                pre_left.push_back(pre[i + 1]);
            } else {
                vin_right.push_back(vin[i]);
                pre_right.push_back(pre[i]);
            }
        }
        root->left = doReConstructBinaryTree(pre_left, vin_left);
        root->right = doReConstructBinaryTree(pre_right, vin_right);
        return root;
    }
};

