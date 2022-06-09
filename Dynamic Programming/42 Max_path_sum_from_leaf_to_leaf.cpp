class Solution {
public:
   int ans;
   int solve(Node *root)
   {
       if(root==NULL)
           return 0;
       
       int l = solve(root->left); //max sum starting from the root->left node till leaf node in left sub tree
       int r = solve(root->right); //max sum starting from the root->right node till leaf node in right sub tree

       if(root->left!=NULL and root->right!=NULL) //considering that max sum from leaf to leaf is through the CURRENT node
           ans = max(ans, l+r+root->data); 
       
       if(root->left==NULL and root->right!=NULL)  //this if, else if, else is considering that max sum from leaf to leaf is through the PARENT node
           return root->data + r;
       else if(root->left!=NULL and root->right==NULL)
           return root->data + l;
       else if((root->left!=NULL and root->right!=NULL) or (root->left==NULL and root->right==NULL))  //or simply do else...see commented part below
           return root->data + max(l,r);
//        else
//             return root->data + max(l,r);
   }
   int maxPathSum(Node* root)
   {
       ans = INT_MIN;
       int x = solve(root);
       if(root->left!=NULL and root->right!=NULL)
            return ans;
      
       return max(ans,x);//IMP....
   }
};
