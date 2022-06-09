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
private:
    int res;
public:
    int Solve(TreeNode* root) {
        if (root == NULL)
            return 0;

        int l = Solve(root->left); //think deeply...its max sum starting from the root->left node...since we want a continuous path
        int r = Solve(root->right); //think deeply...its max sum starting from the root->right node...since we want a continuous path

        int temp = max( root->val+max(l, r) , root->val); //considering max sum is through the parent node...also considering if there are -ive value nodes
        int ans = max(temp, l+r+ root->val); //considering max sum is through current node
        res = max(res, ans); //this is our main ans

        return temp;
    }
    int maxPathSum(TreeNode* root) {
        res = INT_MIN;
        Solve(root);
        return res;
    }
};
