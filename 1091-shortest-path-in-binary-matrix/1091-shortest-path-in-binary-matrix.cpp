class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> dirs{{-1,-1},{-1,0},{-1,1},{0,-1},{0,1},{1,1},{1,0},{1,-1}};
        vector<vector<int>> visited(n,vector<int>(n,-1));
        queue<vector<int>> q;
        if(grid[0][0] == 0){
          q.push({0,0});
          visited[0][0] = 0;
        }

        while(!q.empty()){
            vector<int> par = q.front();
            q.pop();
            for(int i = 0; i < 8; i++){
                int x = par[0] + dirs[i][0];
                int y = par[1] + dirs[i][1];
                if(x >= 0 && x < n && y >= 0 && y < n && visited[x][y] == -1 && grid[x][y] == 0){
                    q.push({x,y});
                    visited[x][y] = visited[par[0]][par[1]] + 1;
                    //cout << x << y << endl;
                }
            }
}
       if(visited[n-1][n-1] >= 0)
           return 1 + visited[n-1][n-1];
        else
            return -1;
    }
};