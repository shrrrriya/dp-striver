class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n=fruits.size();
        if(n<=2) return n;
        int l=0,r=1;
        int type1=fruits[l], type2=fruits[r];
        int maxi=2;
        while(r<n){
            if(fruits[r]!=type1 && fruits[r]!=type2){
                // while(fruits[l]!=fruits[r-1]) l=l+1;
                l=r-1;
                while(l-1>=0 && fruits[l-1]==fruits[r-1]) l--;
            type1=fruits[l];
            if(type1!=fruits[r]) type2=fruits[r];
            }
            maxi=max(maxi,r-l+1);
            r=r+1;
        }
        return maxi;
    }
};