//
// Created by xmly on 2020/1/17.
//

/**
Merge two sorted linked lists and return it as a new list. The new list should be made by splicing
together the nodes of the first two lists.

Example:

Input: 1->2->4, 1->3->4
Output: 1->1->2->3->4->4
*/
#include <cstdio>
#include <iostream>

using namespace std;
struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        ListNode *l3 = new ListNode(-1);
        ListNode *result = l3;
        while (l1 != NULL || l2 != NULL) {
            if (l1 != NULL && l2 != NULL) {
                if (l1->val > l2->val) {
                    l3->next = l2;
                    l2 = l2->next;
                } else {
                    l3->next = l1;
                    l1 = l1->next;
                }
            } else if (l1 != NULL) {
                l3->next=l1;
                l1 = l1->next;
            } else if (l2 != NULL) {
                l3->next=l2;
                l2 = l2->next;
            }
            l3 = l3->next;
        }
        return result->next;
    }
};

int main() {
    Solution solution;
    ListNode*l1=new ListNode(1);
    ListNode*l2=new ListNode(2);
    l1->next=l2;
    ListNode*l3=new ListNode(4);
    l2->next=l3;
    ListNode*l4=new ListNode(1);
    ListNode*l5=new ListNode(3);
    l4->next=l5;
    ListNode*l6=new ListNode(4);
    l5->next=l6;
    solution.mergeTwoLists(l1,l4);
}