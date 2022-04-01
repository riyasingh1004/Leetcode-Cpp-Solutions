// Time Complexity O(n)
// dp array of size n + 1 is to save subproblem solutions. 
// dp[0] means an empty string will have one way to decode
// dp[1] means the way to decode a string of size 1. 
// Check one digit and two digit combination and save the results along the way. 
// In the end, dp[n] will be the end result.

class Solution {
public:
    int numDecodings(string s) {
        
        int n = s.size();
        int dp[n+1];
        if (s[0] == '0')
            return 0;
        dp[0] = 1;
        dp[1] = 1;
        for (int i = 2; i <= n; i++) {
            dp[i] = 0;
            if (s[i-1] > '0')
                dp[i] = dp[i-1];
            if (s[i-2] == '1' || (s[i-2] == '2' && s[i-1] < '7'))
                dp[i] += dp[i-2];
        }
        
        return dp[n];
    }
};