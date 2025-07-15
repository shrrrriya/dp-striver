//SPACE OPTIMIZATION-gpt
class Solution {
  
public:
    int numDistinct(string s, string t) {
        int m=s.length();
        int n=t.length();
        vector<vector<int>>dp(m+1,vector<int>(n+1,0));
        for(int i=0;i<=m;i++){
            dp[i][0]=1;
        }
        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                if(s[i-1]==t[j-1]){
                    dp[i][j]=(long long int)dp[i-1][j-1]+dp[i-1][j];
                }
                else{
                    dp[i][j]=dp[i-1][j];
                }
            }
        }
        return dp[m][n];
    }
};


//strivers way -63/66 test cases passed
//SPACE OPTIMIZATION
// class Solution {
// public:
//     int numDistinct(string s, string t) {
//         if (s.size() > t.size()) return 0; 
//         vector<long long> dp(t.size()+1,0);
//         //base case
//         dp[0]=1;       

//         for(long long ind1=1;ind1<=s.size();ind1++){
//             vector<long long> temp(t.size()+1,0);
//             temp[0]=1;
//             for(long long ind2=1;ind2<=t.size();ind2++){
//                 if(s[ind1-1]==t[ind2-1]){
//                     temp[ind2]=dp[ind2-1]+dp[ind2];}
//                 else{
//                     temp[ind2]=dp[ind2];}               
//             }
//             dp=temp;
//         }
//         return dp[t.size()];
//     }
// };
 
//TABULATION
// class Solution {
// public:
//     int numDistinct(string s, string t) {
//         vector<vector<int>> dp(s.size()+1,vector<int>(t.size()+1,0));
//         //base case
//         for(int i=0;i<=s.size();i++){
//             dp[i][0]=1;
//         }        

//         for(int ind1=1;ind1<=s.size();ind1++){
//             for(int ind2=1;ind2<=t.size();ind2++){
//                 if(s[ind1-1]==t[ind2-1]){
//                     dp[ind1][ind2]=dp[ind1-1][ind2-1]+dp[ind1-1][ind2];}
//                 else{
//                     dp[ind1][ind2]=dp[ind1-1][ind2];}               
//             }
//         }
//         return dp[s.size()][t.size()];
//     }
// };

//MEMOIZATION
// class Solution {
// public:
//     int numDistinct(string s, string t) {
//         vector<vector<int>> dp(s.size()+1,vector<int>(t.size()+1,-1));
//         return func(s.size(),t.size(),s,t,dp);
//     }
//     int func(int ind1,int ind2,string s,string t,vector<vector<int>>& dp){
//         if(ind2==0) return 1;
//         if(ind1==0) return 0;

//         if(dp[ind1][ind2]!=-1) return dp[ind1][ind2];
//         if(s[ind1-1]==t[ind2-1]){
//             return dp[ind1][ind2]=func(ind1-1,ind2-1,s,t,dp) +func(ind1-1,ind2,s,t,dp);
//         }
//         else{
//             return dp[ind1][ind2]=func(ind1-1,ind2,s,t,dp);
//         }
//     }
// };

//RECURSION
// class Solution {
// public:
//     int numDistinct(string s, string t) {
//         return func(s.size()-1,t.size()-1,s,t);
//     }
//     int func(int ind1,int ind2,string s,string t){
//         if(ind2<0) return 1;
//         if(ind1<0) return 0;

//         if(s[ind1]==t[ind2]){
//             return func(ind1-1,ind2-1,s,t) +func(ind1-1,ind2,s,t);
//         }
//         else{
//             return func(ind1-1,ind2,s,t);
//         }
//     }
// };