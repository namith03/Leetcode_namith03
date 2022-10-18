class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int count = 1, result = 1;
        if(nums.size() == 0)
            return 0;
        for(int i = 1; i < nums.size(); i++){
            if(nums[i] - 1 == nums[i-1]){
                count++;
            }
        else if(nums[i] == nums[i-1]){
            
        }
            else{
                if(count >= result)
                    result = count;
                count = 1;
            }
        }
     return max(count,result);
            
}
};