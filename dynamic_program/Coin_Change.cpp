//
// Created by xmly on 2020/2/21.
//
/**
You are given coins of different denominations and a total amount of money amount. Write a function
to compute the fewest number of coins that you need to make up that amount. If that amount of money
cannot be made up by any combination of the coins, return -1.

Example 1:

Input: coins = [1, 2, 5], amount = 11
Output: 3
Explanation: 11 = 5 + 5 + 1
Example 2:

Input: coins = [2], amount = 3
Output: -1
Note:
You may assume that you have an infinite number of each kind of coin.*/
#include <cstdio>
#include <vector>

using namespace std;

class Solution {
public:
    int coinChange(vector<int> &coins, int amount) {
        vector<int> dp(amount + 1, 0);
        for (int i = 1; i <= amount; i++) {
            int minCnt = INT_MAX;
            for (int coin:coins) {
                if ((i == coin) || (i > coin && dp[i - coin] > 0)) {
                    minCnt = min(minCnt, dp[i - coin]);
                }
            }
            dp[i] = minCnt == INT_MAX ? -1 : minCnt + 1;
        }
        return dp[amount];
    }
};

int main() {

}