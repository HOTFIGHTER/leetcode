//
// Created by xmly on 2020/1/13.
//

/**Given a string, find the length of the longest substring without repeating characters.*/

#include <cstdio>
#include <string>
#include <map>
#include <iostream>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
//        map<char, int> map;
//        int max = 0;
//        int temp = 0;
//        for (int i = 0; i < s.size(); i++) {
//            temp = 0;
//            map.clear();
//            for (int j = i; j < s.size(); j++) {
//                if (map.find(s[j]) == map.end()) {
//                    temp++;
//                    map.insert(std::pair<char, int>(s[j], 1));
//                }else{
//                    j=s.size();
//                }
//            }
//            if (max < temp) {
//                max = temp;
//            }
//        }
//        return max;
        int n = s.length(), ans = 0;
        map<char, int> map;
        for (int j = 0, i = 0; j < n; j++) {
            if (map.find(s[j]) != map.end()) {
                i = max(map[s[j]], i);
            }
            ans = max(ans, j - i + 1);
            map[s[j]] = j + 1;
        }
        return ans;
    }
};

int main() {
    Solution solution;
    cout << solution.lengthOfLongestSubstring("abcabcbb");
}