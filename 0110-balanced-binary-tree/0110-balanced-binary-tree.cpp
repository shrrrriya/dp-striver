/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

 //what i thought of after revision 
class Solution {
public:
//what i did wrong i only checked for the tree dint check for the subtree 
    // bool isBalanced(TreeNode* root) {
    //     if(root==NULL) return true;
    //     int lh=0; int rh=0;
    //     if(root->left!=NULL) lh=1+findHeight(root->left);
    //     if(root->right!=NULL) rh=1+findHeight(root->right);
    //     if(abs(lh-rh)<=1) return true;
    //     else return false;
    // }
    bool isBalanced(TreeNode* root) {
        if (root == NULL) return true;
        
        int lh = findHeight(root->left);
        int rh = findHeight(root->right);

        // Check current node's balance and recurse for subtrees
        return abs(lh - rh) <= 1 && isBalanced(root->left) && isBalanced(root->right);
    }
    int findHeight(TreeNode*root){
        if(root==NULL) return 0;
        int lh=0; int rh=0;
        if(root->left!=NULL){
            lh=findHeight(root->left);
        }
        if(root->right!=NULL){
            rh=findHeight(root->right);
        }
        return 1+max(lh,rh);
    }
};


 //O(N2)

// class Solution {
// public:
// int findHeight(TreeNode*root){
//     if(root==NULL)return 0;
//     int lh=findHeight(root->left);
//     int rh=findHeight(root->right);
//     return 1+max(lh,rh);
// }
//     bool isBalanced(TreeNode* root) {
//         if(root==NULL)return true;
//         int lh=findHeight(root->left);
//         int rh=findHeight(root->right);
//         if(abs(lh-rh)>1)return false;
//         bool left=isBalanced(root->left);
//         bool right=isBalanced(root->right);
//         if(!left || !right)return false;
//         return true;
//     }
// };

//O(N)

// class Solution {
// public:
// int findHeight(TreeNode*root){
//     if(root==NULL)return 0;
//     int lh=findHeight(root->left);
//     if(lh==-1)return -1;
//     int rh=findHeight(root->right);
//     if(rh==-1)return -1;
//     if(abs(lh-rh)>1)return -1;
//     return 1+max(lh,rh);
// }
//     bool isBalanced(TreeNode* root) {
//         return findHeight(root)!=-1;
//     }
// };




