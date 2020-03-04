//
// Created by xmly on 2020/2/25.
//
/**
Given a linked list, swap every two adjacent nodes and return its head.

You may not modify the values in the list's nodes, only nodes itself may be changed.



Example:

Given 1->2->3->4, you should return the list as 2->1->4->3.*/
#include <cstdio>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *swapPairs(ListNode *head) {
        if(head == nullptr || head->next == nullptr)
            return head;

        ListNode* dummy = new ListNode(0);
        dummy->next = head->next;
        ListNode* curr = head;
        ListNode* nextNode;
        ListNode* nextNextNode;

        while(curr && curr->next) {
            nextNode = curr->next;
            nextNextNode = nextNode->next;

            nextNode->next = curr;
            if(nextNextNode && nextNextNode->next)
                curr->next = nextNextNode->next;
            else
                curr->next = nextNextNode;
            curr = nextNextNode;
        }
        return dummy->next;
    }
};

int main() {
    ListNode *a = new ListNode(1);
    ListNode *b = new ListNode(2);
    ListNode *c = new ListNode(3);
    ListNode *d = new ListNode(4);
    a->next = b;
    b->next = c;
    c->next = d;
    d->next = NULL;
    Solution solution;

}