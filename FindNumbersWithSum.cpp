#include<iostream>
#include<vector>
using namespace std;
typedef vector<int> vi;
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

/**
数列满足递增，设两个头尾两个指针i和j，
若ai + aj == sum，就是答案（相差越远乘积越小）
若ai + aj > sum，aj肯定不是答案之一（前面已得出 i 前面的数已是不可能），j -= 1
若ai + aj < sum，ai肯定不是答案之一（前面已得出 j 后面的数已是不可能），i += 1
 */
    vi FindNumbersWithSum2(const vi& a,int sum) {
            vi res;
            int n = a.size();
            int i = 0, j = n - 1;
            while(i < j){
                if(a[i] + a[j] == sum){
                    res.push_back(a[i]);
                    res.push_back(a[j]);
                    break;
                }
                while(i < j && a[i] + a[j] > sum) --j;
                while(i < j && a[i] + a[j] < sum) ++i;
            }
            return res;
        }
    };

int main() {
    int data[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    vector<int> data1(data, data + 10);
    Solution *so = new Solution();
    vector<int> res = so -> FindNumbersWithSum2(data1, 10);
    for (int i = 0; i < res.size(); i++) {
        cout << res[i];
    }
}