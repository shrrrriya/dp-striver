class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size()==1) return nums[0];
        if(nums.size()==2) return max(nums[1],nums[0]);
        int prev1=0;  int prev2=nums[0];
        for(int i=1;i<nums.size();i++){
        int pick=nums[i]+ prev1;
        int notpick= prev2;
        int curr=max(pick,notpick);
        prev1=prev2; prev2=curr;
        }
        return prev2;
    }
};