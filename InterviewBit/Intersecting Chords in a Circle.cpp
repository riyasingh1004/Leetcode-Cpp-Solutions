// Time Complexity O(n)

//The pattern gives Catalan numbers 1,1,2,5,14...
//So the solution is to find nth catalan number.

int Solution::chordCnt(int n) {

    long long int dp[n+1];
    if(n==0||n==1)
     return 1;
    else if(n==2)
     return 2;
    dp[0]=1;
    dp[1]=1;
    dp[2]=2;
    for(int i=3;i<=n;i++){
        dp[i]=0;
        for(int k=0;k<i;k++)
            dp[i]=(dp[i]+dp[i-k-1]*dp[k])%1000000007;
    }  
    return dp[n]%1000000007;
}
