//
// Created by xmly on 2020/1/12.
//
/**
Given an integer array nums, find the contiguous subarray (containing at least one number)
which has the largest sum and return its sum.

Example:
Input: [-2,1,-3,4,-1,2,1,-5,4],
Output: 6
Explanation: [4,-1,2,1] has the largest sum = 6.
Follow up:

If you have figured out the O(n) solution, try coding another solution using the divide and
conquer approach, which is more subtle.
 */
#include <cstdio>
#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int maxSubArray(vector<int> &nums) {
        int max[nums.size()];
        max[0] = nums[0];
        int total = max[0];
        for (int i = 1; i < nums.size(); i++) {
            nums[i] > max[i - 1] + nums[i] ? (max[i] = nums[i]) :
            (max[i] = max[i - 1] + nums[i]);
            if (max[i] > total) {
                total = max[i];
            }
        }
        return total;
    }
};

int main() {
    vector<int> nums({-2,1,-3,4,-1,2,1,-5,4});
    Solution solution;
    cout<< solution.maxSubArray(nums)<<endl;
}