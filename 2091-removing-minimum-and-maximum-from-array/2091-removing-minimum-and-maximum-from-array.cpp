class Solution {
public:
    int minimumDeletions(vector<int>& nums) 
    {
        int mini=INT_MAX;
        int maxi=INT_MIN;
        int p,q=-1;
        for(int i =0; i<nums.size();i++)
        {
            if(nums[i]<mini)
            {
                mini=nums[i];
                p=i;
            }
            if(nums[i]>maxi)
            {
                maxi=nums[i];
                q=i;
            }
        }
        int minind=min(p,q);
        cout<<minind<<endl;

        int maxind=max(p,q);
        cout<<maxind<<endl;
        cout<<"size "<<nums.size()<<endl;
        int a =nums.size()-minind;
        int b=nums.size()-maxind;
        int c=maxind+1;
        int d=minind+1;
        return ( min(d+b,min(a,c) ) );
    }
};