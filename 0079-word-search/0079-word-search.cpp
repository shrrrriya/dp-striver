class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int n=board.size();int m=board[0].size();
        vector<vector<int>> hash(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]==word[0]){
                    if(func(i,j,0,board,word,hash)) return true;
                }
            }
        }
        return false;
    }
    bool func(int i,int j,int t,vector<vector<char>>& board, string& word,vector<vector<int>>& hash){
        int n=board.size();int m=board[0].size();
        if(board[i][j]!=word[t]) return false;
        else{
            if(t==word.size()-1) return true;
        }
        int nrow[]={-1,0,1,0};
        int ncol[]={0,1,0,-1};
        int drow=i;
        int dcol=j;
        hash[i][j]=1;
        for(int k=0;k<4;k++){
            int row=nrow[k]+drow;
            int col=ncol[k]+dcol;
            if(row>=0 && row<n && col>=0 && col<m && hash[row][col]!=1 && board[row][col]==word[t+1]){
                if(func(nrow[k]+drow,ncol[k]+dcol,t+1,board,word,hash)){
                   return true; 
                }
            }
        }
        hash[i][j] = 0;  
        return false;
    }
};