//
// Created by xmly on 2020/2/21.
//

/**
Given a positive integer n, break it into the sum of at least two positive integers and
maximize the product of those integers. Return the maximum product you can get.

Example 1:

Input: 2
Output: 1
Explanation: 2 = 1 + 1, 1 × 1 = 1.
Example 2:

Input: 10
Output: 36
Explanation: 10 = 3 + 3 + 4, 3 × 3 × 4 = 36.
Note: You may assume that n is not less than 2 and not larger than 58.*/

#include <cstdio>
#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int integerBreak(int n) {
        if (n == 1) {
            return 1;
        } else if (n == 2) {
            return 1;
        }
        vector<int> dp(n + 1, 1);
        for (int i = 2; i <= n; i++) {
            int maxCount = 1;
            for (int j = 1; j < i; j++) {
                maxCount = max(maxCount, max(j,dp[j]) * max(i-j,dp[i - j]));
            }
            cout<<i<<" "<<maxCount<<endl;
            dp[i] = maxCount;
        }
        return dp[n];
    }
};

int main() {
    Solution solution;
    cout<<solution.integerBreak(11)<<endl;
}