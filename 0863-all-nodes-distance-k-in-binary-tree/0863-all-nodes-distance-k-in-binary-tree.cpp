/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
void parentNode(TreeNode* root,unordered_map<TreeNode*,TreeNode*>&parent){
    parent[root]=NULL;
    queue<TreeNode*>q;
    q.push(root);
    while(!q.empty()){
        TreeNode* node=q.front();
        q.pop();
        if(node->left){
            parent[node->left]=node;
            q.push(node->left);
        }
        if(node->right){
            parent[node->right]=node;
            q.push(node->right);
        }
    }
}
TreeNode* findtarget(TreeNode* root,TreeNode* target){
    if(root==NULL)return NULL;
    if(root==target)return root;
    //left 
    TreeNode* left=findtarget(root->left,target);
    if(left!=NULL)return left;
    TreeNode* right=findtarget(root->right,target);
    if(right!=NULL)return right;
    return NULL;
}
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        //<----------------first store parent of the  nodes---------------->
        unordered_map<TreeNode*,TreeNode*>parent;
        parentNode(root,parent);
        //<-------------------find target node in Tree----------------->
        TreeNode* targetNode=findtarget(root,target);
        if(k==0)return {targetNode->val};
          //BFS 
          vector<int>ans;
          
          unordered_map<TreeNode*,bool>visited;
          
          queue<TreeNode*>q;
          q.push(targetNode);
          visited[target]=true;
          while(!q.empty()){
            int size=q.size();
            for(int i=0;i<size;i++){
                TreeNode* node=q.front();
                q.pop();
                if(node->left && visited[node->left]!=true){
                    visited[node->left]=true;
                    q.push(node->left);
                }
                if(node->right && visited[node->right]!=true){
                    visited[node->right]=true;
                    q.push(node->right);
                }
                //parent 
                if(parent[node]!=NULL && visited[parent[node]]!=true){
                    visited[parent[node]]=true;
                    q.push(parent[node]);
                }
            }
            k--;
            if(k==0){
                while(!q.empty()){
                    TreeNode* node=q.front();
                    q.pop();
                    ans.push_back(node->val);
                }
            }
          }
          return ans;
    }
};