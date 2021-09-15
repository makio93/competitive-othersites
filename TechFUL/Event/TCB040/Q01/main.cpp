#include <iostream>
#include <string>
using namespace std;

const string tar = "[(])";

int main() {
    string s;
    cin >> s;
    bool ok = true;
    for (int i=0; i<2; ++i) for (int j=0; j<4; ++j) if (s[i] == tar[j]) {
        if (j/2 != i) ok = false; 
    }
    cout << (ok ? "Yes" : "No") << endl;
    return 0;
}
