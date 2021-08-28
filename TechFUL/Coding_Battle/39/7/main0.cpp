#include <iostream>
#include <string>
#include <vector>
#include <set>
using namespace std;

// 本番WA,1

int main()
{
    string s;
    cin >> s;
    int n = s.length();
    vector<set<char>> used(n);
    for (int i=0; i<n; ++i) used[i].insert(s[i]);
    vector<set<int>> cvec(26);
    for (int i=0; i<n; ++i) cvec[s[i]-'a'].insert(i);
    long long res = 0;
    for (int i=0; i<n; ++i) {
        int sum = 0;
        for (int j=0; j<26; ++j) if (used[i].find((char)(j+'a')) == used[i].end()) {
            for (auto id : cvec[j]) if (used[id].find(s[i])==used[id].end() && used[i].find(s[id])==used[i].end()) {
                ++sum;
                used[id].insert(s[i]);
                used[i].insert((char)(j+'a'));
                break;
            }
        }
        cvec[s[i]-'a'].erase(i);
        res += sum;
    }
    cout << res << endl;
    return 0;
}
