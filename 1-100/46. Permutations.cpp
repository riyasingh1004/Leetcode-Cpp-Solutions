// Time Complexity O(n!n)

class Solution {
public:
    
    void permuteUtil(vector<int> &num,int begin,vector<vector<int>> &res){
        
        if(begin>=num.size()){
            res.push_back(num);
            return;
        }
        
        for(int i=begin;i<num.size();i++){
            
            swap(num[begin],num[i]);
            permuteUtil(num,begin+1,res);
            swap(num[begin],num[i]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        
        vector<vector<int>> res;
        permuteUtil(nums,0,res);
        return res;
        
    }
    
};