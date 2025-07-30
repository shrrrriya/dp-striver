// class Solution {
// public:
//     int longestSubarray(vector<int>& nums) {
//         int n=nums.size();
//         int len=0; int maxi=INT_MIN;
//         //generate all subsequences 
//         for(int i=0;i<n;i++){
//             int AND=nums[i];
//             for(int j=i;j<n;j++){
//                 AND= AND & nums[j];
//                 if (AND > maxi) {
//                     maxi = AND;
//                     len = j - i + 1;
//                 } else if (AND == maxi) {
//                     len = max(len, j - i + 1);
//                 }
//             }
//         }
//         return len;
//     }
// };

class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int maxVal = *max_element(nums.begin(), nums.end());
        int maxLen = 0, currLen = 0;

        for (int num : nums) {
            if (num == maxVal) {
                currLen++;
                maxLen = max(maxLen, currLen);
            } else {
                currLen = 0;
            }
        }

        return maxLen;
    }
};
