// Time Complexity O(n)

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        int n = s.length();
        int ans = 0;
        unordered_map<int,int> mp;
        for (int i = 0, j = 0; j < n; j++) {
            //i is the characters to be removed from the start 
            i = max(i,mp[s[j]]);
            //j+1 is the length of the substring
            ans = max(ans,j-i+1);
            mp[s[j]] = j+1;
        }
        
        return ans;
    }
};