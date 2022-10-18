class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size() == 0)
            return 0;
      unordered_set<long> set;  
      for(int i = 0; i < nums.size(); i++){
          set.insert(nums[i]);
      }
      int count = 1, result = 1;
      while(!(set.empty())){
          long temp = *set.begin();
          if(count > result){
              result = count;
          }
          count = 1;
          set.erase(temp);
          long temp1 = temp;
          temp++;
          while( set.find(temp) != set.end()){
              count++;
              set.erase(temp);
              temp++;
          }
          temp1--;
          while(set.find(temp1) != set.end()){
              count++;
              set.erase(temp1);
              temp1--;
          }
      }
        return max(count,result);  
}
};