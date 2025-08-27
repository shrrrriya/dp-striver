class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int n=bills.size();
        int fcoins=0;int tcoins=0;
        for(int i=0;i<n;i++){
            if(bills[i]==5){
                fcoins++;
            }
            if(bills[i]==10){
                if(fcoins<1) return false;
                fcoins--; tcoins++;
            }
            if(bills[i]==20){
                if(fcoins>=1 && tcoins>=1){
                    fcoins--; tcoins--; continue;
                }
                if(fcoins>=3){
                    fcoins=fcoins-3; continue;
                }
                return false;
            }
        }
        return true;
    }
};