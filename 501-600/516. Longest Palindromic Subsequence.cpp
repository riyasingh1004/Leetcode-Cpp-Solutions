// Time Complexity O(n*n)

class Solution {
public:
    int longestPalindromeSubseq(string A) {
        
        string B = A;
        reverse(B.begin(),B.end());
        int n = A.length();
        
        int t[n+1][n+1];
        for (int i = 0; i <= n; i++) {
            for (int j = 0; j <= n; j++) {
                if (i == 0 || j == 0)
                    t[i][j] = 0;
                else if (A[i-1] == B[j-1])
                    t[i][j] = 1 + t[i-1][j-1];
                else
                    t[i][j] = max(t[i-1][j], t[i][j-1]);
            }
        }
        return t[n][n];
    }
};