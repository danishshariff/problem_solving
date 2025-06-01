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
    vector<int> postorderTraversal(TreeNode* root) {

        //using recursion
        
        // vector<int> postorder;
        // if(root==nullptr){
        //     return postorder;
        // }

        // vector<int> left=postorderTraversal(root->left);
        // vector<int> right=postorderTraversal(root->right);

        // postorder.insert(postorder.end(),left.begin(),left.end());
        // postorder.insert(postorder.end(),right.begin(),right.end());
        // postorder.push_back(root->val);

        // return postorder;

        //using 2 stack

    //      vector<int> postorder;

  
    // if(root == NULL){
    //     return postorder;
    // }

  
    // stack<TreeNode*> st1, st2;

    
    // st1.push(root);

    // while(!st1.empty()){
        
    //     root = st1.top();
    //     st1.pop();

      
    //     st2.push(root);

        
    //     if(root->left != NULL){
    //         st1.push(root->left);
    //     }

       
    //     if(root->right != NULL){
    //         st1.push(root->right);
    //     }
    // }

    
    // while(!st2.empty()){
    //     postorder.push_back(st2.top()->val);
    //     st2.pop();
    // }

   
    // return postorder;

vector<int> postorder;

TreeNode* curr=root;
stack<TreeNode*> st;
while(curr!=NULL || !st.empty()){
    if(curr!=NULL){
    st.push(curr);
    curr=curr->left;
    }
    else{
        TreeNode* temp=st.top()->right;
        if(temp==NULL){
            temp=st.top();
            st.pop();
            postorder.push_back(temp->val);
            while(!st.empty() && temp==st.top()->right){
                temp=st.top();
                st.pop();
                postorder.push_back(temp->val);
            }
        }
        else{
            curr=temp;
        }
    }

}

return postorder;


    }
};