// Time Complexity O(n*n)

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        
        int n = nums.size();
        sort(nums.begin(),nums.end());
        int ans = nums[0] + nums[1] + nums[2];
        
        for (int i = 0; i < n; i++) {
    
            int l = i+1;
            int r = n-1;
            
            while (l < r) {
                
                int sum = nums[i] + nums[l] + nums[r];
                if (sum == target)
                    return sum;
                if (abs(target-sum) < abs(target-ans))
                    ans = sum;
                if (sum < target)
                    l++;
                else if (sum > target)
                    r--;
                // No need to check for duplicates as only the sum is required
            }
            
            while (i+1 < n && nums[i] == nums[i+1]) i++;
        }
        
        return ans;    
    }
};