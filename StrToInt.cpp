#include<iostream>
#include<string>
using namespace std;
/**
 * 将一个字符串转换成一个整数，要求不能使用字符串转换整数的库函数。 数值为0或者字符串不是一个合法的数值则返回0
 */ 
class Solution {
public:
    int StrToInt(string str) {
        long long s = 1;
        if (str[0] == '-') {
            s = -1;
        }
        int i = 0;
        long long sum = 0;
        if (str[0]== '-' || str[0] == '+')
            i++;
        for (;i < str.size(); i++) {
            if (str[i] < '0' || str[i] > '9') 
                return 0;
            sum = (sum << 1) + (sum << 3) + str[i] - '0';
        }
        //处理边界
        if (sum * s >= 2147483648 || sum * s < -2147483648) {
            return 0;
        }
        return sum * s;
    }
};
int main() {
    string s = "-2147483649";
    Solution *so = new Solution();
    cout << so->StrToInt(s) << endl;
}