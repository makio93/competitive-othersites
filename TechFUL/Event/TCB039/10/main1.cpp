#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

// 解説AC

using ll = long long;
const ll mod = (ll)(1e9) + 7;

int main()
{
    string s;
    cin >> s;
    int n = s.length();
    for (int i=1; i<n; i+=2) s[i] = (s[i]=='a') ? 'b' : 'a';
    vector<int> cdiff(n+1);
    for (int i=0; i<n; ++i) cdiff[i+1] = cdiff[i] + ((s[i]=='a') ? 1 : -1);
    unordered_map<int, ll> vals;
    vector<ll> dp(n+1);
    dp[0] = 1;
    for (int i=0; i<n+1; ++i) {
        if (vals.find(cdiff[i]) != vals.end()) {
            dp[i] = (dp[i] + vals[cdiff[i]]) % mod;
            vals.erase(cdiff[i]);
        }
        vals[cdiff[i]+1] = (vals[cdiff[i]+1] + dp[i]) % mod;
        vals[cdiff[i]-1] = (vals[cdiff[i]-1] + dp[i]) % mod;
    }
    ll res = 0;
    for (int i=0; i<n+1; ++i) if (cdiff[i] == cdiff[n]) res = (res + dp[i]) % mod;
    cout << res << endl;
    return 0;
}
