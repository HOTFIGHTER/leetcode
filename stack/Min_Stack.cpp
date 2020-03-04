//
// Created by xmly on 2020/2/27.
//
/**
Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.

push(x) -- Push element x onto stack.
pop() -- Removes the element on top of the stack.
top() -- Get the top element.
getMin() -- Retrieve the minimum element in the stack.


Example:

MinStack minStack = new MinStack();
minStack.push(-2);
minStack.push(0);
minStack.push(-3);
minStack.getMin();   --> Returns -3.
minStack.pop();
minStack.top();      --> Returns 0.
minStack.getMin();   --> Returns -2.
 */
#include <cstdio>
#include <climits>
#include <list>
using namespace std;
class MinStack {
private:
    list<int>st;
    list<int>min;
public:
    /** initialize your data structure here. */
    MinStack() {

    }

    void push(int x) {
        st.emplace_back(x);
        if (min.empty() || min.back() >= x) {
            min.push_back(x);
        }
    }

    void pop() {
        if (!st.empty()) {
            if (min.back() == st.back())
                min.pop_back();
            st.pop_back();
        }
    }

    int top() {
        if (!st.empty()) {
            return st.back();
        }
        return -1;
    }

    int getMin() {
        if (!min.empty())
            return min.back();
        return -1;
    }
};