// Time Complexity O(n)

class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        
        vector<int> count(1001,0);
        for (auto x : trips) {
            count[x[1]] += x[0];
            count[x[2]] -= x[0];
        }
        
        for (int i = 0; i <= 1000 && capacity >= 0; i++)
            capacity -= count[i];
        
        return capacity >= 0;
        
    }
};