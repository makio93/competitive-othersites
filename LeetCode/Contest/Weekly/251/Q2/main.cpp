#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string maximumNumber(string num, vector<int>& change) {
        int n = num.length();
        bool sub = false;
        for (int i=0; i<n; ++i) {
            if (!sub && (int)(num[i]-'0')<change[num[i]-'0']) sub = true;
            if (sub) {
                if ((int)(num[i]-'0') <= change[num[i]-'0']) num[i] = (char)(change[num[i]-'0'] + '0');
                else break;
            }
        }
        return num;
    }
};
