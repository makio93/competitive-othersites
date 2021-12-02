#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minAbsoluteSumDiff(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        set<int> nlst;
        for (int i=0; i<n; ++i) nlst.insert(nums1[i]);
        int msub = 0;
        for (int i=0; i<n; ++i) {
            auto itr = nlst.lower_bound(nums2[i]);
            int tsub;
            if (itr == nlst.end()) tsub = abs(*prev(itr)-nums2[i]);
            else if (itr == nlst.begin()) tsub = abs(*itr-nums2[i]);
            else tsub = min(abs(*itr-nums2[i]),abs(*prev(itr)-nums2[i]));
            msub = max(msub, abs(nums1[i]-nums2[i])-tsub);
        }
        long long sum = 0;
        for (int i=0; i<n; ++i) sum += abs(nums1[i]-nums2[i]);
        sum -= msub;
        return (int)(sum % (long long)((1e9)+7));
    }
};

int main(){
    Solution cl;
    int n;
    cin >> n;
    vector<int> nums1(n), nums2(n);
    for (int i=0; i<n; ++i) cin >> nums1[i];
    for (int i=0; i<n; ++i) cin >> nums2[i];
    cout << cl.minAbsoluteSumDiff(nums1, nums2) << endl;
    return 0;
}
