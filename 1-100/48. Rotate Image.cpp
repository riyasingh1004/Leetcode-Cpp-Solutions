// Time Complexity O(M)
// M : Number of cells in the 

class Solution {
public:
    
    void transpose(vector<vector<int>>& matrix) {
        
        int n = matrix.size();
        
        for (int i = 0; i < n ; i++) 
            for (int j = i; j < n; j++)
                swap(matrix[i][j], matrix[j][i]);
    }
    
    void reflect(vector<vector<int>>& matrix) {
        
        int n = matrix.size();
        
        for (int i = 0; i< n; i++) 
            reverse(matrix[i].begin(), matrix[i].end());
        
    }
    
    void rotate(vector<vector<int>>& matrix) {
        
        transpose(matrix);
        reflect(matrix);
        
    }
};