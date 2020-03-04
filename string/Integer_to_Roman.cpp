//
// Created by xmly on 2020/1/13.
//
/**
 For example, two is written as II in Roman numeral, just two one's added together. Twelve is written as,
XII, which is simply X + II. The number twenty seven is written as XXVII, which is XX + V + II.

Roman numerals are usually written largest to smallest from left to right. However, the numeral for
four is not IIII. Instead, the number four is written as IV. Because the one is before the five we
subtract it making four. The same principle applies to the number nine, which is written as IX.
There are six instances where subtraction is used:

I can be placed before V (5) and X (10) to make 4 and 9.
X can be placed before L (50) and C (100) to make 40 and 90.
C can be placed before D (500) and M (1000) to make 400 and 900.
Given an integer, convert it to a roman numeral. Input is guaranteed to be within the range from 1 to 3999.
 */
#include <cstdio>
#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
    string intToRoman(int num) {
        string s;
        while (num > 0) {
            if (num >= 1000) {
                s.push_back('M');
                num -= 1000;
                continue;
            }
            if (num >= 900) {
                s.push_back('C');
                s.push_back('M');
                num -= 900;
                continue;
            }
            if (num >= 500) {
                s.push_back('D');
                num -= 500;
                continue;
            }
            if (num >= 400) {
                s.push_back('C');
                s.push_back('D');
                num -= 400;
                continue;
            }
            if (num >= 100) {
                s.push_back('C');
                num -= 100;
                continue;
            }
            if (num >= 90) {
                s.push_back('X');
                s.push_back('C');
                num -= 90;
                continue;
            }
            if (num >= 50) {
                s.push_back('L');
                num -= 50;
                continue;
            }
            if (num >= 40) {
                s.push_back('X');
                s.push_back('L');
                num -= 40;
                continue;
            }
            if (num >= 10) {
                s.push_back('X');
                num -= 10;
                continue;
            }
            if (num >= 9) {
                s.push_back('I');
                s.push_back('X');
                num -= 9;
                continue;
            }
            if (num >= 5) {
                s.push_back('V');
                num -= 5;
                continue;
            }
            if (num >= 4) {
                s.push_back('I');
                s.push_back('V');
                num -= 4;
                continue;
            }
            s.push_back('I');
            num -= 1;
        }
        return s;
    }
};

int main(){
    Solution solution;
    cout<<solution.intToRoman(1994);
}