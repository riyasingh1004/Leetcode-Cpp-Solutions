// Time Complexity O(nm)
/* This problem can be reduced to a Knapsack problem where we have to fill a Knapsack of capacity (S/2) 
as fully as possible and using the minimum no. of elements. 
We will fill the Knapsack with the given elements. Sign of all the elements which come into the knapsack will be flipped.
As sum of all the elements in the Knapsack will be as close to S/2 as possible, 
we are indirectly calculating minimum non-negative sum of all the elements after flipping the sign. 
*/
int Solution::solve(const vector<int> &A) {
    
    int l=A.size();
    int t_sum=0;
    for(int i=0;i<l;i++)
    t_sum+=A[i];
    int h_sum=t_sum/2;
    int dp[l+1][h_sum+1];
    memset(dp,0,sizeof(dp));
    for(int i=1;i<=h_sum;i++)
        dp[0][i]=INT_MAX;
    

    for(int i=1;i<=l;i++){
        for(int j=1;j<=h_sum;j++){
            if(A[i-1]<=j)
                dp[i][j]=min(1+(dp[i-1][j-A[i-1]]!=INT_MAX?dp[i-1][j-A[i-1]]:INT_MAX-1),dp[i-1][j]);
            else
                dp[i][j]=dp[i-1][j];
        }
    }

    for(int i=h_sum;i>=0;i--){
        if(dp[l][i]!=INT_MAX)
            return dp[l][i];
    }

    return -1;

}
