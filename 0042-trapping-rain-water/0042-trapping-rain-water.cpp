class Solution {
public:
    int trap(vector<int>& height) 
    {
        int pre=height[0];
        int n = height.size();
        int suffixmax[n];
        suffixmax[n-1]=height[n-1];
        for(int i =n-2; i>=0;i--)
        {
            suffixmax[i]= max(suffixmax[i+1],height[i]);
        }
        int sum=0;
        for(int i=1;i<n-1;i++)
        {
            if(min(pre,suffixmax[i+1])-height[i]>0)
            sum+= min(pre,suffixmax[i+1])-height[i];
            pre= max(pre,height[i]);
        }
        return sum;
    }
};