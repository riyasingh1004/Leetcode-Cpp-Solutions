// Time Complexity O(n*n)

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        
        int n = nums.size();
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;
        for (int i = 0; i < n; i++) {
            
            int target = -nums[i];
            int l = i+1;
            int r = n-1;
           
            while (l < r) {
                
                int sum = nums[l] + nums[r];
            
                if (sum < target)
                    l++;
                else if(sum > target)
                    r--;
                else {
                    vector<int> triplet = {nums[i], nums[l], nums[r]};
                    ans.push_back(triplet);
                    // Processing duplicates of Number 2
                    // Rolling the front pointer to the next different number forwards
                    while(l < r && nums[l] == triplet[1]) l++;
                    // Processing duplicates of Number 3
                    // Rolling the back pointer to the next different number backwards
                    while(l < r && nums[r] == triplet[2]) r--;
                }
            }
            
            // Processing duplicates of Number 1
            while (i+1 < n && nums[i] == nums[i+1]) i++;

        }
        
        return ans;
        
    }
};