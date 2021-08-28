#include <iostream>
#include <string>
#include <vector>
#include <set>
using namespace std;

int main()
{
    string s;
    cin >> s;
    int n = s.length();
    vector<vector<set<int>>> unused(26, vector<set<int>>(26));
    for (int i0=0; i0<n; ++i0) for (int i=0; i<26; ++i) if (i != (int)(s[i0]-'a')) unused[s[i0]-'a'][i].insert(i0);
    vector<set<int>> units(n);
    for (int i=0; i<n; ++i) units[i].insert((int)(s[i]-'a'));
    int res = 0;
    for (int i0=0; i0<n; ++i0) {
        for (int i=0; i<26; ++i) if (units[i0].find(i) == units[i0].end()) {
            if (!unused[i][s[i0]-'a'].empty()) {
                ++res;
                int id = *unused[i][s[i0]-'a'].begin();
                unused[i][s[i0]-'a'].erase(id);
                unused[s[i0]-'a'][i].erase(i0);
                units[id].insert(s[i0]-'a');
                units[i0].insert(i);
            }
        }
        for (int i=0; i<26; ++i) if (unused[s[i0]-'a'][i].find(i0) != unused[s[i0]-'a'][i].end()) unused[s[i0]-'a'][i].erase(i0);
    }
    cout << res << endl;
    return 0;
}
