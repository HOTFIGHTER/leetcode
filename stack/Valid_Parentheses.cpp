//
// Created by xmly on 2020/1/8.
//
/**
 * Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.
  An input string is valid if:
  Open brackets must be closed by the same type of brackets.
  Open brackets must be closed in the correct order.*/
#include <csignal>
#include <string>
#include <stack>
#include <iostream>

using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> stack;
        for (char i:s) {
            if (stack.size() > 0 && i == ')' && stack.top() == '(') {
                stack.pop();
            } else if (stack.size() > 0 && i == '}' && stack.top() == '{') {
                stack.pop();
            } else if (stack.size() > 0 && i == ']' && stack.top() == '[') {
                stack.pop();
            } else {
                stack.push(i);
            }
        }
        return stack.empty();
    }
};

int main() {
    Solution solution;
    cout << "isvalid:" << boolalpha << solution.isValid("]") << endl;
}