class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        vector<int> Rmax(n,0);
        Rmax[n-1]=height[n-1];
        for(int i=n-2;i>=0;i--){
            Rmax[i]=max(height[i],Rmax[i+1]);
        }
        int total=0; int Lmax=0;
        for(int i=0;i<n;i++){
            if(i==0) Lmax=height[0];
            else Lmax=max(Lmax,height[i]);
            if(height[i]<Lmax && height[i]<Rmax[i]){
                total=total+min(Lmax,Rmax[i])-height[i];
            }
        }
        return total;
    }
};