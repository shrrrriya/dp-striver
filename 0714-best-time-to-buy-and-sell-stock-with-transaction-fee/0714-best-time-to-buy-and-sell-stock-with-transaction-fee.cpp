//SPACE OPTIMIZATION
class Solution {
public:
    int maxProfit(vector<int>& prices,int fee) {
        int n=prices.size();
        vector<int> dp(2,0);

        for(int ind=n-1;ind>=0;ind--){
            vector<int> temp(2,0);
            for(int buy=0;buy<=1;buy++){
        int profit=0;
        if(buy){
            //take 
            int profit1=prices[ind]+dp[0]-fee;
            //not take
            int profit2=dp[buy];
            profit=max(profit,max(profit1,profit2));
        }else{
            //take
            int p1=-prices[ind]+dp[1];
            //not take
            int p2=dp[0];
            profit=max(profit,max(p1,p2));
        }
        temp[buy]=profit;
            }
            dp=temp;
        }
        return dp[0];
    }
};