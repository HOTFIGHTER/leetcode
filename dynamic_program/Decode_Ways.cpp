//
// Created by xmly on 2020/2/2.
//
/**
A message containing letters from A-Z is being encoded to numbers using the following mapping:

'A' -> 1
'B' -> 2
...
'Z' -> 26
Given a non-empty string containing only digits, determine the total number of ways to decode it.

Example 1:

Input: "12"
Output: 2
Explanation: It could be decoded as "AB" (1 2) or "L" (12).
Example 2:

Input: "226"
Output: 3
Explanation: It could be decoded as "BZ" (2 26), "VF" (22 6), or "BBF" (2 2 6).
*/
#include <cstdio>
#include <string>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int numDecodings(string s) {
//        int sum = 0;
//        int i = s.size() - 1;
//        if (i < 0) {
//            return 1;
//        }
//        if (i >= 0) {
//            char c = s[i];
//            if (c <= '9' && c >= '1') {
//                string subStr1 = s.substr(0, i);
//                sum += numDecodings(subStr1);
//            }
//        }
//        if (i > 0) {
//            string subStr2 = s.substr(i - 1, 2);
//            int value = atoi(subStr2.c_str());
//            if (value <= 26 && value >= 10) {
//                string subStr3 = s.substr(0, i - 1);
//                sum += numDecodings(subStr3);
//            }
//        }
//        return sum;
        if (s.empty() || s[0] == '0') return 0;
        vector<int> dp(s.size() + 1, 0);
        dp[0] = 1;
        for (int i = 1; i < dp.size(); ++i) {
            dp[i] = (s[i - 1] == '0') ? 0 : dp[i - 1];
            if (i > 1 && (s[i - 2] == '1' || (s[i - 2] == '2' && s[i - 1] <= '6'))) {
                dp[i] += dp[i - 2];
            }
        }
        return dp.back();
    }
};

int main() {
    string s = "226";
    Solution solution;
    cout << solution.numDecodings(s);
}