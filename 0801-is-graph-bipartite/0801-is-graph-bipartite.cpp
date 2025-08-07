//BFS
class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        queue<int> q;
        vector<int> vis(n,-1);
        q.push(0);
        vis[0]=1;
        while(!q.empty()){
            int top=q.front();
            q.pop();
            for(int it:graph[top]){
                if(vis[it]==-1){
                    q.push(it);
                    vis[it]=vis[top]-1;
                }
                else if(vis[it]!=-1 && vis[it]==vis[top]){
                    return false;
                }
            }
        }
        return true;
    }
};