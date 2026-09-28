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
 bool checkBST(TreeNode* root,long long mini,long long maxi){
    if(!root)return true;

    bool limit=(mini<root->val && maxi>root->val)?true:false;
    bool left=checkBST(root->left,mini,root->val);
    bool right=checkBST(root->right,root->val,maxi);
    
 return left && right && limit;

 }
    bool isValidBST(TreeNode* root) {
        if(root==NULL)return true;
         long long mini = LLONG_MIN;
         long long maxi = LLONG_MAX;
       return  checkBST(root,mini,maxi);
    }
};