class Solution {
public:
    bool rotateString(string s, string goal) {
        int n=s.size();
        s=s+s;
        for(int i=0;i<s.size();i++){
            if(s[i]==goal[0]){
                int k=0;bool b=true;
                for(int j=i;j<i+goal.size();j++){
                    if(s[j]!=goal[k]){
                        b=false; break;
                    }
                    k++;
                }
                if(b && k==goal.size() && k==n) return true;
            }
        }
        return false;
    }
};