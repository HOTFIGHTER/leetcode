//
// Created by xmly on 2020/1/18.
//
/**
Given a m x n grid filled with non-negative numbers, find a path from top left to bottom
right which minimizes the sum of all numbers along its path.
Note: You can only move either down or right at any point in time.

Example:

Input:
[
[1,3,1],
[1,5,1],
[4,2,1]
]
Output: 7
Explanation: Because the path 1→3→1→1→1 minimizes the sum.
 */
#include <cstdio>
#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int minPathSum(vector<vector<int>> &grid) {
//        int width = grid.size() - 1;
//        int height = grid[0].size() - 1;
//        return minPath(grid, width, height);
        int m = grid.size();
        int n = grid[0].size();
        int dp[m][n];
        dp[0][0] = grid[0][0];
        for (int i = 1; i < m; i++) {
            dp[i][0] = dp[i - 1][0] + grid[i][0];
        }
        for (int i = 1; i < n; i++) {
            dp[0][i] = dp[0][i - 1] + grid[0][i];
        }
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + grid[i][j];
            }
        }
        return dp[m - 1][n - 1];
    }

    int minPath(vector<vector<int>> &grid, int i, int j) {
        if (i == 0 && j == 0) {
            return grid[0][0];
        }

        int down = 100000;
        if (i - 1 >= 0) {
            down = minPath(grid, i - 1, j) + grid[i][j];
        }
        int right = 100000;
        if (j - 1 >= 0) {
            right = minPath(grid, i, j - 1) + grid[i][j];
        }
        return min(down, right);
    }
};

int main() {
    vector<vector<int>> vec = {{1, 3, 1},
                               {1, 5, 1},
                               {4, 2, 1}};
    Solution solution;
    cout << solution.minPathSum(vec);
}