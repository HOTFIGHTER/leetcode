//
// Created by xmly on 2020/1/11.
//
/**
Given n non-negative integers a1, a2, ..., an , where each represents a point at coordinate (i, ai).
n vertical lines are drawn such that the two endpoints of line i is at (i, ai) and (i, 0).
Find two lines, which together with x-axis forms a container, such that the container contains the most water.
 */
#include <cstdio>
#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int maxArea(vector<int> &height) {
        int max = 0;
        int left = 0;
        int right = height.size() - 1;
        while (left < right) {
            if (height[left] < height[right]) {
                int leftMax = (right - left) * height[left];
                if (leftMax > max) {
                    max = leftMax;
                }
                left++;
            } else {
                int rightMax = (right - left) * height[right];
                if (rightMax > max) {
                    max = rightMax;
                }
                right--;
            }
        }
        return max;
    }
};


int main() {
    vector<int> vector({1, 8, 6, 2, 5, 4, 8, 3, 7});
    Solution solution;
    cout << solution.maxArea(vector) << endl;

}