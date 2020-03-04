//
// Created by xmly on 2020/2/23.
//
/**
Given a set of candidate numbers (candidates) (without duplicates) and a target number (target),
find all unique combinations in candidates where the candidate numbers sums to target.

The same repeated number may be chosen from candidates unlimited number of times.

Note:

All numbers (including target) will be positive integers.
The solution set must not contain duplicate combinations.
Example 1:

Input: candidates = [2,3,6,7], target = 7,
        A solution set is:
[
[7],
[2,2,3]
]
Example 2:

Input: candidates = [2,3,5], target = 8,
        A solution set is:
[
[2,2,2,2],
[2,3,3],
[3,5]
]*/
#include <cstdio>
#include <vector>

using namespace std;

class Solution {
public:
    void createCombinations(vector<vector<int>> &out, vector<int> &candidates, int start, int target, int currSum,
                            vector<int> &path) {
        if (target == currSum) {
            out.push_back(path);
            return;
        }
        for (int i = start; i < candidates.size(); i++) {
            if (currSum + candidates[i] <= target) {
                path.push_back(candidates[i]);
                createCombinations(out,candidates,i,target,currSum+candidates[i],path);
                path.pop_back();
            }
        }
        return;
    }

    vector<vector<int>> combinationSum(vector<int> &candidates, int target) {
        if (candidates.empty()) return {};
        vector<vector<int>> out;
        vector<int> path;
        createCombinations(out, candidates, 0, target, 0, path);
        return out;
    }
};

int main() {

}