//
// Created by xmly on 2020/1/12.
//
/**
Given two arrays, write a function to compute their intersection.

Example 1:

Input: nums1 = [1,2,2,1], nums2 = [2,2]
Output: [2]
Example 2:

Input: nums1 = [4,9,5], nums2 = [9,4,9,8,4]
Output: [9,4]
 */
#include <cstdio>
#include <vector>
#include <iostream>
#include <map>
#include <set>

using namespace std;

class Solution {
public:
    vector<int> intersection(vector<int> &nums1, vector<int> &nums2) {
        map<int, int> map;
        vector<int> vec;
        for (int num:nums1) {
            map.insert(std::pair<int, int>(num, num));
        }
        for (int num:nums2) {
            if (map.find(num) != map.end()) {
                vec.push_back(map[num]);
            }
        }
        set<int> st(vec.begin(), vec.end());
        vec.assign(st.begin(), st.end());
        return vec;
    }
};

int main() {
    vector<int> num1({1, 2, 2, 1});
    vector<int> num2({2, 2});
    Solution solution;
    solution.intersection(num1, num2);
}