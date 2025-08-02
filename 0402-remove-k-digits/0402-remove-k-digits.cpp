class Solution {
public:
    string removeKdigits(string num, int k) {
        int n=num.size();
        if(k>=n) return "0";
        stack<char> st;
        for(int i=0;i<n;i++){
            while(!st.empty() && k>0 && num[i]-'0'< st.top()-'0'){
                st.pop(); k--;
            }
            st.push(num[i]);
        }
        while(!st.empty() && k>0){
            st.pop();
            k--;
        }
        if(st.empty()) return "0";
        string res;
        while(!st.empty()){
            res.push_back(st.top());
            st.pop();
        }
        reverse(res.begin(), res.end());
        // for(int i=res.size()-1;i>=0;i--){
        //     if(res[i]='0'){
        //         res.pop_back(); continue;}
        //     else break;
        // }
        // reverse(res.begin(),res.end());
        // return res;
         // CHANGED: proper leading-zero removal
        int pos = 0;
        while (pos < res.size() && res[pos] == '0') ++pos;
        res = (pos == res.size()) ? "0" : res.substr(pos);

        return res;
    }
};