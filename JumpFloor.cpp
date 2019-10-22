#include<iostream>
#include<string.h>
using namespace std;
//一只青蛙一次可以跳上1级台阶，也可以跳上2级。求该青蛙跳上一个n级的台阶总共有多少种跳法（先后次序不同算不同的结果）。
class Solution {
public:
    int jumpFloor(int n) {
        if (n <= 3){
            return n;
        }else{
            return jumpFloor(n - 1) + jumpFloor(n - 2);
        }
    }
    int jumpFloor2(int n) {
        int pre = 1, curr = 2;
        int i = 0;
        while (i < n - 2) {
            curr = curr + pre;
            pre = curr - pre;
            i++;
        }
        return curr;
    }
};
int main(){
    Solution *so = new Solution();
    cout << 2 << endl;
    cout << so->jumpFloor2(39) << endl;
}