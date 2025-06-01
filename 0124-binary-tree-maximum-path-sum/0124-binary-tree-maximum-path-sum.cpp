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

    int findmaxpathsum(TreeNode* root, int& maxi){
        if(root==NULL){
            return 0;
        }

        int leftsum=max(0,findmaxpathsum(root->left,maxi));
        int rightsum=max(0,findmaxpathsum(root->right,maxi));
        maxi=max(maxi,leftsum+rightsum+root->val);

        return max(leftsum,rightsum)+root->val;

    }
    int maxPathSum(TreeNode* root) {
        int maxi=INT_MIN;
        findmaxpathsum(root,maxi);
        return maxi;
    }
};