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
   void recursionRight(TreeNode* root, int level, vector<int> &res){

        if(root == NULL){
            return;
        }
        
 
        if(res.size() == level){
   
            res.push_back(root->val);
        }
           
            recursionRight(root->right, level + 1, res);
            
          
            recursionRight(root->left, level + 1, res);
        
   }
    
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        if(root==NULL){
            return ans;
        }
        recursionRight(root,0,ans);
        return ans;
        
    }
};