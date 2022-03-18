// Time Complexity O(N^2)

class Solution {
public:
    
    int digArtifacts(int n, vector<vector<int>>& artifacts, vector<vector<int>>& dig) {
        
        vector<vector<bool>> grid(n,vector<bool>(n,0));
        for(auto vec : dig)
            grid[vec[0]][vec[1]] = 1;
        
        int ans = 0;
        for (auto itr : artifacts) {
          int r1 = itr[0];
          int c1 = itr[1];
          int r2 = itr[2];
          int c2 = itr[3];
          bool flag = true;
         
          for(int i = r1;i<=r2;i++)
                for(int j = c1;j<=c2;j++)
                    if(!grid[i][j])
                        flag = false;
        
          if(flag)
            ans++;
         
        }
        
        return ans;
        
    }
};