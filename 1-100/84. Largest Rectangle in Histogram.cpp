// Time Complexity O(N)

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        
        int n = heights.size();
        stack<int> s;
        int maxarea = 0, i = 0;
        int tp , area;
        
        while (i < n) {
            
            if (s.empty() || heights[s.top()] <= heights[i])
                s.push(i++);
            else {
                
                tp = s.top();
                s.pop();
                
                area = heights[tp] * (s.empty() ? i : i - s.top() - 1);
                maxarea = max(maxarea, area); 
            }
        }
        
        while (!s.empty()) {
            
            tp = s.top();
            s.pop();
                
            area = heights[tp] * (s.empty() ? i : i - s.top() - 1);
            maxarea = max(maxarea, area); 
        }
        
        return maxarea;
        
    }
};