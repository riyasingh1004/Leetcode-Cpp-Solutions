// Time Complexity O(n*n)

// Finding the longest common subsequence except for i == j

int Solution::anytwo(string A) {
    
     int n=A.size();
     int t[n+1][n+1];

    for(int i=0;i<n+1;i++) {
        for(int j=0;j<n+1;j++) {
            if(i==0 || j==0)
                t[i][j] = 0;
            else if(A[i-1]==A[j-1]&&i!=j)
                t[i][j]=t[i-1][j-1]+1;
            else
                t[i][j]=max(t[i][j-1],t[i-1][j]);
        }
    }
    return t[n][n] > 1 ? 1 : 0;
}
