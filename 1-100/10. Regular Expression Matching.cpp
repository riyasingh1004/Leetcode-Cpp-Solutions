// Time Complexity O(NM)

//1. If p[j] == s[i] :  dp[i][j] = dp[i-1][j-1];
//2. If p[j] == '.' : dp[i][j] = dp[i-1][j-1];
//3. If p[j] == '*': 
//    here are two sub conditions:
//                1   if p[j-1] != s[i] : dp[i][j] = dp[i][j-2]  //in this case, a* only counts as empty
//                2   if p[i-1] == s[i] or p[i-1] == '.':
//                               dp[i][j] = dp[i-1][j]    //in this case, a* counts as multiple a 
//                            or dp[i][j] = dp[i][j-1]   // in this case, a* counts as single a
//                            or dp[i][j] = dp[i][j-2]   // in this case, a* counts as empty

class Solution {
public:
    bool isMatch(string s, string p) {
        
        if (s.empty() || p.empty()) {
        return false;
    }
    
    vector<vector<bool>> dp(s.length() + 1, vector<bool>(p.length() + 1, false));
    dp[0][0] = true;
    // when text is empty
    for (int i = 0; i < p.length(); i++) {
        if (p[i] == '*' && dp[0][i-1]) {
            dp[0][i+1] = true;
        }
    }
    for (int i = 0 ; i < s.length(); i++) {
        for (int j = 0; j < p.length(); j++) {
            
            if (p[j] == '.' || p[j] == s[i]) 
                dp[i+1][j+1] = dp[i][j];

            if (p[j] == '*') {
                if (p[j-1] != s[i] && p[j-1] != '.') 
                    dp[i+1][j+1] = dp[i+1][j-1];
                else 
                    dp[i+1][j+1] = (dp[i+1][j] || dp[i][j+1] || dp[i+1][j-1]);
            }
        }
    }
        
    return dp[s.length()][p.length()];
        
    }
};