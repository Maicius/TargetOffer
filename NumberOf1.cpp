/**
 * 题目描述
输入一个整数，输出该数二进制表示中1的个数。其中负数用补码表示。
 **/ 
#include<iostream>
using namespace std;
class Solution {
public:
     int  NumberOf1(int n) {
         int flag = 0, count = 0;
         while (n != 0){
             count++;
             n = (n - 1) & n;
         }
        return count;
     } 
};

int main(){
    Solution *so = new Solution();
    cout << so->NumberOf1(10) << endl;
}