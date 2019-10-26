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
    // 非递归版本
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
    //递归版本
    TreeNode *Convert2(TreeNode *root) {
        if (!root)
            return NULL;
        if (!root -> left && !root -> right) {
            this->last = root;
            return root;
        }
        TreeNode *left = Convert2(root -> left);
        if (!left) {
            this->last -> right = root;
            root -> left = last;
        }
        this->last = root;
        TreeNode *r = Convert2(root -> right);
        if (!r) {
            r -> left = root;
            root -> right = r;
        }
        return left != NULL ? left : root;
    }
    TreeNode *last = NULL;

    // 递归，中序遍历
    TreeNode* Convert3(TreeNode* pRootOfTree) {
        if(pRootOfTree == nullptr) return nullptr;
        TreeNode* pre = nullptr;
        convertHelper(pRootOfTree, pre);
        TreeNode* res = pRootOfTree;
        while(res ->left)
            res = res ->left;
        return res;
    }
     
    void convertHelper(TreeNode* cur, TreeNode*& pre) {
        if(cur == nullptr) return;
        convertHelper(cur ->left, pre); 
        cur ->left = pre;
        if(pre) pre ->right = cur;
        pre = cur;
        convertHelper(cur ->right, pre);  
    }
};

int main() {
    Solution *so = new Solution();
    TreeNode *n1 = new TreeNode(3);
    TreeNode *n2 = new TreeNode(4);
    TreeNode *n3 = new TreeNode(2);
    n1 -> right = n2;
    n1 -> left = n3;
    TreeNode *root = so->Convert3(n1);
    cout << root ->val << endl;
}