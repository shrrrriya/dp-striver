class Solution {
public:
    string makeFancyString(string s) {
        int count=1;
        string ans="";
        ans.push_back(s[0]);
        for(int i=1;i<s.size();i++){
            int j=i-1;
            if(s[i]==s[j]) count++;
            else count=1;
            if(count<3){
                ans.push_back(s[i]);
            }
        }
        return ans;
    }
};