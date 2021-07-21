#include <bits/stdc++.h>
using namespace std;

// 自力AC

class Solution {
public:
    string pushDominoes(string dominoes) {
        int n = dominoes.length();
        queue<int> rest;
        for (int i=0; i<n; ++i) rest.push(i);
        while (!rest.empty()) {
            queue<pair<int, char>> change;
            while (!rest.empty()) {
                int v = rest.front(); rest.pop();
                if (dominoes[v] != '.') {
                    if (dominoes[v]=='L' && v-1>=0 && dominoes[v-1]=='.' && (v-2<0||dominoes[v-2]!='R')) change.emplace(v-1, 'L');
                    if (dominoes[v]=='R' && v+1<n && dominoes[v+1]=='.' && (v+2>=n||dominoes[v+2]!='L')) change.emplace(v+1, 'R');
                }
            }
            while (!change.empty()) {
                auto [ t, c ] = change.front(); change.pop();
                rest.push(t);
                dominoes[t] = c;
            }
        }
        return dominoes;
    }
};
