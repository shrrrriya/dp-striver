class Solution {
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        if(nums.size()<k) return -1;
        return func(nums,k)-func(nums,k-1);
    }
    int func(vector<int>& nums,int k){
        int l=0,r=0,cnt=0;
        map<int,int> mpp;
        while(r<nums.size()){
            mpp[nums[r]]++;
            while(mpp.size()>k){
                mpp[nums[l]]--;
                if(mpp[nums[l]]==0) mpp.erase(nums[l]);
                l=l+1;
            }
            cnt=cnt+r-l+1;
            r++;
        }
        return cnt;
    }
};

//brute force 
// class Solution {
// public:
//     int subarraysWithKDistinct(vector<int>& nums, int k) {
//         int n=nums.size();
//         int cnt=0;
//         for(int i=0;i<n;i++){
//             set<int> mpp;
//             for(int j=i;j<n;j++){
//                 mpp.insert(nums[j]);
//                 if(mpp.size()==k) cnt++;
//             }
//         }
//         return cnt;
//     }
// };