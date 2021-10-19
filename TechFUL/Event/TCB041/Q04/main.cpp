#include <iostream>
#include <map>
using namespace std;

int main() {
    int q;
    cin >> q;
    map<int, int> acnt;
    for (int i=0; i<q; ++i) {
        int qi, ai;
        cin >> qi >> ai;
        if (qi == 1) { if (acnt.find(ai) == acnt.end()) acnt[ai] = i+1; }
        else {
            if (acnt.find(ai) != acnt.end()) cout << acnt[ai] << endl;
            else cout << -1 << endl;
        }
    }
    return 0;
}
