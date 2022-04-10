// Time Complexity O(n*target)
// Similar to 0-1 knapsack 

class Solution {
public:
    bool canPartition(vector<int>& arr) {
        
        int n = arr.size();
        int sum=0;
        for(int i=0;i<n;i++)
            sum+=arr[i];
        if(sum%2!=0)
            return false;
         int s = sum/2;
        bool t[n+1][s+1];
        for(int i=0;i<=n;i++)
            t[i][0]=1;
        for(int i=1;i<=s;i++)
            t[0][i]=0;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=s;j++)
            {
                if(arr[i-1]<=j)
                    t[i][j]=t[i-1][j] || t[i-1][j-arr[i-1]];
                else
                    t[i][j]=t[i-1][j];
            }
        }
        
        return t[n][s];
    }
};