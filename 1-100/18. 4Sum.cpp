// Time Complexity O(n^k-1)
// there are two loops and one for twosum

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& num, int target) {
        sort(num.begin(),num.end());
        set<vector<int>> ans;
    
        for (int i = 0; i < num.size(); i++) {
            int target1 = target - num[i];
            for (int j = i + 1; j < num.size(); j++) {
                int target2 = target1 - num[j];
            
                int l = j + 1;
                int r = num.size() - 1;
            
                while(l < r) {
                    int sum = num[l] + num[r];
                    if (sum < target2) l++;
                    else if (sum > target2) r--;
                
                    else {
                        vector<int> quadruplet = {num[i],num[j],num[l],num[r]};
                        ans.insert(quadruplet);
                        l++;
                        r--;
                    }
                }
            }
        }
        
        vector<vector<int> > res(ans.begin(),ans.end());
        return res;
       
        
    }
    
};