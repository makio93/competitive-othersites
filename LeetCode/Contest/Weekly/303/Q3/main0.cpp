// 本番AC

#include <bits/stdc++.h>
using namespace std;

class FoodRatings {
    unordered_map<string, pair<string, int>> foodlist;
    unordered_map<string, map<int, set<string>>> ranks;
public:
    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        int n = foods.size();
        for (int i=0; i<n; ++i) {
            foodlist[foods[i]] = { cuisines[i], ratings[i] };
            ranks[cuisines[i]][ratings[i]].insert(foods[i]);
        }
    }
    void changeRating(string food, int newRating) {
        auto old = foodlist[food];
        ranks[old.first][old.second].erase(food);
        if (ranks[old.first][old.second].empty()) ranks[old.first].erase(old.second);
        foodlist[food].second = newRating;
        ranks[old.first][newRating].insert(food);
    }
    string highestRated(string cuisine) {
        return *ranks[cuisine].rbegin()->second.begin();
    }
};

/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
 * obj->changeRating(food,newRating);
 * string param_2 = obj->highestRated(cuisine);
 */
