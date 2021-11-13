#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define rep(i, n) for (int i=0; i<(int)(n); ++(i))
#define rep3(i, m, n) for (int i=(m); (i)<(int)(n); ++(i))
#define repr(i, n) for (int i=(int)(n)-1; (i)>=0; --(i))
#define rep3r(i, m, n) for (int i=(int)(n)-1; (i)>=(int)(m); --(i))
#define all(x) (x).begin(), (x).end()

// バチャ本番AC

const string tar = "CDEFGABC", sharp = "ACDFG";

int main() {
	string s;
	cin >> s;
	if (sharp.find(s.front()) != string::npos) s.push_back('#');
	else s.front() = tar[(tar.find(s.front())+1)%tar.length()];
	cout << s << endl;
	return 0;
}
