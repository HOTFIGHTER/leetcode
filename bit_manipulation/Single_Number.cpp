//
// Created by xmly on 2020/2/19.
//
/**
Given a non-empty array of integers, every element appears twice except for one. Find that single one.

Note:

Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?

Example 1:

Input: [2,2,1]
Output: 1
Example 2:

Input: [4,1,2,1,2]
Output: 4*/
#include <cstdio>
#include <vector>
#include <unordered_map>
#include <map>

using namespace std;

class Solution {
public:
    int singleNumber(vector<int> &nums) {
        unordered_map<int, int> map;
        for (int i = 0; i < nums.size(); i++) {
            map[nums[i]]++;
        }
        unordered_map<int, int>::iterator it = map.begin();
        while (it != map.end()) {
            if (it->second == 1) {
                return it->first;
            }
            it++;
        }
        return 0;
    }
};