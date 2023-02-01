#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findingUsersActiveMinutes(vector<vector<int>>& logs, int k) {
        int n = logs.size();
        map<int, set<int>> uam;
        for (int i=0; i<n; ++i) uam[logs[i][0]].insert(logs[i][1]);
        vector<int> ans(k);
        for (auto p : uam) {
            int num = p.second.size();
            ans[num-1]++;
        }
        return ans;
    }
};

int main(){
    Solution cl;
    int n, k;
    cin >> n;
    vector<vector<int>> logs(n, vector<int>(2));
    for (int i=0; i<n; ++i) cin >> logs[i][0] >> logs[i][1];
    cin >> k;
    auto ans = cl.findingUsersActiveMinutes(logs, k);
    for (int i=0; i<k; ++i) printf("%d%c", ans[i], (i<k-1?' ':'\n'));
    return 0;
}
