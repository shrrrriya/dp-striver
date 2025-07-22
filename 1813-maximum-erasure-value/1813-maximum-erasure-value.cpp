#include <vector>
#include <unordered_set>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int n = nums.size();
        unordered_set<int> seen;
        int left = 0;
        int currentSum = 0;
        int maxSum = 0;
        
        for (int right = 0; right < n; ++right) {
            while (seen.find(nums[right]) != seen.end()) {
                currentSum -= nums[left];
                seen.erase(nums[left]);
                ++left;
            }
            currentSum += nums[right];
            seen.insert(nums[right]);
            maxSum = max(maxSum, currentSum);
        }
        
        return maxSum;
    }
};



// class Solution {
// public:
//     int maximumUniqueSubarray(vector<int>& nums) {
//         int n=nums.size();
//         if(n==1) return nums[0];
//         unordered_map<int,int> mp;
//         return func(0,0,nums,mp);
//     }
//     int func(int ind,bool b,vector<int>& nums,unordered_map<int,int> mp){
//         //base case
//         if(ind==nums.size()) return 0;
//         if(mp[nums[ind]]==1) return 0;
//         //pick
//         if(b==1){
//             mp[nums[ind]]=1;
//             return nums[ind]+func(ind+1,1,nums,mp);
//         }
//         //not pick
//         else{
//             unordered_map<int,int> mp;
//             mp[nums[ind]]=1;
//             int pick=nums[ind]+func(ind+1,1,nums,mp);
//             int notpick= func(ind+1,0,nums,mp);
//             return max(pick,notpick);
//         }

//     }
// };