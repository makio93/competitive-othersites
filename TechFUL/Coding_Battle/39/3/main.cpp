#include <iostream>
#include <string>
using namespace std;

int main()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    bool ok = false;
    for (int i=1; i<n-1; ++i) if (s[i-1] == s[i+1]) ok = true;
    for (int i=1; i<n-2; ++i) if (s[i]==s[i+1] && s[i-1]==s[i+2]) ok = true;
    if (ok) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}
