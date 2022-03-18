// Time Complexity O(N)
// N is the lenght of string

class Solution {
public:
    string minWindow(string s, string t) {
        
         int m[256] = { 0 };
 
        int ans = INT_MAX; // length of ans
        int start = 0; // starting index of ans
        int count = 0;

        // creating map
        for (int i = 0; i < t.length(); i++) {
            if (m[t[i]] == 0)
                count++;
            m[t[i]]++;
        }

        // References of Window
        int i = 0;
        int j = 0;

        // Traversing the window
        while (j < s.length()) {
            // Calculations
            m[s[j]]--;
            if (m[s[j]] == 0)
                count--;

            // Condition matching
            if (count == 0) {
                while (count == 0) {
                    // Sorting ans
                    if (ans > j - i + 1) {
                        ans = j - i + 1;
                        start = i;
                    }
                    // Sliding i
                    // Calculation for removing ith character

                    m[s[i]]++;
                    if (m[s[i]] > 0)
                        count++;

                    i++;
                }
            }
            j++;
        }

        
        return ans == INT_MAX ? "" : s.substr(start,ans);
        
    }
};