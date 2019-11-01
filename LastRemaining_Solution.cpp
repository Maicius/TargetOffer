#include<iostream>
using namespace std;

class Solution {
public:
    int LastRemaining_Solution(int n, int m)
    {
        if (n == 0) 
            return -1;
        int data[1000] = {0};
        int count = n, i = -1, step = 0;
        while (count > 0) {
            i++;
            if (i >= n)
                i = 0;
            if (data[i] == -1)
                continue;
            step++;
            if (step == m) {
                data[i] = -1;
                step = 0;
                count--;
            }
        }
        return i;
    }
    // http://zhedahht.blog.163.com/blog/static/2541117420072250322938/
    int LastRemaining_Solution2(int n, int m) {
        if (n ==0) return -1;
        if (n == 1) return 0;
        return (LastRemaining_Solution2(n - 1, m) + m) % n;
    }
};