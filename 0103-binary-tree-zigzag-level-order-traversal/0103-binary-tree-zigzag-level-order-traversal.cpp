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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if(root==NULL){
            return res;
        }

        queue<TreeNode*> q;
        bool flag=true;
        q.push(root);
        while(!q.empty()){
            int size=q.size();
            vector<int> level(size);
            for(int i=0;i<size;i++){
                 TreeNode* node=q.front();
                 q.pop();
                 int ind=(flag)? i:(size-1-i);
                 level[ind]=node->val;
                  if(node->left!=NULL){
                     q.push(node->left);}
                     if(node->right!=NULL){
                     q.push(node->right);
                 }
                 
                

            }
            flag=!flag;
            res.push_back(level);
    }
    return res;
    }

            };

      