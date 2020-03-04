//
// Created by xmly on 2020/1/11.
//
/**
You are given two non-empty linked lists representing two non-negative integers.
The digits are stored in reverse order and each of their nodes contain a single digit.
Add the two numbers and return it as a linked list.
You may assume the two numbers do not contain any leading zero, except the number 0 itself.*/

#include <csignal>
#include <cstdlib>
#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        bool isNeedAdd = false;
        ListNode *l3 = NULL;
        ListNode *mark = NULL;
        while (l1 != NULL || l2 != NULL || isNeedAdd) {
            int val1 = l1 != NULL ? l1->val : 0;
            if (l1 != NULL) {
                l1 = l1->next;
            }
            int val2 = l2 != NULL ? l2->val : 0;
            if (l2 != NULL) {
                l2 = l2->next;
            }
            int val = val1 + val2 + (isNeedAdd ? 1 : 0);
            ListNode *temp = new ListNode((val > 9) ? (isNeedAdd = true, val - 10) : (isNeedAdd = false, val));
            if (l3 == NULL) {
                l3 = temp;
                mark = l3;
            } else {
                mark->next = temp;
                mark = mark->next;
            }
        }
        return l3;
    }
};

int main() {
    ListNode *l1 = new ListNode(2);
    ListNode *l2 = new ListNode(5);
    ListNode *temp1 = l1;
    ListNode *temp2 = l2;
    temp1->next = new ListNode(4);
    temp1 = temp1->next;
    temp2->next = new ListNode(6);
    temp2 = temp2->next;
    temp1->next = new ListNode(3);
    temp1 = temp1->next;
    temp2->next = new ListNode(4);
    temp2 = temp2->next;
    Solution solution;
    solution.addTwoNumbers(l1, l2);

}