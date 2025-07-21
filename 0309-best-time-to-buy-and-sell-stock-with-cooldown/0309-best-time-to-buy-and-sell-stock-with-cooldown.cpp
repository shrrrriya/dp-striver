// TABULATION
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<int>> dp(n+1,vector<int>(2,0));

        for(int ind=n-1;ind>=0;ind--){
            for(int buy=0;buy<=1;buy++){
        int profit=0;
        if(buy){
            //take 
            int profit1=prices[ind];
            if(ind+2<n && ind+2>=0) profit1=profit1+dp[ind+2][0];
            //not take
            int profit2=dp[ind+1][buy];
            profit=max(profit,max(profit1,profit2));
        }else{
            //take
            int p1=-prices[ind]+dp[ind+1][1];
            //not take
            int p2=dp[ind+1][0];
            profit=max(profit,max(p1,p2));
        }
        dp[ind][buy]=profit;
            }
        }
        return dp[0][0];
    }
};