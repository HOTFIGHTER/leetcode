//
// Created by xmly on 2020/2/25.
//

/**
Given a linked list, reverse the nodes of a linked list k at a time and return its modified list.

k is a positive integer and is less than or equal to the length of the linked list. If the number
        of nodes is not a multiple of k then left-out nodes in the end should remain as it is.

Example:

Given this linked list: 1->2->3->4->5

For k = 2, you should return: 2->1->4->3->5

For k = 3, you should return: 3->2->1->4->5

Note:

Only constant extra memory is allowed.
You may not alter the values in the list's nodes, only nodes itself may be changed.*/
#include <cstdio>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *findEnd(ListNode *prev, int k) {
        int i = 1;
        while (prev->next && i <= k) {
            prev = prev->next;
            i++;
        }
        if (i == k + 1)
            return prev;
        else
            return NULL;
    }

    ListNode *reverseKGroup(ListNode *head, int k) {
        ListNode *start = new ListNode(0);
        ListNode *end = NULL;
        start->next = head;
        head = start;
        for (; start->next;) {
            ListNode *pb = start->next;
            ListNode *pe = findEnd(start, k);
            if (!pe) //step 3
                break;
            end = pe->next;
            for (ListNode *aftr = pb, *now = start; aftr != end;) {
                ListNode *tmp = aftr->next;
                aftr->next = now;
                now = aftr;
                aftr = tmp;
            }
            //第0项的下一个
            start->next = pe;
            //第一个元素的下一个
            pb->next = end;
            start = pb;
        }
        start = head;
        head = head->next;
        delete start;
        return head;
    }
};

int main() {

}