//Time Complexity: O(N*W). 
//where ‘N’ is the number of weight element and ‘W’ is capacity. 

/*In the following recursion tree, K() refers 
to knapSack(). The two parameters indicated in the
following recursion tree are n and W.
The recursion tree is for following sample inputs.
wt[] = {1, 1, 1}, W = 2, val[] = {10, 20, 30}
                       K(n, W)
                       K(3, 2)  
                   /            \ 
                 /                \               
            K(2, 2)                  K(2, 1)
          /       \                  /    \ 
        /           \              /        \
       K(1, 2)      K(1, 1)        K(1, 1)     K(1, 0)
       /  \         /   \              /        \
     /      \     /       \          /            \
K(0, 2)  K(0, 1)  K(0, 1)  K(0, 0)  K(0, 1)   K(0, 0)
Time Complexity of recursion is 2^n*/


int Solution::solve(vector<int> &A, vector<int> &B, int C) {

    int n = A.size();
    int dp[n+1][C+1];
    memset(dp,0,sizeof(dp));

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= C; j++) {
            // if the weight is less than capacity of knapsack
            // choose the maximum when the value is included or not included 
            if (B[i-1] <= j)
                dp[i][j] = max(A[i-1] + dp[i-1][j-B[i-1]], dp[i-1][j]);
            else
                dp[i][j] = dp[i-1][j];
        }
    }

    return dp[n][C];
}
