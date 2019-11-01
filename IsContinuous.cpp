#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    bool IsContinuous( vector<int> numbers ) {
        if (numbers.size() == 1)
            return true;
        if (numbers.size() == 0)
            return false;
        for (int i = 1; i < numbers.size(); i++) {
            for (int j = i - 1; j >= 0 && numbers[j] > numbers[j + 1]; j--) {
                int temp = numbers[j + 1];
                numbers[j + 1] = numbers[j];
                numbers[j] = temp;
            }
        }
        int count = 0;
        bool flag = false;
        for (int i = 0; i < numbers.size() - 1; i++) {
            if (numbers[i] == 0) {
                count++;
            } else {
                flag = true;
            }
            if (flag) {
                int temp = numbers[i + 1] - numbers[i] - 1;
                count -= temp;
                if (count < 0) {
                    return false;
                }
            }
        }
        return true;
    }

    // 牌数固定为5张，max - min 不超过5
    bool IsContinuous2( vector<int> numbers ) {
        if (numbers.size() == 1)
            return true;
        if (numbers.size() == 0)
            return false;
        int data[14] = {0};
        data[0] = -5;
        int max = -1, min = 14;
        for (int i = 0; i < numbers.size(); i++) {
            data[numbers[i]]++;
            if (numbers[i] == 0)
                continue;
            if (data[numbers[i]] > 1)
                return false;
            if (numbers[i] > max) {
                max = numbers[i];
            }
            if (numbers[i] < min) {
                min = numbers[i];
            }
        }
        cout << max << min << endl;
        return max - min < 5 ? true : false;
    }
};

int  main() {
    int data[5] = {1, 3, 2, 5, 4};
    vector<int> data1(data, data + 5);
    Solution *so = new Solution();
    cout << so->IsContinuous2(data1) <<endl;
}