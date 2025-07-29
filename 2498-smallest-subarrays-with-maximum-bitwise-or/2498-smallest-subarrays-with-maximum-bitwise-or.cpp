class Solution {
public:
    vector<int> smallestSubarrays(vector<int>& nums) {
        int n = nums.size();
        vector<int> nearest(32, -1);
        vector<int> ans(n);
        
        for (int i = n - 1; i >= 0; i--) {
            for (int j = 0; j < 32; j++) {
                if (nums[i] & (1 << j)) {
                    nearest[j] = i;
                }
            }
            
            int lastSetBit = i;
            for (int j = 0; j < 32; j++) {
                lastSetBit = max(lastSetBit, nearest[j]);
            }

            ans[i] = lastSetBit - i + 1;
        }
        
        return ans;
    }
};

//BRUTE FORCE - O(n^2)
// class Solution {
// public:
//     vector<int> smallestSubarrays(vector<int>& nums) {
//         int n=nums.size();
//         vector<int> ans;
//         //generate all subsequences 
//         for(int i=0;i<n;i++){
//             int OR=0;int cnt=0; int maxi=INT_MIN;
//             for(int j=i;j<n;j++){
//                 OR=OR | nums[j];
//                 if(OR>maxi){
//                     maxi=OR; cnt=j-i+1;
//                 }
//             }
//             ans.push_back(cnt);
//         }
//         return ans;
//     }
// };

//BRUTE FORCE - O(n^2)
// class Solution {
// public:
//     vector<int> smallestSubarrays(vector<int>& nums) {
//         int n=nums.size();
//         vector<int> ans;
//         //generate all subsequences 
//         for(int i=0;i<n;i++){
//             int OR=0;int cnt=0; int maxi=INT_MIN;
//             for(int j=i;j<n;j++){
//                 OR=OR | nums[j];
//                 if(OR>maxi){
//                     maxi=OR; cnt=j-i+1;
//                 }
//             }
//             ans.push_back(cnt);
//         }
//         return ans;
//     }
// };