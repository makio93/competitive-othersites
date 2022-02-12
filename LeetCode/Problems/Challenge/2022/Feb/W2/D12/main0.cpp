#include <bits/stdc++.h>
using namespace std;

// 自力AC

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        int n = wordList.size(), m = beginWord.length();
        unordered_map<string, int> sids;
        for (int i=0; i<n; ++i) sids[wordList[i]] = i;
        if (sids.find(endWord) == sids.end()) return 0;
        vector<int> dist(n, (int)(1e9));
        queue<int> que;
        dist[sids[endWord]] = 0;
        que.push(sids[endWord]);
        while (!que.empty()) {
            int id = que.front(); que.pop();
            int di = dist[id], ndi = di + 1;
            string str = wordList[id];
            int cnt = 0;
            for (int i=0; i<m; ++i) if (str[i] != beginWord[i]) ++cnt;
            if (cnt == 1) return ndi + 1;
            for (int i=0; i<m; ++i) for (char ci='a'; ci<='z'; ++ci) if (str[i] != ci) {
                string nstr = str;
                nstr[i] = ci;
                if (nstr == beginWord) return ndi + 1;
                if (sids.find(nstr) == sids.end()) continue;
                if (dist[sids[nstr]] <= ndi) continue;
                dist[sids[nstr]] = ndi;
                que.push(sids[nstr]);
            }
        }
        return 0;
    }
};
