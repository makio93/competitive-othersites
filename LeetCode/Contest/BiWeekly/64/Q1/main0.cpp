#include <bits/stdc++.h>
using namespace std;

// 本番AC

class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        int n = arr.size();
        unordered_map<string, int> scnt;
        for (int i=0; i<n; ++i) scnt[arr[i]]++;
        vector<string> slst;
        for (int i=0; i<n; ++i) if (scnt[arr[i]] == 1) slst.push_back(arr[i]);
        if ((int)(slst.size()) < k) return "";
        else return slst[k-1];
    }
};
