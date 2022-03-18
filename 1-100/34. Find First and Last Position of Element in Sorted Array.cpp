// Time Complexity O(log(n))

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int x) {
        
    int n = nums.size();
    int low = 0, high = n - 1, first = -1;
    while (low <= high) {
         
        // Normal Binary Search Logic
        int mid = (low + high) / 2;
         
        if (nums[mid] > x)
            high = mid - 1;
        else if (nums[mid] < x)
            low = mid + 1;
 
        // If arr[mid] is same as x, we
        // update res and move to the left
        // half.
        else {
            first = mid;
            high = mid - 1;
        }
    }
      
        
     high = n - 1;
     int last = -1;
    while (low <= high) {
         
        // Normal Binary Search Logic
        int mid = (low + high) / 2;
         
        if (nums[mid] > x)
            high = mid - 1;
        else if (nums[mid] < x)
            low = mid + 1;
 
        // If arr[mid] is same as x, we
        // update res and move to the right
        // half.
        else {
            last = mid;
            low = mid + 1;
        }
    }
    
     return {first,last};
    }
};