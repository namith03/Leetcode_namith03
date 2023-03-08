class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> sub;
        sub.push_back(nums[0]);
        for(int i = 1; i < nums.size(); i++){
            if(sub[sub.size() - 1] < nums[i])
                sub.push_back(nums[i]);
            else{
                //this command finds the element in sub just greater than nums[i]
                //usually we do binary search for this but this command does the same
                    auto iter = lower_bound(sub.begin(), sub.end(),nums[i]);
                    *iter = nums[i];         
                }
            }
        return sub.size();
    }
};