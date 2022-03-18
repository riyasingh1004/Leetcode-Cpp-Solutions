// Time Complexity O(mn)
// To apply DP, we define the state dp[i][j] to be the minimum number of operations to convert word1[0..i) to word2[0..j).

// For the base case, that is, to convert a string to an empty string, the mininum number of operations (deletions) is just the length of the string. So we have dp[i][0] = i and dp[0][j] = j.

// For the general case to convert word1[0..i) to word2[0..j), we break this problem down into sub-problems. Suppose we have already known how to convert word1[0..i - 1) to word2[0..j - 1) (dp[i - 1][j - 1]), if word1[i - 1] == word2[j - 1], then no more operation is needed and dp[i][j] = dp[i - 1][j - 1].

// If word1[i - 1] != word2[j - 1], we need to consider three cases.

// 1.Replace word1[i - 1] by word2[j - 1] (dp[i][j] = dp[i - 1][j - 1] + 1);
// 2.If word1[0..i - 1) = word2[0..j) then delete word1[i - 1] (dp[i][j] = dp[i - 1][j] + 1);
// 3.If word1[0..i) + word2[j - 1] = word2[0..j) then insert word2[j - 1] to word1[0..i) (dp[i][j] = dp[i][j - 1] + 1).
// So when word1[i - 1] != word2[j - 1], dp[i][j] will just be the minimum of the above three cases.

class Solution {
public:
    int minDistance(string word1, string word2) {
        
        int m = word1.size();
        int n = word2.size();
        
        int L[m+1][n+1];
        
        for (int i = 0; i <= m; i++) {
            for (int j = 0; j <= n; j++) {
                if (i == 0)
                    L[i][j] = j;
                else if (j == 0)
                    L[i][j] = i;
                else if (word1[i-1] == word2[j-1])
                    L[i][j] = L[i-1][j-1];
                else
                    L[i][j] = 1 + min(min(L[i-1][j-1], L[i-1][j]),L[i][j-1]);
            }
        }
        
        return L[m][n];
        
    }
};