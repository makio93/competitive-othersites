#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    vector<int> ord(n);
    for (int i=0; i<n; ++i) ord[i] = i;
    string ans = s;
    do {
        string tar;
        for (int i=0; i<n; ++i) tar.push_back(s[ord[i]]);
        int cnt = 0;
        for (int i=0; i<n; ++i) if (s[i] != tar[i]) ++cnt;
        if (cnt <= k) ans = min(ans, tar);
    } while (next_permutation(ord.begin(), ord.end()));
    cout << ans << endl;
    return 0;
}
