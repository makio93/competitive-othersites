// 終了後,自力2,TLE

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
	int n, q;
	cin >> n >> q;
	vector<int> a(n);
	rep(i, n) cin >> a[i];
	bitset<250000> abits(0);
	set<int> bids;
	auto badd = [&](auto badd, int aval, int bid) -> void {
		if (!aval) return;
		if (aval & 1) {
			int tid = bid;
			while (abits[tid]) {
				abits.flip(tid);
				bids.erase(tid);
				++tid;
			}
			abits.flip(tid);
			bids.insert(tid);
		}
		badd(badd, aval>>1, bid+1);
	};
	auto bsub = [&](auto bsub, int aval, int bid) -> void {
		if (!aval) return;
		if (aval & 1) {
			int tid = bid;
			while (!abits[tid]) {
				abits.flip(tid);
				bids.insert(tid);
				++tid;
			}
			abits.flip(tid);
			bids.erase(tid);
		}
		badd(bsub, aval>>1, bid+1);
	};
	rep(i, n) badd(badd, 1, a[i]);
	rep(i, q) {
		int ki, li;
		cin >> ki >> li;
		--ki;
		bsub(bsub, 1, a[ki]);
		badd(badd, 1, li);
		a[ki] = li;
		cout << (*bids.rbegin()) << endl;
	}
	return 0;
}
