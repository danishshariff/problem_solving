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
    vector<int> inorderTraversal(TreeNode* root) {

        //using recursion
        vector<int> inorder;

        if(root==nullptr){
            return inorder;
        }
        vector<int> left= inorderTraversal(root->left);
        vector<int> right= inorderTraversal(root->right);

        inorder.insert(inorder.end(),left.begin(),left.end());
        inorder.push_back(root->val);
        inorder.insert(inorder.end(),right.begin(),right.end());

        return inorder;

        //iterative
        
        // stack<TreeNode*> st;
        // TreeNode * node = root;
        // vector<int> inorder;
        // while(true){
        //     if(node != NULL){
        //         st.push(node);
        //         node = node->left;
        //     }
        //     else{
        //         if(st.empty() == true) break;
        //         node = st.top();
        //         st.pop();
        //         inorder.push_back(node->val);
        //         node = node->right;
        //     }
        // }
        // return inorder;
    }
};