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
TreeNode* findNode(TreeNode* root,int start){
    //base case 
      //root is not presernt 
    if(root==NULL)return NULL;
    if(root->val==start){
        return root;
    }
  
    //now left and right side 
    TreeNode* left= findNode(root->left,start);
    //it may be NULL '
    if(left!=NULL)return left;
    //travese on its right sides
    return findNode(root->right,start);
}
    int amountOfTime(TreeNode* root, int start) {
        //store first parent of each node 
        unordered_map<TreeNode*,TreeNode*>parent;
        //mark root parent -1
        parent[root]=NULL;
        //mark all nodes parent 
        queue<TreeNode*>q;
        q.push(root);
        //while
        while(!q.empty()){
            TreeNode* node=q.front();
            q.pop();
            //check its child first 
            if(node->left){
                q.push(node->left);
                parent[node->left]=node;
            }
            if(node->right){
                q.push(node->right);
                parent[node->right]=node;
            }

        }
        //find node from where have to make infected
        TreeNode* stnode=findNode(root,start);
      //find out node from here have to infr=ect tree 
       //take an visited array to track
       unordered_map<TreeNode*,bool>visited;
      q.push(stnode);
      visited[stnode]=true;
      int time=0;
      //travesre on its all childs and parets
      while(!q.empty()){
        int size=q.size();
        for(int i=0;i<size;i++){
             TreeNode* node=q.front();
             q.pop();
              //childs 
         if(node->left && !visited[node->left]){
            q.push(node->left);
            //mark it visited
            visited[node->left]=true;
         }
         if(node->right && !visited[node->right]){
            q.push(node->right);
            //mark it visited
            visited[node->right]=true;
         }
         //parent 
         if(parent[node] && !visited[parent[node]]){
            q.push(parent[node]);
            visited[parent[node]]=true;
         }
        }
       time++;
      }
     return time-1;

    }
};