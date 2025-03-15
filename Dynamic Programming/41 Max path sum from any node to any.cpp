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



// The number of nodes in the tree is in the range [1, 3 * 104].
// -1000 <= Node.val <= 1000


class Solution {
public:
    int ans=INT_MIN;

    int fun(TreeNode* root){  //fun returns: MAX sum b/w the root node AND any child node of it
        if(root==NULL)
            return 0;
        
        if(root->left==NULL && root->right==NULL){
            ans = max(ans, root->val);
            return root->val;
        }
        
        int r = fun(root->left);
        int l = fun(root->right);

        int v = root->val;

        ans = max(ans , max(v, max(v+l, max(v+r, v + r +l))));

        return max(v, max(v+l, v+r));
    }
    int maxPathSum(TreeNode* root) {
        fun(root);
        return ans;
    }
};
