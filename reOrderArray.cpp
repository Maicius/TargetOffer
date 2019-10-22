#include<iostream>
#include<vector>
/**
 * 题目描述
输入一个整数数组，实现一个函数来调整该数组中数字的顺序，使得所有的奇数位于数组的前半部分，所有的偶数位于数组的后半部分，并保证奇数和奇数，偶数和偶数之间的相对位置不变。
 **/ 

using namespace std;
bool isOk(int n){  return ((n & 1) == 1);}
class Solution {
public:
    void reOrderArray(vector<int> &array) {
        vector<int> arr;
        for (int i=0; i < array.size(); i++){
            if (array[i] % 2 == 1) {
                arr.push_back(array[i]);
            }
        }
        for (int i=0; i < array.size(); i++){
            if (array[i] % 2 == 0) {
                arr.push_back(array[i]);
            }
        }
        array = arr;
    }
    void reOrderArray2(vector<int> &array){
        stable_partition(array.begin(),array.end(),isOk);
    }
};

int main(){
    vector<int> array;
}