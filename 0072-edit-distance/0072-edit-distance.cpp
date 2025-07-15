//MEMOIZATION
class Solution {
public:
    int minDistance(string word1, string word2) {
        return numDistinct(word1, word2);
    }
    int numDistinct(string s, string t) {
        vector<vector<int>> dp(s.size()+1,vector<int>(t.size()+1,-1));
        return func(s.size(),t.size(),s,t,dp);
    }
    int func(int i,int j,string s,string t,vector<vector<int>>& dp){
        if(i==0) return j;
        if(j==0) return i;

        if(dp[i][j]!=-1) return dp[i][j];

        if(s[i-1]==t[j-1]){
            return dp[i][j]=0+func(i-1,j-1,s,t,dp);
        }
        else{
            int insert=1+func(i,j-1,s,t,dp);
            int del=1+func(i-1,j,s,t,dp);
            int replace=1+func(i-1,j-1,s,t,dp);
            return dp[i][j]=min(insert,min(del,replace));
        }
    }
};

//RECURSIVE
// class Solution {
// public:
//     int minDistance(string word1, string word2) {
//         return numDistinct(word1, word2);
//     }
//     int numDistinct(string s, string t) {
//         return func(s.size()-1,t.size()-1,s,t);
//     }
//     int func(int i,int j,string s,string t){
//         if(i<0) return j+1;
//         if(j<0) return i+1;

//         if(s[i]==t[j]){
//             return 0+func(i-1,j-1,s,t);
//         }
//         else{
//             int insert=1+func(i,j-1,s,t);
//             int del=1+func(i-1,j,s,t);
//             int replace=1+func(i-1,j-1,s,t);
//             return min(insert,min(del,replace));
//         }
//     }
// };