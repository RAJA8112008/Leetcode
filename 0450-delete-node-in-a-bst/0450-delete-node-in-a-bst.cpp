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
 TreeNode* findsuccessor(TreeNode* root){
    if(root->left==NULL)return root;
   return findsuccessor(root->left);
 }
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root==NULL)return NULL;
        if(root->val==key){
            //case 1
            if(root->right && !root->left){
                TreeNode* temp=root->right;
                delete(root);
                return temp;
            }
            //case 2
            if(root->left && !root->right){
                TreeNode* temp=root->left;
                delete(root);
                return temp;
            }
            //case 3;
            if(!root->left && !root->right){
                delete(root);
                return NULL;
            }
            //case 4:
            if(root->left && root->right){
                //find succesor 
                TreeNode* succ=findsuccessor(root->right);
                //copy the value 
                root->val=succ->val;
                //delete succesor 
               root->right= deleteNode(root->right,succ->val);
            }

        }else if(root->val>key){
            root->left=deleteNode(root->left,key);
        }else{
            root->right=deleteNode(root->right,key);
        }
        return root;
    }
};