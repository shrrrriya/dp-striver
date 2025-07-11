//SPACE OPTIMIZATION
class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n=text1.size();
        int m=text2.size();
        vector<int> dp(m+1,0);
        for(int ind1=1;ind1<=n;ind1++){
            vector<int> temp(m+1,0);
            for(int ind2=1;ind2<=m;ind2++){
            if(text1[ind1-1]==text2[ind2-1]) temp[ind2]=1+dp[ind2-1];
            else temp[ind2]=max(dp[ind2],temp[ind2-1]);
            }
            dp=temp;
        }
        return dp[m];
    }
};



//TABULATION
// class Solution {
// public:
//     int longestCommonSubsequence(string text1, string text2) {
//         int n=text1.size();
//         int m=text2.size();
//         vector<vector<int>> dp(n+1,vector<int>(m+1,0));
//         for(int ind1=1;ind1<=n;ind1++){
//             for(int ind2=1;ind2<=m;ind2++){
//             if(text1[ind1-1]==text2[ind2-1]) dp[ind1][ind2]=1+dp[ind1-1][ind2-1];
//             else dp[ind1][ind2]=max(dp[ind1-1][ind2],dp[ind1][ind2-1]);
//             }
//         }
//         return dp[n][m];
//     }
// };

//MEMOIZATION
// class Solution {
// public:
//     int longestCommonSubsequence(string text1, string text2) {
//         int n=text1.size();
//         int m=text2.size();
//         vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
//         return func(n,m,text1,text2,dp);
//     }

//     int func(int ind1,int ind2,string& s1, string& s2,vector<vector<int>>& dp){
//         if(ind1<=0 || ind2<=0) return 0;
//         if(dp[ind1][ind2]!=-1) return dp[ind1][ind2];
//         if(s1[ind1-1]==s2[ind2-1]) return dp[ind1][ind2]=1+func(ind1-1,ind2-1,s1,s2,dp);
//         return dp[ind1][ind2]=max(func(ind1-1,ind2,s1,s2,dp),func(ind1,ind2-1,s1,s2,dp));
//     }
// };

//RECURSION 
// class Solution {
// public:
//     int longestCommonSubsequence(string text1, string text2) {
//         int n=text1.size();
//         int m=text2.size();
//         return func(n-1,m-1,text1,text2);
//     }

//     int func(int ind1,int ind2,string& s1, string& s2){
//         if(ind1<0 || ind2<0) return 0;

//         if(s1[ind1]==s2[ind2]) return 1+func(ind1-1,ind2-1,s1,s2);
//         return max(func(ind1-1,ind2,s1,s2),func(ind1,ind2-1,s1,s2));
//     }
// };