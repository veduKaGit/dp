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

        int l = Solve(root->left);//returns max HEIGHT of left sub tree
        int r = Solve(root->right);//returns max HEIGHT of right sub tree

        int temp = (1+max(l, r));  //returns max HEIGHT...considering max DIAMETER is through the parent node
        int ans = max(temp, l+r+1); //l+r+1 is the DIAMATER considering max DIAMETER is through current node
        res = max(res, ans);//this is our main ans
        return temp;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        if (root == NULL)
            return 0;

        res = INT_MIN + 1;
        Solve(root);
        return res - 1; //IMP!!!! return res-1....depends from ques to ques to ques on what they consider the 'diameter'...
    }
};
