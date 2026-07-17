class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) 
    {
      vector<vector<int>>ans;
      vector<int> v;
      kechup(ans,0,v,1,k,n);
      return ans;
    }
    void kechup(vector<vector<int>>&ans, int sum, vector<int>v, int index, int &k , int &n)
    {
        if(sum==n && v.size()==k)
        {
            ans.push_back(v);
            return;
        }
        if(index==10)
        {
            return;
        }
        if(sum>n)
        {
            return;
        }
            v.push_back(index);
            kechup(ans,sum+index,v,index+1,k,n);
            v.pop_back();
            kechup(ans,sum,v,index+1,k,n); 
        
    }
};