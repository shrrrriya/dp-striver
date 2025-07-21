class Solution {
public:
    int maxProfit(int k,vector<int>& prices) {
        int n=prices.size();
        vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(2, vector<int>(k+1, 0)));
        for(int ind=n-1;ind>=0;ind--){
            for(int atMax=0;atMax<k+1;atMax++){
                for(int buy=0;buy<=1;buy++){
        int profit=0;
        if(buy){
            //take 
            int profit1=prices[ind]+dp[ind+1][1-buy][atMax];
            //not take
            int profit2=dp[ind+1][buy][atMax];
            profit=max(profit1,profit2);
        }else{
            if(atMax<k){
            //take
            int p1=-prices[ind]+dp[ind+1][1-buy][1+atMax];
            //not take
            int p2=dp[ind+1][buy][atMax];
            profit=max(p1,p2);}else{
                profit=dp[ind+1][0][atMax];
            }
        }
        dp[ind][buy][atMax]=profit;
                }
            }
        }
       // start at day 0, not holding (buy==0), 0 buys done 
       //got stuck with te return statement
    //    1. **It’s day 0**,  
    //    2. **You haven’t made any transactions** yet, so `atMax = 0`,  
    //    3. **You don’t hold a share** (you can’t magically start by holding one), so `buy = 0`.  
       return dp[0][0][0];

    } 
};