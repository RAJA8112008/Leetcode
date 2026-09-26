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
int height(TreeNode* root){
    if(root==NULL)return 0;
    int leftH=height(root->left);
    int rightH=height(root->right);
    return max(leftH,rightH)+1;
}
    int diameterOfBinaryTree(TreeNode* root) {
        if(root==NULL)return 0;
        int maxD=-1;
        int leftD=height(root->left);
        int rightD=height(root->right);
        maxD=max(leftD+rightD,maxD);
         int left= diameterOfBinaryTree(root->left);
         int right= diameterOfBinaryTree(root->right);
          return max(maxD,max(left,right));
    }
};