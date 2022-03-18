// Time Complexity O(R*C)

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
    
    int maximalRectangle(vector<vector<char>>& matrix) {
        
        int maxRec = 0;
        vector<int> height(matrix[0].size(), 0);
        for(int i = 0; i < matrix.size(); i++){
            for(int j = 0; j < matrix[0].size(); j++){
                if(matrix[i][j] == '0'){
                    height[j] = 0;
                }
                else{
                    height[j]++;
                }
            }
            maxRec = max(maxRec, largestRectangleArea(height));
        }
        return maxRec;   
    }
};