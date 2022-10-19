class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        sort(nums.begin(), nums.end());
        for(int i = 0; i < nums.size() - 2; i++){
            if(nums[i] > 0)
                break;
            if(i > 0 && nums[i] == nums[i-1])
                continue;
            int left = i+1;
            int right = nums.size() - 1;
            while(left < right){
                if((nums[left] + nums[right] + nums[i]) < 0){
                   left++;
                }
                else if((nums[left] + nums[right] + nums[i]) > 0){
                    right--;
                }
                else{
                     result.push_back({nums[i], nums[left], nums[right]});
                     int dum_left = nums[left], dum_right = nums[right]; 
                     while(left < right && nums[left] == dum_left )
                         left++;
                     while(left < right && nums[right] == dum_right)
                         right--;
                } 
            }
}
        return result;
        
    }
};