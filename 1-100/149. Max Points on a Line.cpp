// Time Complexity O(n^2)

class Solution {
public:
    int maxPoints(vector<vector<int>>& A) {
        
         int maxcount = 0;
         for(int i=0;i<A.size();i++){
            int count = 0, overlapCount = 1;
            unordered_map<double,int> mp;
            for(int j=i+1;j<A.size();j++){
                if(A[i][0]==A[j][0] and A[i][1]==A[j][1])overlapCount++;
                else{
                    double slope = A[i][0]!=A[j][0]? (1.0*A[j][1]-A[i][1])/(A[j][0]-A[i][0]): 1e9;
                    count = max(count,++mp[slope]);
                }
            }
            maxcount = max(maxcount,count+overlapCount);
        }
        return maxcount;
    }
};