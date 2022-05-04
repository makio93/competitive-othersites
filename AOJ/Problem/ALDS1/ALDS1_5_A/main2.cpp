// AC

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define rep(i, n) for (int i=0; i<(int)(n); ++(i))
#define rep3(i, m, n) for (int i=(m); (i)<(int)(n); ++(i))
#define repr(i, n) for (int i=(int)(n)-1; (i)>=0; --(i))
#define rep3r(i, m, n) for (int i=(int)(n)-1; (i)>=(int)(m); --(i))
#define all(x) (x).begin(), (x).end()

int main() {
	int n, q;
	cin >> n;
	vector<int> a(n);
	rep(i, n) cin >> a[i];
	cin >> q;
	rep(i, q) {
		int mi;
		cin >> mi;
		auto dfs = [&](auto dfs, int s, int d=0) -> bool {
			if (d == n) return (s == 0);
			if (dfs(dfs, s, d+1)) return true;
			else return (s-a[d] >= 0) && dfs(dfs, s-a[d], d+1);
		};
		if (dfs(dfs, mi)) cout << "yes" << endl;
		else cout << "no" << endl;
	}
	return 0;
}
