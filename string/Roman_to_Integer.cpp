//
// Created by xmly on 2020/1/11.
//
/**
For example, two is written as II in Roman numeral, just two one's added together. Twelve is written as, XII,
which is simply X + II. The number twenty seven is written as XXVII, which is XX + V + II.

Roman numerals are usually written largest to smallest from left to right. However, the numeral for four is
not IIII. Instead, the number four is written as IV. Because the one is before the five we subtract it making four.
The same principle applies to the number nine, which is written as IX. There are six instances where subtraction is used:

I can be placed before V (5) and X (10) to make 4 and 9.
X can be placed before L (50) and C (100) to make 40 and 90.
C can be placed before D (500) and M (1000) to make 400 and 900.
Given a roman numeral, convert it to an integer. Input is guaranteed to be within the range from 1 to 3999.
*/
#include <cstdio>
#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
    int romanToInt(string s) {
        int total = 0;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == 'I') {
                if (i + 1 < s.length() && (s[i + 1] == 'V' || s[i + 1] == 'X')) {
                    if (s[i + 1] == 'V') {
                        total += 4;
                        i++;
                    } else if (s[i + 1] == 'X') {
                        total += 9;
                        i++;
                    }
                } else {
                    total++;
                }
            } else if (s[i] == 'X') {
                if (i + 1 < s.length() && (s[i + 1] == 'L' || s[i + 1] == 'C')) {
                    if (s[i + 1] == 'L') {
                        total += 40;
                        i++;
                    } else if (s[i + 1] == 'C') {
                        total += 90;
                        i++;
                    }
                } else {
                    total += 10;
                }
            } else if (s[i] == 'C') {
                if (i + 1 < s.length() && (s[i + 1] == 'D' || s[i + 1] == 'M')) {
                    if (s[i + 1] == 'D') {
                        total += 400;
                        i++;
                    } else if (s[i + 1] == 'M') {
                        total += 900;
                        i++;
                    }
                } else {
                    total += 100;
                }
            } else if (s[i] == 'V') {
                total += 5;
            } else if (s[i] == 'L') {
                total += 50;
            } else if (s[i] == 'D') {
                total += 500;
            } else if (s[i] == 'M') {
                total += 1000;
            }
        }
        return total;
    }
};

int main() {
    string s = "MCMXCIV";
    Solution solution;
    cout << solution.romanToInt(s) << endl;

}