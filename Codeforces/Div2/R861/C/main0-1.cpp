// 本番WA

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
	int t0;
	cin >> t0;
	rep(i0, t0) {
		ll l, r;
		cin >> l >> r;
		string lstr = to_string(l), rstr = to_string(r);
		int llen = lstr.length(), rlen = rstr.length();
		if (rlen > llen) {
			cout << string(llen, '9') << endl;
			continue;
		}
		if (rstr[0]-lstr[0] >= 2) {
			cout << string(llen, lstr[0]+1) << endl;
			continue;
		}
		auto calc = [](string str) -> int {
			int li = 10, ri = -1, slen = str.length();
			rep(i, slen) {
				li = min(li, str[i]-'0');
				ri = max(ri, str[i]-'0');
			}
			return max(0, ri-li);
		};
		if (lstr == rstr) {
			cout << lstr << endl;
			continue;
		}
		pair<int, string> mval = { 10, "" };
		mval = min(mval, { calc(lstr), lstr });
		mval = min(mval, { calc(rstr), rstr });
		string dstr = lstr, ustr = rstr;
		if (rstr[0] > lstr[0]) {
			bool ok = false;
			rep3(i, 1, llen) {
				if (!ok) {
					if (dstr[i] < dstr[i-1]) {
						ok = true;
						dstr[i] = dstr[i-1];
					}
				}
				else dstr[i] = dstr[i-1];
			}
			if (stoll(dstr)>=l && stoll(dstr)<=r) mval = min(mval, { calc(dstr), dstr });
			ok = false;
			rep3(i, 1, rlen) {
				if (!ok) {
					if (ustr[i] > ustr[i-1]) {
						ok = true;
						ustr[i] = ustr[i-1];
					}
				}
				else ustr[i] = ustr[i-1];
			}
			if (stoll(ustr)>=l && stoll(ustr)<=r) mval = min(mval, { calc(ustr), ustr });
		}
		else {
			int left = 0, lval = 10, rval = -1;
			while (left<llen && lstr[left]==rstr[left]) {
				lval = min(lval, lstr[left]-'0');
				rval = max(rval, lstr[left]-'0');
				++left;
			}
			if (rstr[left]-lstr[left] >= 2) {
				rep3(ci, lstr[left], rstr[left]+1) {
					string mstr = lstr.substr(0, left) + string(llen-left, (char)(ci));
					if (stoll(mstr)>=l && stoll(mstr)<=r) mval = min(mval, { calc(mstr), mstr });
				}
			}
			bool ok = false;
			rep3(i, left+1, llen) {
				if (!ok) {
					if (dstr[i] < dstr[i-1]) {
						ok = true;
						dstr[i] = dstr[i-1];
					}
				}
				else dstr[i] = dstr[i-1];
			}
			if (stoll(dstr)>=l && stoll(dstr)<=r) mval = min(mval, { calc(dstr), dstr });
			ok = false;
			rep3(i, left+1, rlen) {
				if (!ok) {
					if (ustr[i] > ustr[i-1]) {
						ok = true;
						ustr[i] = ustr[i-1];
					}
				}
				else ustr[i] = ustr[i-1];
			}
			if (stoll(ustr)>=l && stoll(ustr)<=r) mval = min(mval, { calc(ustr), ustr });
		}
		cout << mval.second << endl;
	}
	return 0;
}
