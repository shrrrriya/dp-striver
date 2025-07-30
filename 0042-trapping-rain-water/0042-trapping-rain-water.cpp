//APPROACH 2
class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        int l=0; int r=n-1;
        int Lmax=0;int Rmax=0; int total=0;
        while(l<r){
            if(height[l]<=height[r]){
                if(Lmax>height[l]) total+=Lmax-height[l];
                else Lmax=max(Lmax,height[l]);
                l=l+1;
            }else{
                if(Rmax>height[r]) total+=Rmax-height[r];
                else Rmax=max(Rmax,height[r]);
                r=r-1; 
            }
        }
        return total;
    }
};

//APPROACH 1
// class Solution {
// public:
//     int trap(vector<int>& height) {
//         int n=height.size();
//         vector<int> Rmax(n,0);
//         Rmax[n-1]=height[n-1];
//         for(int i=n-2;i>=0;i--){
//             Rmax[i]=max(height[i],Rmax[i+1]);
//         }
//         int total=0; int Lmax=0;
//         for(int i=0;i<n;i++){
//             if(i==0) Lmax=height[0];
//             else Lmax=max(Lmax,height[i]);
//             if(height[i]<Lmax && height[i]<Rmax[i]){
//                 total=total+min(Lmax,Rmax[i])-height[i];
//             }
//         }
//         return total;
//     }
// };