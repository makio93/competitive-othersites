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
	unordered_set<int> st;
	rep(i, (1<<n)) {
		int sum = 0;
		rep(j, n) if ((i>>j)&1) sum += a[j];
		st.insert(sum);
	}
	cin >> q;
	rep(i, q) {
		int mi;
		cin >> mi;
		if (st.find(mi) != st.end()) cout << "yes" << endl;
		else cout << "no" << endl;
	}
	return 0;
}
