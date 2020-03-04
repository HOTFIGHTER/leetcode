//
// Created by xmly on 2020/2/26.
//

/**
Given a linked list, rotate the list to the right by k places, where k is non-negative.

Example 1:

Input: 1->2->3->4->5->NULL, k = 2
Output: 4->5->1->2->3->NULL
        Explanation:
rotate 1 steps to the right: 5->1->2->3->4->NULL
        rotate 2 steps to the right: 4->5->1->2->3->NULL
        Example 2:

Input: 0->1->2->NULL, k = 4
Output: 2->0->1->NULL
        Explanation:
rotate 1 steps to the right: 2->0->1->NULL
        rotate 2 steps to the right: 1->2->0->NULL
        rotate 3 steps to the right: 0->1->2->NULL
        rotate 4 steps to the right: 2->0->1->NULL
 */
#include <cstdio>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *rotateRight(ListNode *head, int k) {
        if (!head) return NULL;
        int n = 1;
        ListNode *cur = head;
        while (cur->next != NULL) {
            cur = cur->next;
            n++;
        }
        cur->next = head;
        ListNode *end = cur;
        int number = n - k % n;
        for (int i = 0; i < number; i++) {
            cur = cur->next;
        }
        ListNode *result = cur->next;
        cur->next = NULL;
        return result;
    }
};