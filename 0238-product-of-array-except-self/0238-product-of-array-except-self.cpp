class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> answer(nums.size());
        answer[nums.size()-1] = 1;
        for(int i = nums.size()-2; i >= 0; i--){
           answer[i] = nums[i+1] * answer[i+1];
        }
        int prefix = 1;
        for(int i = 1; i < nums.size(); i++){
            prefix = prefix * nums[i-1];
            answer[i] =(prefix* answer[i]);
        }
            return answer;
    }
};