class Solution {
public:
    bool isPowerOfThree(int n) {
        if(n<=0) return false;
        if(n==1) return true;
        if(1162261467%n==0)return true;
        return false;

    }
};