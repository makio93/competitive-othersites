#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define rep(i, n) for (int i=0; i<(int)(n); ++(i))
#define rep3(i, m, n) for (int i=(m); (i)<(int)(n); ++(i))
#define repr(i, n) for (int i=(int)(n)-1; (i)>=0; --(i))
#define rep3r(i, m, n) for (int i=(int)(n)-1; (i)>=(int)(m); --(i))
#define all(x) (x).begin(), (x).end()

// 本番WA

int main() {
    int ti;
    cin >> ti;
    rep(i0, ti) {
        int k;
        cin >> k;
        string n;
        cin >> n;
        string res;
        if (k == 1) res = n;
        else if (n.find('1') != string::npos) res = "1";
        else if ((int)(n.front()-'0')%2==0 && (int)(n.front()-'0')!=2) res = n.front();
        else {
            int even = -1;
            rep3(i, 1, k) if ((int)(n[i]-'0')%2 == 0) {
                even = i;
                break;
            }
            if (even != -1) {
                res = n.substr(0, even+1);
            }
            else {
                vector<int> vcnt(10);
                rep(i, k) vcnt[n[i]-'0']++;
                int two = -1;
                rep3(i, 2, 10) if (vcnt[i] >= 2) {
                    two = i;
                    break;
                }
                if (two != -1) res = string(2, (char)(two+'0'));
                else {
                    rep3(i, 1, (1<<k)) {
                        string t;
                        rep(j, k) if ((i>>j)&1) t.push_back(n[j]);
                        ll tval = stoll(t);
                        bool prime = true;
                        for (ll i2=2; i2*i2<=tval; ++i2) if (tval%i2 == 0) {
                            prime = false;
                            break;
                        }
                        if (!prime) {
                            res = t;
                            break;
                        }
                    }
                }
            }
        }
        cout << (int)(res.length()) << endl;
        cout << res << endl;
    }
    return 0;
}
