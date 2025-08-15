class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size()!=t.size()) return false;
        map<int,int> mpp1,mpp2;
        for(int i=0;i<s.size();i++){
            mpp1[s[i]-'a']++;
            mpp2[t[i]-'a']++;
        }
        return mpp1 == mpp2;
    }
};