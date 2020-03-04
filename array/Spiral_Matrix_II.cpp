//
// Created by xmly on 2020/1/19.
//

/**
Given a positive integer n, generate a square matrix filled with elements from 1 to n2 in spiral order.
Example:

Input: 3
Output:
[
[ 1, 2, 3 ],
[ 8, 9, 4 ],
[ 7, 6, 5 ]
]
 */
#include <cstdio>
#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> result(n, vector<int>(n, 0));
        for(int i = 1, dir = 'r', r = 0, c = 0, e = n * n; i <= e; ++i){
            result[r][c] = i;
            switch(dir){
                case 'r': if(c + 1 >= n || result[r][c+1] != 0){ ++r; dir = 'd'; }else{ ++c; } break;
                case 'l': if(c - 1 <  0 || result[r][c-1] != 0){ --r; dir = 'u'; }else{ --c; } break;
                case 'd': if(r + 1 >= n || result[r+1][c] != 0){ --c; dir = 'l'; }else{ ++r; } break;
                case 'u': if(r - 1 <  0 || result[r-1][c] != 0){ ++c; dir = 'r'; }else{ --r; } break;
            }
        }
        return result;
    }
};

int main() {
    Solution solution;
    solution.generateMatrix(2);
}