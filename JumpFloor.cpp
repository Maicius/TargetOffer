#include<iostream>
#include<string.h>
using namespace std;

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