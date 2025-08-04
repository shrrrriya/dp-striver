class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n=nums.size();
        int psum=0;int cnt=0;
        map<int,int>mpp;
        mpp.insert({0,1}); //vvvimp
        for(int i=0;i<n;i++){   
            psum=psum+nums[i];
            if(mpp.find(psum-k)!= mpp.end()) cnt+=mpp[psum-k];
            if(mpp.find(psum)!= mpp.end()) mpp[psum]++;
            else mpp.insert({psum,1});        
        }
        return cnt;
    }
};