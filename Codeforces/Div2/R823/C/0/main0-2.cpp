// 自力AC

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
		string s;
		cin >> s;
		int n = s.length();
		auto calc = [&](string& str, char ti) -> void {
			if (count(all(str), ti) == 0) return;
			int li = INF, ri = -1;
			rep(i, n) {
				if (str[i] >= ti) li = min(li, i);
				if (str[i] == ti) ri = max(ri, i);
			}
			string tmp = str.substr(0, li);
			vector<int> vcnt(10), vid(10, ri);
			int tcnt = 0;
			rep3(i, li, ri+1) {
				if (s[i] > ti) vcnt[min(9, s[i]-'0'+1)]++;
				if (s[i] == ti) ++tcnt;
			}
			tmp += string(tcnt, ti);
			rep3(i, ri+1, n) vid[s[i]-'0'] = i;
			rep(i, 9) vid[i+1] = max(vid[i+1], vid[i]);
			int tid = ri + 1;
			rep3(i, ti-'0'+1, 10) {
				while (tid <= vid[i]) {
					if (tid>ri && tid<n) tmp.push_back(str[tid]);
					++tid;
				}
				if (vcnt[i] > 0) tmp += string(vcnt[i], (char)(i+'0'));
			}
			swap(str, tmp);
		};
		for (char ci='0'; ci<='9'; ++ci) {
			bool fin = true;
			for (int i=0; i+1<n; ++i) if (s[i+1] < s[i]) {
				fin = false;
				break;
			}
			if (fin) break;
			calc(s, ci);
		}
		cout << s << endl;
	}
	return 0;
}
