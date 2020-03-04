//
// Created by xmly on 2020/1/17.
//
/**
Write a function to find the longest common prefix string amongst an array of strings.

If there is no common prefix, return an empty string "".

Example 1:

Input: ["flower","flow","flight"]
Output: "fl"
Example 2:

Input: ["dog","racecar","car"]
Output: ""
Explanation: There is no common prefix among the input strings.
 */
#include <cstdio>
#include <vector>
#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string> &strs) {
        if(strs.size()<=0){
            return "";
        }
        string result = "";
        int m = 0;
        string mark = strs[0];
        for (int j = 0; j < mark.length(); j++) {
            bool isPre = true;
            for (int i = 1; i < strs.size(); i++) {
                if (mark[j] != strs[i][j]) {
                    isPre = false;
                    i = strs.size();
                }
            }
            if(isPre){
               result.push_back(mark[j]);
            }else{
                return result;
            }
        }
        return result;
    }
};

int main() {
   vector<string> vec;
   Solution solution;
   cout<<solution.longestCommonPrefix(vec);
}