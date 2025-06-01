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
    vector<int> preorderTraversal(TreeNode* root) {
        //using recursion
        vector<int> preorder;
        if (root == nullptr)
            return preorder;

        preorder.push_back(root->val);

        vector<int> left = preorderTraversal(root->left);
        vector<int> right = preorderTraversal(root->right);

        preorder.insert(preorder.end(), left.begin(), left.end());
        preorder.insert(preorder.end(), right.begin(), right.end());

        return preorder;

        // iterative
        
        // vector<int>preorder;
        // if(root==NULL)
        // {
        //     return preorder;
        // }
        // stack<TreeNode*>st;
        // st.push(root);
        // while(!st.empty())
        // {
        //     root=st.top();
        //     st.pop();
        //     preorder.push_back(root->val);
        //      if(root->right!=NULL)
        //     {
        //       st.push(root->right);
        //     }
        //     if(root->left!=NULL)
        //     {
        //       st.push(root->left);
        //     }
        // }
        // return preorder;
    }
};