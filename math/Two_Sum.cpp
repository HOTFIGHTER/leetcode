//
// Created by xmly on 2020/1/11.
//

/**
Given an array of integers, return indices of the two numbers such that they add up to a specific target
You may assume that each input would have exactly one solution, and you may not use the same element twice
 */

#include <cstdio>
#include <vector>
#include <iostream>
#include <map>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int> &nums, int target) {
//        vector<int> result;
//        for (int i = 0; i < nums.size(); i++) {
//            for (int j = i + 1; j < nums.size(); j++) {
//                if (nums[i] + nums[j] == target) {
//                    result.push_back(i);
//                    result.push_back(j);
//                }
//            }
//        }
//        return result;

        vector<int> result;
        map<int, int> map;
        for (int i = 0; i < nums.size(); i++) {
            map.insert(std::pair<int, int>(nums[i], i));
        }
        for (int i = 0; i < nums.size(); i++) {
            int complement = target - nums[i];
            if (map.find(complement)!=map.end() && map[complement] != i) {
                result.push_back(i);
                result.push_back(map[complement]);
                break;
            }
        }
        return result;
    }
};

int main() {
    Solution solution;
    vector<int> vector({3, 2, 3});
    solution.twoSum(vector, 6);
}