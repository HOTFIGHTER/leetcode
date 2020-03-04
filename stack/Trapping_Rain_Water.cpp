//
// Created by xmly on 2020/1/10.
//
/**
Given n non-negative integers representing an elevation map where the width of each bar is 1,
compute how much water it is able to trap after raining
 */

/**水桶题*/

#include <csignal>
#include <vector>
#include <stack>
#include <iostream>

using namespace std;

class Solution {
public:
    int trap(vector<int> &height) {
        int total = 0;
        stack<int> stack;
        for (int i = 0; i < height.size(); i++) {
            while (!stack.empty() && (height[i] > height[stack.top()])) {
                int low = stack.top();
                stack.pop();
                if (stack.empty()) {
                    break;
                }
                int start = stack.top();
                total += (min(height[i], height[start]) - height[low]) * (i - start-1);
            }
            stack.push(i);
        }
        return total;
    }
};

int main() {
    vector<int> vec = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    Solution solution;
    cout << solution.trap(vec) << endl;
}