#include<iostream>
#include<queue>
#include<vector>
using namespace std;
/**
 * 题目描述
给定一个数组和滑动窗口的大小，找出所有滑动窗口里数值的最大值。例如，如果输入数组{2,3,4,2,6,2,5,1}及滑动窗口的大小3，那么一共存在6个滑动窗口，
他们的最大值分别为{4,4,6,6,6,5}； 针对数组{2,3,4,2,6,2,5,1}的滑动窗口有以下6个： 
{[2,3,4],2,6,2,5,1}， {2,[3,4,2],6,2,5,1}， {2,3,[4,2,6],2,5,1}， {2,3,4,[2,6,2],5,1}， {2,3,4,2,[6,2,5],1}， {2,3,4,2,6,[2,5,1]}。
 */ 
class Solution {
public:
    vector<int> maxInWindows(const vector<int>& num, unsigned int size)
    {
        vector<int> res;
        if (size == 0) return res;
        deque<int> index;
        for (int i = 0; i < num.size(); i++) {
            while (index.size() && num[index.back()] <= num[i]) index.pop_back();
            while (index.size() && (i - index.front() + 1) > size) index.pop_front();
            index.push_back(i);
            if (i + 1 >= size) {
                res.push_back(num[index.front()]);
            }
        }
        return res;
    }
};