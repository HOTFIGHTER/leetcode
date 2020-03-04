//
// Created by xmly on 2020/2/28.
//

/**
On a single threaded CPU, we execute some functions.  Each function has a unique id between 0 and N-1.
We store logs in timestamp order that describe when a function is entered or exited.
Each log is a string with this format: "{function_id}:{"start" | "end"}:{timestamp}".  For example, "0:start:3"
means the function with id 0 started at the beginning of timestamp 3.  "1:end:2" means the function with id 1
ended at the end of timestamp 2.

A function's exclusive time is the number of units of time spent in this function.  Note that this does not
include any recursive calls to child functions.

The CPU is single threaded which means that only one function is being executed at a given time unit.
Return the exclusive time of each function, sorted by their function id.
Input:
n = 2
logs = ["0:start:0","1:start:2","1:end:5","0:end:6"]
Output: [3, 4]
Explanation:
Function 0 starts at the beginning of time 0, then it executes 2 units of time and reaches the end of time 1.
Now function 1 starts at the beginning of time 2, executes 4 units of time and ends at time 5.
Function 0 is running again at the beginning of time 6, and also ends at the end of time 6, thus executing for 1 unit of time.
So function 0 spends 2 + 1 = 3 units of total time executing, and function 1 spends 4 units of total time executing.

Note:
1 <= n <= 100
Two functions won't start or end at the same time.
Functions will always log when they exit.
 */
#include <cstdio>
#include <vector>
#include <stack>
#include <string>
#include <sstream>

using namespace std;

class Solution {
public:
    void split(string &s, vector<string> &splitted, char delim) {
        istringstream ss(s);
        string temp = "";
        while (getline(ss, temp, delim))
            splitted.push_back(temp);
    }

    vector<int> exclusiveTime(int n, vector<string> &logs) {
        vector<int> res(n, 0);
        stack<int> startIds;
        int prev = 0;
        for (int i = 0; i < logs.size(); i++) {
            vector<string> v;
            split(logs[i], v, ':');
            int id = stoi(v[0]);
            int time = stoi(v[2]);
            if (v[1] == "start") {
                //before pusing new ID, lets keep previous one uptodate
                if (!startIds.empty())
                    res[startIds.top()] += time - prev;
                //push new ID to the stack
                startIds.push(id);
                prev = time;
            } else {
                if (!startIds.empty()) {
                    if (id == startIds.top()) {
                        startIds.pop();
                        res[id] += time - prev + 1;
                        prev = time + 1; //fix prev
                    }
                }
            }
        }
        return res;
    }
};

int main() {

}