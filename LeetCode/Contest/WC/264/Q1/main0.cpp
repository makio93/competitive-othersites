#include <bits/stdc++.h>
using namespace std;

// 本番AC

class Solution {
public:
    int countValidWords(string sentence) {
        int n = sentence.length();
        vector<string> tokens;
        int lid = -1;
        for (int i=0; i<n; ++i) {
            if (sentence[i] == ' ') {
                if (lid != -1) {
                    tokens.push_back(sentence.substr(lid, i-lid));
                    lid = -1;
                }
            }
            else if (lid == -1) lid = i;
        }
        if (lid != -1) tokens.push_back(sentence.substr(lid));
        int res = 0;
        for (string ti : tokens) {
            bool ok = true;
            for (char ci : ti) if (isdigit(ci)) ok = false;
            int ri = ti.length();
            for (char ci : string("!.,")) if (ti[ri-1] == ci) {
                --ri;
                break;
            }
            for (int i=0; i<ri; ++i) {
                bool ok2 = false;
                for (char ci : string("!.,")) if (ti[i] == ci) ok2 = true;
                if (ok2) ok = false;
            }
            if (ti[0]=='-' || (ri-1>=1&&ti[ri-1]=='-')) ok = false;
            int hcnt = 0;
            for (int i=1; i<ri-1; ++i) {
                if (ti[i] == '-') {
                    ++hcnt;
                    if (!islower(ti[i-1]) || !islower(ti[i+1])) ok = false;
                }
            }
            if (hcnt > 1) ok = false;
            if (ok) ++res;
        }
        return res;
    }
};
