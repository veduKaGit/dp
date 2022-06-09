class Solution {
public:
    int ans;
   int solve(Node *root)
   {
       if(root==NULL)
       {
           return 0;
       }
       int l = solve(root->left);
       int r = solve(root->right);

       if(root->left!=NULL and root->right!=NULL)
       {
           ans = max(ans,l+r+root->data);
       }
       
       if(root->left==NULL and root->right!=NULL)
       {
           return root->data + r;
       }
       else if(root->left!=NULL and root->right==NULL)
       {
           return root->data + l;
       }
       else if((root->left!=NULL and root->right!=NULL) or (root->left==NULL and root->right==NULL))
       {
           return root->data + max(l,r);
       }
   }
   int maxPathSum(Node* root)
   {
       ans = INT_MIN;
       int x = solve(root);
      if(root->left and root->right)
      {
          return ans;
      }
       return max(ans,x);
   }
};
