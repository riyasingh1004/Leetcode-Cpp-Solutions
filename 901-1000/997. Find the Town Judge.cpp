// Time Complexity O(n)
class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        
          vector<int> mp(n+1,0);
          for (auto itr : trust) {
              mp[itr[0]]--;
              mp[itr[1]]++;
          }
        
         for (int i = 1; i <= n; i++) {
             if (mp[i] == n-1)
                 return i;
         }
            
        return -1;
    }
};