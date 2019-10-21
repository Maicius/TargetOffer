#include<iostream>
using namespace std;

//题目描述
//请实现一个函数，将一个字符串中的每个空格替换成“%20”。例如，当字符串为We Are Happy.则经过替换之后的字符串为We%20Are%20Happy。
// 重点，从后往前替换
class Solution {
public:
	void replaceSpace(char *str,int length) {
        auto count = 0;
        for(int i = 0;i < length; i++){
            if(str[i] == ' '){
                count++;
            }
        }
        for(int i = length-1; i>=0; i--){
            if(str[i] != ' '){
                str[i + 2*count]=str[i];
            }
            else{
                count--;
                str[i+2*count]='%';
                str[i+2*count+1]='2';
                str[i+2*count+2]='0';
            }
        }
	}
};