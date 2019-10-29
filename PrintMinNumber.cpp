#include<iostream>
#include<vector>
#include<string.h>
using namespace std;

class Solution {
public:
    string PrintMinNumber(vector<int> numbers) {
        sort(numbers.begin(), numbers.end(), cmp);
        string res = "";
        for (int i = 0; i < numbers.size(); i++) {
            res += to_string(numbers[i]);
        }
        cout << res << endl;
        return res;
    }
    
    static bool cmp(int a, int b) {
        string A = "";
        string B = "";
        
        A = to_string(a) + to_string(b);
        B = to_string(b) + to_string(a);
        
        return A < B;
    }
};

int main() {
    Solution *so = new Solution();
    int arr[5] = {32, 31, 311}; 
    vector<int> data(arr, arr + 3);
    so -> PrintMinNumber(data);
}