//
// Created by xmly on 2020/1/23.
//
/**Calculate the sum of two integers a and b, but you are not allowed to use the operator + and -.

Example 1:

Input: a = 1, b = 2
Output: 3
Example 2:

Input: a = -2, b = 3
Output: 1
 */
class Solution {
public:
    int getSum(int a, int b) {
        while (b != 0) {
            int sum = a^b;
            b = (unsigned int) (a & b) << 1;
            a = sum;
        }
        return a;
    }
};