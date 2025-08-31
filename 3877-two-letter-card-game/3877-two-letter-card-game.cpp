class Solution {
public:
    int score(vector<string>& cards, char x) {
        map<char,int>mp1,mp2;
        int both=0;
        for(auto s:cards){
            if(s[0]==x&&s[1]==x)both++;
            else if(s[0]==x)mp1[s[1]]++;
            else if(s[1]==x)mp2[s[0]]++;
        }
        int a=0; int m=0; int u=0;
        for(auto it:mp1){a+=it.second; m=max(m,it.second);}
        u=a;
        int k1=min(a/2,a-m);
        int ans=min(a/2,a-m);
        int rem=a-2*ans;
        a=0; m=0;
        for(auto it:mp2){a+=it.second; m=max(m,it.second);}
        int k=min(a/2,a-m);
        rem+=(a-2*k);
        ans+=min(a/2,a-m);
        u+=a;
        ans+=min(both,rem);
        if(both>rem){//edgecase most important
            int x=min((both-rem)/2,k1+k);
            ans+=x;
        }
        return ans;
    }
};