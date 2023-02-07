// 自力AC

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProduct(vector<string>& words) {
        int n = words.size();
        vector<int> bits(n);
        for (int i=0; i<n; ++i) for (char ci : words[i]) bits[i] |= (1<<(ci-'a'));
        int res = 0;
        for (int i=0; i<n; ++i) for (int j=i+1; j<n; ++j) if (!(bits[i]&bits[j])) res = max(res, (int)(words[i].length()*words[j].length()));
        return res;
    }
};
