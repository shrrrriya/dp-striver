class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string to_comp=strs[0];
        for(int i=1;i<strs.size();i++){
            int n;
            if(strs[i].size()>=to_comp.size()) n=strs[i].size();
            else n=to_comp.size();
            string temp="";
            for(int j=0;j<n;j++){
                if(strs[i][j]==to_comp[j]) temp=temp+ to_comp[j]; 
                else break;
            }
            to_comp=temp;
        }
        return to_comp;
    }
};