// Time Complexity O(n*mlogm)

public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        
        // mapping the strings according to their sorted form
        unordered_map<string, vector<string>> mp;
        for (auto s : strs) {
            string temp = s;
            sort(temp.begin(),temp.end());
            mp[temp].push_back(s);
        }
        
        vector<vector<string>> ans;
        for (auto itr : mp)
            ans.push_back(itr.second);
        
        return ans;
    }
};