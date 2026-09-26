class Solution {
public:
    int solve(TreeNode* root) {
        if(root == NULL)
            return 0;

        int leftsum = solve(root->left);
        int rightsum = solve(root->right);

        return max(0, max(leftsum, rightsum) + root->val);
    }

    int maxPathSum(TreeNode* root) {
        if(root == NULL)
            return INT_MIN;

        int maxval = INT_MIN;

        int leftSum = solve(root->left);
        int rightSum = solve(root->right);

        int currsum = leftSum + rightSum + root->val;

        maxval = max(maxval, currsum);

        int maxleft = maxPathSum(root->left);
        int maxright = maxPathSum(root->right);

        int maxsum = max(maxleft, maxright);

        return max(maxval, maxsum);
    }
};