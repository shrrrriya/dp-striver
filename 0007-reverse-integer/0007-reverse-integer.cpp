class Solution {
public:
    int reverse(int y) {
        long long res=0;
        bool flag=false;
        long long x=y;
        if(x<0){
            flag=true; x=x*(-1);
        }
    while(x>0){
        int N=x%10;
        res=(res*10)+N;
        x=x/10;
        if (res > INT_MAX || res < INT_MIN) return 0;
    }
    if(flag) res=res*(-1);
    if (res < INT_MIN || res > INT_MAX) return 0;
    return res;
    }
};