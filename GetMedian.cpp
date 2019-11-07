#include<iostream>
#include<queue>
#include<vector>
using namespace std;
class Solution {
    priority_queue<int, vector<int>, less<int> > sh;
    priority_queue<int, vector<int>, greater<int> > bh;
public:
    void Insert(int num)
    {
        if (sh.empty() || num < sh.top()) sh.push(num);
        else bh.push(num);
        if (sh.size() == bh.size() + 2) bh.push(sh.top()), sh.pop();
        if (sh.size() == bh.size() - 1) sh.push(bh.top()), bh.pop();
    }

    double GetMedian()
    { 
        return sh.size() == bh.size() ? (sh.top() + bh.top()) / 2.0 : sh.top();
    }
};