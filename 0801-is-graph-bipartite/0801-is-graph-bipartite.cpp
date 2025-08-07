//BFS
class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int> vis(n,-1);
        for(int i=0;i<n;i++){
            if(vis[i]==-1){
        queue<int> q;
        q.push(i);
        vis[i]=1;
        while(!q.empty()){
            int top=q.front();
            q.pop();
            for(int it:graph[top]){
                if(vis[it]==-1){
                    q.push(it);
                    vis[it]=1-vis[top];
                }
                else if(vis[it]!=-1 && vis[it]==vis[top]){
                    return false;
                }
            }}
        }}
        return true;
    }
};