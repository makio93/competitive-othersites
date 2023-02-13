// 本番AC

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
	int n;
	cin >> n;
	vector<int> p(n), q(n);
	rep(i, n) {
		cin >> p[i];
		p[i]--;
	}
	rep(i, n) {
		cin >> q[i];
		q[i]--;
	}
	vector<int> pids(n), qids(n);
	rep(i, n) pids[p[i]] = i;
	rep(i, n) qids[q[i]] = i;
	set<int> st;
	ll res = 0;
	rep(i, n) {
		int li = pids[i], ri = qids[i];
		if (li > ri) swap(li, ri);
		if (i == 0) {
			if (li-1 >= 0) res += (ll)li * (li+1) / 2;
			if (ri-li-2 >= 0) {
				int len = ri - li - 1;
				res += (ll)len * (len+1) / 2;
			}
			if (n-2-ri >= 0) {
				int len = n - ri - 1;
				res += (ll)len * (len+1) / 2;
			}
		}
		else {
			int ai = *st.begin(), bi = *st.rbegin();
			if (li-1>=0 && bi<=li-1) res += (ll)(ai+1) * (li-bi);
			if (ri-li-2>=0 && ai>=li+1 && bi<=ri-1) res += (ll)(ai-li) * (ri-bi);
			if (n-2-ri>=0 && ai>=ri+1) res += (ll)(ai-ri) * (n-bi);
		}
		st.insert(li);
		st.insert(ri);
	}
	cout << (res+1) << endl;
	return 0;
}
