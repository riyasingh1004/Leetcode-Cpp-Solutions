// Time Complexity O(n)

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        
        int n = numbers.size();
        set<int> res;
        int l = 0, r = n-1;
        while (l < r) {
            
            int sum = numbers[l] + numbers[r];
            if (sum < target)
                l++;
            else if (sum > target)
                r--;
            else {
                res.insert({l+1,r+1});
                l++;
                r--;
            }
        }
        
        vector<int> ans(res.begin(),res.end());
        return ans;
    }
};