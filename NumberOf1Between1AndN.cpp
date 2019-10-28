#include<iostream>
#include<string.h>
#include<vector>
using namespace std;
/**
 * 题目描述
求出1~13的整数中1出现的次数,并算出100~1300的整数中1出现的次数？为此他特别数了一下1~13中包含1的数字有1、10、11、12、13因此共出现6次,但是对于后面问题他就没辙了。
ACMer希望你们帮帮他,并把问题更加普遍化,可以很快的求出任意非负整数区间中1出现的次数（从1 到 n 中1出现的次数）。
 */ 
class Solution {
public:
    int NumberOf1Between1AndN_Solution(int n)
    {
        int res = 0;
        int a, b;
        for (int i = 1; i <= n; i *= 10) {
            a = n / i;
            b = n % i;
            res += (a + 8) / 10 * i + (a % 10 == 1) * (b + 1);
        }
        return res;
    }
};

int main() {
    Solution *so = new Solution();
    // so -> cal_C(9, 3);
    // so -> cal_C(9, 2);
    // so -> cal_C(9, 1);
    // so -> cal_C(9, 0);
    cout << so->NumberOf1Between1AndN_Solution(9999) << endl;
}