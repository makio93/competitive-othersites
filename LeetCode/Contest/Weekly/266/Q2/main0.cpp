#include <bits/stdc++.h>
using namespace std;

// 本番AC

using ll = long long;
const string vowels = "aeiou";
class Solution {
public:
    ll countVowels(string word) {
        int n = word.length();
        vector<int> sum(n+1);
        for (int i=0; i<n; ++i) {
            bool isv = false;
            for (int j=0; j<5; ++j) if (word[i] == vowels[j]) isv = true;
            if (isv) sum[i+1] = sum[i] + 1;
            else sum[i+1] = sum[i];
        }
        ll msum = 0, res = 0;
        for (int i=1; i<=n; ++i) {
            res += (ll)sum[i] * i - msum;
            msum += sum[i];
        }
        return res;
    }
};
