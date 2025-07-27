class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n=cardPoints.size();
        int lsum=0; int rSum=0;int maxSum=0;
            //total possible  left sum
            for(int l=0;l<=k-1;l++){
                lsum=lsum+cardPoints[l];
            }
            maxSum=lsum;
            int rIndex=n-1;
            for(int i=k-1;i>=0;i--){
                lsum=lsum-cardPoints[i];
                rSum=rSum+cardPoints[rIndex];
                rIndex--;
                maxSum=max(maxSum,lsum+rSum);
            }
            return maxSum;
    }
};