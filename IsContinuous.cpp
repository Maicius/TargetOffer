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
};

int  main() {
    int data[6] = {8, 7, 4, 6, 0, 0};
    vector<int> data1(data, data + 6);
    Solution *so = new Solution();
    cout << so->IsContinuous(data1) <<endl;
}