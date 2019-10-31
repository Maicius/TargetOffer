#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    vector<vector<int> > FindContinuousSequence(int sum) {
        vector<vector<int> > res;
        int left = 1, right = 2;
        int cur;
        
        while (right > left) {
            cur = (left + right) * (right - left + 1) / 2;
            if (cur == sum) {
                vector<int> temp;
                for (int i = left; i <= right; i++) {
                    temp.push_back(i);
                }
                left++;
                res.push_back(temp);
            } else if (cur < sum) {
                right++;
            } else {
                left++;
            }
        }
        return res;
    }
};

int main()  {
    Solution *so = new Solution();
    vector<vector<int> > res = so -> FindContinuousSequence(1000);
    for (int i = 0; i < res.size(); i++) {
        for (int j = 0; j < res[i].size(); j++) {
            std::cout << res[i][j] << " ";
        }
        cout << endl;
    }
}