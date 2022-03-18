// Time Complexity O(n*s)

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n=s.length();
        
        unordered_map<string,int> mp;
        for(int i=0;i<wordDict.size();i++)
            mp[wordDict[i]]++;
        
        vector<bool> dp(n+1);
        dp[0]=true;
        
        for(int l=1;l<=n;l++)
        {
            for(int i=0;i<l;i++)
            {
                if(dp[i]==true && (mp.find(s.substr(i,l-i))!=mp.end()))
                {
                    dp[l]=true;
                }
            }
        }
        
        return dp[n];
    }
};