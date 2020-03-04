//
// Created by xmly on 2020/2/23.
//
/**
Given a column title as appear in an Excel sheet, return its corresponding column number.

For example:

A -> 1
B -> 2
C -> 3
...
Z -> 26
AA -> 27
AB -> 28
...
Example 1:

Input: "A"
Output: 1
Example 2:

Input: "AB"
Output: 28
Example 3:

Input: "ZY"
Output: 701*/
#include <cstdio>
#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
    int titleToNumber(string s) {
        long base = 1;
        int number = 0;
        int size = s.size();
        for (int i = size - 1; i >= 0; i--) {
            number += (s[i] - 'A' + 1) * base;
            base *= 26;
        }
        return number;
    }
};

int main() {
     Solution solution;
     cout<<solution.titleToNumber("AB");
}