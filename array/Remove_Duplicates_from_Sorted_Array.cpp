//
// Created by xmly on 2020/1/16.
//

/**
Given a sorted array nums, remove the duplicates in-place such that each element appear only once and return the new length.
Do not allocate extra space for another array, you must do this by modifying the input array in-place with O(1) extra memory.
Example 1:
Given nums = [1,1,2],
Your function should return length = 2, with the first two elements of nums being 1 and 2 respectively.
It doesn't matter what you leave beyond the returned length.
Example 2:
Given nums = [0,0,1,1,1,2,2,3,3,4],
Your function should return length = 5, with the first five elements of nums being modified to 0, 1, 2, 3, and 4 respectively.
It doesn't matter what values are set beyond the returned length.
*/
#include <cstdio>
#include <vector>
#include <map>
#include <iostream>

using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int> &nums) {
//        map<int, int> map;
//        for (int i = 1; i < nums.size(); i++) {
//            if (map.find(nums[i]) != map.end()) {
//                nums.erase(nums.begin() + i);
//                i--;
//            } else {
//                map.insert(std::pair<int,int>(nums[i], 1));
//            }
//        }
//        return nums.size();
        /**unique选择重复地址至最后，但不会删除返回重复元素首地址，erase执行最后删除*/
        nums.erase(std::unique(nums.begin(), nums.end()), nums.end());
        return nums.size();
    }
};

int main() {
    vector<int> nums({0,0,1,1,1,2,2,3,3,4});
    Solution solution;
    cout<<solution.removeDuplicates(nums);
}