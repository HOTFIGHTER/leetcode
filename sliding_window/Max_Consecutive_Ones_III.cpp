//
// Created by xmly on 2020/2/18.
//
/**
Given an array A of 0s and 1s, we may change up to K values from 0 to 1.

Return the length of the longest (contiguous) subarray that contains only 1s.

Example 1:

Input: A = [1,1,1,0,0,0,1,1,1,1,0], K = 2
Output: 6
Explanation:
[1,1,1,0,0,1,1,1,1,1,1]
Bolded numbers were flipped from 0 to 1.  The longest subarray is underlined.
Example 2:

Input: A = [0,0,1,1,0,0,1,1,1,0,1,1,0,0,0,1,1,1,1], K = 3
Output: 10
Explanation:
[0,0,1,1,1,1,1,1,1,1,1,1,0,0,0,1,1,1,1]
Bolded numbers were flipped from 0 to 1.  The longest subarray is underlined.*/
#include <cstdio>
#include <vector>
#include <unordered_map>
#include <iostream>

using namespace std;

class Solution {
public:
    int longestOnes(vector<int> &A, int K) {
        unordered_map<int, int> count;
        int i = 0, j = 0, res = 0, maxCout = 0;
        while (i < A.size()) {
            if (A[i] == 1) {
                ++count[A[i]];
            }
            maxCout = max(maxCout, count[A[i]]);
            i++;
            if (i - j - maxCout > K) {
                --count[A[j++]];
            }
            res = max(res, i - j);
        }
        return res;
    }
};

int main() {
    vector<int> A({0,0,1,1,0,0,1,1,1,0,1,1,0,0,0,1,1,1,1});
    Solution solution;
    cout << solution.longestOnes(A, 3);
}