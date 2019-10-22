/**
 * 题目描述
 * 用两个栈来实现一个队列，完成队列的Push和Pop操作。 队列中的元素为int类型。
 * 思路：
 * 1. 压栈时直接压入栈1
 * 2. 出栈从栈2出，每次出栈时将stack1 压入stack2
 **/
#include <iostream>
#include <stack>

using namespace std;
class Solution
{
public:
    void push(int node) {
        stack1.push(node);
    }
    int pop() {
        if (!stack2.empty()){
            int temp = stack2.top();
            stack2.pop();
            return temp;
        } else {
            while (!stack1.empty()){
                stack2.push(stack1.top());
                stack1.pop();
            }
            int temp = stack2.top();
            stack2.pop();
            return temp;
        }
    }
private:
    stack<int> stack1;
    stack<int> stack2;
};