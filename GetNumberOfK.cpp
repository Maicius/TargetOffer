#include<iostream>
#include<vector>
using namespace std;

/**
 * 题目描述
统计一个数字在排序数组中出现的次数。
 */ 
class Solution {
public:
    ////因为data中都是整数，所以可以稍微变一下，不是搜索k的两个位置，而是搜索k-0.5和k+0.5
    //这两个数应该插入的位置，然后相减即可。
    int GetNumberOfK(vector<int> data ,int k) {
        if (data.size() == 0)
            return 0;
        else {
            return biSearch(data, k + 0.5) - biSearch(data, k - 0.5);
        }
    }
    
    int biSearch(const vector<int> &data, double num) {
        int begin = 0, upper = data.size() - 1;
        int mid;
        while (begin <= upper) {
            mid = (begin + upper) >> 1;
            if (data[mid] > num) {
                upper = mid - 1;
            } else {
                begin = mid + 1;
            }
        }
        return begin;
    }
};