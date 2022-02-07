#include <bits/stdc++.h>
using namespace std;

// 自力AC

class MyCalendar {
    int id;
    map<int, int> books;
public:
    MyCalendar() { id = 0; }
    bool book(int start, int end) {
        bool res = false;
        int left = -1;
        if (books.empty()) res = true;
        else {
            auto sitr = books.upper_bound(start), eitr = books.upper_bound(end-1);
            if (sitr==books.begin() && eitr==books.begin()) res = true;
            else if (sitr!=books.begin() && eitr!=books.begin()) {
                --sitr; --eitr;
                if (sitr->second<0 && sitr->second==eitr->second) {
                    res = true;
                    left = sitr->first;
                }
            }
        }
        if (!res) return res;
        if (left == -1) {
            if (books.find(end) == books.end()) {
                books[start] = ++id;
                books[end] = -books[start];
            }
            else {
                books[start] = books[end];
                books.erase(end);
            }
        }
        else if (left == start) {
            if (books.find(end) == books.end()) {
                books[end] = books[start];
                books.erase(start);
            }
            else {
                next(books.find(end))->second = books[start];
                books.erase(start);
                books.erase(end);
            }
        }
        else {
            if (books.find(end) == books.end()) {
                books[start] = ++id;
                books[end] = -books[start];
            }
            else {
                books[start] = books[end];
                books.erase(end);
            }
        }
        return res;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */
