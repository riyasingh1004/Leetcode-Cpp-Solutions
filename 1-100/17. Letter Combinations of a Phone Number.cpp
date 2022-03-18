// Time Complexity O(4^n)

class Solution {
public:
    const vector<string> letters = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    
    vector<string> letterCombinations(string digits) {
        
        if (digits.size() == 0)
            return {};
        vector<string> res;
        res.push_back("");
        for (auto ch : digits) {
            vector<string> temp;
            for (auto i : letters[ch-'0']) {
                for (auto j : res)
                    temp.push_back(j + i);
            }
            
             res = temp;
        }
        
       return res;
        
    }
};