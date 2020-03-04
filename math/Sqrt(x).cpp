//
// Created by xmly on 2020/1/19.
//
/**
Compute and return the square root of x, where x is guaranteed to be a non-negative integer.
Since the return type is an integer, the decimal digits are truncated and only the integer part of the result is returned.

Example 1:

Input: 4
Output: 2
Example 2:

Input: 8
Output: 2
Explanation: The square root of 8 is 2.82842..., and since the decimal part is truncated, 2 is returned.
 */
#include <cstdio>
#include <iostream>

using namespace std;

class Solution {
public:
    int mySqrt(int x) {
        if (x < 0)
            return -1;
        if (x == 0)
            return 0;
        if (x < 4)
            return 1;
        int low = 1;
        int high = x;
        while (low < high) {
            int mid = low + (high - low) / 2;
            if (x / mid == mid) {
                return mid;
            } else if (x / mid > mid) {
                low = mid + 1;
            } else {
                high = mid;
            }
        }
        return low - 1;
    }
};

int main() {
    Solution solution;
    cout << solution.mySqrt(9);
}