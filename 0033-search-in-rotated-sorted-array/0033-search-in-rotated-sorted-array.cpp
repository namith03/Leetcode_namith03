class Solution {
public:
    int search(vector<int>& nums, int target) {
        //first find out the index of smallest element
        int l = 0, r = nums.size()-1;
        int mid = 0;
        while( l <  r){
            //if middle element is greater than last element it means that elements are sorted until middle and there is a possibility of lower element from left
            mid = (l + r)/2;
            if(nums[mid] > nums[r])
                l = mid+1;
            else
                r = mid;
        }
        int small = l;
        l = 0, r = nums.size()-1;
        if(target >= nums[small] && target <= nums[r])
            l = small;
        else
            r = small;
        while(l <= r){
            mid = (l+r)/2;
            if(nums[mid] == target)
                return mid;
            else if(target > nums[mid])
                l = mid+1;
            else
                r = mid-1;
        }
        return -1;
    }
};