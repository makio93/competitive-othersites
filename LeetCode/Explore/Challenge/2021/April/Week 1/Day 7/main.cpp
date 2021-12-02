#include <bits/stdc++.h>
using namespace std;

class Solution {
    const string vowels = "aeiouAEIOU";
public:
    bool halvesAreAlike(string s) {
        int n = s.length();
        pair<int, int> vcnt = { 0, 0 };
        for (int i=0; i<n; ++i) for (char c : vowels) if (s[i] == c) {
            if (i < n/2) vcnt.first++;
            else vcnt.second++;
            break;
        }
        return (vcnt.first == vcnt.second);
    }
};

int main(){
    Solution cl;
    string s;
    cin >> s;
    if (cl.halvesAreAlike(s)) cout << "true" << endl;
    else cout << "false" << endl;
    return 0;
}
