#include <iostream>
#include <stack>
using namespace std;
/**
 * 题目描述
定义栈的数据结构，请在该类型中实现一个能够得到栈中所含最小元素的min函数（时间复杂度应为O（1））。
 */ 
class Solution {
public:
     
    stack<int> stack1,stack2;
    void push(int value) {
        stack1.push(value);
        if(stack2.empty())
            stack2.push(value);
        else if(value <= stack2.top())
            stack2.push(value);
    }
     
    void pop() {
        if(stack1.top() == stack2.top())
            stack2.pop();
        stack1.pop();
    }
     
    int top() {
        return stack1.top();       
    }
     
    int min() {
        return stack2.top();
    }
     
};