class Solution {
public:
    int countMaxOrSubsets(vector<int>& nums) {
        int n=nums.size();
        //generate all subsets of nums then check for the condition 
        int maxi=INT_MIN;
        int subsets=1<<n;
        for(int num=0;num<subsets;num++){
            vector<int> arr;
            for(int i=0;i<=n-1;i++){
                if(num & (1<<i)) arr.push_back(nums[i]);
            }
            //compute the or of all elemnts in that array 
            int OR=0;
            for(int i=0;i<arr.size();i++){
                OR=OR | arr[i];
            }
            maxi=max(maxi,OR);
        }
        int cnt=0;
        for(int num=0;num<subsets;num++){
            vector<int> arr;
            for(int i=0;i<=n-1;i++){
                if(num & (1<<i)) arr.push_back(nums[i]);
            }
            //compute the or of all elemnts in that array 
            int OR=0;
            for(int i=0;i<arr.size();i++){
                OR=OR | arr[i];
            }
            if(OR==maxi) cnt++;
        }
        return cnt;
    }
};