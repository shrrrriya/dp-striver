class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        //create the next greater element array 
        int n=nums2.size();
        stack<int> st;
        vector<int> arr;
        st.push(nums2[n-1]);
        arr.push_back(-1);
        for(int i=n-2;i>=0;i--){
            while(!st.empty() && st.top()<=nums2[i]) st.pop();
            if(st.empty()){
                arr.push_back(-1);
            }else{
                arr.push_back(st.top());
            }
            st.push(nums2[i]);
        }
        reverse(arr.begin(),arr.end());
        vector<int> ans;
        for(int i:nums1){
            int index=finc(i,nums2);
            ans.push_back(arr[index]);
        }
        return ans;
    }
    int finc(int num,vector<int> nums2){
        int i=0;
        while(nums2[i]!=num) i++;
        return i;
    }
};

// class Solution {
// public:
//     vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
//          vector<int> nums(nums2.size(), -1);  // ✅ Fixed: Initialize nums with correct size
//         vector<int> ans(nums1.size(), -1);  // ✅ Fixed: Initialize ans with correct size
//         stack<int> st;

//         for(int i=nums2.size()-1;i>=0;i--){
//             while(!st.empty() && st.top()<=nums2[i]){
//                 st.pop();
//             }
//             if(st.empty()) nums[i]=-1;
//             else nums[i]=st.top();

//             st.push(nums2[i]);
//         }

//         for(int i=0;i<nums1.size();i++){
//             for(int j=0;j<nums2.size();j++){
//                 if(nums2[j]==nums1[i]){
//                     ans[i]=nums[j];
//                     break;
//                 }
//             }
//         }
//         return ans;
//     }
// };