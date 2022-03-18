// Time Complexity O(n)

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
    
      // put nums in a set to remove duplicate
      unordered_set<int> s(begin(nums), end(nums));
      int longest = 0;
        
	  for(auto& num : s) {
        // check if x-1 is present
        if(s.count(num - 1)) continue;
        //else count x+1, x+2, ... 
		int j = 1;
		while(s.count(num + j)) j++;
		longest = max(longest, j);
	   }
	  
      return longest;
    }
};