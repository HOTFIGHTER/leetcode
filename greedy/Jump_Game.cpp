//
// Created by xmly on 2020/1/17.
//
/**
Given an array of non-negative integers, you are initially positioned at the first index of the array.
Each element in the array represents your maximum jump length at that position.
Determine if you are able to reach the last index.
Example 1:
Input: [2,3,1,1,4]
Output: true
Explanation: Jump 1 step from index 0 to 1, then 3 steps to the last index.
Example 2:

Input: [3,2,1,0,4]
Output: false
Explanation: You will always arrive at index 3 no matter what. Its maximum
jump length is 0, which makes it impossible to reach the last index.
 */
#include <csignal>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
public:
    bool canJump(vector<int> &nums) {
//        vector<bool> vec(nums.size(), false);
//        vec[nums.size() - 1] = true;
//        for (int i = nums.size() - 2; i >= 0; i--) {
//            int futherJump = 0;
//            if (nums[i] + i > nums.size() - 1) {
//                futherJump = nums.size() - 1;
//            } else {
//                futherJump = nums[i] + i;
//            }
//            for (int j = i + 1; j <= futherJump; j++) {
//                if (vec[j]) {
//                    vec[i] = true;
//                    break;
//                }
//            }
//        }
//        return vec[0];
        int lastPos = nums.size() - 1;
        for (int i = nums.size() - 1; i >= 0; i--) {
            if (i + nums[i] >= lastPos) {
                lastPos = i;
            }
        }
        return lastPos == 0;
    }
};

int main() {
    vector<int> vec(
            {8, 2, 4, 4, 4, 9, 5, 2, 5, 8, 8, 0, 8, 6, 9, 1, 1, 6, 3, 5, 1, 2, 6, 6, 0, 4, 8, 6, 0, 3, 2, 8, 7, 6, 5, 1,
             7, 0, 3, 4, 8, 3, 5, 9, 0, 4, 0, 1, 0, 5, 9, 2, 0, 7, 0, 2, 1, 0, 8, 2, 5, 1, 2, 3, 9, 7, 4, 7, 0, 0, 1, 8,
             5, 6, 7, 5, 1, 9, 9, 3, 5, 0, 7, 5});
    Solution solution;
    cout << solution.canJump(vec);
}