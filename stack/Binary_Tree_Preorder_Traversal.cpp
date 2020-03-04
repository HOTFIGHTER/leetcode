//
// Created by xmly on 2020/2/27.
//

/**
Given a binary tree, return the preorder traversal of its nodes' values.

Example:

Input: [1,null,2,3]
1
\
     2
/
3

Output: [1,2,3]
Follow up: Recursive solution is trivial, could you do it iteratively?
 */
#include <cstdio>
#include <vector>
#include <iostream>

using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    void preorderTraversal(TreeNode *root,vector<int> &vector){
        if(root!=NULL){
            cout<<root->val<<endl;
            vector.push_back(root->val);
            preorderTraversal(root->left,vector);
            preorderTraversal(root->right,vector);
        }
    }

    vector<int> preorderTraversal(TreeNode *root) {
        vector<int> result;
        preorderTraversal(root,result);
        return result;
    }
};

int main(){
    TreeNode *root=new TreeNode(1);
    TreeNode *right=new TreeNode(2);
    root->right=right;
    TreeNode *right_left=new TreeNode(3);
    right->left=right_left;
    Solution solution;
    solution.preorderTraversal(root);
}