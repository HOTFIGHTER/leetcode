//
// Created by xmly on 2020/2/26.
//
/**
Given a sorted linked list, delete all duplicates such that each element appear only once.

Example 1:

Input: 1->1->2
Output: 1->2
Example 2:

Input: 1->1->2->3->3
Output: 1->2->3*/

#include <cstdio>
#include <unordered_map>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *deleteDuplicates(ListNode *head) {
        if (head == NULL) {
            return head;
        }
        unordered_map<int, int> map;
        ListNode *start = new ListNode(0);
        start->next = head;
        ListNode *result = head;
        while (start!= NULL && start->next!= NULL) {
            ListNode *cur = start->next;
            if (map.find(cur->val) != map.end()) {
                start->next = cur->next;
            } else {
                map.insert(std::pair<int, int>(cur->val, 1));
                start = start->next;
            }
        }
        return result;
    }
};