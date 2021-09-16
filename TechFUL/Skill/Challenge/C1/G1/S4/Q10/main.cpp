#include <iostream>
#include <string>
using namespace std;

using ll = long long;

int main() {
    string c;
    int n;
    cin >> c >> n;
    int x = 0;
    for (char ci : c) x += ci - '0';
    if (stoll(c)%x == n) cout << "real" << endl;
    else cout << "fake" << endl;
    return 0;
}
