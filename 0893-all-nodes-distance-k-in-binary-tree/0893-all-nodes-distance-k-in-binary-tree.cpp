class Solution {
public:
    vector<int> res;

    void maxDepth(TreeNode* root, int dist) {
        if (!root || dist < 0) return;

        if (dist == 0) {
            res.push_back(root->val);
            return;
        }

        maxDepth(root->left, dist - 1);
        maxDepth(root->right, dist - 1);
    }


    int search(TreeNode* root, TreeNode* target, int k) {
        if (!root) return -1;

        if (root == target) {
            maxDepth(root, k);  
            return 0;
        }

        int left = search(root->left, target, k);
        if (left != -1) {
            if (left + 1 == k) res.push_back(root->val);
            else maxDepth(root->right, k - left - 2);
            return left + 1;
        }

        int right = search(root->right, target, k);
        if (right != -1) {
            if (right + 1 == k) res.push_back(root->val);
            else maxDepth(root->left, k - right - 2);
            return right + 1;
        }

        return -1;
    }

    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        search(root, target, k);
        return res;
    }
};
