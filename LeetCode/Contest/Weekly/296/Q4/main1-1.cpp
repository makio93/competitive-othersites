// 解説AC1

#include <bits/stdc++.h>
using namespace std;

class TextEditor {
    stack<char> left, right;
public:
    TextEditor() {}
    void addText(string text) {
        for (char ci : text) left.push(ci);
    }
    int deleteText(int k) {
        int cnt = 0;
        while (k--) {
            if (left.empty()) break;
            left.pop();
            ++cnt;
        }
        return cnt;
    }
    string display() {
        string tmp;
        for (int i=0; i<10; ++i) {
            if (left.empty()) break;
            tmp.push_back(left.top());
            left.pop();
        }
        reverse(tmp.begin(), tmp.end());
        for (char ci : tmp) left.push(ci);
        return tmp;
    }
    string cursorLeft(int k) {
        while (k--) {
            if (left.empty()) break;
            right.push(left.top());
            left.pop();
        }
        return display();
    }
    string cursorRight(int k) {
        while (k--) {
            if (right.empty()) break;
            left.push(right.top());
            right.pop();
        }
        return display();
    }
};

/**
 * Your TextEditor object will be instantiated and called as such:
 * TextEditor* obj = new TextEditor();
 * obj->addText(text);
 * int param_2 = obj->deleteText(k);
 * string param_3 = obj->cursorLeft(k);
 * string param_4 = obj->cursorRight(k);
 */
