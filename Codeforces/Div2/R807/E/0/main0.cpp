// 本番,WA

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
	map<int, int> acnt, scnt;
	rep(i, n) acnt[a[i]]++;
	auto tcnt = acnt;
	for (auto itr=tcnt.begin(); itr!=tcnt.end(); ) {
		scnt[itr->first] = itr->second;
		if (itr->second >= 2) {
			tcnt[itr->first+1] += itr->second / 2;
			tcnt[itr->first] %= 2;
		}
		if (tcnt[itr->first] == 0) itr = tcnt.erase(itr);
		else ++itr;
	}
	rep(i, q) {
		int ki, li;
		cin >> ki >> li;
		--ki;
		int aval = a[ki], bval = li;
		a[ki] = li;
		acnt[aval]--;
		acnt[bval]++;
		if (acnt[aval] == 0) acnt.erase(aval);
		map<int, int> tcnt;
		tcnt[aval] = scnt[aval] - 1;
		if (acnt.find(aval) != acnt.end()) tcnt[aval] -= acnt[aval];
		for (auto itr=tcnt.find(aval); itr!=tcnt.end(); ++itr) {
			if (acnt.find(itr->first) != acnt.end()) tcnt[itr->first] += acnt[itr->first];
			if (scnt.find(itr->first)!=scnt.end() && scnt[itr->first]==itr->second) break;
			scnt[itr->first] = itr->second;
			if (scnt[itr->first] == 0) scnt.erase(itr->first);
			if (itr->second >= 2) {
				tcnt[itr->first+1] += itr->second / 2;
				tcnt[itr->first] %= 2;
			}
		}
		tcnt.clear();
		tcnt[bval] = scnt[bval] + 1;
		if (acnt.find(bval) != acnt.end()) tcnt[bval] -= acnt[bval];
		for (auto itr=tcnt.find(bval); itr!=tcnt.end(); ++itr) {
			if (acnt.find(itr->first) != acnt.end()) tcnt[itr->first] += acnt[itr->first];
			if ((scnt.find(itr->first)!=scnt.end()&&scnt[itr->first]==itr->second) || (scnt.find(itr->first)==scnt.end()&&itr->second==0)) break;
			scnt[itr->first] = itr->second;
			if (scnt[itr->first] == 0) scnt.erase(itr->first);
			tcnt[itr->first+1] += itr->second / 2;
			tcnt[itr->first] %= 2;
		}
		cout << scnt.rbegin()->first << endl;
	}
	return 0;
}
