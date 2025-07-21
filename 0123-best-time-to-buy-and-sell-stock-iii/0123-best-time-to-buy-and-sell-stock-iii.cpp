class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int>(3, -1)));
        return func(0,0,0,prices,dp);    
    }
    int func(int ind,int atMax,bool buy,vector<int>& prices,vector<vector<vector<int>>>& dp){
        if(ind==prices.size()) return 0; //end of the array
        if(atMax==3) return 0;

        if(dp[ind][buy][atMax]!=-1) return dp[ind][buy][atMax];

        if(buy){
            //take 
            int profit1=prices[ind]+func(ind+1,atMax,buy-1,prices,dp);
            //not take
            int profit2=func(ind+1,atMax,buy,prices,dp);
            return dp[ind][buy][atMax]=max(profit1,profit2);
        }else{
            //take
            int p1=-prices[ind]+func(ind+1,atMax+1,buy-1,prices,dp);
            //not take
            int p2=func(ind+1,atMax,buy,prices,dp);
            return dp[ind][buy][atMax]=max(p1,p2);
        }
    }
};
