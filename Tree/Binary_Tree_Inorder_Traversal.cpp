//
// Created by xmly on 2020/1/23.
//
#include <cstdio>

/**
Given a binary tree, return the inorder traversal of its nodes' values.

Example:

Input: [1,null,2,3]
1
\
     2
/
3

Output: [1,3,2]
Follow up: Recursive solution is trivial, could you do it iteratively?
 */
#include <vector>
#include <iostream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void help(TreeNode *root, vector<int> &vec) {
    if (root != NULL) {
        help(root->left, vec);
        vec.push_back(root->val);
        help(root->right, vec);
    }
}

class Solution {
public:
    vector<int> inorderTraversal(TreeNode *root) {
        vector<int> result;
        help(root, result);
        return result;
    }
};

int main() {
    TreeNode *a = new TreeNode(1);
    a->left = NULL;
    TreeNode *b=new TreeNode(2);
    a->right=b;
    b->left=NULL;
    b->right=new TreeNode(3);
    Solution solution;
    solution.inorderTraversal(a);
}