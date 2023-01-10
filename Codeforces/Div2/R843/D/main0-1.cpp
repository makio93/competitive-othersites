// 本番WA

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define rep(i, n) for (int i=0; i<(int)(n); ++(i))
#define rep3(i, m, n) for (int i=(m); (i)<(int)(n); ++(i))
#define repr(i, n) for (int i=(int)(n)-1; (i)>=0; --(i))
#define rep3r(i, m, n) for (int i=(int)(n)-1; (i)>=(int)(m); --(i))
#define all(x) (x).begin(), (x).end()

ll gcd(ll a, ll b) { return (b ? gcd(b, a%b) : a); }
ll lcm(ll a, ll b) { return (a / gcd(a, b) * b); }
const int INF = (int)(1e9);

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, s, t;
	cin >> n;
	vector<int> a(n);
	rep(i, n) cin >> a[i];
	cin >> s >> t;
	--s; --t;
	vector<int> res;
	if (a[s] == a[t]) {
		if (s == t) res.push_back(s+1);
		else {
			res.push_back(s+1);
			res.push_back(t+1);
		}
		int tlen = res.size();
		cout << tlen << endl;
		rep(i, tlen) cout << res[i] << (i<tlen-1?' ':'\n');
		return 0;
	}
	int amx = *max_element(all(a));
	vector<int> aids(amx+1, -1);
	repr(i, n) aids[a[i]] = i;
	aids[a[s]] = s;
	aids[a[t]] = t;
	vector<int> pids(n, -1);
	deque<pair<int, int>> deq;
	res.push_back(s+1);
	pids[s] = INF;
	deq.emplace_back(s, a[s]);
	vector<int> nids, vids;
	rep(i, amx+1) if (aids[i]!=-1 && aids[i]!=s) vids.push_back(aids[i]);
	sort(all(vids));
	while (!deq.empty()) {
		int m = deq.size();
		rep(i, m) {
			auto dval = deq.front(); deq.pop_front();
			for (const int& vi : vids) {
				if (gcd(dval.second, a[vi]) == 1) nids.push_back(vi);
				else {
					pids[vi] = dval.first;
					deq.emplace_back(vi, a[vi]);
				}
			}
			swap(nids, vids);
			nids.clear();
		}
	}
	if (pids[t] == -1) cout << -1 << endl;
	else if (res.back() != t+1) {
		vector<int> tmp;
		tmp.push_back(t);
		while (pids[tmp.back()] != s) {
			int nt = pids[tmp.back()];
			tmp.push_back(nt);
		}
		reverse(all(tmp));
		int tmlen = tmp.size();
		rep(i, tmlen) res.push_back(tmp[i]+1);
		int tlen = res.size();
		cout << tlen << endl;
		rep(i, tlen) cout << res[i] << (i<tlen-1?' ':'\n');
	}
	return 0;
}
