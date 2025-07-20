class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<int>> dp(n,vector<int>(2,-1));
        return func(0,0,prices,dp);
    }
    int func(int ind,bool buy,vector<int>& prices,vector<vector<int>>& dp){
        if(ind==prices.size()) return 0; //end of the array

        if(dp[ind][buy]!=-1) return dp[ind][buy];

        if(buy){
            //take 
            int profit1=prices[ind]+func(ind+1,buy-1,prices,dp);
            //not take
            int profit2=func(ind+1,buy,prices,dp);
            return dp[ind][buy]=max(profit1,profit2);
        }else{
            //take
            int p1=-prices[ind]+func(ind+1,buy-1,prices,dp);
            //not take
            int p2=func(ind+1,buy,prices,dp);
            return dp[ind][buy]=max(p1,p2);
        }
    }
};