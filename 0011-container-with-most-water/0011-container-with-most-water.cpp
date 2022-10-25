class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0;
        int right = height.size()-1;
        int result = 0, product = 0;
        while(left < right){
            product = (right - left) * (min(height[left], height[right]));
            if(product > result)
                result = product;
            if(height[left] < height[right])
                left++;
            else if(height[left] > height[right])
                right--;
            else{
                left++;
                right--;
            }
            product = 0;
        }
        return result;
    }
};