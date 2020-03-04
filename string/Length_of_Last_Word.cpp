//
// Created by xmly on 2020/1/18.
//
/**
Given a string s consists of upper/lower-case alphabets and empty space characters ' ',
return the length of last word (last word means the last appearing word if we loop from left to right) in the string.

If the last word does not exist, return 0.
Note: A word is defined as a maximal substring consisting of non-space characters only.
Example:

Input: "Hello World"
Output: 5*/
#include <cstdio>
#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
    int lengthOfLastWord(string s) {
        int result = 0;
        bool isLetter = false;
        for (int i = s.length() - 1; i >= 0; i--) {
            if (s[i] == ' ' && isLetter) {
                s = s.substr(i, s.length());
                s.erase(remove(s.begin(), s.end(), ' '), s.end());
                return s.length();
            }
            if (s[i] != ' ') {
                isLetter = true;
            }
        }
        s.erase(remove(s.begin(), s.end(), ' '), s.end());
        return s.length();
    }
};

int main() {
    Solution solution;
    cout << solution.lengthOfLastWord(" a");
}