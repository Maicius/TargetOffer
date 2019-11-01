#include<iostream>
#include<vector>
/**
 * 题目描述
给定一个数组A[0,1,...,n-1],请构建一个数组B[0,1,...,n-1],其中B中的元素B[i]=A[0]*A[1]*...*A[i-1]*A[i+1]*...*A[n-1]。不能使用除法。
 */ 
using namespace std;
class Solution {
public:
    vector<int> multiply(const vector<int>& A) {
        int n=A.size();
        vector<int> b(n);
        int ret=1;
        for(int i=0;i < n; i++){
            b[i] = ret;
            ret *= A[i];
        }
        for (int i = 0; i < 5; i++) {
            cout << b[i] << " ";
        }
        cout << endl;
        ret=1;
        for(int i=n-1; i>=0; i--){
            b[i] *= ret;
            ret *= A[i];
        }
        return b;
    }
};

int main() {
    int data[5] = {1, 2, 3, 4, 5};
    vector<int> data1(data, data + 5);
    Solution *so = new Solution();
    vector<int> res = so -> multiply(data1);
    for (int i = 0; i < 5; i++) {
        cout << res[i] << endl;
    }
}