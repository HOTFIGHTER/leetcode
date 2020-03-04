//
// Created by xmly on 2020/1/20.
//
/**
Given a matrix of m x n elements (m rows, n columns), return all elements of the matrix in spiral order.
Example 1:

Input:
[
[ 1, 2, 3 ],
[ 4, 5, 6 ],
[ 7, 8, 9 ]
]
Output: [1,2,3,6,9,8,7,4,5]
Example 2:

Input:
[
[1, 2, 3, 4],
[5, 6, 7, 8],
[9,10,11,12]
]
Output: [1,2,3,4,8,12,11,10,9,5,6,7]
 */
#include <cstdio>
#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>> &matrix) {
        vector<int> result;
        if (matrix.empty()) {
            return result;
        }
        int n = matrix[0].size();
        int m = matrix.size();
        result.push_back(matrix[0][0]);
        matrix[0][0] = -1000000;
        for (int i = 1, dir = 'r', r = 0, c = 0, e = m * n; i < e; ++i) {
            switch (dir) {
                case 'r':
                    if (c + 1 >= n || matrix[r][c + 1] == -1000000) {
                        dir = 'd';
                        i--;
                    } else {
                        c++;
                        result.push_back(matrix[r][c]);
                        matrix[r][c] =-1000000;
                    }
                    break;
                case 'l':
                    if (c - 1 < 0 || matrix[r][c - 1] == -1000000) {
                        dir = 'u';
                        i--;
                    } else {
                        c--;
                        result.push_back(matrix[r][c]);
                        matrix[r][c] = -1000000;
                    }
                    break;
                case 'd':
                    if (r + 1 >= m || matrix[r + 1][c] == -1000000) {
                        dir = 'l';
                        i--;
                    } else {
                        r++;
                        result.push_back(matrix[r][c]);
                        matrix[r][c] = -1000000;
                    }
                    break;
                case 'u':
                    if (r - 1 < 0 || matrix[r - 1][c] == -1000000) {
                        dir = 'r';
                        i--;
                    } else {
                        r--;
                        result.push_back(matrix[r][c]);
                        matrix[r][c] = -1000000;
                    }
                    break;
            }
        }
        return result;
    }
};

int main() {
    vector<vector<int>> matrix({});
    Solution solution;
    solution.spiralOrder(matrix);
}