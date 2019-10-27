#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
        int size = input.size();
        if (size == 0) return input;
        vector<int> res;
        while (k > 0 && input.size() > 0) {
            buildHeap(input);
            res.push_back(input[0]);
            input.erase(input.begin());
            k--;
        }
        return res;
    }
    
    void buildHeap(vector<int> &input) {
        int size = input.size();
        int n = size / 2 - 1;
        // 建堆
        while (n >= 0) {
            int right = 2 * n + 2;
            int left = 2 * n + 1;
            if (right < size) {
                if (input[right] < input[n]) {
                    swap(input[right], input[n]);
                }
            }
            if (left < size) {
                if (input[left] < input[n]) {
                    swap(input[left], input[n]);
                }
            }
            n--;
        }
    }
    
    void swap(int &a, int &b) {
        int temp = a;
        a = b;
        b = temp;
    }
};