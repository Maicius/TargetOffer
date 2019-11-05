#include<iostream>
#include<string>

using namespace std;
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};

/*
题目描述
请实现两个函数，分别用来序列化和反序列化二叉树

二叉树的序列化是指：把一棵二叉树按照某种遍历方式的结果以某种格式保存为字符串，从而使得内存中建立起来的二叉树可以持久保存。序列化可以基于先序、中序、后序、层序的二叉树遍历方式来进行修改，序列化的结果是一个字符串，序列化时通过 某种符号表示空节点（#），以 ！ 表示一个结点值的结束（value!）。

二叉树的反序列化是指：根据某种遍历顺序得到的序列化字符串结果str，重构二叉树。
*/
class Solution {
public:
    char* Serialize(TreeNode *root) {    
        if (!root) return NULL;
        string str;
        Serialize(root, str);
        char *ret = new char[strlen(str.c_str()) + 1];
        strcpy(ret, str.c_str());
        ret[strlen(str.c_str())] = '\0';
        return ret;
    }
    void Serialize(TreeNode *root, string &str) {
        if (!root) {
            str += '#';
            return;
        }
        string r = to_string(root-> val);
        str += r;
        str += ',';
        Serialize(root -> left, str);
        Serialize(root -> right, str);
    }
    TreeNode* Deserialize(char *str) {
        if (!str) return NULL;
        TreeNode *root = doDeserialize(str);
        return root;
    }
    TreeNode* doDeserialize(char *&str) {
        if (*str == '#') {
            str++;
            return NULL;
        }
        int num = 0;
        while (*str != '\0' && *str != ',') {
            num = num * 10 + (*str - '0');
            str++;
        }
        TreeNode *root = new TreeNode(num);
        if (*str == '\0')
            return root;
        else 
            str++;
        root -> left = doDeserialize(str);
        root -> right = doDeserialize(str);
        return root;
    }
};

int main() {
    Solution *so = new Solution();
}