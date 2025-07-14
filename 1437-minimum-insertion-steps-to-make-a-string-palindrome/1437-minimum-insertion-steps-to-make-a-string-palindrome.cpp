class Solution {
public:
    int minInsertions(string s) {
        int n=s.length();
        int palLen=longestPalindromeSubseq(s);
        return n-palLen;
    }
        int longestPalindromeSubseq(string s) {
          string s2=s;
          reverse(s.begin(),s.end());
          return longestCommonSubsequence(s,s2);
    }
    int longestCommonSubsequence(string text1, string text2) {
        int n=text1.size();
        int m=text2.size();
        vector<int> dp(m+1,0);
        for(int ind1=1;ind1<=n;ind1++){
            vector<int> temp(m+1,0);
            for(int ind2=1;ind2<=m;ind2++){
            if(text1[ind1-1]==text2[ind2-1]) temp[ind2]=1+dp[ind2-1];
            else temp[ind2]=max(dp[ind2],temp[ind2-1]);
            }
            dp=temp;
        }
        return dp[m];
    }
};