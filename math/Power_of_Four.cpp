#include <cmath>

//
// Created by xmly on 2020/2/2.
//
class Solution {
public:
    bool isPowerOfFour(int num) {
        return (num > 0 && int (log10(num) / log10(4)) - log10(num) / log10(4) == 0);
    }
};