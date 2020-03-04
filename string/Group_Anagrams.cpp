//
// Created by xmly on 2020/1/15.
//
/**
Given an array of strings, group anagrams together.
Example:

Input: ["eat", "tea", "tan", "ate", "nat", "bat"],
Output:
[
  ["ate","eat","tea"],
  ["nat","tan"],
  ["bat"]
]
Note:

All inputs will be in lowercase.
The order of your output does not matter.
*/
#include <cstdio>
#include <string>
#include <map>
#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string> &strs) {
        vector<vector<string>> vec;
        map<string, int> hashMap;
        int i = 0;
        for (string s:strs) {
            string temp = s;
            sort(temp.begin(), temp.end());
            if (hashMap.find(temp) != hashMap.end()) {
                vec[hashMap[temp]].push_back(s);
            } else {
                hashMap.insert(std::pair<string, int>(temp, i));
                vector<string> vector1;
                vector1.push_back(s);
                vec.push_back(vector1);
                i++;
            }
        }
        return vec;
    }
};

int main() {
    vector<string> vec({"eat", "tea", "tan", "ate", "nat", "bat"});
    Solution solution;
    solution.groupAnagrams(vec);
}