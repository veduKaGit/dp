//OPTIMIZATION: use binary search instead of linear search!

class Solution {
public:
    int find(int k,int n,vector<vector<int>> &memo)
    {   
        if(n==0||n==1) 
            return n;  //if no. of floor 0 , 1 return n:
        if(k==1) 
            return n;        // if 1 egg return number of floor   
        if(memo[k][n]!=-1)
            return memo[k][n];
        
        int ans=1000000,l=1,h=n,temp=0;
     
        while(l<=h)
        {
            int mid=(l+h)/2;
            
            int left=find(k-1,mid-1,memo);   //egg broken
            int right=find(k,n-mid,memo) ;   // not broken  *** VVIMP *** => DONT do h-mid, it's n-mid
            temp = 1 + max(left,right);      // +1 here
            
            if(left<right)                  //we need MORE in worst case
              l=mid+1;                       
            else                            
                h=mid-1;
            
            ans=min(ans,temp);               //store minimum attempts
        }
        
        return memo[k][n]=ans;
     
    }
    int superEggDrop(int K, int N) {
        //K -> egg , N -> floor
        vector<vector<int>> memo(K+1,vector<int> (N+1,-1));
        return find(K,N,memo);
         
    }
};
