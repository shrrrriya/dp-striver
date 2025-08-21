class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n=nums.size();
        vector<int> ans(n,0);
        int pos=0; int neg=1;
        for(int i=0;i<n;i++){
            if(nums[i]>0){
                ans[pos]=nums[i]; pos=pos+2;
            }else{
                ans[neg]=nums[i]; neg=neg+2;
            }
        }
        return ans;
        // for(int i=0;i<n;i++){
        //     if(nums[i]>0) pos.push(nums[i]);
        //     if(nums[i]<0) neg.push(nums[i]);
        // }
        // for(int i=0;i<n;i++){
        //     if(i%2==0){
        //         nums[i]=pos.front();
        //         pos.pop();
        //     }
        //     else{
        //         nums[i]=neg.front();
        //         neg.pop();
        //     }
        // }

    }
};