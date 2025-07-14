class Solution {
public:
    int largestSumAfterKNegations(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());  
        int n = nums.size();
        int i = 0;
        while (i < n && nums[i] < 0 && k > 0) {
            nums[i] = -nums[i];
            i++;
            k--;
        }
        int sum = 0;
        int min_abs = INT_MAX;
        for (int x : nums) {
            sum += x;
            min_abs = min(min_abs, abs(x));
        }
        
        if (k % 2 == 1) {
            sum -= 2 * min_abs;
        }
        return sum;
    }
};
