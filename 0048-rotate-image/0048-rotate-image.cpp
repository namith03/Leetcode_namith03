class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int start = 0;
        int end = matrix.size() - 1;
        while(start < end){
            //n is the size
            int n = (end - start) + 1;
            int turn = n - 1;
            while(turn){
                int count = pow(n,2) - pow(n-2,2);
                int temp = matrix[start+1][start];
                int i = start, j = start;
                while(count){
                    int dummy = matrix[i][j];
                    if(i == start && j != end){
                        matrix[i][j] = temp;
                        temp = dummy;
                        j++;
                        count--;
                        continue;
                    }
                    if(j == end && i != end){
                        matrix[i][j] = temp;
                        temp = dummy;
                        i++;
                        count--;
                        continue;
                    }
                    if(i == end && j != start){
                        matrix[i][j] = temp;
                        temp = dummy;
                        j--;
                        count--;
                        continue;
                    }
                    if(j == start && i != start){
                        matrix[i][j] = temp;
                        temp = dummy;
                        i--;
                        count--;
                        continue;
                    }
                    count--;
                }
                turn--;
            }
            start++;
            end--;
        }
    }
};