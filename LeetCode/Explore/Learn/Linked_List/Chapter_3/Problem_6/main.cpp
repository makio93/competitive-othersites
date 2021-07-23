#include <bits/stdc++.h>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// 自力解答,AC

class Solution {
    const long long mod = (long long)(1e9) + 7;
    long long modpow(long long a, long long b) {
        long long p = 1, q = a;
        while (b > 0LL) {
            if (b&1LL) p = p * q % mod;
            b /= 2;
            q = q * q % mod;
        }
        return p;
    }
public:
    bool isPalindrome(ListNode* head) {
        if (head == nullptr) return false;
        ListNode* p = head;
        int n = 0;
        while (p != nullptr) {
            p = p->next;
            ++n;
        }
        p = head;
        long long hval1 = 0, hval2 = 0;
        for (int i=0; i<n; ++i) {
            if (i < n/2) hval1 = (hval1 * 10 + p->val) % mod;
            else if (i >= n-n/2) hval2 = (hval2 + p->val * modpow(10, i-(n-n/2))) % mod;
            p = p->next;
        }
        return (hval1 == hval2);
    }
};
