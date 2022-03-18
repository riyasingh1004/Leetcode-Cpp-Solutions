// Time Complexity O(n)
// 1.The widest container (using first and last line) is a good candidate, because of its width. Its water level is the height of the smaller one of first and last line.
// 2.All other containers are less wide and thus would need a higher water level in order to hold more water.
// 3.The smaller one of first and last line doesn't support a higher water level and can thus be safely removed from further consideration.

class Solution {
public:
    int maxArea(vector<int>& height) {
        
        int l = 0, r = height.size()-1;
        
        int ans = 0;
        while (l < r) {
            
            ans = max(ans, (r-l) * min(height[l],height[r]));
            if (height[l] < height[r])
                l++;
            else
                r--;
        }
        
        return ans;
        
    }
};