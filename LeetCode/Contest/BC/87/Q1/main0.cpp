// 本番AC

#include <bits/stdc++.h>
using namespace std;

class Solution {
    const vector<int> days = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    int count_days(string mmdd) {
        int mval = stoi(mmdd.substr(0, 2)), dval = stoi(mmdd.substr(3, 2)), rval = 0;
        for (int i=0; i<mval-1; ++i) rval += days[i];
        rval += dval;
        return rval;
    }
public:
    int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob) {
        int al = count_days(arriveAlice), ar = count_days(leaveAlice), bl = count_days(arriveBob), br = count_days(leaveBob);
        return max(0, min(ar,br)-max(al,bl)+1);
    }
};
