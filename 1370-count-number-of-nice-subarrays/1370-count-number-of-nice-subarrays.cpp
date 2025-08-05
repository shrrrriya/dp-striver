class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        return func(nums,k)-func(nums,k-1);
    }
    int func(vector<int>& nums, int k){
        int n=nums.size();
        int l=0,r=0,cnt=0;
        int odd=0;
        while(r<n){
            if(nums[r]%2==1)odd++;
            if(odd>k){
                while(odd>k){
                    if(nums[l]%2==1)odd--;
                    l=l+1;
                }
            }
            if(odd<=k)cnt=cnt+r-l+1;
            r++;
        }
        return cnt;
    }
};