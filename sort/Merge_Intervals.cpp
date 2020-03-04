//
// Created by xmly on 2020/2/23.
//
/**
Given a collection of intervals, merge all overlapping intervals.

Example 1:

Input: [[1,3],[2,6],[8,10],[15,18]]
Output: [[1,6],[8,10],[15,18]]
Explanation: Since intervals [1,3] and [2,6] overlaps, merge them into [1,6].
Example 2:

Input: [[1,4],[4,5]]
Output: [[1,5]]
Explanation: Intervals [1,4] and [4,5] are considered overlapping.
NOTE: input types have been changed on April 15, 2019. Please reset to
default code definition to get new method signature.*/
#include <cstdio>
#include <vector>

using namespace std;

class Solution {
public:
    struct comp {
        bool operator()(const vector<int>& lhs, const vector<int>& rhs) {
            return(lhs[0] < rhs[0]);
        }
    };

    vector<vector<int>> merge(vector<vector<int>> &intervals) {
        if (intervals.empty()) return intervals;
        sort(intervals.begin(), intervals.end(), comp());
        vector<vector<int>> ans({intervals[0]});
        for (int i = 1; i < intervals.size(); ++i) {
            if (intervals[i][0] <= ans[ans.size() - 1][1]) {
                ans[ans.size() - 1][1] = max(intervals[i][1], ans[ans.size() - 1][1]);
            } else {
                ans.push_back(intervals[i]);
            }
        }

        return ans;
    }
};

int main() {

}