//
// Created by xmly on 2020/2/13.
//
/**
Given a non-empty string s and a dictionary wordDict containing a list of non-empty words, determine if s can be
segmented into a space-separated sequence of one or more dictionary words.

Note:

The same word in the dictionary may be reused multiple times in the segmentation.
You may assume the dictionary does not contain duplicate words.
Example 1:

Input: s = "leetcode", wordDict = ["leet", "code"]
Output: true
Explanation: Return true because "leetcode" can be segmented as "leet code".
Example 2:

Input: s = "applepenapple", wordDict = ["apple", "pen"]
Output: true
Explanation: Return true because "applepenapple" can be segmented as "apple pen apple".
Note that you are allowed to reuse a dictionary word.
Example 3:

Input: s = "catsandog", wordDict = ["cats", "dog", "sand", "and", "cat"]
Output: false*/

#include <cstdio>
#include <string>
#include <vector>
#include <unordered_set>
#include <iostream>

using namespace std;

class Solution {
public:
    bool wordBreak(string s, vector<string> &wordDict) {
        if (wordDict.size() == 0 || s.length() == 0) {
            return false;
        }
        unordered_set<string> set;
        for (string a:wordDict) {
            set.insert(a);
        }
        vector<bool> dp(s.length() + 1, false);
        dp[0] = true;
        for (int i = 1; i < s.length() + 1; i++) {
            for (int j = 0; j < i; j++) {
                string subStr = s.substr(j, i-j);
                if (dp[j] && set.find(subStr) != set.end()) {
                    cout<<i<<endl;
                    dp[i] = true;

                }
            }
        }
        cout<<boolalpha<<dp[s.length()];
        return dp[s.length()];
    }
};


int main(){
    vector<string> wordDict({"apple", "pen"});
    string s="applepenapple";
    Solution solution;
    solution.wordBreak(s,wordDict);
}