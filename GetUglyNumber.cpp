#include<iostream>
#include<vector>

#include<algorithm>
using namespace std;

class Solution {
public:
    int GetUglyNumber_Solution(int index) {
        if (index < 7) return index;
        int p2 = 0, p3=0, p5=0, num = 1;
        vector<int> res;
        res.push_back(num);
        while (res.size() < index) {
            num = min(res[p2] * 2, min(res[p3] * 3, res[p5] * 5));
            if (res[p2]*2 == num) p2++;
            if (res[p3]*3 == num) p3++;
            if (res[p5]*5 == num) p5++;
            res.push_back(num);
        }
        return res.back();
    }
};