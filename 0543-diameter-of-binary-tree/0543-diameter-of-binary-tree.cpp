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
        int diameter=0;
// int maxDepth(TreeNode* root) {
//         if (!root) return 0;
//         int lefth=maxDepth(root->left);
//         int righth=maxDepth(root->right);
//         diameter=max(lefth+righth, diameter);

//         return 1 + max(lefth,righth);
//    }
// int diameterOfBinaryTree(TreeNode* root) {
//         maxDepth(root);
//         return diameter;
//     }
//optimal

int maxheight(TreeNode* root, int& diameter){
    if(root==NULL){
        return 0;
    }
    int lh=maxheight(root->left,diameter);
    int rh=maxheight(root->right,diameter);
    diameter=max(lh+rh,diameter);
    return 1+max(lh,rh);

}

    
    int diameterOfBinaryTree(TreeNode* root) {
        maxheight(root,diameter);
        return diameter;
    }
};