// 解説AC

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
	int n, m, q;
	string s;
	cin >> n >> m >> q >> s;
	set<int> ids;
	rep(i, n) ids.insert(i);
	vector<int> tlst;
	rep(i, m) {
		int li, ri;
		cin >> li >> ri;
		--li;
		auto itr = ids.lower_bound(li);
		while (itr!=ids.end() && *itr<ri) {
			tlst.push_back(*itr);
			itr = ids.erase(itr);
		}
	}
	int tlen = tlst.size();
	vector<int> stots(n, -1);
	rep(i, tlen) stots[tlst[i]] = i;
	int xcnt = count(all(s), '1'), rval = 0;
	rep(i, xcnt) {
		if (i >= tlen) break;
		if (s[tlst[i]] == '0') ++rval;
	}
	rep(i, q) {
		int xi;
		cin >> xi;
		--xi;
		if (stots[xi] != -1 && stots[xi] < xcnt) {
			if (s[xi] == '0') --rval;
			else ++rval;
		}
		if (s[xi] == '0') {
			s[xi] = '1';
			++xcnt;
			if (xcnt-1 < tlen && s[tlst[xcnt-1]] == '0') ++rval;
		}
		else {
			s[xi] = '0';
			if (xcnt-1 < tlen && s[tlst[xcnt-1]] == '0') --rval;
			--xcnt;
		}
		cout << rval << endl;
	}
	return 0;
}
