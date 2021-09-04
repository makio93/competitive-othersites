#include <bits/stdc++.h>
using namespace std;

// 自力AC

class Solution {
    const int INF = (int)(1e4);
public:
    vector<vector<int>> outerTrees(vector<vector<int>>& trees) {
        int n = trees.size();
        vector<map<int, int>> xy(2);
        for (int i=0; i<n; ++i) for (int j=0; j<2; ++j) {
            if (xy[j].find(trees[i][0]) == xy[j].end()) xy[j][trees[i][0]] = trees[i][1];
            else {
                if (j == 0) xy[j][trees[i][0]] = max(xy[j][trees[i][0]], trees[i][1]);
                else xy[j][trees[i][0]] = min(xy[j][trees[i][0]], trees[i][1]);
            }
        }
        set<pair<int, int>> choosed;
        for (int i1=0; i1<2; ++i1) {
            pair<int, int> rpos = { xy[i1].begin()->first, xy[i1].begin()->second }, tfrac = { 1, -1 }, tpos = { -1, -1 };
            choosed.insert(rpos);
            set<pair<int, int>> ins;
            vector<int> ops = { 1, -1 };
            auto itr = xy[i1].begin();
            while (next(itr) != xy[i1].end()) {
                auto fcalc = [](pair<int, int> ri, pair<int, int> ti) -> pair<int, int> {
                    if (abs(ti.second-ri.second) > 0) {
                        int gi = gcd(ti.first-ri.first, abs(ti.second-ri.second));
                        return { (ti.first-ri.first)/gi, (ti.second-ri.second)/gi };
                    }
                    else return { ti.first-ri.first, 0 };
                };
                auto fcomp = [](pair<int, int> fs, pair<int, int> ft, int op) -> bool {
                    int li = lcm(fs.first, ft.first);
                    if (op == 0) return (ft.second*(li/ft.first) == fs.second*(li/fs.first));
                    else if (op > 0) return (ft.second*(li/ft.first) > fs.second*(li/fs.first));
                    else return (ft.second*(li/ft.first) < fs.second*(li/fs.first));
                };
                auto nitr = next(itr);
                pair<int, int> tfrac = fcalc(*itr, *nitr);
                set<pair<int, int>> ins;
                int xmax = 0;
                while (nitr != xy[i1].end()) {
                    if (fcomp(tfrac, fcalc(*itr, *nitr), 0)) {
                        ins.insert(*nitr);
                        xmax = max(xmax, nitr->first);
                    }
                    else if (fcomp(tfrac, fcalc(*itr, *nitr), ops[i1])) {
                        ins.clear();
                        ins.insert(*nitr);
                        tfrac = fcalc(*itr, *nitr);
                        xmax = nitr->first;
                    }
                    ++nitr;
                }
                for (auto p : ins) choosed.insert(p);
                itr = xy[i1].find(xmax);
            }
        }
        int lid = xy.front().begin()->first, rid = xy.front().rbegin()->first;
        for (int i=0; i<n; ++i) if (trees[i][0]==lid || trees[i][0]==rid) choosed.emplace(trees[i][0], trees[i][1]);
        vector<vector<int>> res;
        for (auto p : choosed) res.push_back({ p.first, p.second });
        return res;
    }
};
