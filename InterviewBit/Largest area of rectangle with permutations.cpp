// Time Complexity O(rc)

int Solution::solve(vector<vector<int> > &A) {

    int r = A.size();
    int c = A[0].size();

    int sum[r][c];
    memset(sum,0,sizeof(sum));

    // find longest consecutive 1s in each column
    for (int j = 0; j < c; j++) {
        sum[0][j] = A[0][j];
        for (int i = 1; i < r; i++) 
            sum[i][j] = A[i][j] ? sum[i-1][j] + 1 : 0;
    }

    // sort the columns in decreasing order
    for (int i = 0; i < r; i++)
        sort(sum[i], sum[i]+c, greater<int>());

    int ans = 0;
    // calculate the maximum area
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            int area = sum[i][j] * (j+1);
            ans = max(ans, area);
        }
    }

    return ans;
}
