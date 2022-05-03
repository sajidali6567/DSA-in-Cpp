class Solution {
public:
    int climbStairs(int n) {
        vector<int> dp(n+1, -1);
        if(n == 0 || n == 1) {
            return 1;
        }
        dp[0] = dp[1] = 1;
        return climbStairsRec(n, dp);
    }
    int climbStairsRec(int n, vector<int>& dp) {
        for(int i=2;i<=n;i++) {
            dp[i] = dp[i-1] + dp[i-2];
        }
        return dp[n];
    } 
};