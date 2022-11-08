class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0, r = nums.size()-1;
        while(l < r){
            int mid = (l+r)/2;
            if(nums[mid] > nums[r])
                l = mid + 1;
            else
                r = mid;
        }
        //index of min element
        int min = l;
        l = 0, r = nums.size()-1;
        if(target <= nums[r])
            l = min;
        else
            r = min;
        while(l <= r){
            int mid = (l+r)/2;
            if( target == nums[mid])
                return mid;
            else if(target > nums[mid])
                l = mid + 1;
            else
                r = mid - 1;
        }
         return -1;   
    }
};