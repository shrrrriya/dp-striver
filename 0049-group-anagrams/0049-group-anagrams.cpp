class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int n = strs.size();
        vector<vector<string>> ans;
        vector<char> used(n, 0);

        for (int i = 0; i < n; i++) {
            vector<string> temp;
            if (used[i]) continue;
            temp.push_back(strs[i]);
            // put everything into the first hash map 
            vector<int> hash1(26, 0);
            for (char c : strs[i]) hash1[c - 'a']++;
            for (int j = i + 1; j < n; j++) {
                // put everything into the second map 
                if (!used[j] && strs[i].size() == strs[j].size()) {
                    vector<int> hash2(26, 0);
                    for (int k = 0; k < (int)strs[i].size(); k++) {
                        hash2[strs[j][k] - 'a']++;
                    }
                    if (hash1 == hash2) {
                        temp.push_back(strs[j]);
                        used[j] = 1;
                    }
                }
            }
            used[i] = 1;
            ans.push_back(temp);
        }
        return ans;
    }
};
