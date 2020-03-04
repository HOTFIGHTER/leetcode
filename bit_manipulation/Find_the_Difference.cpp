//
// Created by xmly on 2020/2/5.
//
/**
Given two strings s and t which consist of only lowercase letters.

String t is generated by random shuffling string s and then add one more letter at a random position.

Find the letter that was added in t.

Example:

Input:
s = "abcd"
t = "abcde"

Output:
e

        Explanation:
'e' is the letter that was added.
 */
#include <cstdio>
#include <string>
#include <unordered_set>

using namespace std;

class Solution {
public:
    char findTheDifference(string s, string t) {
        unordered_multiset<char> dict;
        for (auto w : s) {
            dict.insert(w);
        }
        for(auto w : t) {
            auto ww = dict.find(w);
            if(ww == dict.end()) return w;
            dict.erase(ww);
        }
        return '1';
    }
};