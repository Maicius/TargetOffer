#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<int> FindNumbersWithSum(vector<int> array,int sum) {
        int low = 0, high = 1;
        vector<int> res;
        if (array.size() == 0)
            return res;
        int cur;
        while (low < array.size() - 2) {
            cur = array[low] + array[high];
            if (cur == sum) {
                if (res.size() > 0) {
                    int mul1 = array[low] * array[high];
                    int mul2 = res[0] * res[1];
                    if (mul1 < mul2) {
                        res.clear();
                        res.push_back(array[low]);
                        res.push_back(array[high]);
                    }
                } else {
                    res.push_back(array[low]);
                    res.push_back(array[high]);
                }
                low++;
                high = low + 1;
            }
            high++;
            if (array[high] > sum) {
                low++;
                high = low + 1;
            }
        }
        return res;
    }
};

int main() {
    int data[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    vector<int> data1(data, data + 10);
    Solution *so = new Solution();
    vector<int> res = so -> FindNumbersWithSum(data1, 10);
    for (int i = 0; i < res.size(); i++) {
        cout << res[i];
    }
}