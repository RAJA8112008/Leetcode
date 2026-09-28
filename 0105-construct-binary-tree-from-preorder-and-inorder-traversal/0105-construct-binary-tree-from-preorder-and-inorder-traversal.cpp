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
TreeNode* solve(vector<int>& preorder, vector<int>& inorder,int st,int ed,int &idx){
    if(st>ed)return NULL;
    TreeNode* root=new TreeNode(preorder[idx]);
    //find this root in inorder 
    int i=0;
    for(;i<inorder.size();i++){
        if(inorder[i]==preorder[idx]){
            break;
        }
    }
    idx++;
    root->left=solve(preorder,inorder,st,i-1,idx);
    root->right=solve(preorder,inorder,i+1,ed,idx);
     return root;
    
}
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n=inorder.size();
        int st=0;
        int ed=n-1;
        int idx=0;
        return solve(preorder,inorder,st,ed,idx);
    }
};