//
// Created by xmly on 2020/2/21.
//
/**
A robot is located at the top-left corner of a m x n grid (marked 'Start' in the diagram below).

The robot can only move either down or right at any point in time. The robot is trying to reach the bottom-right
corner of the grid (marked 'Finish' in the diagram below).

Now consider if some obstacles are added to the grids. How many unique paths would there be?
An obstacle and empty space is marked as 1 and 0 respectively in the grid.

Note: m and n will be at most 100.

Example 1:

Input:
[
[0,0,0],
[0,1,0],
[0,0,0]
]
Output: 2
Explanation:
There is one obstacle in the middle of the 3x3 grid above.
There are two ways to reach the bottom-right corner:
1. Right -> Right -> Down -> Down
2. Down -> Down -> Right -> Right*/

#include <cstdio>
#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<long> vec(m * n, 0);
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (obstacleGrid[i][j] == 0) {
                    if (i == 0 && j == 0) {
                        vec[0] = 1;
                    }
                    if (i > 0) {
                        vec[i * n + j] = vec[(i - 1) * n + j];
                    }
                    if (j > 0) {
                        vec[i * n + j] = vec[i * n + j] + vec[i * n + j - 1];
                    }
                }
            }
        }
        return vec[m * n - 1];
    }
};

int main() {
    vector<vector<int>> obstacleGrid({{0},{0}});
    Solution solution;
    cout << solution.uniquePathsWithObstacles(obstacleGrid) << endl;
}