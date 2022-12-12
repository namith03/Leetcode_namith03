class Solution {
public:
    vector<vector<int>> result;

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> temp;
        helper(candidates, target, temp,0);
        return result;
    }
    void helper(vector<int>& candidates, int target, vector<int> &temp, int i){
        if(target < 0)
            return ;
        if(target == 0){
            result.push_back(temp);
            return ;
        }
        if(i >= candidates.size())
            return ;
        
        temp.push_back(candidates[i]);
        helper(candidates, target - candidates[i],temp,i);
        temp.pop_back();
        helper(candidates, target, temp, i+1);
    }
};