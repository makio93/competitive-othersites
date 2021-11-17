#include <iostream>
#include <string>
#include <vector>
using namespace std;

const vector<string> tar = { "()", "{}", "[]" };

int main() {
    string s;
    cin >> s;
    bool ok = false;
    for (string ti : tar) if (s == ti) ok = true;
    if (ok) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}
