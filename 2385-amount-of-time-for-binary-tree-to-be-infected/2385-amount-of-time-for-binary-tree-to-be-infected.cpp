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
TreeNode* searchnode(TreeNode* root, int start){
    if(root==NULL)return NULL;
    if(root->val==start)return root;
   
     TreeNode* leftnode= searchnode(root->left,start);
        if(leftnode!=NULL)return leftnode;
    
    return searchnode(root->right,start);

}
    int amountOfTime(TreeNode* root, int start) {
     int time=0;
     //create an attachment 
    unordered_map<TreeNode*,TreeNode*>parent;
      
     queue<TreeNode*>q;
     q.push(root);
     //mark it visited

     parent[root]=NULL;
     while(!q.empty()){
        TreeNode* node=q.front();
        q.pop();
        //push its right and left with parent mark 
        if(node->left){
            q.push(node->left);
            //mark its  parent 
            parent[node->left]=node;
        }
        if(node->right){
            q.push(node->right);
            //mark 
            parent[node->right]=node;
        }
     }
     //find node into the tree 
     TreeNode* startnode=searchnode(root,start);
     //Bfs 
     unordered_map<TreeNode*,bool>visited;
     q.push(startnode);
     visited[startnode]=true;
     while(!q.empty()){
        int size=q.size();
        for(int i=0;i<size;i++){
            TreeNode* node=q.front();
            q.pop();
            //bfs 
            if(node->left && !visited[node->left]){
                q.push(node->left);
                visited[node->left]=true;
            }
            if(node->right && !visited[node->right]){
                q.push(node->right);
                visited[node->right]=true;
            }
            if(parent[node]&& !visited[parent[node]]){
                 q.push(parent[node]);
                 visited[parent[node]]=true;
            }
           
        }
        time++;
     }
    return time-1;
    }
};