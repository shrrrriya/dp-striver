class Solution {
public:
    bool isPowerOfFour(int n) {
        if(n==1) return true;
        if(n<4)return false;
        if(n>0 && ((n & (n-1))==0)){
            int cnt=0;
            while((n&1)==0){
                cnt++;
                n>>=1;
            }
            if(cnt%2==0) return true;
        }
        return false;
    }
};