//
// Created by xmly on 2020/2/28.
//
/**
Write an algorithm to determine if a number is "happy".

A happy number is a number defined by the following process: Starting with any positive integer,
replace the number by the sum of the squares of its digits, and repeat the process until the number
equals 1 (where it will stay), or it loops endlessly in a cycle which does not include 1.
Those numbers for which this process ends in 1 are happy numbers.

Example:

Input: 19
Output: true
Explanation:
12 + 92 = 82
82 + 22 = 68
62 + 82 = 100
12 + 02 + 02 = 1
 */
#include <cstdio>
#include <iostream>

using namespace std;

class Solution {
public:
    bool isHappy(int n) {
        int sum = 0;
        int cnt = 0;

        while(true) {
            std::string s = std::to_string(n);
            for(size_t i = 0; i < s.size(); i++) {
                sum += (s[i] - '0') * (s[i] - '0');
            }
            if(sum == 1) return true;
            n = sum;
            sum = 0;
            cnt++;
            if(cnt > 10) return false;
        }
    }
};

int main() {
    Solution solution;
    cout << solution.isHappy(7);
}