// 

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define rep(i, n) for (int i=0; i<(int)(n); ++(i))
#define rep3(i, m, n) for (int i=(m); (i)<(int)(n); ++(i))
#define repr(i, n) for (int i=(int)(n)-1; (i)>=0; --(i))
#define rep3r(i, m, n) for (int i=(int)(n)-1; (i)>=(int)(m); --(i))
#define all(x) (x).begin(), (x).end()

const int INF = (int)(1e9);

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t0;
	cin >> t0;
	rep(i0, t0) {
		int n;
		cin >> n;
		vector<string> s(n);
		rep(i, n) cin >> s[i];
		unordered_map<string, int> scnt;
		ll res = 0;
		rep(i, n) {
			for (char ci='a'; ci<='z'; ++ci) if (ci != s[i][0]) {
				string tmp = s[i];
				tmp[0] = ci;
				if (scnt.find(tmp) != scnt.end()) res += scnt[tmp];
			}
			for (char ci='a'; ci<='z'; ++ci) if (ci != s[i][1]) {
				string tmp = s[i];
				tmp[1] = ci;
				if (scnt.find(tmp) != scnt.end()) res += scnt[tmp];
			}
			scnt[s[i]]++;
		}
		cout << res << endl;
	}
	return 0;
}
