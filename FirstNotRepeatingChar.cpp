#include<iostream>
#include <unordered_map>
#include<map>
using namespace std;

/*
题目描述
在一个字符串(0<=字符串长度<=10000，全部由字母组成)中找到第一个只出现一次的字符,并返回它的位置, 如果没有则返回 -1（需要区分大小写）.
*
*/
class Solution {
public:
    int FirstNotRepeatingChar(string str) {
        unordered_map<char, int> map1;

        for (int i = 0; i < str.size(); i++) {
            if (map1.find(str[i]) == map1.end()) {
                map1[str[i]] = i;
            } else {
                if (map1[str[i]] != -1) {
                    map1[str[i]] = -1;
                }
            }
        }
        int index = 1000000;
        bool flag = false;
        while (map1.size() > 0) {
            if (map1.begin() -> second >= 0) {
                flag = true;
                index = min(map1.begin()->second, index);
            }
            map1.erase(map1.begin());
        }
        return flag ? index : -1;
    }
    //因为map是以红黑树实现的，map后，不能以map的迭代器遍历，必需用str[i]来遍历
    int FirstNotRepeatingChar2(string str) {
            map<char, int> mp;
            for(int i = 0; i < str.size(); ++i)
                mp[str[i]]++;
            for(int i = 0; i < str.size(); ++i){
                if(mp[str[i]]==1)
                    return i;
            }
            return -1;
        }
    };

int main() {
    Solution *so = new Solution();
    cout << so -> FirstNotRepeatingChar("google") << endl;
    cout << so -> FirstNotRepeatingChar("aaaabbb") << endl;
}