//
// Created by xmly on 2020/2/5.
//
/**
Given two binary strings, return their sum (also a binary string).

The input strings are both non-empty and contains only characters 1 or 0.

Example 1:

Input: a = "11", b = "1"
Output: "100"
Example 2:

Input: a = "1010", b = "1011"
Output: "10101"*/
#include <cstdio>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    string addBinary(string a, string b) {
        vector<char> result;
        bool needAdd= false;
        int size = max(a.size(), b.size());
        for (int i = size - 1; i >= 0; i--) {

        }
    }
};