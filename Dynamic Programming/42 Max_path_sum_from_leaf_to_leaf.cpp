class Solution {
private:
int res;

int Solve(Node* root) {
    if (root == NULL)
        return 0;

    int l = Solve(root->left);
    int r = Solve(root->right);

    int temp;
    if (root->left && root->right) {
        res = max(res, l + r + root->data);
        temp = root->data + max(l, r);
    }
    else if (root->left)
        temp = root->data + l;
    else if (root->right)
        temp = root->data + r;
    else
        temp = root->data;
}

    return temp;
}

int maxPathSum(Node* root)
{
    // code here
    res = INT_MIN;
    Solve(root);
    return res;
}









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
       return root->data + max(l,r);
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
