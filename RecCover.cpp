#include<iostream>

using namespace std;
/**
 * 题目描述
我们可以用2*1的小矩形横着或者竖着去覆盖更大的矩形。请问用n个2*1的小矩形无重叠地覆盖一个2*n的大矩形，总共有多少种方法？
 **/ 
class Solution {
public:
    int dp[100000] = {0, 1, 2};
    //普通递归
    int rectCover(int number) {
        if (number <= 1){
            return number;
        } else if(number == 2) {
            return 2;
        }
        else{
            return rectCover(number - 1) + rectCover(number - 2);
        }
    }
    // 动态规划
    int rectCover2(int number) {
        if (dp[number] > 0){
            return dp[number];
        }
        else{
            int temp = rectCover2(number - 1) + rectCover2(number - 2);
            dp[number] = temp;
            return temp;
        }
    }
};

int main(){
    Solution *so = new Solution();
    cout << so->dp <<endl;
    cout << so->rectCover2(7) <<endl;
}