class Solution {
public:
    bool cyclic(int i, vector<int> adj[], int visited[], int stack[] ){
        visited[i] = 1;
        stack[i] = 1;
        for(auto nbr:adj[i]){
            if(!visited[nbr]){
                if(cyclic(nbr,adj,visited,stack))
                    return true;
            }
            if(stack[nbr])
                return true;
}
            stack[i] = 0;
            return false;
        }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int v = numCourses;
        vector<int> adj[v+1];
        for(int i = 0; i < prerequisites.size(); i++){
            adj[prerequisites[i][0]].push_back(prerequisites[i][1]);
        }
        int visited[v];
        int stack[v];
        for(int i = 0; i < v; i++){
            visited[i] = false;
            stack[i] = false;
        }
        for(int i = 0; i < v; i++){
            if(!visited[i]){
                if(cyclic(i,adj,visited,stack))
                    return false;
            }
        }
        return true;
        
    }
};