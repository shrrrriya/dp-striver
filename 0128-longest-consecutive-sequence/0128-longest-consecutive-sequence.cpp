class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size()==0)return 0;
        //intuition:start looking only if you believe you are on the start otherwise skip it 
        unordered_set<int> st;
        for(int i=0;i<nums.size();i++){
            st.insert(nums[i]);
        }
        int longest=1;
        for(auto it:st){
            if(st.find(it-1)==st.end()){ //apne se chota koi hai hi nahi 
                int cnt=1;
                int x=it;
                while(st.find(++x)!=st.end()){ //apne se saare bado ka count lelo 
                    cnt++;
                }
                longest=max(longest,cnt);
            }
        }
        return longest;
    }
};