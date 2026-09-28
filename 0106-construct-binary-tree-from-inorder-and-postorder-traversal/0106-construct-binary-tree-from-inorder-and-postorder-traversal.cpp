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
   TreeNode* solve(vector<int>& inorder, vector<int>& postorder,int st,int ed,int& idx){
    if(st>ed)return NULL;
    if(idx<0)return NULL;
    TreeNode* root=new TreeNode(postorder[idx]);
    //find in inorder 
    int i=0;
    for(;i<inorder.size();i++){
        if(inorder[i]==postorder[idx]){
            break;
        }
    }
    idx--;
     root->right=solve(inorder,postorder,i+1,ed,idx);
    root->left=solve(inorder,postorder,st,i-1,idx);
    return root;
   }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n=inorder.size();
        int st=0;
        int ed=n-1;
        int idx=n-1;
        return solve(inorder,postorder,st,ed,idx);
    }
};