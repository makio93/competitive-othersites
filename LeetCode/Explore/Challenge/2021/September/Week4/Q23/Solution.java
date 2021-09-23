// 解説AC

class Solution {
    public String breakPalindrome(String palindrome) {
        int n = palindrome.length();
        if (n == 1) return "";
        char[] res = palindrome.toCharArray();
        for (int i=0; i<n/2; ++i) if (res[i] != 'a') {
            res[i] = 'a';
            return String.valueOf(res);
        }
        res[n-1] = 'b';
        return String.valueOf(res);
    }
}
