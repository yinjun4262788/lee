#include<iostream>
#include<string>
#include<stack>
#include<queue>
#include<unordered_map>
#include<vector>
#include<math.h>
#include<algorithm>
#include<typeinfo>
#include<unordered_set>
using namespace std;
class Solution {
private:
    bool used[300] = { 0 };
    vector<string> temp = { "JFK" };
    vector<string> ans;
    void backtracking(vector<vector<string>>& tickets, int len, string& target) {
        //收获结果
        if (temp.size() == len + 1) {
            ans = temp;
            return;
        }
        for (int i = 0; i < len; i++) {
            if (used[i] == 0 && tickets[i][0] == target) {
                used[i] = 1;
                temp.push_back(tickets[i][1]);
                backtracking(tickets, len, tickets[i][1]);
                if (ans.size()) break;
                temp.pop_back();
                used[i] = 0;
            }
        }
        //找了一圈 发现没有 应该return  条件是什么
    }
public:
    /*bool combine(vector<string>&a, vector<string>&b) {
     return a[1] < b[1];
    }*/
    static bool combine(vector<string>& a, vector<string>& b) {
        return a[1] < b[1];
    }
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        int len = tickets.size();
        sort(tickets.begin(), tickets.end(), combine);//这个排序很重要
        string target("JFK");
        backtracking(tickets, len, target);
        return ans;
    }
};
int main() {
    Solution so;
    vector<vector<string>> a({ {"JFK","SFO" },{ "JFK","ATL" } ,{"SFO","ATL"} ,{"ATL","JFK"},{"ATL","SFO"} });
    so.findItinerary(a);
}