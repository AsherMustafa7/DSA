class Solution {
public:
    int maxProduct(int n) 
    {
        vector<int>v;
        int copy=n;
        while(copy>0)
        {
            int d= copy%10;
            v.push_back(d);
            copy=copy/10;
        }
        sort(v.begin(),v.end());
        if(v.size()>1)
        return v[v.size()-1] * v[v.size()-2];
        return v[v.size()-1];
    }
};