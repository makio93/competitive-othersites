#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

// 本番AC

int main()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<vector<int>> ids(26);
    for (int i=0; i<n; ++i) ids[s[i]-'a'].push_back(i);
    int mval = 0;
    for (int i=0; i<26; ++i) mval = max(mval, (int)(ids[i].size()));
    if (mval <= 1) cout << 0 << endl;
    else if (mval > 2) cout << max(0,n-2) << endl;
    else {
        vector<pair<int, int>> terms;
        int mterm = n;
        for (int i=0; i<26; ++i) if ((int)(ids[i].size()) == 2) {
            terms.emplace_back(ids[i][1], ids[i][0]);
            mterm = min(mterm, ids[i][1]-ids[i][0]+1);
        }
        sort(terms.begin(), terms.end());
        bool three = false, two = false;
        int m = terms.size(), rest = n;
        for (int i=0; i<m; ++i) {
            for (int j=i+1; j<m; ++j) {
                if (terms[j].second<terms[i].first && terms[i].second<terms[j].second) {
                    three = true;
                    rest = min(rest, terms[i].first-terms[j].second-1);
                }
                if (terms[i].first < terms[j].second) two = true;
            }
        }
        int res = mterm;
        if (two) res = min(res, 2);
        else if (three) res = min(res, 3+rest);
        cout << max(0, n-res) << endl;
    }
    return 0;
}
