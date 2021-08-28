#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")

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
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, k;
	cin >> n >> k;
	string s;
	cin >> s;
	int id = -1;
	rep3(i, 1, min(n,k)) {
		int len = min(n-i, i);
		if (s.substr(0,len) < s.substr(i,len)) {
			id = i;
			break;
		}
	}
	if (id == -1) id = n;
	string tar = s.substr(0, id);
	int len = 0;
	string t;
	while (len < k) {
		t += tar;
		len += id;
	}
	t = t.substr(0, k);
	cout << t << '\n';
	return 0;
}
