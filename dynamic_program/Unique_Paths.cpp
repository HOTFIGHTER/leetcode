//
// Created by xmly on 2020/1/12.
//
/**
A robot is located at the top-left corner of a m x n grid (marked 'Start' in the diagram below).
The robot can only move either down or right at any point in time. The robot is trying to reach
the bottom-right corner of the grid (marked 'Finish' in the diagram below).
How many possible unique paths are there?
 */

#include <cstdio>
#include <iostream>

using namespace std;
class Solution {
public:
    int uniquePaths(int m, int n) {
        int path[m][n];
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (i == 0 && j == 0) {
                    path[i][j] = 1;
                } else {
                    path[i][j] = 0;
                }
                if (j > 0) {
                    path[i][j] += path[i][j - 1];
                }
                if (i > 0) {
                    path[i][j] += path[i - 1][j];
                }
            }
        }
        return path[m - 1][n - 1];
    }
};


int main(){
    Solution solution;
    cout<<solution.uniquePaths(3,2);
}