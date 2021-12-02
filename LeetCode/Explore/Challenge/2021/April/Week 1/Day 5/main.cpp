#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isIdealPermutation(vector<int>& A) {
        int n = A.size(), gcnt = 0, lcnt = 0;
        set<int> visited;
        for (int i=n-1; i>=0; --i) {
            gcnt += distance(visited.begin(), visited.lower_bound(A[i]));
            visited.insert(A[i]);
        }
        for (int i=0; i+1<n; ++i) if (A[i] > A[i+1]) ++lcnt;
        return (gcnt == lcnt);
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
