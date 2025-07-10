//striver optimised 
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        return countPartitions(nums,target);
    }
    int countPartitions(vector<int>& arr, int d) {
        int total=0;
        for(int i:arr){
            total+=i;
        }
        if((total-d)<0) return 0;
        if((total-d)%2!=0) return 0;
        return perfectSum(arr,(total-d)/2);
        
    }
    int perfectSum(vector<int>& arr, int target) {
        int n=arr.size();
        vector<int> dp(target+1,0);

        if(arr[0] == 0) dp[0]=2;
        else{
            dp[0]=1; //not pick
            if (arr[0] <= target) dp[arr[0]] = 1; // Pick
        }
        
        for(int ind=1;ind<n;ind++){
            vector<int> temp(target+1);
            for(int j=0;j<=target;j++){
                int nottake=dp[j];
                int take=0;
                if(j>=arr[ind]) take=dp[j-arr[ind]];
        
                temp[j]=take+nottake;
            }
            dp=temp;
        }
        return dp[target];
    }
};

//RECURSIVE SOLUTION - brute (my way)
// class Solution {
// public:
//     int findTargetSumWays(vector<int>& nums, int target) {
//         return func(nums.size()-1,target,nums,target);
//     }
//     int func(int ind,int target,vector<int>& nums,int sum){
//         if (ind == 0) {
//             int count = 0;
//             if (+nums[0] == target) count++;
//             if (-nums[0] == target) count++;
//             return count;
//         }
//         int takepos=func(ind-1,target+nums[ind],nums,sum);
//         int takeneg=func(ind-1,target-nums[ind],nums,sum);
//         return takepos+takeneg;
//     }
// };

//shabdagya solution 
// class Solution { 
// public:
//     int tsum=0;
//     int rec(vector<int>&arr,int target,int i,int ans,vector<vector<int>>&dp){
//         if(ans==target && i==arr.size())return 1;
//         if(i==arr.size()) return 0;

//         if(dp[i][tsum+ans]!=-1)return dp[i][tsum+ans];

//         int add=rec(arr,target,i+1,ans+arr[i],dp);
//         int sub=rec(arr,target,i+1,ans-arr[i],dp);
//         return dp[i][ans+tsum]=add+sub;
//     }
//     int findTargetSumWays(vector<int>& arr, int target) {
//         int n=arr.size();
//         for(int i=0;i<n;i++)tsum+=arr[i];
//         vector<vector<int>>dp(n+1,vector<int>(2*tsum+1,0));
//         if(target+tsum<=2*tsum && target+tsum>=0) dp[n][target+tsum]=1;

//         for(int i=n-1;i>=0;i--){
//             for(int ans=-tsum;ans<=tsum;ans++){

//                 int add=0;
//                 int sub=0;
//                 if(ans+arr[i]<=tsum)add=dp[i+1][ans+arr[i]+tsum];
//                 if(ans-arr[i]+tsum>=0)sub=dp[i+1][ans-arr[i]+tsum];

//                 dp[i][ans+tsum]=add+sub;
//             }
//         }
//         return dp[0][tsum];
//     }
// };