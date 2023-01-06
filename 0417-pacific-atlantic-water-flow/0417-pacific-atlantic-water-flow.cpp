class Solution {
public:
    void dfs(vector<vector<int>>& heights, vector<vector<int>>& visited, int i, int j){
        visited[i][j] = 1;
        
        //go left
        if(j > 0 && !visited[i][j-1] && heights[i][j-1] >= heights[i][j])
            dfs(heights,visited,i,j-1);
        //go right
        if(j < heights[0].size()-1 && !visited[i][j+1] && heights[i][j+1] >= heights[i][j])
            dfs(heights,visited,i,j+1);
        //go up
        if(i > 0 && !visited[i-1][j] && heights[i-1][j] >= heights[i][j])
            dfs(heights,visited,i-1,j);
        //go down
        if(i < heights.size()-1 && !visited[i+1][j] && heights[i+1][j] >= heights[i][j])
            dfs(heights,visited,i+1,j);
        
        
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int m = heights.size();
        int n = heights[0].size();
        vector<vector<int>> pac(m, vector<int>(n));
        vector<vector<int>> atl(m, vector<int>(n));
        vector<vector<int>> result;
        //reach nodes from edges
        //left and right edges
        for(int i = 0; i < m; i++){
            dfs(heights,pac,i,0);
            dfs(heights,atl,i,n-1);
        }
        //top edge and bottom edge
        for(int j = 0; j < n; j++){
            dfs(heights,pac,0,j);
            dfs(heights,atl,m-1,j);
        }
        
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(pac[i][j] == 1 && atl[i][j] == 1)
                    result.push_back(vector<int>{i,j});
            }
        }
        
        return result;
    }
};