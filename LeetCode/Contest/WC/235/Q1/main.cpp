#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string truncateSentence(string s, int k) {
        int n = s.length(), cnt = 0;
        string res;
        for (int i=0; i<n; ++i) {
            if (s[i] == ' ') {
                if (cnt >= k-1) break;
                else ++cnt;
            }
            res += s[i];
        }
        return res;
    }
};

int main(){
    Solution cl;
    string s;
    int k;
    cin >> s >> k;
    cout << cl.truncateSentence(s, k) << endl;
    return 0;
}
