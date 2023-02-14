// 終了後,自力3,AC

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
	map<int, int> ltor;
	auto badd = [&](int bid) -> void {
		if (ltor.empty()) {
			ltor[bid] = bid;
			return;
		}
		auto itr = ltor.upper_bound(bid);
		if (itr == ltor.begin()) {
			ltor[bid] = bid;
			if (itr->first == bid+1) {
				int rval = itr->second;
				ltor.erase(itr);
				ltor[bid] = rval;
			}
			return;
		}
		auto pitr = prev(itr);
		if (bid <= pitr->second) {
			int rval = pitr->second;
			if (bid-1 >= pitr->first) ltor[pitr->first] = bid - 1;
			else ltor.erase(pitr->first);
			ltor[rval+1] = rval + 1;
			if (itr!=ltor.end() && rval+2==itr->first) {
				ltor[rval+1] = itr->second;
				ltor.erase(itr->first);
			}
		}
		else {
			if (bid-1==pitr->second && itr!=ltor.end() && bid+1==itr->first) {
				ltor[pitr->first] = itr->second;
				ltor.erase(itr->first);
			}
			else if (bid-1 == pitr->second) ltor[pitr->first] = bid;
			else if (itr!=ltor.end() && bid+1==itr->first) {
				ltor[bid] = itr->second;
				ltor.erase(itr->first);
			}
			else ltor[bid] = bid;
		}
	};
	auto bsub = [&](int bid) -> void {
		auto itr = ltor.upper_bound(bid);
		if (itr == ltor.begin()) {
			ltor[bid] = itr->first - 1;
			if (itr->first < itr->second) ltor[itr->first+1] = itr->second;
			ltor.erase(itr->first);
			return;
		}
		auto pitr = prev(itr);
		if (bid <= pitr->second) {
			int rval = pitr->second;
			if (bid-1 >= pitr->first) ltor[pitr->first] = bid - 1;
			else ltor.erase(pitr->first);
			if (bid+1 <= rval) ltor[bid+1] = rval;
		}
		else {
			if (bid-1 == pitr->second) ltor[pitr->first] = itr->first - 1;
			else ltor[bid] = itr->first - 1;
			if (itr->second > itr->first) ltor[itr->first+1] = itr->second;
			ltor.erase(itr->first);
		}
	};
	rep(i, n) badd(a[i]);
	rep(i, q) {
		int ki, li;
		cin >> ki >> li;
		--ki;
		bsub(a[ki]);
		badd(li);
		a[ki] = li;
		cout << ltor.rbegin()->second << endl;
	}
	return 0;
}
