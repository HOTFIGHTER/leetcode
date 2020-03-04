//
// Created by xmly on 2020/1/29.
//
/**
   For an undirected graph with tree characteristics, we can choose any node as the root. The result graph is
then a rooted tree. Among all possible rooted trees, those with minimum height are called minimum height trees (MHTs).
Given such a graph, write a function to find all the MHTs and return a list of their root labels.
Format
   The graph contains n nodes which are labeled from 0 to n - 1. You will be given the number n and a list of
undirected edges (each edge is a pair of labels).
You can assume that no duplicate edges will appear in edges. Since all edges are undirected, [0, 1] is the same as [1, 0]
and thus will not appear together in edges.
Example 1 :
Input: n = 4, edges = [[1, 0], [1, 2], [1, 3]]

0
|
1
/ \
2   3

Output: [1]
Example 2 :

Input: n = 6, edges = [[0, 3], [1, 3], [2, 3], [4, 3], [5, 4]]

0  1  2
\ | /
3
|
4
|
5
Output: [3, 4]

https://www.jianshu.com/p/bef9b70b998f
题目的要求是在一个没有环的图里，找一个节点作为根节点，将图转换成一棵树，使树的高度最小
先考虑最简单的图，每个节点只有一条边进入和一条边离开，这样的图退化成为一个链表。选取某一个节点作为Root时，
树的高度由根节点到左右两侧叶子节点的最大路径决定。因此想要树的高度最小，需要左右两侧的路径大小尽可能接近。
对于链表来说，中间节点就是我们的寻找的根节点，根据全部节点的个数不同，符合条件的根节点可能是一个或者两个。
 寻找中间节点的算法很简单，可以分别从左右两个叶子节点以相同的速度前进，相遇的节点即是中间节点。

退化成链表的图
回到题目中的场景：没有环的图，可以看作是多条链表，并且共用了一些节点。可以看出树的高度是由最长的链表决定的，
 即图中1-7的链表。寻找MHT根节点问题就转化成了找到最长的链表的中间节点

获取所有叶子节点
while true
     从所有叶子节点出发，当前节点为叶子节点的下一个节点
     删除所有叶子节点
     当前节点是否变为叶子节点？
        是：当前节点加入叶子节点
        否：表示有更长的路径，舍弃掉此路径
     叶子节点数量 <= 2
        使用链表中间节点算法找到根节点，结束
*/
#include <cstdio>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <queue>

using namespace std;

class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>> &edges) {
        if (n == 1) return {0};
        unordered_map<int, unordered_set<int>> graph;
        for (const auto &e : edges) {
            graph[e[0]].insert(e[1]);
            graph[e[1]].insert(e[0]);
        }
        queue<int> que;
        vector<int> res;
        for (int i = 0; i < n; i++) {
            if (graph[i].size() == 1) {
                que.push(i);
            }
        }
        while (n > 2) {
            int size = que.size();
            n -= size;
            for (int i = 0; i < size; ++i) {
                int t = que.front();
                que.pop();
                for (auto a : graph[t]) {
                    graph[a].erase(t);
                    if (graph[a].size() == 1) {
                        que.push(a);
                    }
                }
            }
        }
        while (!que.empty()) {
            res.push_back(que.front());
            que.pop();
        }
        return res;
    }
};

int main() {

}