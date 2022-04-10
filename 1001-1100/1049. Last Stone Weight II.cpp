// Time Complexity O(n*sum/2)
/* Explaination
This problem can be converted into a knapsack problem.
Stones = [x, y, a, b, c]. Remove (x, y). Put in z = y - x
Stones = [z, a, b, c]. Remove (a, b). Put in d = b - a
Stones = [z, d, c]. Remove (d, c). Put in e = c - d
Stones = [z, e]. Remove (z, e) Put in add in Z = e - z
Stones = [Z].

Z = (z) - (e)
  = (z) - (d - c)
  = (z) - ((a - b) - c)
  = (x - y) - ((a - b) - c)
  = (x - y) -(a - b) + c
  = x - y - a + b + c
  = (x + b + c) - (y + a + c)
 = X - Y  [X = (x + b + c) Y = (y + a + c)]

 We get two formulas from this :
 S = X + Y (sum)
 D = X - Y (difference)
 We need to find the minimum value of D, so we combine the two formulas
 D = S - 2*Y;
 When D = 0, Y = S/2;
 Therefore find the maximum value of Y for all items with Knapsack capacity S/2
    */


class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
        
        int n = stones.size();
        int sum = accumulate(stones.begin(), stones.end(), 0);
        int dp[n+1][sum/2 + 1];
        memset(dp,0,sizeof(dp));
        
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= sum/2; j++) {
                if (stones[i-1] <= j)
                    dp[i][j] = max(dp[i-1][j], stones[i-1] + dp[i-1][j-stones[i-1]]);
                else
                    dp[i][j] = dp[i-1][j];
            }
        }
        
        return sum - 2*dp[n][sum/2];
    }
};