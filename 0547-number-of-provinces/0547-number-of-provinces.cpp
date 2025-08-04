class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
        vector<int> vis(n,0);
        int cnt=0;
        for(int i=0;i<n;i++){
            if(vis[i]==0){
               bfs(i,vis,isConnected);
               cnt++; 
            } 
        }
        return cnt;
    }
    void bfs(int i,vector<int>& vis,vector<vector<int>>& adj){
        queue<int> q;
        q.push(i);
        while(!q.empty()){
            int x=q.front();
            q.pop();
            for(int it = 0; it < adj.size(); it++){
                if(adj[x][it]==1 && vis[it]==0){
                    vis[it]++; q.push(it);
                }
            }
        }
    }
};

// class Solution {
// public:
//     int findCircleNum(vector<vector<int>>& isConnected) {
//         int n=isConnected.size();
//         int cnt=0;
//         vector<int> vis(n,0);
//         for(int i=0;i<n;i++){
//             if(vis[i]==0){
//                 cnt++;
//                 bfs(i,isConnected,vis);
//             }
//         }
//         return cnt;
//     }
//     void bfs(int n,vector<vector<int>>& isConnected,vector<int> &vis){
//         queue<int> q;
//         q.push(n);
//         while(!q.empty()){
//             int node=q.front();
//             q.pop();
//             for(int i = 0; i < isConnected.size(); i++) {
//                 if(isConnected[node][i] == 1 && vis[i] == 0) {
//                     q.push(i);
//                     vis[i] = 1;
//                 }
//             }
//         }
//     }
// };