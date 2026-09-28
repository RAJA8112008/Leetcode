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
void NodeParent(TreeNode* root,unordered_map<TreeNode*,TreeNode*>&parent){
        parent[root]=NULL;
        //BFs 
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
           TreeNode* node=q.front();
           q.pop();
           //check its  nbe and  update the parent 
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

TreeNode* findTarget(TreeNode* root,int start){
    if(root==NULL)return NULL;
     if(root->val==start)return root;
     //check left size 
     TreeNode* left=findTarget(root->left,start);
     if(left!=NULL)return left;
       //check right size 
     TreeNode* right=findTarget(root->right,start);
     if(right!=NULL)return right;
     return NULL;
}
    int amountOfTime(TreeNode* root, int start) {
        //<---------------------parent process------------->
     unordered_map<TreeNode*,TreeNode*>parent;
      
        NodeParent(root,parent);
    //<---------------find target node---------->
    TreeNode* burnnode=findTarget(root,start);
    //<----------------start burn tree--------->
    int time=0;
    //vector to tarck node is prev burn or not 
   unordered_map<TreeNode*,bool>visited;
       queue<TreeNode*>q;
       q.push(burnnode);
       while(!q.empty()){
         int size=q.size();
           time++;
         for(int i=0;i<size;i++){
            TreeNode* node=q.front();
            q.pop();
            //mark is visited 
            visited[node]=true;
            if(node->left && visited[node->left]==false){
                q.push(node->left);
                visited[node->left]=true;
            }
            if(node->right && !visited[node->right]){
                q.push(node->right);
                visited[node->right]=true;
            }
            //parent 
            if(parent[node]!=NULL && !visited[parent[node]]){
                q.push(parent[node]);
                visited[parent[node]]=true;
            }
         }
       
       }
       return time-1;
    }
};