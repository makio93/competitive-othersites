// 本番AC

#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

using ll = long long;

#define rep(i, n) for (int i=0; i<(int)(n); ++(i))
#define rep3(i, m, n) for (int i=(m); (i)<(int)(n); ++(i))
#define repr(i, n) for (int i=(int)(n)-1; (i)>=0; --(i))
#define rep3r(i, m, n) for (int i=(int)(n)-1; (i)>=(int)(m); --(i))
#define all(x) (x).begin(), (x).end()

const int INF = (int)(1e9);

int main() {
	int n;
	cin >> n;
	vector<int> a(n);
	rep(i, n) cin >> a[i];
	if (n >= 16) {
		cout << ((1<<16)-1) << endl;
		return 0;
	}
	unordered_set<int> st;
	st.insert(0);
	rep(i, n) {
		int val = a[i];
		unordered_set<int> nst;
		rep(j, 16) {
			for (const int& pval : st) nst.insert(pval|val);
			val = ((val&1)<<15) + (val >> 1);
		}
		swap(nst, st);
	}
	int res = 0;
	for (const int& pval : st) res = max(res, pval);
	cout << res << endl;
	return 0;
}
