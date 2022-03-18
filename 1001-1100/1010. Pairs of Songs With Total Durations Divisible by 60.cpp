// Time Complexity O(n)
// we want to know that, for each t,
//how many x satisfy (t + x) % 60 = 0.
// This will work in all cases expect t % 60 == 0
class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        
        map<int,int> mp;
        int n = time.size();
        int res = 0, x;
        for (int t : time) {
            x = t % 60;
            if (x > 0)
                res += mp[60 - x]; 
            else 
                res += mp[0];
            mp[x]++;
        }
        
        return res;
    }
};