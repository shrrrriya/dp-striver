class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int n=strs.size();
        map<vector<int>,vector<string>> mpp;
        for(int i=0;i<n;i++){
            //create a hash map 
            vector<int> hash(26,0);
            for(int j=0;j<strs[i].size();j++){
                hash[strs[i][j]-'a']++;
            }
                mpp[hash].push_back(strs[i]);
        }
        vector<vector<string>> ans;
        for(auto it:mpp){
            ans.push_back(it.second);
        }
        return ans;
    }
};