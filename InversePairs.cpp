#include<iostream>
using namespace std;
#include<vector>

/**
 * 题目描述
在数组中的两个数字，如果前面一个数字大于后面的数字，则这两个数字组成一个逆序对。
输入一个数组,求出这个数组中的逆序对的总数P。并将P对1000000007取模的结果输出。 即输出P%1000000007

 思路：
 归并排序，求交换次数
 */

class Solution {
public:
    int InversePairs(vector<int> data) {
        vector<int> temp(data);
        // cout << temp.size() << endl;
        int count = doReverse(data, temp, 0, data.size() - 1);
        return count;
    }
    // 注意此处转引用
    int doReverse(vector<int> &data, vector<int> &temp, int low, int upper) {
        if (low == upper) return 0;
        int mid = (low + upper) >> 1;
        int left_count = doReverse(data, temp, low, mid) % 1000000007;
        int right_count =  doReverse(data, temp, mid + 1, upper) % 1000000007;

        int count = 0;
        int i = mid, j = upper;
        int loc = upper;
        while (i >= low && j > mid) {
            if (data[i] > data[j]) {
                count += j - mid;
                temp[loc--] = data[i--];
                if (count > 1000000007)
                    count = count % 1000000007;
            } else {
                temp[loc--] = data[j--];
            }
        }
        for(;i >= low;i--)
            temp[loc--] = data[i];
        for(;j > mid;j--)
            temp[loc--] = data[j];
        for (int k = low; k <= upper; k++) {
            data[k] = temp[k];
        }
        return (left_count + right_count + count) % 1000000007;
    }
};

int main() {
    Solution *so = new Solution();
    // int arr[5] = {32, 31, 311}; 
    // vector<int> data(arr, arr + 3);
    int data[8] = {1, 2, 3, 4, 5, 6, 7, 0};
    vector<int> data1(data, data + 8);
    so -> InversePairs(data1);
    cout << 7 % 1000000007 << endl;
}