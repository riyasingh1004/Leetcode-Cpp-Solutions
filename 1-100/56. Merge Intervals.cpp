// Time Complexity O(NlogN)

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> merged;
        
        for (auto interval : intervals) {
            
            // merged is empty or the interval is non overlapping
            if (merged.empty() || merged.back()[1] < interval[0]) 
                merged.push_back(interval);
            else
                merged.back()[1] = max(merged.back()[1], interval[1]);
        }
        
        return merged;
    }
};