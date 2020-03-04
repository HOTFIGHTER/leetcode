//
// Created by xmly on 2020/1/14.
//
#include <cstdio>
#include <iostream>

/**
Given a linked list, remove the n-th node from the end of list and return its head.
Example:
Given linked list: 1->2->3->4->5, and n = 2.
After removing the second node from the end, the linked list becomes 1->2->3->5.
Note:
Given n will always be valid.
Follow up:
Could you do this in one pass?
 */
using namespace std;

struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        ListNode *dummy=new ListNode(0);
        dummy->next = head;
        ListNode *first = dummy;
        for (int i = 0; i < n; i++) {
            first = first->next;
        }
        ListNode *second = dummy;
        while (first != NULL && first->next != NULL) {
            first = first->next;
            second = second->next;
        }
        second->next = second->next->next;
        return dummy->next;
    }
};

int main() {
    Solution solution;
    ListNode l1(1);
//    ListNode l2(2);
//    ListNode l3(3);
//    ListNode l4(4);
//    ListNode l5(5);
//    (&l1)->next=&l2;
//    (&l2)->next=&l3;
//    (&l3)->next=&l4;
//    (&l4)->next=&l5;
    solution.removeNthFromEnd(&l1, 1);
}