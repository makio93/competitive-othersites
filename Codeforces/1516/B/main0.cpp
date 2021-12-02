#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define rep(i, n) for (int i=0; i<(int)(n); ++(i))
#define rep3(i, m, n) for (int i=(m); (i)<(int)(n); ++(i))
#define repr(i, n) for (int i=(int)(n)-1; (i)>=0; --(i))
#define rep3r(i, m, n) for (int i=(int)(n)-1; (i)>=(int)(m); --(i))
#define all(x) (x).begin(), (x).end()

int main() {
	int t;
	cin >> t;
	rep(i1, t) {
		int n;
		cin >> n;
		vector<int> a(n);
		rep(i, n) cin >> a[i];
		vector<int> sum(n+1);
		rep(i, n) sum[i+1] = sum[i] ^ a[i];
		unordered_map<int, set<int>> memo;
		rep3(i, 1, n+1) {
			if (i != n) memo[i].insert(sum[i]);
			rep3(j, 1, i) {
				if (memo[j].find(sum[i]^sum[j]) != memo[j].end()) memo[i].insert(sum[i]^sum[j]);
			}
		}
		if (!memo[n].empty()) cout << "YES" << endl;
		else cout << "NO" << endl;
	}
	return 0;
}

