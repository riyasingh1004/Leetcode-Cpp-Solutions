// Time Complexity O(n)
// dp[i] is the number of combinations possible when N = 2*i;
// dp[1] = 1, dp[2] = 2, dp[3] = 5;
// dp[n] = {dp[n-1] + dp[n-2]} + 1 step
// dp[n] = {dp[n-3], dp[n-4]... dp[0]} + 2 steps;
/* formula : dp[n] = dp[n-1] + dp[n-2] + 2*(dp[n-3] ... dp[0])
                   = dp[n-1] + dp[n-3] + {d[n-2] + dp[n-3] + 2*(dp[n-4] ... dp[0])} --> dp[n-1]
                   = dp[n-1] + dp[n-3] + dp[n-1]
    Final Formula = 2*dp[n-1] + dp[n-3];
*/

class Solution {
public:
    int mod=1e9+7;
    int numTilings(int N) {
        
        vector<long long> dp(1001,0);
        dp[1]=1;
        dp[2]=2;
        dp[3]=5;
        if(N<=3)
            return dp[N];
        for (int i = 4;i <= N; i++){
            dp[i] = 2*dp[i-1] + dp[i-3]; 
            dp[i] %= mod;
        }
        
        return dp[N];
    }
};