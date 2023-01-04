class Solution {
public:
    void helper(vector<vector<char>>& grid, int i, int j, vector<vector<bool>>& visited){
        visited[i][j] = true;
        //up
        if(i > 0 && grid[i-1][j] == '1' && !visited[i-1][j])
            helper(grid,i-1,j,visited);
        //down
        if(i < grid.size() - 1 && grid[i+1][j] == '1' && !visited[i+1][j])
            helper(grid,i+1,j,visited);
        //left
        if(j > 0 && grid[i][j-1] == '1' && !visited[i][j-1])
            helper(grid,i,j-1, visited);
        //right
        if(j < grid[0].size()-1 && grid[i][j+1] == '1' && !visited[i][j+1])
            helper(grid, i , j+1, visited);
        
        return;
}
    int numIslands(vector<vector<char>>& grid) {
        int result = 0;
        
        vector<vector<bool>> visited(grid.size(),vector<bool>(grid[0].size(),false));
        
        /*
        vector<vector<bool>> visited;
        
        for(int a = 0; a < grid.size(); a++){
            for(int b = 0; b < grid[0].size(); b++){
                visited[a][b] = false;
            } 
        }
        */
        
        for(int i = 0; i < grid.size();i++){
            for(int j = 0; j < grid[0].size();j++){
                if(grid[i][j] == '1' && !visited[i][j]){
                    helper(grid,i,j,visited);
                    result++;
                }     
            }
        }
        return result;
    }
};