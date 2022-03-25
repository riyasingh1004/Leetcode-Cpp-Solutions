// Time Complexity O(n)

int Solution::solve(vector<vector<int> > &A) {

    int n = A.size();
    // min cost dp
    int dp[n][3];
    // initialize the first row same as the first row of cost
    dp[0][0] = A[0][0];
    dp[0][1] = A[0][1];
    dp[0][2] = A[0][2];
    for (int i = 1; i < n; i++) {
            // select the minimum cost in the previous row exclusing the color chosen(0,1,2)
            dp[i][0] = A[i][0] + min(dp[i-1][1], dp[i-1][2]);
            dp[i][1] = A[i][1] + min(dp[i-1][0], dp[i-1][2]);
            dp[i][2] = A[i][2] + min(dp[i-1][0], dp[i-1][1]);
        }
    // The minimum element of the last row given the result
    return *min_element(dp[n-1],dp[n-1]+3);
}

