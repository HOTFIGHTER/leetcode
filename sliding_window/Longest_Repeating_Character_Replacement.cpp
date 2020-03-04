//
// Created by xmly on 2020/2/17.
//
/**
Given a string s that consists of only uppercase English letters, you can perform at most k operations on that string.

In one operation, you can choose any character of the string and change it to any other uppercase English character.

Find the length of the longest sub-string containing all repeating letters you can get after performing the above operations.

Note:
Both the string's length and k will not exceed 104.

Example 1:

Input:
s = "ABAB", k = 2

Output:
4

Explanation:
Replace the two 'A's with two 'B's or vice versa.


Example 2:

Input:
s = "AABABBA", k = 1

Output:
4

Explanation:
Replace the one 'A' in the middle with 'B' and form "AABBBBA".
The substring "BBBB" has the longest repeating letters, which is 4.*/
#include <cstdio>
#include <string>
#include <unordered_map>
#include <iostream>

using namespace std;

class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char, int> count;
        int i = 0, j = 0, res = 0, maxCount = 0;
        while (i < s.length()) {
            maxCount = max(maxCount, ++count[s[i++]]);
            while (i - j - maxCount > k) {
                count[s[j++]]--;
            }
            res = max(res, i - j);
        }
        return res;
    }
};

int main() {
    Solution s;
    cout << s.characterReplacement("ABAB", 2);
}

