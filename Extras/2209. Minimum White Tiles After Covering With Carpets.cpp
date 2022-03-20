// Time Complexity O(N)

// dp[i][k] means that,
// using k tiles to cover the first i tiles
// the minimum number of white tiles still visible.

// For each tile s[i], we heve two options,
// One option is doing nothing, jump this tile,
// jump = dp[i - 1][k] + int(s[i - 1])
// The other option is covering this tile
// cover = dp[i - l][k - 1]

// Then we take the minimum result of two options:
// dp[i][k] = min(jump, cover)

// Finally after explore all combination of (i,k),
// we return dp[n][nc].

class Solution {
public:
    int minimumWhiteTiles(string s, int nc, int l) {
       
         int n = s.size();
        vector<vector<int>> dp(n + 1, vector<int>(nc + 1));
        for (int i = 1; i <= n; i++) {
            for (int k = 0; k <= nc; k++) {
                int jump = dp[i - 1][k] + s[i - 1] - '0';
                int cover = k > 0 ? dp[max(i - l, 0)][k - 1] : 1000;
                dp[i][k] = min(cover, jump);
            }
        }
        
        return dp[n][nc];
    }
};