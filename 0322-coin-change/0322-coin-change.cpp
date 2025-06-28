class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<vector<int>> dp(coins.size(),vector<int>(amount+1,-1));
        int k= func(coins.size()-1,amount,coins,dp);
        if(k==INT_MAX) return -1;
        return k;
    }
 int func(int ind,int target,vector<int>& coins,vector<vector<int>>& dp){
    if(ind==0){
        if(target % coins[ind]==0) return target/coins[ind];
        else return INT_MAX;
    }

    if(dp[ind][target]!=-1) return dp[ind][target];
    int pick=INT_MAX;
    if(target>=coins[ind]){
        int res = func(ind, target - coins[ind], coins, dp);
        if (res != INT_MAX) pick = 1 + res;
    }
    int notpick= 0 +func(ind-1,target,coins,dp);
    return dp[ind][target]=min(pick,notpick);
}
};

//MEMOIZATION 
// class Solution {
// public:
//     int coinChange(vector<int>& coins, int amount) {
//         vector<vector<int>> dp(coins.size(),vector<int>(amount+1,-1));
//         int k= func(coins.size()-1,amount,coins,dp);
//         if(k==INT_MAX) return -1;
//         return k;
//     }
//  int func(int ind,int target,vector<int>& coins,vector<vector<int>>& dp){
//     if(ind==0){
//         if(target % coins[ind]==0) return target/coins[ind];
//         else return INT_MAX;
//     }

//     if(dp[ind][target]!=-1) return dp[ind][target];
//     int pick=INT_MAX;
//     if(target>=coins[ind]) pick=1+func(ind,target-coins[ind],coins,dp);
//     int notpick= 0 +func(ind-1,target,coins,dp);
//     return dp[ind][target]=min(pick,notpick);
// }
// };



//RECURSION 
// class Solution {
// public:
//     int coinChange(vector<int>& coins, int amount) {
//         int k= func(coins.size()-1,amount,coins);
//         if(k==INT_MAX) return -1;
//         return k;
//     }
//  int func(int ind,int target,vector<int>& coins){
//     if(ind==0){
//         if(target % coins[ind]==0) return target/coins[ind];
//         else return INT_MAX;
//     }

//     int pick=INT_MAX;
//     if(target>=coins[ind]) pick=1+func(ind,target-coins[ind],coins);
//     int notpick= 0 +func(ind-1,target,coins);
//     return min(pick,notpick);
// }
// };