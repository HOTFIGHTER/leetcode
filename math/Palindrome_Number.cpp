//
// Created by xmly on 2020/1/14.
//
/**
 Determine whether an integer is a palindrome. An integer is a palindrome
 when it reads the same backward as forward.
 */
#include <cstdio>
#include <iostream>

using namespace std;
class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0 || (x % 10 == 0 && x != 0)) {
            return false;
        }
        int revertNumber = 0;
        while (x > revertNumber) {
            revertNumber = revertNumber * 10 + x % 10;
            x /= 10;
        }
        return x == revertNumber || x == revertNumber/10;
    }
};

int main() {
      Solution solution;
      cout<<solution.isPalindrome(121);
}