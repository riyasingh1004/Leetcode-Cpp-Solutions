// Time Complexity O(d)

vector<int> Solution::solve(int A, int B, int C, int D) {
    
    int dp[D+1];
    dp[0] = 1;
    int iA = 0, iB = 0, iC = 0;
    int numA = A, numB = B, numC = C;
    int num = 1;
    
    for (int i = 1; i <= D; i++) {
        
        num = min(numA, min(numB, numC));
        dp[i] = num;
        
        if(num == numA) {
            iA++;
            numA = dp[iA] * A;
        }
        
        else if(num == numB) {
            iB++;
            numA = dp[iB] * B;
        }
        
        else {
            iC++;
            numA = dp[iC] * C;
        }
        
    }
    
    vector<int> ans;
    for (int i = 1; i <= D; i++)
        ans.push_back(dp[i]);
    
    return ans;
}
