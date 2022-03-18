// Time Complexity O(logn)

class Solution {
public:
    int binary_search(vector<int>& arr, int start, int end, int ele) {
        
        
        while(start <= end) {
            
            int mid = start + (end - start) / 2;
            
            if (arr[mid] == ele)
                return mid;
            else if (arr[mid] < ele)
                start = mid + 1;
            else
                end = mid - 1;
        }
        
        return -1;
    }
    
    int search(vector<int>& nums, int target) {
        
        int n = nums.size();
        int start=0, end=nums.size()-1, index;
        
        // Find the index of rotation
        while (start<end) {
            if (nums[start] < nums[end]) {
                index = start;
                break;
            }
            
            int mid = start + (end - start) / 2;
            
            if (nums[mid] >= nums[start]) {
                start = mid + 1;
            } else {
                end = mid;
            }
        }
        
         index = start;
         return max(binary_search(nums,0,index-1,target), binary_search(nums,index,n-1,target));
        
    }
};