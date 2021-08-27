#include <bits/stdc++.h>
using namespace std;

// 解説AC

class Solution {
public:
    bool isValidSerialization(string preorder) {
        preorder += ',';
        int n = preorder.length(), cap = 1;
        for (int i=0; i<n; ++i) if (preorder[i] == ',') {
            if (cap < 0) return false;
            if (preorder[i-1] != '#') cap += 2;
            --cap;
        }
        return (cap == 0);
    }
};
