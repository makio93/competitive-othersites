#include <bits/stdc++.h>
using namespace std;

// 解説AC

class Solution {
public:
    int getXORSum(vector<int>& arr1, vector<int>& arr2) {
        int n1 = arr1.size(), n2 = arr2.size();
        int xval1 = 0, xval2 = 0;
        for (int i=0; i<n1; ++i) xval1 ^= arr1[i];
        for (int i=0; i<n2; ++i) xval2 ^= arr2[i];
        return (xval1 & xval2);
    }
};
