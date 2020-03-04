//
// Created by xmly on 2020/1/11.
//
/**
Given two strings s and t , write a function to determine if t is an anagram of s.

Example 1:

Input: s = "anagram", t = "nagaram"
Output: true
Example 2:

Input: s = "rat", t = "car"
Output: false
*/
#include <cstdio>
#include <string>
#include <iostream>

using namespace std;
class Solution {
public:
    bool isAnagram(string s, string t) {
        sort(s.begin(),s.end());
        sort(t.begin(),t.end());
        if(s.compare(t)){
            return false;
        }else{
            return true;
        }
    }
};

int main(){
   Solution solution;
   cout<<solution.isAnagram("rat","car");
}