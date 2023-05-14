// 本番AC

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool doesValidArrayExist(vector<int>& derived) {
        int n = derived.size();
        vector<int> original(n);
        for (int i=0; i<n-1; ++i) if ((original[i]^original[i+1]) != derived[i]) original[i+1] = 1;
        return (original[n-1] ^ original[0]) == derived[n-1];
    }
};
