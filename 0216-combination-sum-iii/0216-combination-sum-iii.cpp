class Solution {
public:
    void arrays(vector<vector<int>>&vec, vector<int>v, int i, int sum,int &target, int &k,int count)
    {
        if(count==k)
        {
            if(sum==target)
            {
                vec.push_back(v);
            }
            return;
        }
        if(i==10 || sum>target)
        {
            return;
        } 
        
        v.push_back(i); // 1 2 3 
        arrays(vec,v,i+1,sum+i,target,k,count+1);
        v.pop_back();
        arrays(vec,v,i+1,sum,target,k,count);
        
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>>vec;
        arrays(vec,{},1,0,n,k,0);
        return vec;
    }
};