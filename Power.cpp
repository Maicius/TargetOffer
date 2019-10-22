/**
 * 题目描述
给定一个double类型的浮点数base和int类型的整数exponent。求base的exponent次方。
保证base和exponent不同时为0
 **/

#include <iostream>
using namespace std;
class Solution {
public:
    double Power(double base, int exponent) {
        double res = 1;
        int temp;
        temp = exponent > 0 ? exponent : -exponent;
        // for(int i = 0; i < temp; i++){
        //     res *= base;
        // }
        
        while (temp) {
            // cout << temp << endl;
            if (temp & 1)
                res =res * base;
            base *= base;
            temp >>= 1;
        }
        return exponent > 0 ? res : 1.0 / res;
    }
};
int main(){
    Solution *so = new Solution();
    cout << so->Power(2, 10) << endl;
}