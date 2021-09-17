class Solution {
    public int maxTurbulenceSize(int[] arr) {
        int n = arr.length, ans = 1, lid = 0;
        for (int i=1; i<n; ++i) {
            int ci = Integer.compare(arr[i-1],arr[i]);
            if (ci == 0) lid = i;
            else if (i+1>=n || ci*Integer.compare(arr[i],arr[i+1])!=-1) {
                ans = Math.max(ans, i-lid+1);
                lid = i;
            }
        }
        return ans;
    }
}
