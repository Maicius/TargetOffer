#include<iostream>
#include<string.h>
using namespace std;

class Solution {
public:
    int Fibonacci(int n) {
        int pre = 0, curr = 1;
        while (n--){
            curr = curr + pre;
            pre = curr - pre;
        }
        return pre;
    }
     int Fibonacci2(int n) {
        if (n <= 1) {
            return n;
        } else {
            return Fibonacci(n - 1) + Fibonacci(n - 2);
        }
    }
};
int main(){
    Solution *so = new Solution();
    cout << 2 << endl;
    cout << so->Fibonacci2(39) << endl;
}