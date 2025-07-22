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
class Solution {
public:
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        unordered_map<string,int> mp;
        vector<TreeNode*> ans;
        func(root,mp,ans);
        return ans;
    }
    string func(TreeNode* root,unordered_map<string,int>& mp,vector<TreeNode*>& ans){
        if(root==NULL) return "N";

        //preorder
        string s=to_string(root->val)+","+func(root->left,mp,ans)+","+func(root->right,mp,ans);

        if(mp[s]==1) ans.push_back(root);

        mp[s]++;

        return s;
    }
};