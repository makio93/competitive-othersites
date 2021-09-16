#include <iostream>
#include <vector>
#include <string>
using namespace std;

const vector<string> types = { "fire", "wood", "water" };

int main() {
    int n, p;
    string m, q;
    cin >> n >> m >> p >> q;
    for (int i=0; i<3; ++i) if (m == types[i]) {
        if (q == types[(i+1)%3]) n *= 2;
        else if (q == types[(i+2)%3]) p *= 2;
    }
    if (n > p) cout << "win" << endl;
    else if (n < p) cout << "lose" << endl;
    else cout << "draw" << endl;
    return 0;
}
