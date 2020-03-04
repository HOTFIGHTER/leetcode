//
// Created by xmly on 2020/1/15.
//
/**Given a collection of distinct integers, return all possible permutations.
Example:
Input: [1,2,3]
Output:
[
[1,2,3],
[1,3,2],
[2,1,3],
[2,3,1],
[3,1,2],
[3,2,1]
]*/

#include <cstdio>
#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<vector<int>> permute(vector<int> &nums) {
        vector<vector<int>> vec;
        recursivePermute(nums, 0, vec);
        return vec;
    }

    void recursivePermute(vector<int> &nums, int pos, vector<vector<int>> &vec) {
        if (pos > nums.size() - 1) {
            for (int a:nums) {
                cout << a;
            }
            cout << endl;
            vec.push_back(nums);
            return;
        }
        for (int i = pos; i < nums.size(); i++) {
            swap(nums, pos, i);
            recursivePermute(nums, pos + 1, vec);
            swap(nums, pos, i);
        }
    }

    void swap(vector<int> &nums, int i, int j) {
        int temp = nums[i];
        nums[i] = nums[j];
        nums[j] = temp;
    }
};

int main(){
    vector<int> nums({1,2,3});
    Solution solution;
    solution.permute(nums);
}