// 自力WA

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define rep(i, n) for (int i=0; i<(int)(n); ++(i))
#define rep3(i, m, n) for (int i=(m); (i)<(int)(n); ++(i))
#define repr(i, n) for (int i=(int)(n)-1; (i)>=0; --(i))
#define rep3r(i, m, n) for (int i=(int)(n)-1; (i)>=(int)(m); --(i))
#define all(x) (x).begin(), (x).end()

const int INF = (int)(1e9);

void output(vector<int>& vlst) {
	int n = vlst.size();
	vector<int> vlst2(n);
	rep(i, n) vlst2[i] = n + 1 - vlst[i];
	cout << "! ";
	rep(i, n) cout << vlst[i] << ' ';
	rep(i, n) cout << vlst2[i] << (i<n-1?' ':'\n');
	cout << endl;
	cout.flush();
	int val;
	cin >> val;
	if (val != 1) exit(0);
}

void query1(int xi) {
	cout << "+ " << xi << '\n';
	cout << endl;
	cout.flush();
	int val;
	cin >> val;
	if (val == -2) exit(0);
}

int query2(int a, int b) {
	cout << "? " << a << ' ' << b << '\n';
	cout << endl;
	cout.flush();
	int val;
	cin >> val;
	if (val == -2) exit(0);
	return val;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t0;
	cin >> t0;
	rep(i0, t0) {
		int n;
		cin >> n;
		vector<int> res(n);
		if (n == 2) {
			rep(i, n) res[i] = i + 1;
			output(res);
			continue;
		}
		query1(n+1);
		query1(n+2);
		vector<vector<int>> vlst1(n);
		rep3(i, 1, n) vlst1[query2(1, i+1)].push_back(i);
		int ri = -1;
		rep(i, n) if ((int)(vlst1[i].size()) == 2) ri = max(ri, i);
		if (ri == -1) {
			res[0] = 1;
			rep3(i, 1, n) if (!vlst1[i].empty()) res[vlst1[i][0]] = i + 1;
		}
		else if (vlst1[ri+1].empty()) {
			int si = vlst1[ri][0], ti = vlst1[ri][1];
			res[si] = 1;
			res[ti] = n;
			rep(i, n) if (i!=si && i!=ti) res[i] = query2(si+1, i+1) + 1;
		}
		else {
			int tval = ri * 2 + 1;
			rep3(i, ri+1, n) {
				if (vlst1[i].empty()) break;
				++tval;
				res[vlst1[i][0]] = tval;
			}
			int si = vlst1[ri+1][0];
			tval = ri * 2 + 2;
			rep(i, n) if (res[i] == 0) res[i] = tval - query2(si+1, i+1);
		}
		output(res);
	}
	return 0;
}
