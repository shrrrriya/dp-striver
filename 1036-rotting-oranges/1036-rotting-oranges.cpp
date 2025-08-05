class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        queue<pair<pair<int,int>,int>> q;
        vector<vector<int>> vis(n,vector<int>(m,0));
        //push all of the rotten into the queue 
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2){
                     q.push({{i,j},0});
                     vis[i][j]=2;
                }
            }
        }
        int tm=0;
        int drow[]={0,-1,0,1};
        int dcol[]={-1,0,1,0};
        //start iterating
        while(!q.empty()){
            auto top=q.front();
            int row= top.first.first;
            int col=top.first.second;
            int time=top.second;
            q.pop();
            tm=max(tm,time);
            for(int i=0;i<4;i++){
                int nrow=row+drow[i];
                int ncol=col+dcol[i];
                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && grid[nrow][ncol]==1 && vis[nrow][ncol]!=2){
                    q.push({{nrow,ncol},time+1});
                    vis[nrow][ncol]=2;
                }
            }
        }
        //check if there is a one left
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(vis[i][j]!=2 && grid[i][j]==1){
                    return -1;
                }
            }
        }
        return tm;
    }
};