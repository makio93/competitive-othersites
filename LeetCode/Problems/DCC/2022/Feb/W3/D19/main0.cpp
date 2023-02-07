// 自力解答,WA

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumDeviation(vector<int>& nums) {
        int n = nums.size();
        vector<int> odd, even;
        for (int i=0; i<n; ++i) {
            if (nums[i]%2 == 1) odd.push_back(nums[i]);
            else even.push_back(nums[i]);
        }
        int mval = 0;
        if (!even.empty()) {
            vector<pair<int, int>> evals;
            for (int i=0; i<(int)(even.size()); ++i) {
                int eval = even[i];
                while (eval%2 == 0) eval /= 2;
                evals.emplace_back(eval, i);
            }
            sort(evals.rbegin(), evals.rend());
            mval = evals.front().first;
        }
        if (odd.empty()) {
            int li = 0, ri = (int)(1e9);
            while (ri-li > 1) {
                int ci = li + (ri-li) / 2;
                bool ok = true;
                for (int i=0; i<(int)(even.size()); ++i) {
                    int tval = even[i];
                    while (tval-mval > ci) tval /= 2;
                    if (abs(tval-mval) > ci) {
                        ok = false;
                        break;
                    }
                }
                if (ok) ri = ci;
                else li = ci;
            }
            int hval1 = 0, lval1 = (int)(1e9), hval2 = 0, lval2 = (int)(1e9);
            for (int i=0; i<(int)(even.size()); ++i) {
                int tval = even[i];
                while (tval-mval > ri) tval /= 2;
                hval1 = max(hval1, tval);
                lval1 = min(lval1, tval);
                if (tval%2==0 && mval-tval/2<=ri) tval /= 2;
                hval2 = max(hval2, tval);
                lval2 = min(lval2, tval);
            }
            return min(hval1-lval1, hval2-lval2);
        }
        else {
            sort(odd.rbegin(), odd.rend());
            mval = max(mval, odd.front());
            int li = 0, ri = (int)(1e9);
            while (ri-li > 1) {
                int ci = li + (ri-li) / 2;
                bool ok = true;
                if (!even.empty()) {
                    for (int i=0; i<(int)(even.size()); ++i) {
                        int tval = even[i];
                        while (tval-mval > ci) tval /= 2;
                        if (abs(tval-mval) > ci) {
                            ok = false;
                            break;
                        }
                    }
                }
                if (ok) {
                    for (int i=0; i<(int)(odd.size()); ++i) {
                        int tval = odd[i];
                        if (mval-tval > ci) tval *= 2;
                        if (abs(mval-tval) > ci) {
                            ok = false;
                            break;
                        }
                    }
                }
                if (ok) ri = ci;
                else li = ci;
            }
            int hval1 = 0, lval1 = (int)(1e9), hval2 = 0, lval2 = (int)(1e9);
            if (!even.empty()) {
                for (int i=0; i<(int)(even.size()); ++i) {
                    int tval = even[i];
                    while (tval-mval > ri) tval /= 2;
                    hval1 = max(hval1, tval);
                    lval1 = min(lval1, tval);
                    if (tval%2==0 && mval-tval/2<=ri) tval /= 2;
                    hval2 = max(hval2, tval);
                    lval2 = min(lval2, tval);
                }
            }
            for (int i=0; i<(int)(odd.size()); ++i) {
                int tval = odd[i];
                if (mval-tval > ri) tval *= 2;
                hval1 = max(hval1, tval);
                lval1 = min(lval1, tval);
                hval2 = max(hval2, tval);
                lval2 = min(lval2, tval);
            }
            return min(hval1-lval1, hval2-lval2);
        }
    }
};
