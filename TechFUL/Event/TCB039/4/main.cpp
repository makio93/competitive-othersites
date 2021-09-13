#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
    vector<vector<char>> a(5, vector<char>(5));
    for (int i=0; i<5; ++i) for (int j=0; j<5; ++j) cin >> a[i][j];
    int k;
    cin >> k;
    vector<char> b(k);
    for (int i=0; i<k; ++i) cin >> b[i];
    vector<vector<bool>> holes(5, vector<bool>(5));
    for (int i0=0; i0<k; ++i0) {
        for (int i=0; i<5; ++i) for (int j=0; j<5; ++j) if (a[i][j] == b[i0]) holes[i][j] = true;
    }
    bool ok = false;
    for (int i=0; i<5; ++i) {
        bool ok2 = true;
        for (int j=0; j<5; ++j) if (!holes[i][j]) ok2 = false;
        if (ok2) ok = true;
    }
    for (int j=0; j<5; ++j) {
        bool ok2 = true;
        for (int i=0; i<5; ++i) if (!holes[i][j]) ok2 = false;
        if (ok2) ok = true;
    }
    {
        bool ok2 = true;
        for (int i=0; i<5; ++i) if (!holes[i][i]) ok2 = false;
        if (ok2) ok = true;
    }
    {
        bool ok2 = true;
        for (int i=0; i<5; ++i) if (!holes[i][4-i]) ok2 = false;
        if (ok2) ok = true;
    }
    if (ok) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}
