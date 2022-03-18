// Time Complexity O(nxm)

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        
        vector<int> ans;
        
        int rowBegin = 0, colBegin = 0;
        int rowEnd = matrix.size()-1, colEnd = matrix[0].size()-1;
        
        while (rowBegin <= rowEnd && colBegin <= colEnd) {
            
            // right
            for (int i = colBegin; i <= colEnd; i++)
                ans.push_back(matrix[rowBegin][i]);
            rowBegin++;
            
            // down
             for (int i = rowBegin; i <= rowEnd; i++)
                ans.push_back(matrix[i][colEnd]);
            colEnd--;
            
            // left
            if (rowBegin <= rowEnd) {
                
                 for (int i = colEnd; i >= colBegin; i--)
                    ans.push_back(matrix[rowEnd][i]);
                
                 rowEnd--;
            }
            
            // up
            
            if (colBegin <= colEnd) {
                
                 for (int i = rowEnd; i >= rowBegin; i--)
                    ans.push_back(matrix[i][colBegin]);
                
                 colBegin++;
            }
        }
        
        return ans;
        
    }
};
