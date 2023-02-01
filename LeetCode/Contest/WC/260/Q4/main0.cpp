#include <bits/stdc++.h>
using namespace std;

// 本番WA

using ll = long long;
class Solution {
public:
    int scoreOfStudents(string s, vector<int>& answers) {
        int n = s.length(), m = answers.size(), c = n / 2;
        vector<ll> cmuls;
        cmuls.push_back(s[0]-'0');
        for (int i=1; i<n; i+=2) {
            if (s[i] == '*') cmuls.back() *= (ll)(s[i+1] - '0');
            else {
                cmuls.push_back(1);
                cmuls.push_back((ll)(s[i+1]-'0'));
            }
        }
        ll cval = cmuls[0];
        for (int i=2; i<(int)(cmuls.size()); i+=2) cval += cmuls[i];
        cout << "cval : " << cval << endl;
        vector<int> scores(m);
        for (int i=0; i<m; ++i) if ((ll)answers[i] == cval) scores[i] = 5;
        unordered_set<ll> vals;
        for (int i=0; i<(1<<c); ++i) {
            vector<ll> muls;
            muls.push_back((ll)(s[0]-'0'));
            for (int j=0; j<c; ++j) {
                if ((i>>j)&1) {
                    if (s[j*2+1] == '+') muls.back() += (ll)(s[j*2+2] - '0');
                    else muls.back() *= (ll)(s[j*2+2] - '0');
                }
                else {
                    if (s[j*2+1] == '+') muls.push_back(1);
                    else muls.push_back(0);
                    muls.push_back((ll)(s[j*2+2]-'0'));
                }
            }
            ll val = muls[0];
            for (int j=1; j<(int)(muls.size()); j+=2) {
                if (muls[j] == 1) val += muls[j+1];
                else val *= muls[j+1];
            }
            vals.insert(val);
        }
        for (int i=0; i<m; ++i) {
            if (vals.find((ll)answers[i]) != vals.end()) scores[i] = max(2, scores[i]);
        }
        int res = 0;
        for (int i=0; i<m; ++i) res += scores[i];
        return res;
    }
};

int main() {
    string s = "1+4+4+1*0+2";
    vector<int> answer = { 7,717,2,11,11,236,7,15,7,11,11,561,7,164,19,11,11,15,11,15,11,826,7,733,19,2,831,2,11,2,665,3,11,3,2,11,52,19,7,559,2,19,7,15,664,3,113,11,454 };
    Solution cl;
    int res = cl.scoreOfStudents(s, answer);
    cout << res << endl;
    return 0;
}
