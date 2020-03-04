//
// Created by xmly on 2020/1/19.
//

/**
Given a sorted array and a target value, return the index if the target is found. If not,
return the index where it would be if it were inserted in order.

You may assume no duplicates in the array.

Example 1:

Input: [1,3,5,6], 5
Output: 2
Example 2:

Input: [1,3,5,6], 2
Output: 1
Example 3:

Input: [1,3,5,6], 7
Output: 4
Example 4:

Input: [1,3,5,6], 0
Output: 0
 */

#include <cstdio>
#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int searchInsert(vector<int> &nums, int target) {
        int left = 0;
        int right = nums.size() - 1;
        if(target>nums[right]){
            return nums.size();
        }
        if(target<nums[0]){
            return 0;
        }
        while (right>left) {
            int middle = (left + right) / 2;
            if (nums[middle] < target) {
                left = middle+1;
            } else {
                right = middle;
            }
        }
        return left;
    }
};

int main() {
    vector<int> vec({1, 3, 5, 6});
    Solution solution;
    cout << solution.searchInsert(vec, 5);
}