// Time Complexity O(N^3)

class Solution {
public:
    int maxCoins(vector<int>& nums) {
        
         nums.insert(nums.begin(), 1);
         nums.push_back(1);
         int n = nums.size(); 
         int m[n][n];
         memset(m,0,sizeof(m));
         int i,j,k,L,q;
        
          for (L = 2; L < n; L++) {
              for (i = 1; i < n-L+1; i++) {
                  j = i + L - 1;
                  for (k = i; k < j; k++) {
                      q = m[i][k] + m[k+1][j] + nums[i-1]*nums[k]*nums[j];
                      if(q > m[i][j])
                          m[i][j] = q;
                  }
              }
          }
        return m[1][n-1];
    }
};