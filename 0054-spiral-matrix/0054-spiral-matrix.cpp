class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        int top=0,bottom=n-1,left=0,right=m-1;
        vector<int> ans;
        while(ans.size()<n*m){
            //compute top
            for(int i=left;i<=right;i++){
                ans.push_back(matrix[top][i]);
            }
            if (++top > bottom) break;
            //compute right
            for(int i=top;i<=bottom;i++){
                ans.push_back(matrix[i][right]);
            }
            if (--right < left) break;
            //compute bottom
            for(int i=right;i>=left;i--){
                ans.push_back(matrix[bottom][i]);
            }
            if (--bottom < top) break;
            //compute left
            for(int i=bottom;i>=top;i--){
                ans.push_back(matrix[i][left]);
            }
            left++;
        } 
        return ans;
    }
};