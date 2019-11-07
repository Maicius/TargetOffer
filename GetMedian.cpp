#include<iostream>
#include<queue>
#include<vector>
using namespace std;
/**
 * 题目描述
如何得到一个数据流中的中位数？如果从数据流中读出奇数个数值，那么中位数就是所有数值排序之后位于中间的数值。
如果从数据流中读出偶数个数值，那么中位数就是所有数值排序之后中间两个数的平均值。我们使用Insert()方法读取数据流，使用GetMedian()方法获取当前读取数据的中位数。
 */ 
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