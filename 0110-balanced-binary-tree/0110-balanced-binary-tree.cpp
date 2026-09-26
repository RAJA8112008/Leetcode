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
   int heightcount(TreeNode* root){
    if(!root)return 0;
    int leftH=heightcount(root->left);
    int rightH=heightcount(root->right);
    return max(leftH,rightH)+1;
   }
    bool isBalanced(TreeNode* root) {
        if(!root)return true;
        int  leftH=heightcount(root->left);
        bool leftcheck=isBalanced(root->left);
        int rightH=heightcount(root->right);
         bool rightcheck=isBalanced(root->right);
      bool checked =( abs(leftH - rightH) <= 1);
       return leftcheck && rightcheck&& checked;
    }
};