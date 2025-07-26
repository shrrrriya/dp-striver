class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n=matrix.size();
        int m=matrix[0].size();
        int low=0; int high=(n*m)-1;
        while(low<=high){
            int mid=(low+high)/2;
            int row=mid/m; int col=mid%m;
            if(matrix[row][col]==target) return true;
            else if(matrix[row][col]<target) low=mid+1;
            else high=mid-1;
        }
        return false;
    }
};

//nlog(n) doesnt satisfy all test cases 
// class Solution {
// public:
//     bool searchMatrix(vector<vector<int>>& matrix, int target) {
//         int n=matrix.size();
//         int m=matrix[0].size();
//         if(n==1 && m==1){
//             if(matrix[0][0]==target) return true;
//             else return false;
//         }
//         int i=0; bool b=false;

//         while(i<n-1){
//             if(matrix[i][0]<=target && matrix[i+1][0]>=target){
//                 b=true;
//                 break;
//             } i++;
//         }
//         if(!b) i=n-1;
//         //binary search
//         int low=0; int high=m-1;
//         while(low<high){
//             if(target==matrix[i][low] || target==matrix[i][high]) return true;
//             if(target>matrix[i][low]) low++;
//             else high--;
//         }
//         return false;
//     }
// };