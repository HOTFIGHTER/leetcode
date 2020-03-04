//
// Created by xmly on 2020/1/15.
//
/**
You are given an n x n 2D matrix representing an image.
Rotate the image by 90 degrees (clockwise).
Note:
You have to rotate the image in-place, which means you have to modify
the input 2D matrix directly. DO NOT allocate another 2D matrix and do the rotation.
*/
#include <cstdio>
#include <vector>

using namespace std;

class Solution {
public:
    void rotate(vector<vector<int>> &matrix) {
        int width = matrix[0].size();
        vector<std::vector<int> > vec(width, vector<int>(width, 0));
        for (int i = 0; i < width; i++) {
            for (int j = 0; j < width; j++) {
                vec[i][j] = matrix[width - j - 1][i];
            }
        }
        matrix = vec;
    }
};

int main() {
    Solution solution;
}