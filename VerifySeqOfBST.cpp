#include<iostream>
#include<vector>
using namespace std;

/**
 * 题目描述
输入一个整数数组，判断该数组是不是某二叉搜索树的后序遍历的结果。如果是则输出Yes,否则输出No。假设输入的数组的任意两个数字都互不相同。
 */ 
class Solution {
public:
    bool VerifySquenceOfBST(vector<int> sequence) {
        if (sequence.size() == 0) 
            return false;
        auto root = sequence.back();
        sequence.pop_back();
        if (sequence.size() == 0) {
            return true;
        }
        vector<int> front, end;
        bool flag = true;
        for (int i = 0; i < sequence.size(); i++) {
            if (sequence[i] > root) {
                flag = false;
            }
            if (flag)
                front.push_back(sequence[i]);
            else {
                if (sequence[i] < root)
                    return false;
                end.push_back(sequence[i]);
            }
        }
        bool l = true, r = true;
        if (front.size() > 0) {
            l = VerifySquenceOfBST(front);
        }
        if (end.size() > 0) {
            r = VerifySquenceOfBST(end);
        }
        return l && r;
    }
};