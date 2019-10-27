#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    vector<string> Permutation(string str) {
        vector<string> res;
        if(str.empty()) return res;
        Permutation(res, str, 0);
        sort(res.begin(), res.end());
        return res;
        
    }
    void Permutation(vector<string> &res, string str, int begin) {
        if (begin == str.size() - 1) {
            if (find(res.begin(), res.end(), str) == res.end())
                res.push_back(str);
        }
        else {
            for (int i = begin; i < str.size(); i++) {
                swap(str[i], str[begin]);
                Permutation(res, str, begin + 1);
                swap(str[i], str[begin]);
            }
        }
    }
    
    void swap(char &a, char &b) {
        char temp = a;
        a = b;
        b = temp;
    }
};