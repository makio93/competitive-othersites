#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isIdealPermutation(vector<int>& A) {
        int n = A.size();
        for (int i=0; i+1<n; ++i) if (A[i]==i+1&&A[i+1]==i) swap(A[i], A[i+1]);
        bool ok = true;
        for (int i=0; i<n; ++i) if (A[i] != i) ok = false;
        return ok;
    }
};

int main(){
    Solution cl;
    int n;
    cin >> n;
    vector<int> A(n);
    for (int i=0; i<n; ++i) cin >> A[i];
    if (cl.isIdealPermutation(A)) cout << "true" << endl;
    else cout << "false" << endl;
    return 0;
}
